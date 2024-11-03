#include "shm_header.h"


int main(int argc,char** argv){
    int seg_fd; 
    seg_info* seg; 
    seg_info* request;
    mqd_t mqd_comm_chanel; 

    seg_fd=shm_open(SHM_PATH, O_CREAT|O_RDWR, 0777);
    if (seg_fd < 0){
        perror("shm_open reader");
        shm_unlink(SHM_PATH);
    }
   
    if (ftruncate(seg_fd,sizeof(seg_info))<0){
        perror("ftruncate");
    }

    seg = mmap(NULL, sizeof(seg_info), PROT_READ | PROT_WRITE,MAP_SHARED, seg_fd, 0);
    if (seg == MAP_FAILED) {
        perror("mmap error");
        exit(EXIT_FAILURE);
    }
   

    /*create message queue*/
	struct mq_attr attr; 

	attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    mq_unlink(MQ_QUEUE_NAME);
    if ((mqd_comm_chanel=mq_open(MQ_QUEUE_NAME, O_CREAT |  O_RDWR, 0777, &attr ))<0){
		perror("messege queue open err");
		exit(EXIT_FAILURE);
	}
    

    if (sem_init(&seg->sem_mq, 1, 0)<0){
        perror("sem mq init");
    }  

    if (sem_init(&seg->sem_shm_reader, 1, 0)<0){
        perror("sem mq init");
    }  

    if (sem_init(&seg->sem_shm_writer, 1, 0)<0){
        perror("sem mq init");
    }  
    //wait for message from writer 
    if (sem_wait(&seg->sem_mq)<0){
        perror("sem wait");
    }
    request=malloc(1000);
    //receive request
    if (mq_receive (mqd_comm_chanel,(char *) request,1000, NULL) < 0) {
        perror ("mq_receive err receiving request from handle w cache");
            
    }
    printf("buffer received from message queue:%s\n",request->sent_buffer); 
    
    printf("name in req struct:%s\n",request->shm_name);
   

    //wait for content from writer
    if (sem_wait(&seg->sem_shm_reader)<0){
        perror("sem wait");
    }

    printf(" buffer is %s\n",seg->sent_buffer);

    seg->status=400;
    if (sem_post(&seg->sem_shm_writer)<0){
        perror("sem wait writter");
    }
    

    sem_destroy(&seg->sem_mq);
    sem_destroy(&seg->sem_shm_reader);
    sem_destroy(&seg->sem_shm_writer); 
    
    free(request);
    shm_unlink(SHM_PATH); 
    exit(EXIT_SUCCESS);

}
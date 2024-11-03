#include "shm_header.h"

int main(int argc, char** argv){
    int seg_fd; 
    size_t seg_size=5721;
    seg_info* seg;
    seg_info* request;
   
    mqd_t mqd_comm_chanel; 

    mqd_comm_chanel=mq_open(MQ_QUEUE_NAME,O_RDWR); 
    if (mqd_comm_chanel<0){
        perror("comm channel writer"); 
    }
    char shm_name[16]=SHM_PATH;

    seg_fd=shm_open(shm_name,O_RDWR,0); 
    if (seg_fd<0){
        perror("shm_open err"); 
    }
    
    seg=mmap(NULL,sizeof(seg_info),PROT_READ | PROT_WRITE,MAP_SHARED, seg_fd, 0); 
    if (seg == MAP_FAILED) {
        perror("mmap error");
        exit(EXIT_FAILURE);
    }
      
    request=malloc(sizeof(seg_info));
    //copy share mem path name into the struct 
    memcpy(request->sent_buffer,"lpham test name",sizeof(request->sent_buffer)); 

    //testing dereferencing struct
    exam* seg_struct=malloc(sizeof(exam));
    memcpy(seg_struct->name,"linhhhhhhhh",sizeof(seg_struct->name));
    memcpy(request->shm_name,seg_struct->name,sizeof(seg_struct->name));
    // request->ex=*seg_struct; 
    
    //send req via mq 
    if (mq_send(mqd_comm_chanel,(const char*)request,256,0)<0){
        perror("mq_send request"); 
        exit(EXIT_FAILURE);
	}
    //post to reader for the mq
    if (sem_post(&seg->sem_mq)<0){
        perror("sem wait mq");
    };


    
    char* test="this is a test in shm"; 
    memcpy(seg->sent_buffer,test,strlen(test));
    
    if (sem_post(&seg->sem_shm_reader)<0){
        perror("sem post writer");
    }; 
   
    if (sem_wait(&seg->sem_shm_writer)<0){
        perror("sem wait writter");
    }

    // sem_wait(&seg->sem_shm); 
    printf("status:%d\n",seg->status);

    free(request);
    free(seg_struct);

  
    
    exit(EXIT_SUCCESS);


    
}
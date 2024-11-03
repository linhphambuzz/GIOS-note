#include <sys/mman.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <mqueue.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

#define SHM_PATH "/lpham_shm"
#define PATH_SHM_SIZE 64
#define BUFFSIZE 256
#define MQ_QUEUE_NAME "/lpham_queue"

typedef struct seg_info{
    char sent_buffer[BUFFSIZE]; 
    size_t sent_size;
    char shm_name[16];
    int status;
    sem_t  sem_mq;
    sem_t sem_shm_reader;
    sem_t sem_shm_writer;
	
} seg_info;


typedef struct exam{
    char name[16];
} exam;


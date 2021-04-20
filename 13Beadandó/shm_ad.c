#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<string.h>


int main(int argc, char *argv[])
{

    FILE *fp;
    char *data, *buf;
    fp = fopen("bigfile.txt", "r");
    if (fp == NULL){
        perror("fp");
        exit(1);
    }
    fscanf(fp, "%[^\t]",data);
    printf("%s",data);
    key_t key= 1234;
    int shmid;
    char *shmdata;
    if(( shmid = shmget(key,sizeof(char)* fseek(fp,0L,SEEK_END),0666|IPC_CREAT)) < 0 ){
        perror("shmget");
        exit(1);
    }

    if ((shmdata = shmat(shmid,NULL,0)) == (char *) -1){
        perror("shmat");
        exit(1);
    }

    strcpy(shmdata, data);
    printf("%s", data);
    shmdt(shmdata);
    fclose(fp);
    exit(0);
    return 0;
}

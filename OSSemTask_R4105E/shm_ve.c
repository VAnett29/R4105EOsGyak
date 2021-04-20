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
        fp = fopen("bigfile2.txt", "w");


        key_t key= 1234;
        int shmid;
        char *data, *bigtext;
        if ((shmid = shmget(key,sizeof(char)* fseek(fp,0L,SEEK_END), 0666 | IPC_CREAT)) < 0){
                perror("shmget");
                exit(1);
        }
        if((data = shmat(shmid,NULL,0)) == (char *) -1){
                perror("shmat");
                exit(1);
        }

        printf("%s", data);
        fprintf(fp,"%s", data);
        fclose(fp);
        shmdt(data);
        exit(0);
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pidnum;
    int snum;
    int x = 5;
    int y = 0;
    pidnum = fork();
    /// Exit verzi�
    if(pidnum == 0) { exit(1); }
    else { perror("Nem parent processz"); }
    if(WIFEXITED(snum) == 1) { printf("Lefut�s �rt�ke: %d", WEXITSTATUS(snum)); }
	
    /// Abort verzi�
	///A t�bbi nem fut le mert az els� alkalommal kil�p a programb�l
	
    /*if(pidnum == 0) { abort(); }
    else { perror("Nem parent processz"); }
    if(WIFSIGNALED(snum) == 1){ printf("Lefut�s �rt�ke: %d", WTERMSIG(snum)); }*/
	
    /// 0-val val� oszt�s
	
    /*if(pidnum == 0) { x = x / y; }
    else { perror("Nem parent processz"); }
    if(WIFSIGNALED(snum) == 1) { printf("Lefut�s �rt�ke: %d", WTERMSIG(snum)); }*/
	
    return 0;
}

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
    /// Exit verzió
    if(pidnum == 0) { exit(1); }
    else { perror("Nem parent processz"); }
    if(WIFEXITED(snum) == 1) { printf("Lefutás értéke: %d", WEXITSTATUS(snum)); }
	
    /// Abort verzió
	///A többi nem fut le mert az elsõ alkalommal kilép a programból
	
    /*if(pidnum == 0) { abort(); }
    else { perror("Nem parent processz"); }
    if(WIFSIGNALED(snum) == 1){ printf("Lefutás értéke: %d", WTERMSIG(snum)); }*/
	
    /// 0-val való osztás
	
    /*if(pidnum == 0) { x = x / y; }
    else { perror("Nem parent processz"); }
    if(WIFSIGNALED(snum) == 1) { printf("Lefutás értéke: %d", WTERMSIG(snum)); }*/
	
    return 0;
}

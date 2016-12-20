/* These code is from Qiita.com */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define P_MAX 3

int main() {
	int pid[P_MAX];
	int status, i;

	for(i=0; i<P_MAX; i++){
		pid[i] = fork();
		if (pid[i] == 0)
		{
			printf("a process of a child No.%d: Start\n", i);
			sleep(i+1);
			printf("a process of a child No.%d:   End\n", i);
			exit(0);
		}else {
			printf("A Parent process: a process of a child No.%d (pid=%d): Start\n", i, pid[i]);
		}
	}
	printf("Wainting for finishing all processes of children\n");
	for ( i=0; i<P_MAX; i++){
		wait (&status);
	}
	return;
}


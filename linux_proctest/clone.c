/* check after excute this and get logs : $ ps aux | head -1; ps auxw | grep 2596 | grep -v grep */

#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <sys/signal.h>

int main(){
	int status;
	int pid = syscall (SYS_clone, SIGCHLD, 0, 0, 0, 0);

	if(pid == 0){
		int gpid = getpid();
		int gppid = getppid();
		printf("Child, my pid = %d\n", gpid);
		printf("Child, my parent pid = %d\n", gppid);
	}else if (pid == -1){
		perror("SYS_clone: ");
	}else {
		int gpid = getpid();
		int gppid = getppid();
		printf("Parent, my pid = %d\n", gpid);
		printf("Parent, my parent pid = %d\n", gppid);
	}
	wait(&status);
	return;
}

		

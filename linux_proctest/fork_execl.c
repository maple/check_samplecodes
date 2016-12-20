#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	int status, pid;

	pid = fork();

	if (pid == 0){
		printf("child process No.%d: will run pwd after 3 sec\n", pid);
		sleep(3);
		execl("/bin/pwd", "/bin/pwd", NULL);
		printf("this line will NOT handle because child process already fineshed above.\n");
	}else {
		printf("Parent process: Waiting for the child process pid = %d \n", pid);
		wait(&status);
		printf("Parent process: Finished\n");
	}
	return;
}


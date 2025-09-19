#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char * argv[]) {

	// Forks
	pid_t pid = fork();

	// Child Process
	if(pid == 0) {

		printf("IN CHILD: pid=%d\n", getpid());
		execvp(argv[1], argv);

	// Parent Process
	} else {
		
		wait(0);
		printf("IN PARENT: successfully waited child (pid=%d)\n", pid);
	
	}
    
    return 0;
}

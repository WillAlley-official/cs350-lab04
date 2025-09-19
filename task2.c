#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define INPUT_FILE "./input/if1"

int main(int argc, char * argv[]) {
	pid_t pid = fork();

	// Child Process
	if(pid == 0) {

		printf("IN CHILD: pid=%d\n", getpid());
		int fd = open(INPUT_FILE);
		dup2(fd, STDIN_FILENO);
		int output = open("./result", O_CREAT);
		dup2(output, STDOUT_FILENO);
		execvp(argv[1], &argv[1]);

	// Parent Process
	} else {
		
		wait(0);
		printf("IN PARENT: successfully waited child (pid=%d)\n", pid);

	}	
    return 0;
}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	pid_t pid;
	pid = fork();

	if (pid == -1) {
		printf("Failed to create child");
	} else if (pid > 0) {
		printf("From parent %d, %d", getpid(), getppid());
	} else {
		printf("From child %d, %d", getpid(), getppid());
	}

	printf("Hello, World!");
	return 0;
}

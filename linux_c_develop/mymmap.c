//使用mmap函数完成父子进程间通信
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main27()
{
	//使用mmap函数建立共享映射区
	//void *mmap(void *addr, size_t length, int prot, int flags,
	//              int fd, off_t offset);
	char buf[1024];
	memset(buf, 0, sizeof(buf)+1);
	getcwd(buf, sizeof(buf));
	printf("pwd=%s\n", buf);
	int fd = open("b.txt", O_RDWR,0x777);
	if (fd < 0)
	{
		printf("fd=%d\n", fd);
		perror("open error");
		return -1;
	}

	off_t len = lseek(fd, 0, SEEK_END);

	void* addr = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	//void * addr = mmap(NULL, len, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	if (addr == MAP_FAILED)
	{
		perror("mmap error");
		return -1;
	}
	close(fd);

	//创建子进程
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0)
	{
		memcpy(addr, "hello world", strlen("hello world"));
		wait(NULL);
	}
	else if (pid == 0)
	{
		sleep(1);
		char* p = (char*)addr;
		printf("[%s]", p);
	}

	return 0;
}

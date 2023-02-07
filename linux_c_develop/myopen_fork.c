
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
//多个进程通过同一个文件描述符写文件  不会相互覆盖写出去的内容
int main24(int argc, char* arg1[])
{
	char* argv[] = { "","a.txt" };
	//打开文件
	int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}
	pid_t pid = fork();
	if (pid < 0) //fork失败的情况
	{
		perror("fork error");
		return -1;
	}
	if (pid == 0) {
		char buf[1024];
		sprintf(buf, "this is child,pid=%d\t", getpid());

		for (int i = 0; i < 10; i++) {
			ssize_t len = write(fd, buf, strlen(buf));
			off_t cur = lseek(fd, 0, SEEK_CUR);
			printf("child cur =%ld\n", cur);//父子进程获取的cur可能会相同，但是内容不会覆盖
		}
		//printf("len =%d\n", len);
		close(fd);
		//sleep(60);
	}
	else {
		//wait(NULL);

		//sleep(1);
		char* hw = "hello world";
		//写文件
		//ssize_t write(int fd, const void *buf, size_t count);
		for (int i = 0; i < 10; i++) {
			ssize_t len = write(fd, hw, strlen(hw));
			if (len < 0) {
				printf("write error\n");
				return -1;
			}
			off_t cur = lseek(fd, 0, SEEK_CUR);
			printf("parent cur =%ld\n", cur);
		}

		//移动文件指针到文件开始处
		//off_t lseek(int fd, off_t offset, int whence);

		lseek(fd, 0, SEEK_SET);

		//读文件
		//ssize_t read(int fd, void *buf, size_t count);
		char buf[1024];
		memset(buf, 0x00, sizeof(buf));
		ssize_t n = read(fd, buf, sizeof(buf));
		if (n < 0) {
			printf("read error\n");
			return -1;
		}
		printf("n==[%d], buf==[%s]\n", n, buf);

		//关闭文件
		close(fd);

	}
	return 0;
}

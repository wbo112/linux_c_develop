
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
//�������ͨ��ͬһ���ļ�������д�ļ�  �����໥����д��ȥ������
int main24(int argc, char* arg1[])
{
	char* argv[] = { "","a.txt" };
	//���ļ�
	int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}
	pid_t pid = fork();
	if (pid < 0) //forkʧ�ܵ����
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
			printf("child cur =%ld\n", cur);//���ӽ��̻�ȡ��cur���ܻ���ͬ���������ݲ��Ḳ��
		}
		//printf("len =%d\n", len);
		close(fd);
		//sleep(60);
	}
	else {
		//wait(NULL);

		//sleep(1);
		char* hw = "hello world";
		//д�ļ�
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

		//�ƶ��ļ�ָ�뵽�ļ���ʼ��
		//off_t lseek(int fd, off_t offset, int whence);

		lseek(fd, 0, SEEK_SET);

		//���ļ�
		//ssize_t read(int fd, void *buf, size_t count);
		char buf[1024];
		memset(buf, 0x00, sizeof(buf));
		ssize_t n = read(fd, buf, sizeof(buf));
		if (n < 0) {
			printf("read error\n");
			return -1;
		}
		printf("n==[%d], buf==[%s]\n", n, buf);

		//�ر��ļ�
		close(fd);

	}
	return 0;
}

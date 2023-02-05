//����dup2���������ļ�������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main9(int argc, char* argv1[])
{
	char* argv[] = { "","a.txt","b.txt"};
	//���ļ�
	int oldfd = open(argv[1], O_RDWR | O_CREAT, 0755);
	if (oldfd < 0)
	{
		perror("open error");
		return -1;
	}

	int newfd = open(argv[2], O_RDWR | O_CREAT, 0755);
	if (newfd < 0)
	{
		perror("open error");
		return -1;
	}
	//����dup2��������fd
	dup2(oldfd, newfd);
	printf("newfd:[%d], oldfd:[%d]\n", newfd, oldfd);

	//ʹ��fd���ļ�����д����
	write(newfd, "hello world", strlen("hello world"));

	//����lseek�����ƶ��ļ�ָ�뵽��ʼ��
	lseek(newfd, 0, SEEK_SET);

	//ʹ��newfd���ļ�
	char buf[64];
	memset(buf, 0x00, sizeof(buf));
	int n = read(oldfd, buf, sizeof(buf));
	printf("read over: n==[%d], buf==[%s]\n", n, buf);

	//�ر��ļ�
	close(oldfd);
	close(newfd);

	return 0;
}

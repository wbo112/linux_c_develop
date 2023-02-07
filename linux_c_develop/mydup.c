//����dup���������ļ�������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main8(int argc, char* argv1[])
{
	char* argv[] = { "","a.txt" };
	//���ļ�
	int fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	//����dup��������fd
	int newfd = dup(fd);
	printf("newfd:[%d], fd:[%d]\n", newfd, fd);

	//ʹ��fd���ļ�����д����
	write(fd, "hello world", strlen("hello world"));

	//����lseek�����ƶ��ļ�ָ�뵽��ʼ��
	lseek(fd, 0, SEEK_SET);

	//ʹ��newfd���ļ�
	char buf[64];
	memset(buf, 0x00, sizeof(buf));
	ssize_t n = read(newfd, buf, sizeof(buf));
	printf("read over: n==[%d], buf==[%s]\n", n, buf);

	//�ر��ļ�
	close(fd);
	close(newfd);

	return 0;
}

//�޸��ļ���������flag����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main10(int argc, char* argv1[])
{
	char* argv[] = { "","a.txt" };
	//���ļ�
	int fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	//��ú�����fd��flags����
	int flags = fcntl(fd, F_GETFL, 0);
	flags = flags | O_APPEND;
	fcntl(fd, F_SETFL, flags);

	//д�ļ�
	write(fd, "hello world", strlen("hello world"));

	//�ر��ļ�
	close(fd);

	return 0;
}

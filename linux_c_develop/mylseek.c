//lseek����ʵ���ļ���չ
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main4(int argc, char* argv1[])

{
	char* argv[] = {"","a.txt"};
	//���ļ�
	int fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	//�ƶ��ļ�ָ�뵽��100���ֽڴ�
	lseek(fd, 100, SEEK_SET);

	//����һ��д�����
	write(fd, "H", 1);

	//�ر��ļ�
	close(fd);

	return 0;
}

//fifo����������̼�ͨ�ŵĲ���
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main25()
{
	//����fifo�ļ�
	//int mkfifo(const char *pathname, mode_t mode);
	int ret = access("./myfifo", F_OK);
	if (ret != 0)
	{
		ret = mkfifo("./myfifo", 0777);
		if (ret < 0)
		{
			perror("mkfifo error");
			return -1;
		}
	}

	//���ļ�
	int fd = open("./myfifo", O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	//дfifo�ļ�
	int i = 0;
	char buf[64];
	while (1)
	{
		memset(buf, 0x00, sizeof(buf));
		sprintf(buf, "%d:%s", i, "hello world");
		write(fd, buf, strlen(buf));
		sleep(1);

		i++;
	}

	//�ر��ļ�
	close(fd);

	//getchar();

	return 0;
}

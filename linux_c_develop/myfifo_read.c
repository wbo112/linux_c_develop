//fifo完成两个进程间通信的测试
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main26()
{
	//创建fifo文件
	//int mkfifo(const char *pathname, mode_t mode);
	//判断myfofo文件是否存在,若不存在则创建
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

	//打开文件
	int fd = open("./myfifo", O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	//读fifo文件
	ssize_t n;
	char buf[64];
	while (1)
	{
		memset(buf, 0x00, sizeof(buf)+1);
		n = read(fd, buf, sizeof(buf));//
		printf("n==[%d], buf==[%s]\n", n, buf);
		//ssize_t len=write(fd, buf, strlen(buf));
		//printf("len =%d\n", len);
	}

	//关闭文件
	close(fd);

	//getchar();

	return 0;
}

//IO函数测试--->open close read write lseek
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main3(int argc, char* arg1[])
{
	char * argv[] = {"","a.txt"};
	//打开文件
	int fd = open(argv[1], O_RDWR | O_CREAT, 0777);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}

	char* hw = "hello world";
	//写文件
	//ssize_t write(int fd, const void *buf, size_t count);
	ssize_t len=write(fd, hw, strlen(hw));
	if (len < 0) {
		printf("write error\n");
		return -1;
	}
	//移动文件指针到文件开始处
	//off_t lseek(int fd, off_t offset, int whence);

	/*
	* 
	参数 offset 的含义取决于参数 whence：
	如果 whence 是 SEEK_SET，文件偏移量将设置为 offset。
	如果 whence 是 SEEK_CUR，文件偏移量将被设置为 cfo 加上 offset，offset 可以为正也可以为负。
	如果 whence 是 SEEK_END，文件偏移量将被设置为文件长度加上 offset，offset 可以为正也可以为负。
	函数返回值: 若lseek成功执行, 则返回新的偏移量。
	lseek函数常用操作
	文件指针移动到头部
		lseek(fd, 0, SEEK_SET);
	获取文件指针当前位置
		int len = lseek(fd, 0, SEEK_CUR);
	获取文件长度
		int len = lseek(fd, 0, SEEK_END);
		
	*/
	lseek(fd, 0, SEEK_SET);

	//读文件
	//ssize_t read(int fd, void *buf, size_t count);
	char buf[1024];
	memset(buf, 0x00, sizeof(buf));
	int n = read(fd, buf, sizeof(buf));
	if (n < 0) {
		printf("read error\n");
		return -1;
	}
	printf("n==[%d], buf==[%s]\n", n, buf);

	//关闭文件
	close(fd);

	return 0;
}

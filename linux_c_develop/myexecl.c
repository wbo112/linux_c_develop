//fork��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main14()
{
	//�����ӽ���
	pid_t pid = fork();
	if (pid < 0) //forkʧ�ܵ����
	{
		perror("fork error");
		return -1;
	}
	else if (pid > 0)//������
	{
		printf("father: [%d], pid==[%d], fpid==[%d]\n", pid, getpid(), getppid());
		//sleep(1);
	}
	else if (pid == 0) //�ӽ���
	{
		printf("child: pid==[%d], fpid==[%d]\n", getpid(), getppid());
		//execl("/bin/ls", "ls", "-l", NULL);
		//execl("./test", "test", "hello", "world", "ni", "hao", NULL);
		//execlp("ls", "ls", "-l", NULL);1
		execlp("./test", "TESTING", "hello", "world", "ni", "hao", NULL);
		//execlp("./iitest", "test", "hello", "world", "ni", "hao", NULL);
		perror("execl error");
	}

	return 0;
}

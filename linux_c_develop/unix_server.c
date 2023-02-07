//����socketͨ�ŷ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/un.h>


int main1()
{
	//����socket
	int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if (lfd < 0)
	{
		perror("socket error");
		return -1;
	}

	//ɾ��socket�ļ�,����bindʧ��
	unlink("./server.sock");

	//��bind
	struct sockaddr_un serv;
	bzero(&serv, sizeof(serv));
	serv.sun_family = AF_UNIX;
	strcpy(serv.sun_path, "./server.sock");
	int ret = bind(lfd, (struct sockaddr*)&serv, sizeof(serv));
	if (ret < 0)
	{
		perror("bind error");
		return -1;
	}

	//����listen
	listen(lfd, 10);

	//�����µ�����-accept
	struct sockaddr_un client;
	bzero(&client, sizeof(client));
	int len = sizeof(client);
	int cfd = accept(lfd, (struct sockaddr*)&client, &len);
	if (cfd < 0)
	{
		perror("accept error");
		return -1;
	}
	printf("client->[%s]\n", client.sun_path);

	ssize_t n;
	char buf[1024];

	while (1)
	{
		//������
		memset(buf, 0x00, sizeof(buf));
		n = read(cfd, buf, sizeof(buf));
		if (n <= 0)
		{
			printf("read error or client close, n==[%d]\n", n);
			break;
		}
		printf("n==[%d], buf==[%s]\n", n, buf);

		//��������
		write(cfd, buf, n);
	}

	close(lfd);

	return 0;
}


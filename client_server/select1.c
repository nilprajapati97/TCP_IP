#include<stdio.h>
#include<unistd.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/select.h>
#include<fcntl.h>
main()
{
	struct timeval t;
	fd_set v;
	char s[20];
	
	int fd,ret;
	while(1)
	{
	fd= open("f1",O_RDWR);
	
	FD_ZERO(&v);
	FD_SET(0,&v);
	FD_SET(fd,&v);
	
	t.tv_sec=10;
	t.tv_usec=0;
	
	ret= select(10,&v,0,0,&t);
	if(ret <0)
	{
		perror("select");
		return;
	}
	else if(ret==0)
	{
		printf("time out .....\n");
		FD_CLR(fd,&v);
		
	}
	else if(FD_ISSET(0,&v))
	{
		scanf("%s",s);
		printf("STDIN: %s\n",s);
	}
	else if(FD_ISSET(fd,&v))
	{
		read(fd,s,sizeof(s));
		printf("FIFO: %s\n",s);
	}

}
}

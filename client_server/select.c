#include<stdio.h>
#include<sys/select.h>
#include<sys/types.h>
#include<netinet/ip.h>
#include<netinet/in.h>
#include<unistd.h>


main()
{
	int ret;
	struct timeval t;
	fd_set v;
	
	char s[10];
	
	printf("enter the data...\n");
	
	FD_ZERO(&v);
	FD_SET(0,&v);
	
	t.tv_sec=10;
	t.tv_usec=0;
	
	ret= select(10,&v,0,0,&t);
	
	if(ret==-1)
	{
		perror("select");
		return;

	}
	else if(ret==0)
	{
		printf("time out .........\n");
	}
	else
	{
		scanf("%s",s);
		printf("data: %s\n",s);
	}
}

#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
struct st
{
	int rollno;
	char name[20];
	float marks;

};
typedef struct st ST;

main(int argc ,char **argv)
{

	ST s;
	int roll;
	
	if(argc!=3)
	{
		printf("Usage: ./c  port ip\n");
		return;
	}
	char a[20];
	struct sockaddr_in v,v1;

	int sfd,len,nsfd;

	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");

	////////////////////////////////////////////
	// fill the structure member 

	v.sin_family = AF_INET;
	v.sin_port= htons(atoi(argv[1]));
	v.sin_addr.s_addr=inet_addr(argv[2]);

	///////////////////////////////////////////

	len= sizeof(v);
	if(connect(sfd,(struct sockaddr *)&v,len)<0)
	{
		perror("connect");
		return;
	}
	perror("connect");
	while(1)
	{
		printf("Enter the rollno you want to find\n");
		//scanf("%d",&s.rollno);
		scanf("%d",&roll);
		write(sfd,&roll,sizeof(int));
		read(sfd,&s,sizeof(s));

		printf("%d %s %f\n",s.rollno,s.name,s.marks);

	}
}

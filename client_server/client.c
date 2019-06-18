#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>

main()
{
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
v.sin_port= htons(3000);
v.sin_addr.s_addr=inet_addr("127.0.0.1");

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
printf("Enter the data\n");
gets(a);
//scanf("%[^\n]",a);
write(sfd,a,strlen(a)+1);
}












}

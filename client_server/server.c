#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>

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
v.sin_addr.s_addr=inet_addr("0.0.0.0");

///////////////////////////////////////////

len= sizeof(v);
if(bind(sfd,(struct sockaddr *)&v,len)<0)
{
	perror("bind");
	return;
}
perror("bind");
//////////////////////////////////////////
listen(sfd,5);
perror("listen");

//////////////////////////////
printf("before\n");
nsfd = accept(sfd,(struct sockaddr *)&v,&len);
perror("accept");

printf("after");
///////////////////////////////////////////
while(1)
{
read(nsfd,a,sizeof(a));
printf("data: %s\n",a);
}












}

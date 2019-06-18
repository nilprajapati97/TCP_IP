#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>

main()
{
	char a[20];

	struct sockaddr_in v,v1;

	int sfd,len;

	sfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");

	////////////////////////////////////////////////////////////////////////

	v.sin_family=AF_INET;
	v.sin_port=htons(2500);
	v.sin_addr.s_addr=inet_addr("0.0.0.0");

	len = sizeof(v);

	printf("enter the data\n");

	scanf("%s",a);

	sendto(sfd,a,strlen(a)+1,0,(struct sockaddr *)&v,len);

}

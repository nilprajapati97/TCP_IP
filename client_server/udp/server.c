#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>

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

	///////////////////////////////////////////////////////////////////

	v.sin_family=AF_INET;
	v.sin_port=htons(2500);
        v.sin_addr.s_addr= inet_addr("0.0.0.0");

	len= sizeof(v);

	if(bind(sfd,(struct sockaddr *)&v,len)<0)
	{
		perror("bind");
		return;
	}
	perror("bind");


	printf("before\n");

	recvfrom(sfd,a,sizeof(a),0,(struct sockaddr *)&v,&len);

	printf("After data= %s\n",a);
}


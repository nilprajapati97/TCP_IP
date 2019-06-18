#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<string.h>
#include<stdlib.h>

struct st
{
	int rollno;
	char name[20];
	float marks;
	struct st *next;
};
typedef struct st ST;
ST *serch_node(ST *, int );
void add_node(ST **ptr)
{
	ST *temp;
	temp = malloc(sizeof(ST));

	printf("enter the roll no\n");
	scanf("%d",&temp->rollno);	
	printf("enter the name\n");
	scanf("%s",temp->name);	
	printf("enter thr makrs\n");
	scanf("%f",&temp->marks);

	temp->next = *ptr;
	*ptr=temp;	

}
main(int argc, char **argv)
{
	ST s;
	ST *headptr=0,*a;
	char ch;
	int roll;
	if(argc!=2)
	{
		printf("Usage : ./s port_number\n");
		return;
	}

	do
	{
		add_node(&headptr);
		printf("do you want to add another node? (y/n)");
		scanf(" %c",&ch);
	}while(ch == 'y' || ch=='Y');





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
	/////////////////////////////////////////////
	// write structure in file


	///////////////////////////////////////////
	while(1)
	{
		roll=0;
		read(nsfd,&roll,sizeof(int));
		a=serch_node(headptr,roll);
		if(a==0)
		{
			s.rollno=0;
			s.marks=0.0;
			strcpy(s.name,"notfound");
			write(nsfd,&s,sizeof(s));

		}
		else if(a)
		{
			s.rollno=a->rollno;
			strcpy(s.name,a->name);
			s.marks=a->marks;

			write(nsfd,&s,sizeof(s));
		}
	}
}
ST *serch_node(ST *p, int no)
{
	if(p)
	{
		if(p->rollno==no)
			return p;
		else
			return(serch_node(p->next,no));
	}
	else
		return 0;
}


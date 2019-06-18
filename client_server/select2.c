#include<stdio.h>
#include<fcntl.h>
#include<string.h>
main()
{

	char s[20];
	int fd;
	fd= open("f1",O_WRONLY);
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
}

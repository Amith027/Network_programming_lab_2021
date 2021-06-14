#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char frame[1024];

void sender();
void receiver();
int main(void)
{
	sender();
}

void sender()
{
	printf("-----------------------------------------------------------------------------------\n");
	printf("SENDER PORTAL\n");
	int len, n, i; 
	char str[50], flag[10];
	printf("Enter the number of frames you want to send: ");
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		printf("Enter the frame: ");
		scanf("%s", str);
	
		len = strlen(str);
		printf("The length is: %d\n\n",len);
		len = len + 1;
	
		sprintf(flag, "%d", len); // This will convert the len to string and store it in flag.
		strcat(frame, flag);
		strcat(frame, str);
	}
	
	printf("The whole packet is: ");
	for(i=0; frame[i]!='\0'; i++)
	{
		printf("%c", frame[i]);
	}
	printf("\n\n");
	
	receiver();
}

void receiver()
{
	int i=0, framelen, fvar, frmno=0;
	char len;
	printf("-----------------------------------------------------------------------------------\n");
	printf("RECEIVER PORTAL\n");
	
	printf("The frames received are: \n");
	while(frame[i]!='\0')
	{
		frmno++;
		len = frame[i];
		framelen = (int)len - (int)'0';	
		fvar = i + framelen;
		i = i + 1;
		
		printf("\nFrame %d: ",frmno);
		while(i<fvar)
		{
			printf("%c",frame[i++]);
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define d 10

void search(char pattern[],char text[],int primeno);
void loading();
int main()
{
	char text[100],pattern[100],ans;
	int primeno,length,i;
	do
	{
		system("cls");
		printf("**************		RABIN KARP METHOD FOR PATTERN SEARCHING		********************");
		printf("\n\nENTER THE TEXT:\t\t");
		fflush(stdin);
		gets(text);
		printf("\n\nENTER THE PATTERN:\t");
		fflush(stdin);
		gets(pattern);
		length=strlen(text);
		printf("\n\nENTER A PRIME NUMBER:\t");
		scanf("%d",&primeno);
		loading();
		system("cls");
		printf("**************		RABIN KARP METHOD FOR PATTERN SEARCHING		********************\n\n");
		printf("INDEX : ");
		for(i=0;i<length;i++)
		{
			printf("%d  ",i);
		}
		printf("\nSTRING: ");
		for(i=0;text[i]!='\0';i++)
		{
			printf("%c  ",text[i]);
			if(i>=10)
			{
				printf(" ");
			}
		}
		printf("\n\nPATTERN: %s",pattern);
		search(pattern,text,primeno);
		printf("\n\nDO YOU WANT TO TRY FOR ANOTHER TEXT?[y/n]:");
		fflush(stdin);
		scanf("%c",&ans);
	}while(ans=='y');
	return 0;
}

void search(char pattern[],char text[],int primeno)
{
	int m,n,c=0;
	int i,j;
	int pattern_hashvalue=0,text_hashvalue=0,h,a;
	m=strlen(pattern);
	n=strlen(text);
	a=pow(d,m-1);
	h=a%primeno;
	for(i=0;i<m;i++)
	{
		pattern_hashvalue=(d*pattern_hashvalue+pattern[i])%primeno;
		text_hashvalue=(d*text_hashvalue+text[i])%primeno;
	}
	for(i=0;i<=(n-m);i++)
	{
		if(pattern_hashvalue==text_hashvalue)
		{
			for(j=0;j<m;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					break;
				}
			}
			if(j==m)
			{
				printf("\n\nPATTERN FOUND AT INDEX %d.",i);
				c++;
			}
		}
		if(i<(n-m))
		{
			text_hashvalue=(d*(text_hashvalue-text[i]*h)+text[i+m])%primeno;
			if(text_hashvalue<0)
			{
				text_hashvalue=(text_hashvalue+primeno);
			}
		}
	}
	if(c==0)
	{
		printf("\n\nTHE PATTERN YOU ENTERED WAS NOT FOUND IN TEXT!!");
	}
}

void loading() 
{
	int i;
	printf("\nSEARCHING FOR PATTERN");
  	for (i=0;i<1; i++) 
  	{
    	printf(".");
		sleep(1);
		printf(".");
    	sleep(1);
    	printf(".");
    	sleep(1);
    	printf("\r                        ");
  	}
}

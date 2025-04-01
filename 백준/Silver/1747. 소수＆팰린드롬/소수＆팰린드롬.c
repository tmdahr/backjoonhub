#include <stdio.h>
#include <string.h>
int main(void)
{
	int i, l, j, num, m=0, flag=0, k;
	int sieve[1050000]={1,1,0,}, np[8]={10,10,10,10,10,10,10,10};
	
	for(i=2; i<1050000; i++)
	{
		if(sieve[i]==0)
		{
			for(l=i+i; l<1050000; l=l+i)
			{
				sieve[l] = 1;
			}
		}
	}
	scanf("%d", &k);
	for (; k < 1050000; k++)
	{
		num = k;
		flag = 0;
		if(sieve[num]!=0)
			continue;
		else
		{
			//printf("%d\n", num);
			for(i=0; num!=0; i++)
			{
				np[i]=num%10;
				num=num/10;
			}
			//printf("%d\n", num);
			//for(i=0; i<8; i++) printf("%d", np[i]);
			
			l=0;
			while(np[l]!=10) l++;
			
			j=l-1;
			for(i=0; i<l; i++)
			{
				if(np[i] != np[j]) 
				{
					flag = 1;
					break;
				}
				j--;
			}
			
			if(flag == 0)
			{
				printf("%d", k);
				break;
			}	
			else
				continue;		
				
		}	
		
	}

	
	return 0;
}
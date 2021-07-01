#include<stdio.h>
int main(){
	int a,b,f1,f2;
	int i,s;
	int f[10000];
	 int n;
	f[0]=1;
	f[1]=1;

	i=2;
	while(scanf("%d %d %d",&a,&b,&n)==3&&n)
	{
		while(i<10000){
			f[i]=(a*f[i-1]+b*f[i-2])%7;
		
			if(f[i]==1&&f[i-1]==1)
			{
				break;
			}
			i++;
		}
		s=i-2;	
		if(n<=s) printf("%d\n",f[n]);
		else printf("%d\n",f[(n-2)%s]);	
	}
} 

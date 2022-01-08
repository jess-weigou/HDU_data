#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	int a[1001];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		int ans=0;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans^=a[i];	
		}
		if(ans==0)
		{
			printf("0\n");
		}else{
			for(int i=1;i<=n;i++)
			{
				int k=ans^a[i];
				if(k<a[i])
				{
					num++;
				}
			}
			printf("%d\n",num);
		} 
		
	}
	return 0; 
}

#include<stdio.h>
#include<math.h>

int main()
{
	int n,a,b,c,temp;
	int num[3];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d%d",&a,&b,&c);
		
		if(a+b<=c||a+c<=b||b+c<=a)
		{
			printf("Impossible!\n");
			continue;
		}
		num[0]=a;num[1]=b;num[2]=c;
		for(int i=0;i<2;i++)
		{
			for(int j=i+1;j<=2;j++)
			{
				if(num[i]>num[j])
				{
					temp=num[i];
					num[i]=num[j];
					num[j]=temp;
				}
			}
		}

		double fa=(num[0]*num[0]+num[1]*num[1]-num[2]*num[2])*1.0/(2*num[0]*num[1]);
		if(fa==0){
			printf("Right triangle\n");	
		} else if(fa<0){
			printf("Obtuse triangle\n");
		}else{
			printf("Acute triangle\n");
		}
	}
} 

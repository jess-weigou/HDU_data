#include<stdio.h>
 int main()
 {
 	int k,m,n,swap, i,min,j;
 	float sum;
 	scanf("%d",&k);
 	while(scanf("%d %d",&m,&n)!=EOF&&k--)
	 {
	 	float number1[n],number2[n];
	 	for( i=0;i<n;i++)
		 {
		 	scanf("%f %f",&number1[i],&number2[i]); 
		 }
		for(i=0;i<n;i++)//ÉıĞòÅÅĞò 
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(number1[j]<number1[min]) min=j;
			}
			swap=number1[min];number1[min]=number1[i];number1[i]=swap;
			swap=number2[min];number2[min]=number2[i];number2[i]=swap;
		}
		i=0;
		sum=0.0;
		while(m!=0)
		{
			if(m>number1[i]*number2[i])
			{
				sum+=number2[i];
				m-=number1[i]*number2[i];
				i++;
			}else{
				sum+=m/number1[i];
				m=0;
				printf("%.2f\n",sum);
			}
		} 
	 }
 }

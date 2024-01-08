<<<<<<< HEAD
#include<stdio.h>
 struct data{
	int firstdata;
	int lastdata;
};
int main()
{
	int number,j,min,swap,k;
	int endtime,startime;
	int i=0;
	while(scanf("%d",&number)!=EOF)
	{
		if(number==0) break;
		data numbers[number];
		for(i=0;i<number;i++)
		{
			scanf("%d %d",&numbers[i].firstdata,&numbers[i].lastdata);
		}
	//	for(i=1;i<=number;i++)
	//	{
	//		printf("firstdata: %d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
	//	}
		for(i=0;i<number;i++)//ÅÅĞò 
		{
			min=i;
			for(j=i+1;j<number;j++)
			{
				if(numbers[j].lastdata<numbers[min].lastdata) min=j;
			}
			swap=numbers[min].lastdata;numbers[min].lastdata=numbers[i].lastdata;numbers[i].lastdata=swap;
			swap=numbers[min].firstdata;numbers[min].firstdata=numbers[i].firstdata;numbers[i].firstdata=swap;
		}
	//	for(i=0;i<number;i++)
	//	{
	//		printf("data: %d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
	//	}
		
		k=1;
		endtime = numbers[0].lastdata;
		for(i=1;i<number;i++)
		{
			if(numbers[i].firstdata>=endtime)
			{
				k++;
				endtime = numbers[i].lastdata;
	//			printf("%d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
			}
		}
		printf("%d\n",k);
	}
}
 
=======
#include<stdio.h>
 struct data{
	int firstdata;
	int lastdata;
};
int main()
{
	int number,j,min,swap,k;
	int endtime,startime;
	int i=0;
	while(scanf("%d",&number)!=EOF)
	{
		if(number==0) break;
		data numbers[number];
		for(i=0;i<number;i++)
		{
			scanf("%d %d",&numbers[i].firstdata,&numbers[i].lastdata);
		}
	//	for(i=1;i<=number;i++)
	//	{
	//		printf("firstdata: %d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
	//	}
		for(i=0;i<number;i++)//ÅÅĞò 
		{
			min=i;
			for(j=i+1;j<number;j++)
			{
				if(numbers[j].lastdata<numbers[min].lastdata) min=j;
			}
			swap=numbers[min].lastdata;numbers[min].lastdata=numbers[i].lastdata;numbers[i].lastdata=swap;
			swap=numbers[min].firstdata;numbers[min].firstdata=numbers[i].firstdata;numbers[i].firstdata=swap;
		}
	//	for(i=0;i<number;i++)
	//	{
	//		printf("data: %d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
	//	}
		
		k=1;
		endtime = numbers[0].lastdata;
		for(i=1;i<number;i++)
		{
			if(numbers[i].firstdata>=endtime)
			{
				k++;
				endtime = numbers[i].lastdata;
	//			printf("%d %d\n",numbers[i].firstdata,numbers[i].lastdata);	
			}
		}
		printf("%d\n",k);
	}
}
 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

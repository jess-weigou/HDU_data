<<<<<<< HEAD
#include<stdio.h>
int main(){
	int time;
	int i;
	int floor1,floors,floor2;
	while(scanf("%d",&floors)!=EOF)
	{
		if (floors!=0)
		{
			scanf("%d",&floor1);
			time=floor1*6+5;
			for(i=1;i<floors;i++)
			{
				scanf("%d",&floor2);
				if(floor2>floor1) time+=(floor2-floor1)*6+5;
				else if(floor2==floor1 ) time +=5;
				else time+=(floor1-floor2)*4+5;
				floor1=floor2; 
			}
			printf("%d\n",time);
			time = 0;
		}else{
			break;
		}
	}
	return 0;
}
=======
#include<stdio.h>
int main(){
	int time;
	int i;
	int floor1,floors,floor2;
	while(scanf("%d",&floors)!=EOF)
	{
		if (floors!=0)
		{
			scanf("%d",&floor1);
			time=floor1*6+5;
			for(i=1;i<floors;i++)
			{
				scanf("%d",&floor2);
				if(floor2>floor1) time+=(floor2-floor1)*6+5;
				else if(floor2==floor1 ) time +=5;
				else time+=(floor1-floor2)*4+5;
				floor1=floor2; 
			}
			printf("%d\n",time);
			time = 0;
		}else{
			break;
		}
	}
	return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

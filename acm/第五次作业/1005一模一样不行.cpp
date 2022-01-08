#include<stdio.h>
#include<math.h>
int shuzu[6000];
int min(int a,int b)
{
	if(a>b) return b;
	else return a;
}
void prepare()
{
	shuzu[1]=1;
	int a,b,c,d;
	int pos1=1,pos2=1,pos3=1,pos4=1;
	for(int i=2;i<=5842;i++)
	{
		shuzu[i]=min(min(a=shuzu[pos1]*2,b=shuzu[pos2]*3),min(c=shuzu[pos3]*5,d=shuzu[pos4]*7));
		if(shuzu[i]==a) pos1++;
		 if(shuzu[i]==b) pos2++;
		 if(shuzu[i]==c) pos3++;
		if(shuzu[i]==d) pos4++;
	}
} 
int main() {
	prepare();
	int n;
	while (scanf("%d", &n) != EOF&&n) {
		 printf("The %d",n);
		if (n % 100 != 11 && n % 10 == 1){
			printf("st");
		}else if (n % 100 != 12 && n % 10 == 2){
			printf("nd");
		}else if (n % 100 != 13 && n % 10 == 3){
			printf("rd");
		}else{
			printf("th");
		}
		printf(" humble number is %d.\n",shuzu[n]);
	}
	return 0;
}

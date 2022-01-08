<<<<<<< HEAD
#include<stdio.h>
int fun(int a,int b)
{
    if(a>b)
    {
        if(a%b==0)
            return b;
        else
            return fun(b,a%b);
    }
    else if(a==b)
        return b;
    else
    {
        if(b%a==0)
            return a;
        else
            return fun(a,b%a);
    }
}
int main(){
	int n;
	int a,b,c,d,e,f,k;
	scanf("%d",&n);
	while(n--){
		 scanf("%d %d %d %d",&a,&b,&c,&d);
		 e=a*c;
		 f=b*d;
		 k=fun(e,f);
		 e=e/k;
		 f=f/k;
		 printf("%d %d\n",e,f);
	}
} 
=======
#include<stdio.h>
int fun(int a,int b)
{
    if(a>b)
    {
        if(a%b==0)
            return b;
        else
            return fun(b,a%b);
    }
    else if(a==b)
        return b;
    else
    {
        if(b%a==0)
            return a;
        else
            return fun(a,b%a);
    }
}
int main(){
	int n;
	int a,b,c,d,e,f,k;
	scanf("%d",&n);
	while(n--){
		 scanf("%d %d %d %d",&a,&b,&c,&d);
		 e=a*c;
		 f=b*d;
		 k=fun(e,f);
		 e=e/k;
		 f=f/k;
		 printf("%d %d\n",e,f);
	}
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

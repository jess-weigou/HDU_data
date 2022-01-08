#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int main(){
	char a[10000] ;
	char b[10000];
	int n;
	int i=0;
	int c=0;
	char d; 
	scanf("%d\n",&n);
	while(n--){
		i=0;
		while(scanf("%c",&a[i])&&a[i]!='\n'){
			i++;
		}
		a[i]='\0';
		c=strlen(a);
		for(int i=c-1;i>=0;i--){
			b[c-i-1]=a[i];
		}
		printf("%s\n",b);
		memset(a,0,sizeof(a)); 
		memset(b,0,sizeof(b));
	}
	return 0;
} 

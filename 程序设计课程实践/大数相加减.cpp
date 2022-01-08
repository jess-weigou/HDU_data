#include<stdio.h>
#include<string.h>
#include<math.h>
void reverse(char s[],int lens){
	char tmp;
	for(int i=0;i<lens/2;i++){
		tmp=s[i];
		s[i]=s[lens-i-1];
		s[lens-i-1]=tmp;
	}
	s[lens]='\0';
}
void reverse1(char s[],int lens){
	char tmp;
	int j=lens-1;
	while(s[j]=='0'){
		lens--;
		j--;
	} 
	for(int i=0;i<lens/2;i++){
		tmp=s[i];
		s[i]=s[lens-i-1];
		s[lens-i-1]=tmp;
	}
	s[lens]='\0';
}
int main(){
	char s1[10002];
	char s2[10002];
	char s3[10002];
	char s4[10002];
	int flag=0;
	scanf("%s%s",s1,s2);
	int len_s1=strlen(s1);
	int len_s2=strlen(s2);
	reverse(s1,len_s1);
	reverse(s2,len_s2);
	//printf("%s\n%s\n",s1,s2);
	if(len_s1>len_s2){
		for(int i=len_s2;i<len_s1;i++){
			s2[i]='0';
		}
		s2[len_s1]='\0';
	} else if (len_s1<len_s2){
		for(int i=len_s1;i<len_s2;i++){
			s1[i]='0';
		}
		s2[len_s2]='\0';
	}
	//printf("%s\n%s\n",s1,s2);
	//ПајУ
	for (int i=0;i<len_s1;i++){
		if (flag+s1[i]+s2[i]-'0'-'0'>9){
			s3[i]=(flag+s1[i]+s2[i]-'0'-'0')%10+'0';
			flag=1;
		}else{
			s3[i]=flag+s1[i]+s2[i]-'0';
			flag=0;
		}
	}
	if (flag==1){
			s3[len_s1]='1';
			s3[len_s1+1]='\0';
		}else{
			s3[len_s1]='\0';
	}
	reverse(s3,strlen(s3));
	flag=0; 
	//sub 
	for(int i=0;i<len_s1;i++){
		if ((s1[i]-s2[i]-flag)<0){
			
			s4[i]=s1[i]-s2[i]-flag+10+'0';
			flag=1;
		}else{
			s4[i]=s1[i]-s2[i]-flag+'0';
			flag=0;
		}
	}
	reverse(s4,strlen(s4));
	reverse(s1,len_s1);
	reverse(s2,len_s2);
	printf("%s+%s=%s\n",s1,s2,s3);
	if (strcmp(s1,s2)==0){
		printf("%s-%s=0",s1,s2);	
	}else{
		printf("%s-%s=%s",s1,s2,s4);	
	}
	
}


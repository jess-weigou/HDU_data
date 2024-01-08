<<<<<<< HEAD
#include<stdio.h>
#include<map>
#include<string.h> 
#include <algorithm>
using namespace std;
map<char,int>mm;
int vis[1001],ta,num[1001],len;
char s[1001],ch[1001],m_ch[1001];
void fun(){
    char c = 'A';
    for(int i=1;i<=26;i++){
        mm[c++] = i;    
    }
}  
int is(int v,int w,int x,int y,int z,int tar){
    if(v - w*w + x*x*x - y*y*y*y + z*z*z*z*z == tar) return 1;  
    else return 0; 
}
void dfs(int cur)
{
	if(cur==5)
	{
		if( is(num[0],num[1],num[2],num[3],num[4],ta) && strcmp(ch,m_ch)>0 ){//用strcmp判断两字符串的大小 
            strcpy(m_ch,ch);
        }
    }else{
    	for(int i=0;i<len;i++)
		{
			if(vis[mm[s[i]]]==0)
			{
				vis[mm[s[i]]]=1;
				num[cur]=mm[s[i]];//储存数字 
				ch[cur]=s[i];
				dfs(cur+1);
				vis[mm[s[i]]]=0;
			} 
		}
    	
	}
}
int main()
{
	fun();	
	while(scanf("%d %s",&ta,s)!=EOF&& (ta||strcmp(s,"END")))
	{
		memset(vis,0,sizeof(vis));
        memset(ch,'\0',sizeof(ch));
        memset(m_ch,'\0',sizeof(m_ch));
        len = strlen(s);
        sort(s,s+len);
        dfs(0);
        if(strlen(m_ch)==0) printf("no solution\n");
        else printf("%s\n",m_ch);
	}
}
=======
#include<stdio.h>
#include<map>
#include<string.h> 
#include <algorithm>
using namespace std;
map<char,int>mm;
int vis[1001],ta,num[1001],len;
char s[1001],ch[1001],m_ch[1001];
void fun(){
    char c = 'A';
    for(int i=1;i<=26;i++){
        mm[c++] = i;    
    }
}  
int is(int v,int w,int x,int y,int z,int tar){
    if(v - w*w + x*x*x - y*y*y*y + z*z*z*z*z == tar) return 1;  
    else return 0; 
}
void dfs(int cur)
{
	if(cur==5)
	{
		if( is(num[0],num[1],num[2],num[3],num[4],ta) && strcmp(ch,m_ch)>0 ){//用strcmp判断两字符串的大小 
            strcpy(m_ch,ch);
        }
    }else{
    	for(int i=0;i<len;i++)
		{
			if(vis[mm[s[i]]]==0)
			{
				vis[mm[s[i]]]=1;
				num[cur]=mm[s[i]];//储存数字 
				ch[cur]=s[i];
				dfs(cur+1);
				vis[mm[s[i]]]=0;
			} 
		}
    	
	}
}
int main()
{
	fun();	
	while(scanf("%d %s",&ta,s)!=EOF&& (ta||strcmp(s,"END")))
	{
		memset(vis,0,sizeof(vis));
        memset(ch,'\0',sizeof(ch));
        memset(m_ch,'\0',sizeof(m_ch));
        len = strlen(s);
        sort(s,s+len);
        dfs(0);
        if(strlen(m_ch)==0) printf("no solution\n");
        else printf("%s\n",m_ch);
	}
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

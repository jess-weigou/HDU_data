<<<<<<< HEAD
#include<iostream>
#include<cstdio>
#include <time.h>
using namespace std;
long long int f[30][30][30];
int w(int a, int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        return w(20,20,20);
    }
    //如果不等于0说明已经赋值过了 
    else if(f[a][b][c]!=0) return f[a][b][c]; 
    else if(a<b&&b<c){
        f[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }
    else{
        f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return f[a][b][c];
}

int main(){
    int a, b, c, s;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        s = w(a, b, c);
        printf("%d\n", s);
    }
    return 0;
}
=======
#include<iostream>
#include<cstdio>
#include <time.h>
using namespace std;
long long int f[30][30][30];
int w(int a, int b,int c){
    if(a<=0||b<=0||c<=0){
        return 1;
    }
    else if(a>20||b>20||c>20){
        return w(20,20,20);
    }
    //如果不等于0说明已经赋值过了 
    else if(f[a][b][c]!=0) return f[a][b][c]; 
    else if(a<b&&b<c){
        f[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
    }
    else{
        f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
    return f[a][b][c];
}

int main(){
    int a, b, c, s;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        s = w(a, b, c);
        printf("%d\n", s);
    }
    return 0;
}
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

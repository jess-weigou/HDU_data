<<<<<<< HEAD
#include<stdio.h>
#include<string.h>
int dparr[101][101];
int arr[101][101];
int position[4][2]={1,0,0,1,-1,0,0,-1};
int m,n;
void dp(int x,int y){
	dparr[x][y]=1;
	if (x==m&&y==n){
		return ;
	}
	for (int i=0;i<4;i++){
		int xx = x+position[i][0];
		int yy = y+position[i][1];
		if (xx<m&&yy<n&&dparr[xx][yy]==0&&arr[xx][yy]==arr[x][y]){
			dp(xx,yy);
		}
	}
}
int main(){
	int count=0;
	memset(dparr,0,sizeof(dparr));
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		} 
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if (dparr[i][j]==0){
				dp(i,j);
				count++;
			}
		} 
	}
	printf("%d",count);
} 
=======
#include<stdio.h>
#include<string.h>
int dparr[101][101];
int arr[101][101];
int position[4][2]={1,0,0,1,-1,0,0,-1};
int m,n;
void dp(int x,int y){
	dparr[x][y]=1;
	if (x==m&&y==n){
		return ;
	}
	for (int i=0;i<4;i++){
		int xx = x+position[i][0];
		int yy = y+position[i][1];
		if (xx<m&&yy<n&&dparr[xx][yy]==0&&arr[xx][yy]==arr[x][y]){
			dp(xx,yy);
		}
	}
}
int main(){
	int count=0;
	memset(dparr,0,sizeof(dparr));
	scanf("%d%d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		} 
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if (dparr[i][j]==0){
				dp(i,j);
				count++;
			}
		} 
	}
	printf("%d",count);
} 
>>>>>>> 416e8b5f236488c939d9cfa43725b8a87fc02006

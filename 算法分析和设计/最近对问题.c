#include<stdio.h>
#include<math.h>
struct node
{
    int x;
    int y;
};

struct  node devide(int num[],int l,int r)
{
    if(l==r){
        struct node max = {-99999,999999};
        return max;
    }else if(r-l==1){
        struct node min = {num[l],num[r]};
        return min;
    }else{
        int m = (l+r)/2;
        struct node leftNode = devide(num,l,m);
        struct node rightNode = devide(num,m+1,r);
        struct node mNode = devide(num,m,m+1);
        struct node minNode = leftNode.y-leftNode.x < rightNode.y-rightNode.x ? leftNode:rightNode;
        minNode = minNode.y -minNode.x < mNode.y-mNode.x ? minNode:mNode;
        return minNode;
    }
}

int main(){
    int num[7] = {1,4,5,7,8,13,16};
    struct node node1 = devide(num,0,6);
    printf("%d %d\n",node1.x,node1.y);
}
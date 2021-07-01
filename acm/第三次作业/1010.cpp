
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
 
using namespace std;
 
const int maxn = 20;
 
struct node
{
    int degree;    //顶点的度
    int index;    //顶点的序号
};
node v[maxn];
int edge[maxn][maxn];
 
bool cmp( node a, node b )
{
    return a.degree > b.degree;
}
 
int main()
{
    int n;
    int t;
    scanf( "%d", &t );
    while( t-- )
    {
        int flag = 1;
        scanf( "%d", &n );
        for(int i=0; i<n; i++)
        {
            scanf("%d", &v[i].degree);
            v[i].index = i;
        }
        memset( edge, 0, sizeof(edge) );
        for(int i=0; i<n; i++)
        {
            sort( v, v+n, cmp );  //排序
            if( v[0].degree==0 )  break;
            for(int j=1; j<n; j++)
            {
                v[j].degree--;
                if( v[j].degree<0 ) //出现不合理的情况
                {
                    flag = 0;
                    break;
                }
                edge[ v[0].index ][ v[j].index ] = edge[ v[j].index ][ v[0].index ] = 1;
                v[0].degree--; 
                if(v[0].degree==0)  break;
            }
            if( flag == 0 )
                break;
        }
        if( flag==0 )
            printf("NO\n");
        else
        {
            printf("YES\n");
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(!j)
                        printf("%d", edge[i][j]);
                    else
                        printf(" %d", edge[i][j]);
                }
                printf("\n");
            }
        }
        if(t)
            printf("\n");
    }
 
    return 0;
}


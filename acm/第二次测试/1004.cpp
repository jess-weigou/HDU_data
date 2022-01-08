#include<bits/stdc++.h>
using namespace std;
int n,W,w[10005],v[10005],dp[1005];
int main(){
    while(cin>>W>>n){
    	if(W==-1&&n==-1) break;
        memset(dp,-1,sizeof(dp));dp[0]=0;
        //for(int i=0;i<=W;i++) printf("%d  ",dp[i]);
        for(int i=1;i<=n;++i)
            cin>>v[i]>>w[i];
        for(int i=1;i<=n;++i)
            for(int j=W;j>=w[i];--j)
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
        if(dp[W]<0)cout<<-1<<endl;
        else cout<<dp[W]<<endl;
    }
    return 0;
}

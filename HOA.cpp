#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("HOA.INP","r",stdin);
    freopen("HOA.OUT","w",stdout);
    ll k,n;cin>>k>>n;
    ll a[k+1][n+1];
    for(ll i=1;i<=k;i++){
        for(ll j=1;j<=n;j++)cin>>a[i][j];
    }ll dp[k+1][n+1];memset(dp,0,sizeof(dp));ll b[k+1][n+1];memset(b,0,sizeof(b));
    for(ll i=1;i<=k;i++){
        for(ll j=i;j<=n;j++){
                //dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+a[i][j]);
            if(dp[i][j-1]<dp[i-1][j-1]+a[i][j]){
                dp[i][j]=dp[i-1][j-1]+a[i][j];
                b[i][j]=j;
            }else{
                dp[i][j]=dp[i][j-1];b[i][j]=b[i][j-1];
            }
        }
    }cout<<dp[k][n]<<endl;
    vector<ll>res(k+1);
    ll i=k,j=n;
    while(i>0){
        res[i]=b[i][j];
        j=b[i][j]-1;i--;
    }
    for(ll i=1;i<=k;i++)cout<<res[i]<<" ";
    return 0;
}


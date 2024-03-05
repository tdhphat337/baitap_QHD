#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("GOLD.INP","r",stdin);
    freopen("GOLD.OUT","w",stdout);
    ll n;cin>>n;
    ll a[n+1][n+1];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)cin>>a[i][j];
    }ll f[n+1][n+1];memset(f,0,sizeof(f));
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++)f[i][j]=max(f[i][j-1],f[i-1][j])+a[i][j];
    }cout<<f[n][n];
    return 0;
}


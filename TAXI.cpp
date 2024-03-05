#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    //freopen("TAXI.INP","r",stdin);
    //freopen("TAXI.OUT","w",stdout);
    ll k;cin>>k;
    ll a[k+1];for(ll i=1;i<=k;i++)cin>>a[i];
    ll n;cin>>n;
    vector<ll>dp(n+1,INT_MAX);dp[0]=0;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=min(i,k);j++){
            if(dp[i]>dp[i-j]+a[j]){
                dp[i]=dp[i-j]+a[j];
            }
        }
    }cout<<dp[n];
    return 0;
}


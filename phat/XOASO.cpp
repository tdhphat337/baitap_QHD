#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd(ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main() {
    freopen("XOASO.INP","r",stdin);
    freopen("XOASO.OUT","w",stdout);
    ll n;cin>>n;
    ll a[n+1];for(ll i=1;i<=n;i++)cin>>a[i];
    vector<ll>dp(n+1);
    for(ll i=1;i<=n;i++){
        dp[i]=1;
        for(ll j=1;j<i;j++){
            if(a[i]>a[j]&&gcd(a[i],a[j])>1)dp[i]=max(dp[i],dp[j]+1);
        }
    }cout<<n-*max_element(dp.begin(),dp.end());
    return 0;
}


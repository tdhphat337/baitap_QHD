#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("ZERO.INP","r",stdin);
    freopen("ZERO.OUT","w",stdout);
    ll n,sum=0,res=0;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    unordered_map<ll,ll>mp;
    for(ll i=0;i<n;i++){
        sum+=a[i];
        if(sum==0)res=i+1;
        if(mp.find(sum)==mp.end())mp[sum]=i;
        if(mp.find(sum)!=mp.end())res=max(res,i-mp[sum]);
    }cout<<res;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("JUMPING.INP","r",stdin);
    freopen("JUMPING.OUT","w",stdout);
    ll k;cin>>k;
    ll a[k+1];for(ll i=1;i<=k;i++)cin>>a[i];
    vector<ll>f(k+1,0);f[1]=min(a[1],3*a[2]);
    for(ll i=2;i<=k;i++)f[i]=min(f[i-1]+abs(a[i]-a[i-1]),f[i-2]+3*abs(a[i]-a[i-2]));
    cout<<f[k];
    //for(ll i=1;i<=k;i++)cout<<f[i]<<" ";
    return 0;
}

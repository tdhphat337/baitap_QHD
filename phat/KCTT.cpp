#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll bs1(ll a[],ll l,ll r,ll x){
    ll res=INT_MAX;
    while(l<=r){
        ll mid=(l+r)/2;
        if(a[mid]<=x){
            res=a[mid];
            l=mid+1;
        }else r=mid-1;
    }return res;
}ll bs2(ll a[],ll l,ll r,ll x){
    ll res=0;
    while(l<=r){
        ll mid=(l+r)/2;
        if(a[mid]>=x){
            res=a[mid];
            r=mid-1;
        }else l=mid+1;
    }return res;
}
int main() {
    freopen("KCTT.INP","r",stdin);
    freopen("KCTT.OUT","w",stdout);
    ll n,m;cin>>n>>m;
    ll a[n],b[m];for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<m;i++)cin>>b[i];
    sort(b,b+m);vector<ll>c;
    for(ll i=0;i<n;i++){
        ll t1=bs1(b,0,m-1,a[i]),t2=bs2(b,0,m-1,a[i]);
        //cout<<t1<<" "<<t2<<endl;
        c.push_back(min(abs(a[i]-t1),abs(a[i]-t2)));
    }cout<<*max_element(c.begin(),c.end());//for(ll x:c)cout<<x<<" ";
    return 0;
}


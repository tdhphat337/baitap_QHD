#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("POSTER.INP","r",stdin);
    freopen("POSTER.OUT","w",stdout);
    ll n,res=1;cin>>n;
    vector<ll>d(n),a(n);for(ll i=0;i<n;i++)cin>>d[i]>>a[i];
    ll nho_nhat=INT_MAX,pos;
    for(ll i=0;i<n;i++){
        if(a[i]<nho_nhat){nho_nhat=a[i];pos=i;}
    }ll j=pos,k=pos;
    while(j>0||k<n-1){
           // cout<<1<<" ";
        if(j>0){if(a[j]!=a[j-1]&&a[j-1]>nho_nhat)res++;}
        if(k<n-1){if(a[k]!=a[k+1]&&a[k+1]>nho_nhat)res++;}
        j--;k++;
    }cout<<res;
    return 0;
}


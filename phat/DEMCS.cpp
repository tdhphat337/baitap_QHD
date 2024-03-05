#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("DEMCS.INP","r",stdin);
    freopen("DEMCS.OUT","w",stdout);
    ll n;cin>>n;
    vector<ll>a(n);
    for (ll i=0;i<n;i++)cin>>a[i];
    unordered_map<ll, ll> freq;
    for (ll i=0;i<n;i++)freq[a[i]]++;
    ll count=0;
    for (ll i=0;i<n;i++) {
        freq[a[i]]--;
        for (ll j=0;j<=63;j++) {
            ll target=(1LL<<j)-a[i];
            if(freq.count(target))count+=freq[target];
        }
    }
    cout<<count;
    return 0;
}


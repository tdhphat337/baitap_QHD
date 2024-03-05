#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("QUADRUPLE.INP","r",stdin);
    freopen("QUADRUPLE.OUT","w",stdout);
    ll n,cnt=0;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    unordered_map<ll,vector<pair<ll,ll>>>mp;
    for(ll i=0;i<n;i++){
        for(ll j=i+1;j<n;j++)mp[a[i]-a[j]].push_back(make_pair(i,j));
    }for(auto entry:mp){
        vector<pair<ll,ll>>pairs=entry.second;
        for(ll i=0;i<pairs.size();i++){
            for(ll j=i+1;j<pairs.size();j++){
                if(pairs[j].first>pairs[i].second)cnt++;
            }
        }
    }cout<<cnt;
    return 0;
}


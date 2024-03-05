#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    ll n,sum=0,res=0;cin>>n;
    string s;cin>>s;
    unordered_map<ll,ll>mp;
    for(ll i=0;i<s.length();i++){
        sum+=s[i]-'0';
        if(sum==n)res++;
        if(mp.find(sum-n)!=mp.end())res+=mp[sum-n];
        mp[sum]++;
    }cout<<res;
    return 0;
}


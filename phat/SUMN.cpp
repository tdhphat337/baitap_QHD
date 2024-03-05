#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("SUMN.INP","r",stdin);
    freopen("SUMN.OUT","w",stdout);
    string n;cin>>n;ll sum=0;
    for(ll i=0;i<n.length();i++)sum+=(n[i]-'0');
    cout<<sum;
    return 0;
}


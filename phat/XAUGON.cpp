#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("XAUGON.INP","r",stdin);
    freopen("XAUGON.OUT","w",stdout);
    string s;getline(cin,s);
    string t;t+=s[0];
    for(ll i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1])t+=s[i+1];
    }cout<<t;
    return 0;
}


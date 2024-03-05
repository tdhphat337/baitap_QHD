#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll gcd (ll a,ll b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int main(){
    freopen("TRNHAT.INP","r",stdin);
    freopen("TRNHAT.OUT","w",stdout);
    ll a,b;cin>>a>>b;
    ll res=a*b/gcd(a,b);
    cout<<res<<endl;
    cout<<res/a<<" "<<res/b;
    return 0;
}
// sau 6 ngay n truc lai
// sau 4 ngayt h truc lai
//ngay 1 lun ruc chnh
//=>ngay 1 la 1

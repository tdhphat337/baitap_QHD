#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <ll> f(100006,0);
ll n, res=1, p[100006];
const ll mod=1e9+7;
void start(){
    p[1]=1;
    for (int i=2; i<=1e5+6; i++) if (p[i]==0)
        for (int j=i; j<=1e5+6; j+=i) p[j]=i;
}
void pt(int n){
    while (n!=1) f[p[n]]++,n/=p[n];
}
ll power(int a, int b){
	if (b==0) return 1; else
	if (b%2==0) 
	return (power(a,b/2)%mod*power(a,b/2)%mod)%mod; else
	return (((power(a,b/2)%mod*power(a,b/2)%mod)%mod)*(a%mod))%mod;
}
void result(){
    for (int i=2; i<=n; i++) pt(i);
    for (int i=2; i<=n; i++){
        f[i]=3*(f[i]/3);
        res=res*power(i,f[i])%mod;
        f[i]=0;
    }
    cout<<res<<endl;
    res=1;
}
int main(){
	freopen("cuberoot.inp","r",stdin);
	freopen("cuberoot.out","w",stdout);
    start();
    int t; cin >> t;
    while (t--){
        cin >> n;
        result();
    }
}


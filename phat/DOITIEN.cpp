#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
	freopen("DOITIEN.INP","r",stdin);
	freopen("DOITIEN.OUT","w",stdout);
    ll n,m,sum=0;cin>>n>>m;
    unordered_map<ll,ll>danhdau;
    ll a[n+1];for(ll i=1;i<=n;i++){cin>>a[i];danhdau[a[i]]=i;}
    vector<ll>dp(m+1,INT_MAX);
    vector<ll>trace(m+1,0),b(n+1,0);
    dp[0]=0;
    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=min(i,n);j++){
            if(a[j] <= i && dp[i-a[j]] != INT_MAX && dp[i]>dp[i-a[j]]+1){
                dp[i]=dp[i-a[j]]+1;
                trace[i]=a[j];
            }
        }
    }
    if(dp[m]==INT_MAX)cout<<-1;
    else{
        cout<<dp[m]<<endl;
        vector<ll>stops;
        while(m>0) {
            stops.push_back(trace[m]);
            m-=trace[m];
        }map<ll,ll>dem;
        for(ll i=0;i<stops.size();i++)dem[stops[i]]++;
        for(auto it:dem){
            b[danhdau[it.first]]=it.second;
        }for(ll i=1;i<=n;i++)cout<<b[i]<<" ";
    }
    return 0;
}


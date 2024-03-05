#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll W,res=0,sum=0,n,m,w[1000006],v[1000006],used[1000006];
void Try(){
    for(ll i=1;i<=n;i++){
        if(used[i]==0){
            used[i]=1;W+=w[i];sum+=v[i];
            if(W<=m){
                res=max(res,sum);
                Try();
            }
            used[i]=0;W-=w[i];sum-=v[i];
        }
    }
}
int main(){
	freopen("DTTUI.INP","r",stdin);
    freopen("DTTUI.OUT","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>w[i]>>v[i];
    Try();cout<<res;
    return 0;
}

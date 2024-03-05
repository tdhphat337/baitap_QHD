#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    //freopen("CANDY.INP","r",stdin);
    //freopen("CANDY.OUT","w",stdout);
    ll q;cin>>q;
    while(q--){
        ll n,x,dem2=0,dem=0,sum=0;cin>>n>>x;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];sum+=a[i];
        }for(ll i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){dem2=1;break;}
        }
        if(n==1){
            if(x>a[0]){
                ll m=(x+a[0])/2;
                if(m*2==x+a[0])cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else cout<<"NO"<<endl;
        }
        else if(dem2==0){
            if(a[0]==0){
                if(x%(n+1)==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            else if(x==a[0])cout<<"YES"<<endl;
            else if(x>a[0]){
                ll p=x-a[0];
                if(p%(n+1)==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }else cout<<"NO"<<endl;
        }else{
            sort(a,a+n);
            ll p=a[n-1];
            for(ll i=p;;i++){
                if(x-(i*n-sum)==i){
                    cout<<"YES"<<endl;break;
                }else if(x-(i*n-sum)<0){cout<<"NO"<<endl;break;}
            }
        }
    }
    return 0;
}


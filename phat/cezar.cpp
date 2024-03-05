#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,k,r=0,t=0,res=0,dem=0;
bool mark[1000006];
ll dist[1000006];
vector<pair<ll, ll>> edge(1000006),kq; // luu l?i c?nh dã du?c ch?n
vector<pair<ll, ll>> adj[1000006];
const ll INF = 1e18;
struct CEZAR {ll a,b,d;};
bool cmp(CEZAR e,CEZAR f){
    return (e.d>f.d);
}
void Dijkstra(ll s){
    fill(dist+1,dist+n+1,INF);
    dist[s]=0;
    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    pq.push({0,s});
    while(!pq.empty()){
        ll u=pq.top().second;
        pq.pop();
        if(mark[u])continue;
        mark[u]=true;
        for(auto e:adj[u]){
            ll v=e.first;
            ll w=e.second;
            if(dist[v]>dist[u] + w){
                dist[v]=dist[u] + w;
                edge[v]={u, v}; // luu l?i c?nh dã du?c ch?n
                pq.push({dist[v],v});
            }
        }
    }
}
vector<pair<ll, ll>> find_path(ll s, ll t) {
    vector<pair<ll, ll>> path;
    for (ll v = t; v != s; v = edge[v].first) {
        path.push_back(edge[v]);
    }
    reverse(path.begin(), path.end());
    return path;
}
int main() {
    freopen("CEZAR.INP","r",stdin);
    freopen("CEZAR.OUT","w",stdout);
    cin>>n>>k;
    vector<CEZAR>c(n-1);
    for(ll i=0;i<n-1;i++)cin>>c[i].a>>c[i].b;
    map<ll,ll>mp;
    for(ll i=0;i<n-1;i++){mp[c[i].a]++;mp[c[i].b]++;}
    for(auto it:mp){
        if(it.second>t){
            t=it.second;
            r=it.first;
        }
    }
    for(ll i=0;i<n-1;i++){
        if(c[i].a>c[i].b)swap(c[i].a,c[i].b);
    }
    for(ll i=0;i<n-1;i++){
        adj[c[i].a].push_back({c[i].b,1});
        adj[c[i].b].push_back({c[i].a,1});
    }Dijkstra(r);
    for (ll i = 1; i <= n; ++i) {
        if (i != r) {
            vector<pair<ll, ll>> path = find_path(r, i);
            //cout << "Path from " << r << " to " << i << ": ";
            for (auto e : path) {
                if(e.first<e.second)kq.push_back(make_pair(e.first,e.second));
                if(e.first>e.second)kq.push_back(make_pair(e.second,e.first));
                //cout << "(" << e.first << ", " << e.second << ") ";
            }dem=0;
            //cout << "\n";
        }
    }
    //for(pair<ll,ll>cell:kq)cout<<cell.first<<","<<cell.second<<" ";
    map<pair<ll,ll>,ll>dem2;
    for(pair<ll,ll>cell:kq)dem2[cell]++;
    //for(pair<ll,ll>cell:kq)cout<<cell.first<<"-"<<cell.second<<":"<<dem2[cell]<<endl;
    vector<pair<ll,ll>>s;
    for(ll i=0;i<n-1;i++)s.push_back(make_pair(c[i].a,c[i].b));
    for(ll i=0;i<n-1;i++)c[i].d=dem2[s[i]];
    sort(c.begin(),c.end(),cmp);
    for(ll i=0;i<n-1;i++)c[i].d=1;
    for(ll i=0;i<k;i++)c[i].d=0;
   // for(ll i=0;i<n-1;i++)cout<<c[i].a<<" "<<c[i].b<<" "<<c[i].d<<endl;
    memset(adj,0,sizeof(adj));memset(mark,0,sizeof(mark));memset(dist,0,sizeof(dist));
    for(ll i=0;i<n-1;i++){
        adj[c[i].a].push_back({c[i].b,c[i].d});
        adj[c[i].b].push_back({c[i].a,c[i].d});
    }
    Dijkstra(r);for(ll i=1;i<=n;i++)res+=dist[i];
    cout<<res;
    return 0;
}


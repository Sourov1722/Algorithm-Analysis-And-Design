#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
const long long int INF=1e9;
const int N=1e3;
vector<pair<ll,ll>>g[N];
vector<ll>dist(N,INF);
ll arr[N];
void path(ll x)
{
    if(arr[x]==-1)
    {
        cout<<1<<" ";
        return;
    }
    ll next=arr[x];
    path(next);
    cout<<x<<" ";
}
void dijkstra(ll source)
{
    
    vector<ll>vis(N,0);
    // vector<ll>dist(N,INF);
    set<pair<ll,ll>>st;
    st.insert({0,source});
    dist[source]=0;
    arr[source]=-1;
    while(st.size()>0)
    {
        auto node =*st.begin();
        ll v=node.ss;
        ll v_dist=node.ff;
        st.erase(st.begin());
        if(vis[v])
        continue;
        vis[v]=1;
        for(auto child:g[v])
        {
            ll child_v=child.ff;
            ll wt=child.ss;
            if(dist[v]+wt < dist[child_v])
            {
                dist[child_v]=dist[v]+wt;
                arr[child_v]=v;
                st.insert({dist[child_v],child_v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    ll node,edge;
    cin>>node>>edge;
    for(ll i=0;i<edge;i++)
    {
        ll x,y,wt;
        cin>>x>>y>>wt;
        g[x].pb({y,wt});
    }
    dijkstra(1);
    for(ll i=1;i<=node;i++)
    {
        cout<<"Node"<<" ";
    cout<<i<<" "<<"wt"<<" "<<dist[i]<<" path "<<" ";
    path(i);
    cout<<endl;
    cout<<endl;
    }
}
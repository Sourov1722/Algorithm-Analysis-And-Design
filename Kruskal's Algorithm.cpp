#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
ll parent[1000];
void makeSet(ll u)
{
    parent[u]=u;
}
ll Find(ll u)
{
    if(u==parent[u])
    return u;
    return parent[u]=Find(parent[u]);
}
void Union(ll u,ll v)
{
    ll p=Find(u);
    ll q=Find(v);
    // cout<<p<<" "<<q<<endl;
    if(p!=q)
    parent[q]=p;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
    ll node,edge;
    cin>>node>>edge;
    for(ll i=1;i<=node;i++)
    makeSet(i);
    vector<pair<ll,pair<ll,ll>>>p;
    for(ll i=0;i<edge;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        p.pb({wt,{u,v}});
    }
    sort(p.begin(),p.end());
    // for(auto &it:p)
    // {
    //     cout<<it.ff<<" "<<it.ss.ff<<" "<<it.ss.ss<<endl;
    // }
    ll t_cost=0;
    for(auto &edge:p)
    {
        ll wt=edge.ff;
        ll u=edge.ss.ff;
        ll v=edge.ss.ss;
        if(Find(u)==Find(v))
        continue;
        Union(u,v);
        cout<<u<<" "<<v<<endl; // minimum cost egde
        t_cost+=wt;
    }
    cout<<t_cost<<endl;
    return 0;
}
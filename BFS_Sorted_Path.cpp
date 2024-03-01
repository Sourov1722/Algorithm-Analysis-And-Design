#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
vector<ll>v[100];
ll vis[100];
ll dis[100];
ll pre[1000];
void path(ll x)
{
    if(pre[x]==-1)
    {
        cout<<1<<" ";
        return;
    }
    ll p=pre[x];
    path(p);
    cout<<x<<" ";
}
void bfs(ll x)
{
    queue<ll>q;
    q.push(x);
    vis[x]=1;
    dis[x]=0;
    pre[x]=-1;
    while(!q.empty())
    {
        ll cur=q.front();
        q.pop();
        // cout<<cur<<" ";
        for(ll it:v[cur])
        {
            ll next=it;
            if(vis[next]==0)
            {
                vis[next]=1;
                pre[next]=cur;
                dis[next]=dis[cur]+1;
                q.push(next);
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
        ll x,y;
        cin>>x>>y;
        v[x].pb(y);
    }
    bfs(1);
   for(ll i=1;i<=node;i++)
    {
        cout<<"Node"<<" ";
    cout<<i<<" "<<"dist"<<" "<<dis[i]<<" path "<<" ";
    path(i);
    cout<<endl;
    cout<<endl;
    }
   
    // ll x=source;
    // vector<ll>v;
    // while(x!=-1)
    // {
    //     v.pb(pre[x]);
    //     x=pre[x];
    // }
    // sort(v.begin(),v.end());
    // v.erase(v.begin()+0);
    // for(ll it:v)
    // cout<<it<<" ";
    
    return 0;
}
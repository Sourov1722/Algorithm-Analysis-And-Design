#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
    ll node,edge;
    cin>>node>>edge;
    vector<pair<ll,pair<ll,ll>>>p;
    for(ll i=0;i<edge;i++)
    {
        ll u,v,wt;
        cin>>u>>v>>wt;
        p.pb({wt,{u,v}});
    }
    sort(p.begin(),p.end());
    for(auto &it:p)
    {
        cout<<it.ff<<" "<<it.ss.ff<<" "<<it.ss.ss<<endl;
    }
    return 0;
}
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
    
    vector<pair<ll,ll>>p;
    ll t;
    cin>>t;
   for(ll i=0;i<t;i++)
    {
        ll x,y;
        cin>>x>>y;
        p.pb({y,x});
    }
    sort(p.begin(),p.end());
    // for(auto it:p)
    // cout<<it.ff<<" "<<it.ss<<endl;
    ll ans=0;
    ll c1;
    c1=p[0].ff;
   for(ll i=1;i<t;i++)
   {
    ll l1=p[i].ss;
    if(l1>c1)
    {
        ans++;
        cout<<p[i].ff<<" "<<p[i].ss<<endl;
        c1=p[i].ff;
    }
   }
   cout<<"Total Activity :"<<ans<<endl;
    return 0;
}

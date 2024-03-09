#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
ll merge(ll arr[],ll l,ll mid,ll r)
{
    ll l_sum=INT_MIN;
    ll r_sum=INT_MIN;
    ll sum=0;
    for(ll i=mid;i>=l;i--)
    {
      sum+=arr[i];
      l_sum=max(l_sum,sum);
    }
    sum=0;
    for(ll i=mid+1;i<=r;i++)
    {
        sum+=arr[i];
        r_sum=max(r_sum,sum);
    }
    return l_sum+r_sum;
}
ll mx_subarray_sum(ll arr[],ll l,ll r)
{
   ll mid=(l+r)/2;
   if(l==r)
   return arr[l];
   else
   {
     ll left_sum=mx_subarray_sum(arr,l,mid);
     ll right_sum=mx_subarray_sum(arr,mid+1,r);
     ll cross_sum=merge(arr,l,mid,r);
     return max(left_sum,max(right_sum,cross_sum));
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    cout<<mx_subarray_sum(arr,0,n-1)<<endl;
    
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
ll partition(ll arr[],ll low,ll high)
{
   ll pivot=arr[high];
   ll i=(low-1);
   for(ll j=low;j<high;j++)
   {
    if(arr[j]<=pivot)
    {
        i++;
        swap(arr[i],arr[j]);
    }
   }
   swap(arr[i+1],arr[high]);
   return (i+1);
}
void Quick_Sort(ll arr[],ll low,ll high)
{
    if(high>low)
    {
        ll pos=partition(arr,low,high);
        Quick_Sort(arr,low,pos-1);
        Quick_Sort(arr,pos+1,high);
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
    Quick_Sort(arr,0,n-1);
    for(ll i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}
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
    
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    cin>>arr[i];
    // 1st element are sorted
    for(ll i=2;i<n;i++)
    {
        ll value=arr[i];
        ll index=i;
        // check index position to previous position
        while(index>0 && arr[index-1]>value)
        {
            arr[index]=arr[index-1];
            index--;
        }
        arr[index]=value;
    }
    for(ll i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}
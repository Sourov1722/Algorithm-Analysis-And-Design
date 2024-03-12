#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
void merge(ll arr[],ll low,ll mid,ll high)
{
    ll n1=mid-low+1;
    ll n2=high-mid;
    ll a[n1];
    ll b[n2];
    for(ll i=0;i<n1;i++)
    a[i]=arr[low+i];

    for(ll j=0;j<n2;j++)
    b[j]=arr[mid+1+j];

    ll i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        j++;
        k++;
    }
}
void Merge_Sort(ll arr[],ll low,ll high)
{
    if(low>=high)
    return;
        ll mid=(low+high)/2;
        Merge_Sort(arr,low,mid);
        Merge_Sort(arr,mid+1,high);
        merge(arr,low,mid,high);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     
    Merge_Sort(arr,0,n-1);
   for(ll i=0;i<n;i++)
    cout<<arr[i]<<" ";
    
    return 0;
}
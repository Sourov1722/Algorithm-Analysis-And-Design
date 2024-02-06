#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string k;
        cin>>k;
        int len=k.size();
        char b;
        cin>>b;
        int p=0;
        int q=0;
        for(int i=len-1;i>=0;i-=2)
        {
            if(k[i]==b){
            cout<<"YES"<<endl;
            p++;
            break;}
        }
        if(p==0)
        {
        for(int i=0;i<len;i+=2)
        {
            if(k[i]==b)
            {
            cout<<"YES"<<endl;
            q++;
            break;}
        }
        }
        if(p==0 && q==0)
        cout<<"NO"<<endl;
        
    }
}
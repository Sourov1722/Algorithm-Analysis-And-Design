#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
ll n, m;
ll lps[100000];
void LpsArray(string k)
{
    ll index = 0;
    lps[0] = 0;
    for (ll i = 1; i < m;)
    {
        if (k[i] == k[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
            if (index != 0)
                index = lps[index - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
bool kmp(string text, string pattern)
{
    ll i = 0, j = 0;
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
        if (j == m)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string text, pattern;
    cin >> text >> pattern;
    n = text.size();
    m = pattern.size();
    LpsArray(pattern);
    if (kmp(text, pattern))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
    return 0;
}
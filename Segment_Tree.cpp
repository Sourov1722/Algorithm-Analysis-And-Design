#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
const long long int M = 1e9 + 7;
const int N = 1e5 + 9;
ll arr[N];
ll sum[4 * N];
void build(ll node, ll b, ll e)
{
    if (b == e)
    {
        sum[node] = arr[b];
        return;
    }
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    build(l, b, mid);
    build(r, mid + 1, e);
    sum[node] = sum[l] + sum[r];
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if (b > j or e < i)
        return 0;
    if (b >= i and e <= j)
        return sum[node];
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
void update(ll node, ll b, ll e, ll i, ll x)
{
    if (b > i or e < i)
        return;
    if (b == e and b == i)
    {
        sum[node] = x;
        return;
    }
    ll l = 2 * node;
    ll r = 2 * node + 1;
    ll mid = (b + e) / 2;
    update(l, b, mid, i, x);
    update(r, mid + 1, e, i, x);
    sum[node] = sum[l] + sum[r];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n = 5;
    for (ll i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    build(1, 1, n);
    cout << sum[1] << endl;
    cout << query(1, 1, n, 2, 4) << endl;
    update(1, 1, n, 3, 10);
    cout << query(1, 1, n, 2, 4) << endl;

    return 0;
}
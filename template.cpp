// In the name of God
// Saurav Bhattarai

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 

using namespace std;

#define ll long long
#define mod 1000000007;
#define sort(c) sort(c.begin(), c.end())
#define input(c) cin >> c
#define vi vector< int >
#define vl vector< ll >
#define pii pair< int, int >
#define pll pair< ll, ll>
#define vii vector< pii >
#define vll vector< pll>
#define rep(i, a, b) for (i = a; i < b; ++i)
#define newline cout<<'\n'
#define pb(x) push_back(x)

inline ll fast_pow(ll base, ll exp)
{
    ll ret = 1;
    while (exp != 0)
    {
        if (exp % 2) ret *= base;
        base *= base;
        exp >>= 1;
    }
    return ret;
}

inline ll fast_mod_pow(ll base, ll exp)
{
    ll ret = 1;
    while (exp != 0)
    {
        if (exp % 2) ret *= base;
        base *= base;
        exp >>= 1;
        base %= mod;
        ret %= mod;
    }
    return ret;
}

int main()
{
    // Good luck!!
    return 0;
}


// In the name of God
// Saurav Bhattarai

#include <bits/stdc++.h>
#include <vector>
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
#define SORT(c) sort(c.begin(), c.end())
#define vi vector< int >
#define vl vector< ll >
#define pii pair< int, int >
#define pll pair< ll, ll>
#define vii vector< pii >
#define vll vector< pll>
#define rep(i, a, b) for (i = a; i < b; ++i)
#define newline cout<<'\n'
#define pb(x) push_back(x)

inline int m_dist(int x0, int y0, int x1, int y1)
{
    return abs(x0 - x1) + abs(y0 - y1);
}

inline int min_dist(int x, int y) { return (x > y ? y : x); }


inline int max_dist(int x, int y) { return (x < y ? y : x); }


int grid[250][250];
int d_grid[250][250];
int R, C, i, j, k, l, preresult;

inline void new_office(int a, int b)
{
    grid[a][b] = 1;
    preresult = 0;
    rep(k, 0, R)
    {
        rep(l, 0, C)
        {
            if (grid[k][l] == 0) 
            preresult = max_dist(preresult, min_dist(d_grid[k][l], m_dist(a, b, k, l)));
        }
    }
    grid[a][b] = 0;
    return;
}


int main()
{
    int T, result, k, l, cnum=0;
    bool haszero;
    char arr[251];
    cin>>T;
    while(T--)
    {
        result=-1;
        ++cnum;
        haszero=false;
        cin>>R>>C;
        rep(i,0,R)
        {
            cin>>arr;
            rep(j, 0, C)
            {
                grid[i][j] = arr[j] - '0';
            }
        }
        
        rep(i, 0, R)
        {
            rep(j, 0, C)
            {
                if (grid[i][j] == 0) haszero = true;
            }
        }
        
        if (!haszero)
        {
            cout<<"Case #" << cnum << ": " << 0 << '\n';
            continue;
        }
        
        rep(i, 0, R)
        {
            rep(j, 0, C)
            {
                if (grid[i][j]==0)
                {
                    preresult = 501;
                    rep(k, 0, R)
                    {
                        rep (l, 0, C)
                        {
                            if (grid[k][l] == 1)
                                preresult = min_dist(preresult, m_dist(i, j, k, l));
                        }
                    }
                    d_grid[i][j] = preresult;
                    result = max_dist(result, preresult);
                }       
            }
        }
        
        rep(i, 0, R)
        {
            rep(j, 0, C)
            {
                if (grid[i][j] == 0)
                {
                    new_office(i, j);
                    result = min_dist(preresult, result);
                }
            }
        }
        cout<<"Case #" << cnum << ": " << result << '\n';
    }
    return 0;
}

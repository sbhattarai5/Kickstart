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



int grid[250][250];
int dist[250][250];
int color[250][250];
int R, C, i, j, d, lowerbound, upperbound;
int dist1, dist2, dist3, dist4;
pair< pii, int > top;

inline void init_color()
{
    rep(i, 0, R)
    {
        rep(j, 0, C)
        {
            color[i][j] = 0;
        }
    }
    return;
}

inline void calc_dist()
{
    
    queue< pair< pii, int >> q;
    init_color();
    //add all the 1s to Queue
    rep(i, 0, R)
    {
        rep(j, 0, C)
        {
            if (grid[i][j]) 
            {
                q.push(make_pair(make_pair(i, j), 0));
                color[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }
    
    //do dfs
    while (!q.empty())
    {
        top = q.front();
        q.pop();
        d = top.second;
        i = top.first.first;
        j = top.first.second;
        upperbound = d;
        if (i + 1 < R && !color[i + 1][j])
        {
            q.push(make_pair(make_pair(i + 1, j), d + 1));
            color[i + 1][j] = 1;
            dist[i + 1][j] = d + 1;
        }
        if (i - 1 >= 0 && !color[i - 1][j])
        {
            q.push(make_pair(make_pair(i - 1, j), d + 1));
            color[i - 1][j] = 1;
            dist[i - 1][j] = d + 1;
        }
        if (j + 1 < C && !color[i][j + 1])
        {
            q.push(make_pair(make_pair(i, j + 1), d + 1));
            color[i][j + 1] = 1;
            dist[i][j + 1] = d + 1;
        }
        if (j - 1 >= 0 && !color[i][j - 1])
        {
            q.push(make_pair(make_pair(i, j - 1), d + 1));
            color[i][j - 1] = 1;
            dist[i][j - 1] = d + 1;
        }
        
    }    
    return;
}


inline int max(int a, int b, int c, int d)
{
    if (a > b) b = a;
    if (b > c) c = b;
    if (c > d) d = c;
    return d;
}

inline int max_2(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{
    int T, K, cnum=0, add, diff, mindiff, maxdiff, minadd, maxadd, intermidadd, intermiddiff;
    bool found;
    char arr[251];
    cin>>T;
    while(T--)
    {
        ++cnum;
        cin>>R>>C;
        rep(i,0,R)
        {
            cin>>arr;
            rep(j, 0, C)
            {
                grid[i][j] = arr[j] - '0';
            }
        }
        
        calc_dist();
        lowerbound = 0;
        while (lowerbound < upperbound)
        {
            mindiff = 501;
            maxdiff = -501;
            minadd = 501;
            maxadd = -501;
            K = (lowerbound + upperbound)/ 2;
            rep(i, 0, R)
            {
                rep(j, 0, C)
                {
                    if (dist[i][j] > K)
                    {
                        add = i + j;
                        diff = i - j;
                        if (add > maxadd) maxadd = add;
                        if (add < minadd) minadd = add;
                        if (diff > maxdiff) maxdiff = diff;
                        if (diff < mindiff) mindiff = diff;
                    }
                }
            }
            found = false;
            rep(i, 0, R)
            {
                rep(j, 0, C)
                {
                    if (grid[i][j] == 0) // add a delivery office
                    {
                        intermidadd = i + j;
                        intermiddiff = i - j;
                        dist1 = max_2(abs(maxadd - intermidadd), abs(maxdiff - intermiddiff));
                        dist2 = max_2(abs(maxadd - intermidadd), abs(mindiff - intermiddiff));
                        dist3 = max_2(abs(minadd - intermidadd), abs(maxdiff - intermiddiff));
                        dist4 = max_2(abs(minadd - intermidadd), abs(mindiff - intermiddiff));
                        if (max(dist1, dist2, dist3, dist4) <= K)
                        {
                            found = true;
                            break;
                        }
                    }
                }
                if (found) break;
            }
            
            if (found) upperbound = K;
            else lowerbound = K + 1;
        }
        cout<<"Case #" << cnum << ": " << upperbound << '\n';
    }
    return 0;
}

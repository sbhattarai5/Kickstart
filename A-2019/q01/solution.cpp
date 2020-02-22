// In the name of God
// Saurav Bhattarai
 
//Description
//Sort the array, choose a ending point and calculate hours by subtracting with the max
//calculating hours for subsequent array is O(1), just do some simple math

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
#define SORT(c) sort(c.begin(), c.end())
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

int S[100000];
int main()
{
    int T, i, case_num = 0;
    int N, P;
    ll last_sum;
    ll min_hours;
    input(T);
    while (T--)
    {
        ++case_num;
    
        //input
        input(N);
        input(P);
        rep(i, 0, N)
        {
            input(S[i]);
        }
        
        //process
        sort(S, S + N);
        last_sum = 0;
        rep(i, 0, P)
        {
            last_sum += S[P - 1] - S[i];   
        }
        min_hours = last_sum;
    
        rep(i, P, N)
        {
            last_sum -= (S[i - 1] - S[i - P]);
            last_sum += (S[i] - S[i - 1]) * (P - 1);
            if (last_sum < min_hours) min_hours = last_sum;
        }
        
        //output
        cout << "Case #" << case_num << ": " << min_hours << '\n'; 
    }
    return 0;
}

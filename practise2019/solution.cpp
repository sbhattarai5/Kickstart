// In the name of God
// Saurav Bhattarai

#include <iostream>
#define ll long long
#define mod 1000000007
ll A[1000000];

inline ll fast_pow(ll base, ll exp)
{
    ll ret = 1;
    while (exp != 0)
    {
        if (exp % 2) ret *= base;
        base *= base;
        exp >>= 1;
        ret %= mod;
        base %= mod;
    }
    return ret;
}

inline ll inverse(ll a)
{
    return fast_pow(a, mod - 2);
}

inline ll GP_sum(ll a, ll r, ll n)
{
    ll ret = a;
    ret *= inverse(r - 1);
    ret %= mod;
    ret *= (fast_pow(r, n)) - 1;
    return ret % mod;
}   

int main()
{
    ll T, N, K, x1, y1, C, D, E1, E2, F;
    std::cin >> T;
    ll t = T;
    while (t--)
    {
        ll total_power = 0;
        std::cin >> N >> K >> x1 >> y1 >> C >> D
                 >> E1 >> E2 >> F;  
        for (ll i = 0; i < N; ++i)
        {
            A[i] = (x1 + y1) % F;
            ll new_x1 = (C * x1 + D * y1 + E1) % F;
            y1 = (D * x1 + C * y1 + E2) % F;
            x1 = new_x1;
        }
        ll GP = K;    
        for (ll i = 0; i < N; ++i)
        {
            if (i != 0)
            {
                GP += (GP_sum(i + 1, i + 1, K));
                GP %= mod;
            }
            A[i] *= GP; 
            A[i] %= mod;
            A[i] *= (N - i);
            A[i] %= mod;
            total_power += A[i];
            total_power %= mod;
        }
        std::cout << "Case #" << T - t << ": " << total_power << '\n';
    }   
    return 0;
}

#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long ll;

int prime[MAX];

ll power(ll x, ll y, int p)
{
    ll res = 1;

    x = x % p;

    if (x == 0)
        return 0;

    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void sieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * 2; j < MAX; j += i)
            {
                if (prime[j] == 0)
                {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}

ll lcmModuloM(const ll *ar, ll n, ll m)
{
    unordered_map<long, long> max_map;
    for (int i = 0; i < n; i++)
    {
        long num = ar[i];
        unordered_map<long, long> temp;
        while (num > 1)
        {
            long factor = prime[num];
            temp[factor]++;
            num /= factor;
        }
        for (auto it : temp)
        {
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }
    ll ans = 1;
    for (auto it : max_map)
    {

        ans = (ans * power(it.F, it.S, m)) % m;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    ll t;
    cin >> t;
    while (t--)
    {
        long long n, m, k, i, l;
        cin >> n >> m >> k;
        ll a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        l = lcmModuloM(a, n, m);
        l = power(l, k, m);
        cout << l % m << endl;
    }
    return 0;
}
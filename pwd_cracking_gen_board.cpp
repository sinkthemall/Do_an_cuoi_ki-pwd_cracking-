#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pir;
ll mod;
#define fi first
#define se second

pir extend_euclid(ll a,ll b, ll c)
{
    ll x0 = 1, y0 = 0, r0 = a;
    ll x1 = 0, y1 = 1, r1 = b;
    while(r1 != c)
    {
        ll q = r0 / r1;
        ll r = r0%r1;
        ll x = x0 - x1*q, y = y0 - y1*q;
        x0 = x1;
        y0 = y1;
        x1 = x;
        y1 = y;
        r0 = r1;
        r1 = r;
    }
    return pir(x1, y1);
}
ll gcd(ll a,ll b)
{
    return (b == 0) ? a : gcd(b, a%b);
}
ll inverse_modulo(ll a, ll b)/// find the a^-1 of modulo b
{
    if (gcd(a, b) != 1)
    {
        cout<<"Cannot find the inverse modulo!!\n";
        exit(1);
    }
    pir ans = extend_euclid(a, b, 1);
    while(ans.fi  <0)
    {
        ans.fi += b;
    }
    return ans.fi%b;
}
///cannot multiply 2 40 bit numbers so i have to make a quick multiplier
ll nhan(ll a,ll b)
{
    if (b==0) return 0;
    else
    {
        ll p = nhan(a, b/2);
        p = p*2;
        p = p%mod;
        if (b%2) return (p + a)%mod;
        else return p;
    }
}
void gen_board()
{
    int N = 40;/// assume that the board will be 40 row, you can change it later
    ll a[100];
    _for(i,0,N)
    {
        a[i] = ll(1)<<i;
    }
    mod = ll(1)<<N;
    ll k = (((ll(rand())*ll(rand()))%mod)*ll(rand()))%mod;/// this is where everything start
    if (k%2==0) k += 1;
    ll _k = inverse_modulo(k, mod);
    _for(i,0,N)
    {
        a[i] = nhan(a[i], _k);
    }
    cout<<N<<"\n";
    random_shuffle(a, a+N);
    _for(i,0,N)
    {
        for(int j = N-1; j>=0; --j)
        {
            cout<<((a[i]>>j)&1);
        }
        cout<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    srand(int(time(0)));
    /**test
    cout<<inverse_modulo(3, 16)<<"\n";
    cout<<inverse_modulo(11, 15)<<"\n";
    cout<<inverse_modulo(1001, 1021)<<"\n";
    cout<<inverse_modulo(1234567, 1000000007);
    */
    freopen("data.inp","w",stdout);
    gen_board();
    return 0;
}

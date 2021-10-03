// CF_1519B.
#pragma     GCC     optimize("Ofast")
#pragma     GCC     taget("avx,avx2,fma")
#pragma     GCC     optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_cxx;

typedef     long long           ll;
typedef     unsigned long long  ull;
typedef     long double         ld;
typedef     vector <int>        vi;
typedef     vector <ll>         vl;
typedef     pair <int, int>     pii;
typedef     pair <ll, ll>       pll;
typedef     map <int, int>      mii;
typedef     map <ll, ll>        mll;

#define     FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define     ALL(v)          v.begin(), v.end()
#define     PB              push_back
#define     EB              emplace_back
#define     MP              make_pair
#define     ff              first
#define     ss              second
#define     UB              upper_bound
#define     LB              lower_bound
#define     PI              2*acos(0.0)
#define     GCD(a, b)       __gcd(a, b)
#define     LCM(a, b)       a * b / GCD(a, b)
#define     endl            '\n'
#define     nl              cout << endl
#define     spc             cout << ' '
#define     dbg(x)          cerr << #x << " = " << x << ' '
#define     dbgnl(x)        cerr << #x << " = " << x << '\n'

#define     MOD             1000000007
#define     MAX4            10005
#define     MAX5            100005
#define     MAX6            1000005
#define     min3(a,b,c)     min(a, min(b,c))
#define     max3(a,b,c)     max(a, max(b,c))
#define     min4(a,b,c,d)   min(min(a,b), min(c,d))
#define     max4(a,b,c,d)   min(max(a,b), max(c,d))

#define     yes             cout << "yes" << endl
#define     no              cout << "no" << endl
#define     Yes             cout << "Yes" << endl
#define     No              cout << "No" << endl
#define     YES             cout << "YES" << endl
#define     NO              cout << "NO" << endl

#define     LIMIT(a, b)     (a>=1 && a<=n && b>=1 && b<=m)
#define     INPUT           freopen("input.txt", "r", stdin)
#define     OUTPUT          freopen("output.txt", "w", stdout)
#define     PRINT(a)        for(auto i : a) cout << i << " "; nl;
#define     PRINTS(s)       for(auto i=s.begin(); i!=s.end(); i++) cout << *i << " "; nl;
#define     PRINTM(m)       for(auto i=m.begin(); i!=m.end(); i++) cout << i->first << " " << i->second << endl;
#define     TIME(start)     cout << "Time elapsed : " << (double)(clock()-start) / CLOCKS_PER_SEC << endl;

int r, c;
bool dp[102][102];
bool vis[102][102];

bool solve(int x, int y, int k)
{
    if(x==r && y==c && k==0) return true;
    if(x<0 || x>r || y<0 || y>c) return false;
    if(vis[x][y] != false) return dp[x][y];
    vis[x][y] = true;
    bool ans = false;
    ans |= solve(x, y+1, k-x);
    ans |= solve(x+1, y, k-y);
    return dp[x][y] = ans;
}

int main()
{
    FIO;
    int t=1, k;
    cin >> t;
    for(int tc=1; tc<=t; tc++)
    {
        cin >> r >> c >> k;
        memset(dp, false, sizeof dp);
        memset(vis, false, sizeof vis);
        bool ans = solve(1, 1, k);
        ans ? YES : NO;
    }

    return 0;
}

// CF_1195C. Basketball Exercise
#include <bits/stdc++.h>

using namespace std;

#define IOS             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ALL(v)          v.begin(), v.end()
#define PB              push_back
#define MP              make_pair
#define UB              upper_bound
#define LB              lower_bound
#define PI              2*acos(0.0)
#define MOD             1000000007
#define GCD(a, b)       __gcd(a, b)
#define LCM(a, b)       ((a)*(b)) / GCD(a, b)
#define MS(a, b)        memset(a, b, sizeof(a))
#define GETPOS(a, b)    find(ALL(v), b) - a.begin()
#define INPUT           freopen("input.txt", "r", stdin);
#define OUTPUT          freopen("output.txt", "w", stdout);
#define PRINT(a)        for(auto i : a) cout << i << " "; cout << endl;

typedef long long ll;
typedef long double LD;
typedef vector<vector<int>> vi;

bool vis[2][100000];
ll   dp[2][100000];
int    v[2][100000];
int n;

ll solve(int i, int j)
{
    if(i>=2 || j>=n) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    ll ans1 = 0;
    ll ans2 = 0;
    if(i==0)
    {
        ans1 = v[i][j] + solve(1, j+1);
        ans1 = max(ans1, solve(0, j+1));
        ans1 = max(ans1, solve(1, j+1));
    }
    else
    {
        ans2 = v[i][j] + solve(0, j+1);
        ans2 = max(ans2, solve(0, j+1));
        ans2 = max(ans2, solve(1, j+1));
    }
    return dp[i][j] = max(ans1, ans2);
}

int main()
{
    IOS;
    cin >> n;
    memset(dp, -1, sizeof dp);

    for(int i=0; i<2; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];

    ll ans1 = solve(0, 0);
    ll ans2 = solve(1, 0);
    cout << max(ans1, ans2) << endl;
/*
    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
*/
    return 0;
}

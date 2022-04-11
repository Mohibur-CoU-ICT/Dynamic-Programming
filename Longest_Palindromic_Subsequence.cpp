// Longest Palindromic Subsequence Dynamic Programming
#include<iostream>
using namespace std;

string reverse(string s)
{
    string ans;
    for(int i=s.length()-1; i>=0; i--){
        ans += s[i];
    }
    return ans;
}

int dp[1001][1001];

int lps(string& s1, string& s2, int n1, int n2)
{
    if(n1==0 || n2==0){
        return 0;
    }
    if(dp[n1][n2] != -1){
        return dp[n1][n2];
    }
    if(s1[n1-1] == s2[n2-1]){
        return dp[n1][n2] = 1 + lps(s1, s2, n1-1, n2-1);
    }
    else{
        return dp[n1][n2] = max(lps(s1, s2, n1-1, n2), lps(s1, s2, n1, n2-1));
    }
}

int main()
{
    string s1;
    cin >> s1;
    int n = s1.length();
    string s2 = reverse(s1);
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = -1;
        }
    }
    int lps_length = lps(s1, s2, n, n);
    cout << "Longest Palindromic Subsequence length = " << lps_length << "\n";

    return 0;
}

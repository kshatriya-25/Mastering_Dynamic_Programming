/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
int dp[1001001];
int n;
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {

    dp[i] = 0;
    for (int j = 1; j <= 6; j++) {
      if (i - j >= 0) {
        dp[i] += dp[i - j];
      }
    }
    dp[i] %= mod;
  }
  cout << dp[n] << endl;
}
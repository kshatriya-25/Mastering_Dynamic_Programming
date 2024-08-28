/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(x + 1, 0);
  dp[0] = 1; // Base case: There's 1 way to make sum 0 (using no coins).

  // Process each coin
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j <= x; j++) {
      dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
  }

  cout << dp[x] << endl;
  return 0;
}

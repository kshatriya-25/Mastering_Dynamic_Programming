/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int dp[100100];
int x[10100];

int rec(int level) {
  //base case
  if (level == n - 1)
    return 0;

  //cache check
  if (dp[level] != -1)
    return dp[level];
  //transition
  int ans = 1e18;
  for (int i = 1; i <= k; i++) {
    if (level + i < n) {
      ans = min(ans, abs(x[level] - x[level + i]) + rec(level + i));
    }
  }
  return dp[level] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  //memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int level = n - 1; level >= 0; level--) {
    //base case
    if (level == n - 1)
      dp[level] = 0;

    else {

      //transition
      int ans = 1e18;
      for (int i = 1; i <= k; i++) {
        if (level + i < n) {
          ans = min(ans, abs(x[level] - x[level + i]) + dp[level + i]);
        }
      }
      dp[level] = ans;
    }
  }
  cout << dp[0];
}
/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[100100];
int n;
int h[100100];

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[i];

  for (int level = n - 1; level >= 0; level--) {
    // base case
    if (level == n - 1)
      dp[level] = 0; // No more jumps possible from the last level
    else { // transition
      int ans = 1e18;
      if (level + 1 < n)
        ans = min(ans, abs(h[level] - h[level + 1]) + dp[level + 1]);
      if (level + 2 < n)
        ans = min(ans, abs(h[level] - h[level + 2]) + dp[level + 2]);
      // save and return
      dp[level] = ans;
    }
  }
  cout << dp[0];
}

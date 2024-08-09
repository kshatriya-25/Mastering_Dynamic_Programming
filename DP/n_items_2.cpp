/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
int x[101];
int t;
int n, q;
int dp[105][10100];

bool rec(int level, int left) {
  // Pruning
  if (left < 0)
    return 0;
  // Base case
  if (level == n) {
    return left == 0;
  }
  // Cache check
  if (dp[level][left] != -1)
    return dp[level][left];

  // Compute and transition
  bool ans = rec(level + 1, left) || rec(level + 1, left - x[level]);

  // Save and return
  return dp[level][left] = ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  memset(dp, -1, sizeof(dp));
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> x[i];
  while (q-- > 0) {
    cin >> t;
    cout << rec(0, t) << endl;
  }
  return 0;
}

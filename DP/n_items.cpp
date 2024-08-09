#include <bits/stdc++.h>

using namespace std;

#define int long long
int x[101];
int t;
int n;
int dp[105][10100];

bool rec(int level, int taken) {
  // Pruning
  if (taken > t)
    return 0;
  // Base case
  if (level == n) {
    return taken == t;
  }
  // Cache check
  if (dp[level][taken] != -1)
    return dp[level][taken];

  // Compute and transition
  bool ans = rec(level + 1, taken) || rec(level + 1, taken + x[level]);

  // Save and return
  return dp[level][taken] = ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  memset(dp, -1, sizeof(dp));
  cin >> n >> t;
  for (int i = 0; i < n; i++)
    cin >> x[i];

  cout << rec(0, 0) << endl;
  return 0;
}

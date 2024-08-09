/* OM VIVGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, x, k, t[10001], s[10001];
int dp[101][101][101];

int rec(int level, int timeTaken, int itemtaken) {
  //pruning

  //base
  if (level == n)
    return 0;
  //cache check

  if (dp[level][timeTaken][itemtaken] != -1)
    return dp[level][timeTaken][itemtaken];

  //compute and transition
  int ans = rec(level + 1, timeTaken, itemtaken);
  if (timeTaken + t[level] <= x && itemtaken + 1 <= k)
    ans = max(ans, s[level] + rec(level + 1, timeTaken + t[level], itemtaken + 1));
  //save and return
  dp[level][timeTaken][itemtaken] = ans;
  return ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n >> x >> k;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> s[i];
  }
  cout << rec(0, 0, 0);
}
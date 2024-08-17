/* OM VIGHNHARTAYE NAMO NAMAH :*/

/*DESCRIPTION:  u have n types of coin denomination, can u make a sum m??*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int x[] = {1, 2, 5, 10};
int m, n;
int dp[1000][1000];
bool rec(int level, int sum_left) {
  //pruning
  if (sum_left < 0)
    return 0;
  //base case
  if (level == n)
    return 0;
  if (sum_left == 0)
    return 1;
  //cache check
  if (dp[level][sum_left] != -1)
    return dp[level][sum_left];
  //compute and transition
  int ans = 0;
  if (rec(level, sum_left - x[level]))
    ans = 1;
  if (rec(level + 1, sum_left))
    ans = 1;
  //save and return
  return dp[level][sum_left] = ans;
}

//iterative version

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  //memset(dp, -1, sizeof(dp));
  cin >> m;
  n = sizeof(x) / sizeof(x[0]);
  //cout << rec(0, m) << endl;
  int dp[n + 1][m + 1];
  for (int l = n; l >= 0; l--) {
    for (int s = 0; s <= m; s++) {
      if (l == n) {
        if (s == 0)
          dp[l][s] = 1;
        else
          dp[l][s] = 0;
      }

      int ans = 0;
      if (s >= x[l] && dp[l][s - x[l]])
        ans = 1;
      if (dp[l + 1][s])
        ans = 1;

      dp[l][s] = ans;
    }
  }
  cout << dp[0][m];
}
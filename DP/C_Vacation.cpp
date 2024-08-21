/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

//int dp[100100][3];
int cost[100100][3];
int n;

// int rec(int level, int k) {

//   //base case
//   if (level == n)
//     return 0;

//   //cache check
//   if (dp[level][k] != -1)
//     return dp[level][k];
//   //transition
//   int ans = 0;
//   for (int i = 0; i < 3; i++) {
//     if (i != k) {
//       ans = max(ans, cost[level][i] + rec(level + 1, i));
//     }
//   }
//   return dp[level][k] = ans;
// }

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> cost[i][j];
    }
  }

  //memset(dp, -1, sizeof(dp));

  int res = 0;
  //   for (int i = 0; i < 3; i++) {
  //     res = max(res, rec(0, i));
  //   }
  int dp[n + 1][3];
  for (int level = n; level >= 0; level++) {
  }
  cout << res << endl;
}
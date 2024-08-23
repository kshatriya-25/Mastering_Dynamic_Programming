/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[110][1000000010];
int n, w;

int x[1000][1000];

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> x[i][j];
    }
  }

  for (int level = n; level >= 0; level--) {
    for (int wleft = 0; wleft <= w; wleft++) {
      if (level == n)
        dp[level][wleft] = 0;
      else {
        //transition
        int ans = 0;
        if (wleft >= x[level][0])
          ans += x[level][1] + dp[level + 1][wleft - x[level][0]]; //take case
        ans = max(ans, dp[level + 1][wleft]);

        //save and return
        dp[level][wleft] = ans;
      }
    }
  }
  cout << dp[0][w];
}
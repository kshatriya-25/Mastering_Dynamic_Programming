/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[1001001];
int n, x;
int coins[1001001];

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  dp[x] = -1; //if given x is not reachable
  for (int i = 0; i <= x; i++) {
    if (i == 0)
      dp[i] = 0;
    else {
      dp[i] = 1e18;
      for (int j = 0; j < n; j++) {
        if (i - coins[j] >= 0) {
          dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
      }
    }
  }
  if (dp[x] == 1e18)
    cout << -1 << endl;
  else
    cout << dp[x] << endl; //if its reachable then the val will be output else -1
}
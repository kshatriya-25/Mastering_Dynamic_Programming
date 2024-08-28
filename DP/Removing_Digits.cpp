/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int dp[1001001];
int n;

void jaiShreeRam() {
  cin >> n;
  dp[0] = 0; //no of steps to reach 0 from zero
  for (int i = 1; i <= n; i++) {
    dp[i] = 1e18;
    int temp = i;
    while (temp > 0) {
      dp[i] = min(dp[i], dp[i - temp % 10] + 1);
      temp /= 10;
    }
  }
  cout << dp[n];
  return;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  //cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}
/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, x;
int dp[1001001];
int a[110];
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = a[i]; j <= x; j++) {
      dp[j] = dp[j - a[i]];
    }
  }
  cout << dp[x] << endl;
}
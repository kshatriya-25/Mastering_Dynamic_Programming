/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> g[100100];
int dp[100100];
int n, m;

int rec(int level) { //longest path stating at level
  if (dp[level] != -1)
    return dp[level];
  int ans = 0;
  for (auto v : g[level])
    ans = max(ans, 1 + rec(v));
  return dp[level] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }
  int ans = 0;

  for (int i = 1; i <= n; i++) {
    ans = max(ans, rec(i));
  }
  cout << ans << endl;
}
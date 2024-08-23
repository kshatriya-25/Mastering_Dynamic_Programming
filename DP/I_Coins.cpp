/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
int n;
int dp[3003][3003];
double p[3003];

double rec(int level, int x) {
  //base
  if (level == n)
    return x > n - x ? 1 : 0;
  if (dp[level][x] != -1)
    return dp[level][x];
  //tansition
  double ans = 0.0;
  ans += rec(level + 1, x + 1) * p[level];
  ans += rec(level + 1, x) * (1 - p[level]);
  return dp[level][x] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  cout << fixed << setprecision(6) << rec(0, 0) << endl;
}
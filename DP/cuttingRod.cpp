/* OM VIGHNHARTAYE NAMO NAMAH :*/

/* description: cut the given rod in given weakpoints such that at each cut the cost is of length of current rod and u r suppsed to minimize the cost*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, x[1000];
int dp[100][100];

int rec(int l, int r) {
  //pruning

  //base case
  if (l + 1 == r)
    return 0;
  //cache check
  if (dp[l][r] != -1)
    return dp[l][r];
  //compute and transition
  int ans = 1e9;
  for (int p = l + 1; p < r; p++) {
    ans = min(ans, rec(l, p) + rec(p, r));
  }
  ans += x[r] - x[l];
  //save and return
  return dp[l][r] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  x[0] = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; i++)
    cin >> x[i];
  cout << rec(0, n);
}
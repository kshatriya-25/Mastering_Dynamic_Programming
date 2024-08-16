/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
int x, dp[1000];

bool rec(int level) {

  // pruning
  if (level <= 0)
    return 0;

  // base condition
  if (level == 1)
    return 1; // winning state for level 1

  // cache check
  if (dp[level] != -1)
    return dp[level];

  // compute and transition
  int ans = 0;
  for (int i = 0; (1 << i) <= level; i++) {
    ans = 1 << i;
    if (!rec(level - ans))
      return dp[level] = 1; // means current state is a winning state
  }

  // save and return
  return dp[level] = 0; // current state is a losing state since all transitions lead to a win
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> x;
  cout << rec(x);
}

/* OM VIGHNHARTAYE NAMO NAMAH :*/

/*Description: find total number of binary strings of length n, such that "0100" is not a 1)subsequence , 2)substring */

#include <bits/stdc++.h>

using namespace std;

#define int long long
int n;

int dp[10010][5];

int rec(int level, int prefix) {
  //pruning
  if (prefix == 4)
    return 0;
  //basecase
  if (level == n)
    return 1;
  //cache check
  if (dp[level][prefix] != -1)
    return dp[level][prefix];
  //compute and transition
  int ans = rec(level + 1, prefix + 1) + rec(level, prefix);

  //save and return
  return dp[level][prefix] = ans;
}

string t = "0100";
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> n;
}
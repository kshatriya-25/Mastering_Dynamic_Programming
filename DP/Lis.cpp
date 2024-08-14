/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int x[1000], n;
int dp[1000];

//code skeleton

int rec(int level) { //gonna return best LIS till this level
  //pruning
  if (level < 0)
    return 0;

  //base case
  //no base needed here since we are checking eery thing psbl

  //cache check
  if (dp[level] != -1)
    return dp[level];

  //condition and transition
  int ans = 1;
  for (int prev_taken = 0; prev_taken < level; prev_taken++) {
    if (x[prev_taken] < x[level])
      ans = max(rec(prev_taken) + 1, ans);
  }

  //save and return

  return dp[level] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++)
    cin >> x[i];
  int best = 1;
  for (int i = 0; i < n; i++) {
    best = max(best, rec(i));
  }
  cout << best;
}
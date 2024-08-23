/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

string s, t;

int dp[3030][3030];

int rec(int i, int j) {
  //pruning

  //base
  if (i == s.size() || j == t.size())
    return 0;
  //cache check
  if (dp[i][j] != -1)
    return dp[i][j];
  //compute and transition
  int ans = 0;
  if (s[i] == t[j])
    ans = rec(i + 1, j + 1) + 1;

  else {
    ans = max(ans, rec(i + 1, j));
    ans = max(ans, rec(i, j + 1));
  }

  //save and return
  return dp[i][j] = ans;
}

void printlcs(int i, int j) {
  if (i == s.size() || j == t.size())
    return;
  if (s[i] == t[j]) {
    cout << s[i];
    printlcs(i + 1, j + 1);
  } else {
    if (rec(i + 1, j) > rec(i, j + 1))
      printlcs(i + 1, j);
    else
      printlcs(i, j + 1);
  }
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s >> t;
  memset(dp, -1, sizeof(dp));
  printlcs(0, 0);
  cout << endl;
}
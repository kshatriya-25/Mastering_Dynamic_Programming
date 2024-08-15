/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

string x, y, z;
int dp[100][100][100];

int rec(int i, int j, int k) {
  // pruning

  //base
  if (i >= x.length() || j >= y.length() || k >= z.length())
    return 0;
  //cache check
  if (dp[i][j][k] != -1)
    return dp[i][j][k];
  //compute and transition
  int ans = 0;
  if (x[i] == y[j] && y[j] == z[k]) {
    ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
  }
  ans = max(ans, rec(i + 1, j, k));
  ans = max(ans, rec(i, j + 1, k));
  ans = max(ans, rec(i, j, k + 1));
  //save and return
  return dp[i][j][k] = ans;
}

void printlcs(int i, int j, int k) {
  //base case
  if (i >= x.length() || j >= y.length() || k >= z.length())
    return;

  //found a match
  if (x[i] == y[j] && y[j] == z[k]) {
    cout << x[i];
    printlcs(i + 1, j + 1, k + 1);
    return;
  }
  if (rec(i + 1, j, k) > rec(i, j + 1, k) && rec(i + 1, j, k) > rec(i, j, k + 1)) {
    printlcs(i + 1, j, k);
  } else if (rec(i, j + 1, k) > rec(i, j, k + 1))
    printlcs(i, j + 1, k);
  else
    printlcs(i, j, k + 1);
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> y >> z;
  memset(dp, -1, sizeof(dp));
  cout << rec(0, 0, 0) << endl;
  printlcs(0, 0, 0);
}
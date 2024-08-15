/* OM VIGHNHARTAYE NAMO NAMAH :*/

/* descrioption: given two strings find the longest common subsequence*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

string x, y;
int dp[1000][1000];

int rec(int i, int j) { //the meaning of thie rec its gonna return lcs of x[i..n-1] && y[j..m-1]
  //pruning

  //base
  if (i >= x.length() || j >= y.length())
    return 0;
  //cache check
  if (dp[i][j] != -1)
    return dp[i][j]; //the lcs from i to j

  //compute and transition
  int ans = 0;
  if (x[i] == y[j]) {
    ans = max(ans, 1 + rec(i + 1, j + 1));
  }
  ans = max(ans, rec(i + 1, j)); //x is waste
  ans = max(ans, rec(i, j + 1)); //y is waste
  //save and return
  return dp[i][j] = ans;
}

void printlcs(int i, int j) {
  if (i >= x.length() || j >= y.length())
    return;
  if (x[i] == y[j]) {
    cout << x[i];
    printlcs(i + 1, j + 1);
  } else if (rec(i + 1, j) > rec(i, j + 1))
    printlcs(i + 1, j);
  else
    printlcs(i, j + 1);
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(dp, -1, sizeof(dp));
  cin >> x >> y;
  cout << rec(0, 0) << endl;
  printlcs(0, 0);
}
/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
int h, w;
int dp[1010][1010];
char grid[1010][1010];

const int mod = 1e9 + 7;

int rec(int row, int col) {
  //base
  if (row == h - 1 && col == w - 1)
    return 1;
  //pruning
  if (row >= h || col >= w || grid[row][col] == '#')
    return 0;
  //cache check
  if (dp[row][col] != -1)
    return dp[row][col];
  //transition
  int right = rec(row, col + 1) % mod;
  int down = rec(row + 1, col) % mod;
  return dp[row][col] = (right + down) % mod;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> h >> w;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> grid[i][j];
    }
  }
  cout << rec(0, 0);
}
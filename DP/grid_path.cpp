/* OM VIGHNHARTAYE NAMO NAMAH :*/

/*drscription:
    here u have find the maximum path sum from 1 , 1 to (n , m) by moving only ➡ and ⬇
*/

/*💡 -> think at ending form pattern, best sum path till (r , c) */

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m, x[1000][1000];
int dp[1000][1000];
bool done[1000][1000];

int rec(int row, int col) {
  //pruning
  if (row >= n || col >= m)
    return -1e9;
  //base
  if (row == n - 1 && col == m - 1)
    return x[row][col];
  //cache check
  if (done[row][col] != 0)
    return dp[row][col];
  //compute and transition
  int ans = x[row][col];
  ans = max(ans + rec(row + 1, col), ans + rec(row, col + 1));
  done[row][col] = 1;
  return dp[row][col] = ans;
}

void printpath(int r, int c) {
  if (r >= n || c >= m)
    return;
  if (r == n - 1 && c == m - 1) {
    cout << x[r][c] << " ";
    return;
  }
  cout << x[r][c] << " ";
  if (r + 1 < n && rec(r + 1, c) > rec(r, c + 1)) {
    printpath(r + 1, c);
  } else if (c + 1 < m)
    printpath(r, c + 1);
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> x[i][j];
      done[i][j] = 0;
    }
  }

  cout << rec(0, 0) << endl;

  printpath(0, 0);
}
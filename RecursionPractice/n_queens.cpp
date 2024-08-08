/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int queens[20]; // queen[i] -> where is myqueen in row i
int n;

bool check(int row, int col) {
  for (int i = 0; i < row; i++) {
    int prow = i;
    int pcol = queens[i];
    if (pcol == col || abs(row - prow) == abs(col - pcol))
      return false;
  }
  return 1;
}

int rec(int level) { // rec is number of ways populate [level to n-1] with valid configuration
  //  level -> row @ which we are placing the queen
  //pruning

  //base step
  if (level == n) { //which means we have palced all queens till now correctly and last step means we figured out a way
    return 1;
  }
  //compute
  int ans = 0;
  for (int col = 0; col < n; col++) {
    if (check(level, col)) { //here level is the row
      //place the queen
      queens[level] = col;
      //explore
      ans += rec(level + 1);
      //revert the changes since u have explored current transition
      queens[level] = -1;
    }
  }
  //return
  return ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(queens, -1, size(queens));
  cin >> n;
  cout << rec(0);
}
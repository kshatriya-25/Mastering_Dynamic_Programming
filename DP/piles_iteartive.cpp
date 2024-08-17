/* OM VIGHNHARTAYE NAMO NAMAH :*/

/* Description: u have 2 piles with no of stones A and B, ant any turn u can pick any number of stones from one pile or equal number of staone from both pile. And a player who cant move looses , decide optimal game play */

#include <bits/stdc++.h>

using namespace std;

#define int long long
int x, y, dp[1000][1000];

bool rec(int a, int b) {
  //pruning

  //base case
  if (a == 0 && b == 0) //loosing state
    return 0;
  if (a == 0 || b == 0)
    return 1; //winning state
  //cache check
  if (dp[a][b] != -1)
    return dp[a][b];
  //compute and transition
  int ans = 0;
  for (int k = 0; k < a; k++) { //can take any number of staone from pile a
    ans |= rec(k, b);
  }

  if (ans) //if any of the state is winning i can force openant for loosing state
    return dp[a][b] = ans;

  for (int k = 0; k < b; k++) // can take any number of stones from pile b
    ans |= rec(a, k);
  if (ans)
    return dp[a][b] = ans;
  for (int k = 0; k < min(a, b); k++)
    ans |= rec(a - k, b - k); //can take equal number of stones from both piles
  //save and return
  return dp[a][b] = ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> y;
  //   memset(dp, -1, sizeof(dp));
  //   cout << rec(x, y);
  for (int a = 0; a <= x; a++) {
    for (int b = 0; b <= y; b++) {
      if (a == 0 && b == 0) {
        dp[a][b] = 0;
      }
      int ans = 0;
      for (int k = 0; k < a; k++) { //can take any number of staone from pile a
        if (dp[k][b] == 0) {
          ans = 1;
          break;
        }
      }

      for (int k = 0; k < b; k++) // can take any number of stones from pile b
        if (dp[a][k] == 0) {
          ans = 1;
          break;
        }

      for (int k = 0; k < min(a, b); k++) //can take equal number of stones from both piles
        if (dp[a - k][b - k] == 0) {
          ans = 1;
          break;
        }
      //save and return
      dp[a][b] = ans;
    }
    cout << dp[x][y];
  }
}
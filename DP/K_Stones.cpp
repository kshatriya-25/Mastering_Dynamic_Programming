/* OM VIGHNHARTAYE NAMO NAMAH */

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // If only one move is possible, determine the winner based on k % a[0]
  if (n == 1) {
    if (k % a[0] == 0) {
      cout << "Second" << endl; // Jiro wins
    } else {
      cout << "First" << endl; // Taro wins
    }
  } else {
    // General DP solution for multiple moves
    vector<int> dp(k + 1, 0);

    for (int i = 1; i <= k; i++) {
      for (int x : a) {
        if (i >= x && dp[i - x] == 0) {
          dp[i] = 1;
          break;
        }
      }
    }

    cout << (dp[k] ? "First" : "Second") << endl;
  }

  return 0;
}

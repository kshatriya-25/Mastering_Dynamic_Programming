/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int rec(int level, int n) {  // return what is asked in the question

  // pruning
  if (level > n) return 0;

  if (level == n) return 1;          // sure shot ans we know
  int ans = 0;                       // initailly we dont have any ways
  for (int i = 1; i <= 3; i++) {     // deciding on choices
    if (level + i <= n) {            // checking the condition
      int ways = rec(level + i, n);  // making the move
      ans += ways;
    }
  }
  return ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  cout << rec(1, n);
}
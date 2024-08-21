/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int x[1000];

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  int ans = -1e9;
  int last;
  for (int i = 0; i < n; i++) {
    if (i == 0)
      last = x[i];
    else {
      last = max(x[i], last + x[i]);
    }
    ans = max(ans, last);
  }
  cout << ans;
}
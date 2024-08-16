/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int &x : arr)
    cin >> x;
  vector<int> lis;
  for (int i = 0; i < n; i++) {
    if (lis.empty() || lis.back() < arr[i])
      lis.push_back(arr[i]);
    else {
      auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
      *it = arr[i];
    }
  }
  cout << lis.size() << endl;
}
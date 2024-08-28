/* OM VIGHNHARTAYE NAMO NAMAH :*/

/* Description: u have a series of cities from1 to n (like a anaumber line) and u have a bus route from city i to city i+1 with cost B[i], and u have option for flights where u kan hop atmost k cites and the cost is a[i] + a[i+k], given these data, find the min cost path from 1 to n*/

#include <bits/stdc++.h>

using namespace std;

#define int long long

int b[1001];
int a[1000];
int dp[10001][10001];
int k;

int rec(int level) {
  //base case
  if (level == 0)
    return 0;

  //cache check

  //transition
  int ans = INFINITY;
  ans = min(ans, rec(level - 1) + b[level]);
  for (int i = 1; i <= k; i++) {
    ans = min(ans, rec(level - i) + a[level - i] + a[level]);
  }
  return ans;
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
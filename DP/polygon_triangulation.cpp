/* OM VIGHNHARTAYE NAMO NAMAH :*/

/*Description: Given a convex polygon, find the min cost triangulation (splitting the polygn into triangle), cost of diagonal is sin(length)*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

int n;
pair<double, double> p[101];

double sq(double x) { return x * x; }

double cost(int x, int y) {
  double dist = sqrt(sq(p[x].first - p[y].first) + sqrt(sq(p[x].second - p[y].second)));
  return sin(dist);
}

signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  double dp[n + 1][n + 1];
  for (int len = 3; len <= n; len++) {
    for (int l = 1; l + len <= n; l++) {
      int r = len + l - 1;
      if (len == 3)
        return 0;
    }
  }
}
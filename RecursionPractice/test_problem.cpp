/*GANAPATI BAPPA MORYA*/

/*You are given two arrays representing a set of questions in a coding competition:

An array time[] of size n, where time[i] represents the time required to solve the i-th question.
An array skill[] of size n, where skill[i] represents the skill level gained by solving the i-th question.
You are also given two additional parameters:

T: The total time you have to solve the questions.
K: The maximum number of questions you can solve.
Your task is to maximize the total skill level you can achieve by solving up to K questions, while not exceeding the total available time T.*/

/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>

using namespace std;

#define int long long
int n, t, k;

int tym[10001];
int skill[1001];
int taken[1000];

bool check(int level) {
  int timeusedtillnow = 0;
  int itemtaken = 0;
  for (int i = 0; i < level; i++) {
    if (taken[i]) {
      timeusedtillnow += tym[i];
      itemtaken++;
    }
  }
  timeusedtillnow += tym[level];
  itemtaken++;
  return timeusedtillnow <= t && itemtaken <= k;
}

int rec(int level) {
  //pruning

  //base
  if (level == n) //zero based indexing
    return 0;
  //exploring choices: we can either take or not take an particular exam
  int ans = rec(level + 1); //not take , so no need of check step
  if (check(level)) {
    taken[level] = 1;
    ans = max(ans, skill[level] + rec(level + 1));
    taken[level] = 0; //backtrack
  }
  return ans;
}
signed main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(taken, 0, size(taken));
  cin >> n >> t >> k;
  for (int i = 0; i < n; i++) {
    cin >> tym[i] >> skill[i];
  }
  cout << rec(0);
}
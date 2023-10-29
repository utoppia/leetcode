/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 10:02:40
 * filename    : 978-longest-turbulent-subarray.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define vall(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define fi first
#define snd second

#define ll long long
#define nMax 40005

#define MOD 998244353
using namespace std;

int dp[nMax][2];

class Solution {
public:
  int maxTurbulenceSize(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i)
      dp[i][0] = dp[i][1] = 1;

    int ans = 1;
    for (int i = 1; i < n; ++i) {
      if (arr[i] == arr[i - 1])
        continue;
      if (arr[i] > arr[i - 1]) {
        dp[i][0] = 1 + dp[i - 1][1];
        ans = max(ans, dp[i][0]);
        dp[i][1] = 1;
      } else {
        dp[i][1] = 1 + dp[i - 1][0];
        ans = max(ans, dp[i][1]);
        dp[i][0] = 1;
      }
    }
    return ans;
  }
};

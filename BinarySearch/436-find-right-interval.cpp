/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 15:33:30
 * filename    : 436-find-right-interval.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

#define vall(v) v.begin(), v.end()
#define pir pair<int, int>

#define pb push_back
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  vector<int> findRightInterval(vector<vector<int>> &intervals) {
    int n = intervals.size();
    vector<int> pos(n);
    iota(vall(pos), 0);

    sort(vall(pos),
         [&](int i, int j) { return intervals[i][0] < intervals[j][0]; });

    auto binary_find = [&](int val) {
      int l = 0, r = n - 1;
      int ans = -1;
      while (l <= r) {
        int m = (l + r) >> 1;
        if (intervals[pos[m]][0] >= val) {
          ans = pos[m];
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      return ans;
    };

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
      ans[i] = binary_find(intervals[i][1]);
    }
    return ans;
  }
};

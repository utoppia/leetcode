/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 01:10:34
 * filename    : 2389-longest-subsequence-with-limited-sum.cpp
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
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    sort(vall(nums));

    vector<int> pref(nums.size() + 1);
    for (int i = 1; i <= nums.size(); ++i) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }

    vector<int> ans(queries.size());

    for (int i = 0; i < queries.size(); ++i) {
      int q = queries[i];
      int l = 0, r = nums.size();

      while (l <= r) {
        int m = (l + r) >> 1;
        if (pref[m] <= q) {
          ans[i] = m;
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    return ans;
  }
};

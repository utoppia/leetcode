/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:26:45
 * filename    : 300-longest-increasing-subsequence.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    int n = nums.sz();
    if (n == 0)
      return 0;

    vector<int> st;
    st.eb(nums[0]);

    for (int i = 1; i < n; ++i) {
      auto it = upper_bound(begin(st), end(st), nums[i]);

      if (it != begin(st) && *(it - 1) == nums[i])
        continue;

      if (it == end(st))
        st.eb(nums[i]);
      else if (*it > nums[i])
        *it = nums[i];
    }

    return (int)st.sz();
  }
};

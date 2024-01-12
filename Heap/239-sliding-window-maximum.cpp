/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 16:51:54
 * filename    : 239-sliding-window-maximum.cpp
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
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<vector<int>> h;
    for (int i = 0; i < k; ++i) {
      h.pb({nums[i], i});
    }

    make_heap(begin(h), end(h));

    vector<int> ans;
    ans.eb(h.front()[0]);

    int n = nums.sz();
    for (int i = k; i < n; ++i) {
      h.pb({nums[i], i});
      push_heap(begin(h), end(h));
      while (i - h.front()[1] >= k) {
        pop_heap(begin(h), end(h));
        h.pop_back();
      }
      ans.eb(h.front()[0]);
    }
    return ans;
  }
};

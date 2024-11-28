/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-18 21:33:05
 * filename    : 376-wiggle-subsequence.cpp
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
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() <= 1)
      return nums.size();
    int cur = 0;
    int pre = 0;
    int ans = 1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      cur = nums[i + 1] - nums[i];
      if (pre <= 0 && cur > 0 || pre >= 0 && cur < 0) {
        ans++;
        pre = cur;
      }
    }
    return ans;
  }
};

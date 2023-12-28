/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-29 01:01:43
 * filename    : 2574-left-and-right-sum-differences.cpp
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
  vector<int> leftRightDifference(vector<int> &nums) {
    int total = accumulate(vall(nums), 0);
    int n = nums.size();
    vector<int> ans(n);

    int pre = 0;
    for (int i = 0; i < n; ++i) {
      pre += nums[i];
      ans[i] = abs(pre - nums[i] - (total - pre));
    }
    return ans;
  }
};

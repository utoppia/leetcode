/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 17:29:42
 * filename    : 53-maximum-subarray.cpp
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
  int maxSubArray(vector<int> &nums) {
    int n = nums.sz();
    if (n == 0)
      return 0;
    int ans = nums[0];
    for (int i = 1; i < n; ++i) {
      nums[i] = max(nums[i], nums[i] + nums[i - 1]);
      ans = max(ans, nums[i]);
    }
    return ans;
  }
};

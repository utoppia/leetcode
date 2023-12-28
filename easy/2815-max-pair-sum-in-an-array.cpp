/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:18:44
 * filename    : 2815-max-pair-sum-in-an-array.cpp
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
private:
  int maxNum(int val) {
    int ans = val % 10;
    while (val) {
      ans = max(ans, val % 10);
      val /= 10;
    }
    return ans;
  }

public:
  int maxSum(vector<int> &nums) {
    int n = nums.size();
    int ans = -1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (maxNum(nums[i]) == maxNum(nums[j])) {
          ans = max(ans, nums[i] + nums[j]);
        }
      }
    }
    return ans;
  }
};

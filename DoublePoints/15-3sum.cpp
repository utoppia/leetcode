/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 15:46:41
 * filename    : 15-3sum.cpp
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

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
private:
  int next(int i, int n, vector<int> &nums) {
    int j = i;
    while (j < n && nums[j] == nums[i])
      j++;
    return j;
  }
  int prev(int i, int n, vector<int> &nums) {
    int j = i;
    while (j >= 0 && nums[j] == nums[i])
      j--;
    return j;
  }

public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(vall(nums));

    vector<vector<int>> ans;

    int i = 0, n = nums.size();
    while (i < n && nums[i] <= 0) {
      int j = i + 1, k = n - 1;
      while (j < k) {
        int cur = nums[i] + nums[j] + nums[k];
        if (cur == 0) {
          ans.pb({nums[i], nums[j], nums[k]});
          j = next(j, n, nums);
          k = prev(k, n, nums);
        } else if (cur > 0) {
          k = prev(k, n, nums);
        } else {
          j = next(j, n, nums);
        }
      }
      i = next(i, n, nums);
    }
    return ans;
  }
};

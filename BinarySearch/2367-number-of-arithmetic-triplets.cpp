/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 17:47:25
 * filename    : 2367-number-of-arithmetic-triplets.cpp
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
  int find(vector<int> &nums, int l, int r, int val) {
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] == val)
        return m;
      if (nums[m] < val)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }

public:
  int arithmeticTriplets(vector<int> &nums, int diff) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      int j = find(nums, i + 1, n - 1, nums[i] + diff);
      if (j != -1) {
        int k = find(nums, j + 1, n - 1, nums[j] + diff);
        if (k != -1)
          ans++;
      }
    }
    return ans;
  }
};

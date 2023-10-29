/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 15:39:57
 * filename    : 540-single-element-in-a-sorted-array.cpp
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
  int singleNonDuplicate(vector<int> &nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (m - 1 >= 0 && nums[m] == nums[m - 1]) {
        if (m % 2 == 0)
          r = m - 2;
        else
          l = m + 1;
        continue;
      }
      if (m + 1 < n && nums[m] == nums[m + 1]) {
        if (m % 2 == 0)
          l = m + 2;
        else
          r = m - 1;
        continue;
      }
      return nums[m];
    }
    return nums[r];
  }
};

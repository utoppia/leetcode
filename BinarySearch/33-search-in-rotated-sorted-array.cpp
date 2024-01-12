/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 23:54:38
 * filename    : 33-search-in-rotated-sorted-array.cpp
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
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (nums[m] == target)
        return m;
      if (m + 1 < n && nums[m + 1] <= nums[r]) {
        if (nums[m + 1] <= target && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      } else {
        if (nums[l] <= target && target <= nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
    }
    return -1;
  }
};

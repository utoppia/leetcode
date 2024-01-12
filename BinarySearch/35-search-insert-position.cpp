/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 23:33:39
 * filename    : 35-search-insert-position.cpp
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
  int searchInsert(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans + 1;
  }
};

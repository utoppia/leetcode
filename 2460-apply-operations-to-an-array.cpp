/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 14:15:05
 * filename    : 2460-apply-operations-to-an-array.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  vector<int> applyOperations(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i)
      if (nums[i] == nums[i + 1]) {
        nums[i] *= 2;
        nums[i + 1] = 0;
      }
    int i = 0, j = 0;
    while (i < n && nums[i] != 0)
      ++i;
    j = i + 1;
    while (i < n && j < n) {
      while (i < n && nums[i] != 0)
        ++i;
      while (j < n && nums[j] == 0)
        ++j;
      if (i < n && j < n)
        swap(nums[i], nums[j]);
    }
    return nums;
  }
};

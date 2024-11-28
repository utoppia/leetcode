/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 02:04:39
 * filename    : 41-first-missing-positive.cpp
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
  int firstMissingPositive(vector<int> &nums) {
    int n = nums.sz();

    for (int i = 0; i < n; ++i) {
      if (nums[i] <= 0)
        nums[i] = n + 1;
    }

    for (int v : nums) {
      if (abs(v) <= n) {
        nums[abs(v) - 1] = -abs(nums[abs(v) - 1]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] > 0)
        return i + 1;
    }

    return n + 1;
  }
};

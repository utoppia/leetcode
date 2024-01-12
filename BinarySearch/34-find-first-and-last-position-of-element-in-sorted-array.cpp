/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 23:44:27
 * filename    : 34-find-first-and-last-position-of-element-in-sorted-array.cpp
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
  vector<int> searchRange(vector<int> &nums, int target) {
    auto it = equal_range(begin(nums), end(nums), target);
    if (it.first == end(nums) || *it.first != target)
      return {-1, -1};
    int left = (int)(it.first - begin(nums));
    int right = (int)(it.second - begin(nums));
    return {left, right};
  }
};

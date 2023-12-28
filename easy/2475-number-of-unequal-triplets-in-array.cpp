/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-29 00:15:43
 * filename    : 2475-number-of-unequal-triplets-in-array.cpp
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
  int unequalTriplets(vector<int> &nums) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (nums[i] != nums[j] && nums[i] != nums[k] && nums[j] != nums[k])
            ans++;
        }
      }
    }
    return ans;
  }
};

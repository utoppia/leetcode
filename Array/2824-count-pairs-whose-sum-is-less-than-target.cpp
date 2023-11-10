/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 18:02:37
 * filename    : 2824-count-pairs-whose-sum-is-less-than-target.cpp
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
  int countPairs(vector<int> &nums, int target) {
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[i] + nums[j] < target)
          ans++;
      }
    }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 12:19:20
 * filename    : 922-sort-array-by-parity-ii.cpp
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
  vector<int> sortArrayByParityII(vector<int> &nums) {
    vector<int> odds, evens;
    for (int val : nums) {
      if (val & 1)
        odds.pb(val);
      else
        evens.pb(val);
    }

    for (int i = 0; i < nums.size(); ++i) {
      if (i & 1) {
        nums[i] = odds[i / 2];
      } else {
        nums[i] = evens[i / 2];
      }
    }

    return nums;
  }
};

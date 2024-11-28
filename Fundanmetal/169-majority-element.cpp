/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:13:51
 * filename    : 169-majority-element.cpp
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
  int majorityElement(vector<int> &nums) {
    vector<int> bit(32, 0);

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < 32; ++j) {
        if ((nums[i] >> j) & 1)
          bit[j]++;
      }
    }

    unsigned int ans = 0;

    for (int i = 31; i >= 0; --i) {
      if (bit[i] > nums.size() / 2) {
        ans = ans * 2 + 1;
      } else {
        ans = ans * 2;
      }
    }
    return ans;
  }
};

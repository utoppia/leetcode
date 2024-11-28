/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:17:23
 * filename    : 75-sort-colors.cpp
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
  void sortColors(vector<int> &nums) {
    int colorSum[3] = {0, 0, 0};
    int n = nums.sz();

    int i, j = 0;

    for (i = 0; i < n; ++i)
      colorSum[nums[i]]++;

    for (i = 0; i < 3; ++i) {
      while (colorSum[i]--) {
        nums[j++] = i;
      }
    }
  }
};

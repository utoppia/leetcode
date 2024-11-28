/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 01:21:01
 * filename    : 55-jump-game.cpp
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
  bool canJump(vector<int> &nums) {
    int n = nums.sz();
    int i = 0;
    int max_n = 0;
    while (i <= max_n) {
      if (i + nums[i] > max_n)
        max_n = i + nums[i];
      if (max_n >= n - 1)
        return true;
      i++;
    }
    return false;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 12:42:11
 * filename    : 1512-number-of-good-pairs.cpp
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
  int numIdenticalPairs(vector<int> &nums) {
    vector<int> cnt(101);
    int ans = 0;
    for (int val : nums) {
      ans += cnt[val];
      cnt[val] += 1;
    }
    return ans;
  }
};

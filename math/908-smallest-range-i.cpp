/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 00:55:24
 * filename    : 908-smallest-range-i.cpp
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
  int smallestRangeI(vector<int> &nums, int k) {
    int s = max_element(all(nums)) - min_element(all(nums)) - 2 * k;
    return max(0, s);
  }
};

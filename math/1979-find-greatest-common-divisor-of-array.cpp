/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 13:19:34
 * filename    : 1979-find-greatest-common-divisor-of-array.cpp
 * language    : cpp
 *****************************************/
#include "math.h"
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
  int findGCD(vector<int> &nums) {
    return gcd(*min_element(all(nums)), *max_element(all(nums)));
  }
};

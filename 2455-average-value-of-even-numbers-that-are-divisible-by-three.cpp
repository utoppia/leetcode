/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 13:57:56
 * filename    :
 *2455_average-value-of-even-numbers-that-are-divisible-by-three.cpp language :
 *cpp
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
  int averageValue(vector<int> &nums) {
    ll s = 0ll;
    int n = 0;
    for (auto c : nums) {
      if (c % 6 == 0)
        s += c, ++n;
    }
    if (n == 0)
      return 0;
    return (int)(s / n);
  }
};

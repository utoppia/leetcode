/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-09 01:00:20
 * filename    : 1561-maximum-number-of-coins-you-can-get.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
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
  int maxCoins(vector<int> &piles) {
    sort(vall(piles), greater<int>());
    int n = piles.size() / 3;
    int ans = 0;

    for (int i = 0; i < n; ++i)
      ans += piles[1 + i * 2];
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 00:19:54
 * filename    : 875-koko-eating-bananas.cpp
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
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(vall(piles));
    int ans = r;
    while (l <= r) {
      int m = (l + r) >> 1;
      ll c = 0ll;
      for (int p : piles) {
        c += p / m + (p % m == 0 ? 0 : 1);
      }
      if (c <= h) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 16:30:24
 * filename    : 475-heaters.cpp
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
  int findRadius(vector<int> &houses, vector<int> &heaters) {
    sort(vall(houses));
    sort(vall(heaters));

    int ans = 0;
    for (int v : houses) {
      auto it = upper_bound(vall(heaters), v);
      int val = 0;
      if (it != heaters.end()) {
        val = *it - v;
        if (it != heaters.begin()) {
          it--;
          val = min(v - *it, val);
        }
      } else {
        it = heaters.end() - 1;
        val = v - *it;
      }

      ans = max(ans, val);
    }
    return ans;
  }
};

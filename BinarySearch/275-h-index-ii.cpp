/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 15:25:56
 * filename    : 275-h-index-ii.cpp
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
  int hIndex(vector<int> &citations) {

    int n = citations.size();
    int l = 0, r = n - 1;

    int ans = 0;

    while (l <= r) {
      int m = (l + r) / 2;
      if (citations[m] >= n - m) {
        ans = n - m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};

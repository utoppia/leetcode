/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-29 15:16:55
 * filename    : 274-h-index.cpp
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
    sort(vall(citations));
    int n = citations.size();
    int l = 0, r = n;

    int ans = 0;
    auto count = [&citations](int val) {
      int l = 0, r = citations.size() - 1;
      int ans = citations.size();
      while (l <= r) {
        int m = (l + r) / 2;
        if (citations[m] >= val) {
          r = m - 1;
          ans = m;
        } else {
          l = m + 1;
        }
      }
      return citations.size() - ans;
    };

    while (l <= r) {
      int m = (l + r) / 2;
      if (count(m) >= m) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }
};

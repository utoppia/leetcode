/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:45:06
 * filename    : 2399-check-distances-between-same-letters.cpp
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
  bool checkDistances(string s, vector<int> &distance) {
    vector<int> pos(26);
    pos.assign(26, -1);

    for (int i = 0, c; i < s.length(); ++i) {
      c = s[i] - 'a';
      if (pos[c] != -1) {
        if (i - pos[c] - 1 != distance[c])
          return false;
      } else {
        pos[c] = i;
      }
    }
    return true;
  }
};

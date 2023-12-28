/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:49:57
 * filename    : 2404-most-frequent-even-element.cpp
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
  int mostFrequentEven(vector<int> &nums) {
    map<int, int> M;
    for (int val : nums)
      if (val % 2 == 0)
        M[val]++;
    int ans = -1, maxVal = 0;
    for (auto it = M.begin(); it != M.end(); ++it) {
      if (it->second > maxVal) {
        ans = it->first;
        maxVal = it->second;
      }
    }
    return ans;
  }
};

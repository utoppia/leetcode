/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-10 13:40:14
 * filename    : 495-teemo-attacking.cpp
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
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int ans = 0;
    int en;

    int i = 0, j;
    while (i < timeSeries.size()) {
      en = timeSeries[i] + duration - 1;
      j = i + 1;
      while (j < timeSeries.size() && timeSeries[j] <= en) {
        en = timeSeries[j] + duration - 1;
        j++;
      }
      ans += en - timeSeries[i] + 1;
      i = j;
    }
    return ans;
  }
};

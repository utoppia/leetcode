/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-29 00:09:37
 * filename    : 2432-the-employee-that-worked-on-the-longest-task.cpp
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
  int hardestWorker(int n, vector<vector<int>> &logs) {
    int pre = 0;
    int ans = -1, maxExcuteTime = 0;
    for (int i = 0, s; i < logs.size(); ++i) {
      s = logs[i][1] - pre;
      if (s > maxExcuteTime || (s == maxExcuteTime && logs[i][0] < ans)) {
        ans = logs[i][0];
        maxExcuteTime = s;
      }
      pre = logs[i][1];
    }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-11 20:26:09
 * filename    : 56-merge-intervals.cpp
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
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    sort(vall(intervals), [](vector<int> &i, vector<int> &j) {
      if (i[0] == j[0])
        return i[1] > j[1];
      else
        return i[0] < j[0];
    });

    vector<vector<int>> ans;

    int left, right = 0;
    int i = 0, j;
    int n = intervals.size();

    while (i < n) {
      left = intervals[i][0];
      right = intervals[i][1];
      j = i;
      while (j < n && intervals[j][0] <= right) {
        right = max(right, intervals[j][1]);
        j++;
      }
      vector<int> tmp;
      tmp.pb(left);
      tmp.pb(right);
      ans.pb(tmp);
      i = j;
    }
    return ans;
  }
};

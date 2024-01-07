/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-08 00:35:31
 * filename    : 1090-largest-values-from-labels.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
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
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int numWanted, int useLimit) {
    int n = values.size();

    vector<int> idx(n);

    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(),
         [&](int i, int j) { return values[i] > values[j]; });

    unordered_map<int, int> flag;

    int cnt = 0;
    int ans = 0;
    for (int i : idx) {
      if (flag[labels[i]] == useLimit)
        continue;
      flag[labels[i]]++;
      cnt++;
      ans += values[i];
      if (cnt == numWanted)
        break;
    }
    return ans;
  }
};

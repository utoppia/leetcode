/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:36:19
 * filename    : 2363-merge-similar-items.cpp
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
  vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1,
                                        vector<vector<int>> &items2) {
    vector<int> weights(1001); // we know that vale <= 1000;
    for (int i = 0; i < items1.size(); ++i) {
      weights[items1[i][0]] += items1[i][1];
    }
    for (int i = 0; i < items2.size(); ++i) {
      weights[items2[i][0]] += items2[i][1];
    }
    vector<vector<int>> ans;
    for (int i = 1; i < 1001; ++i)
      if (weights[i] > 0) {
        vector<int> tmp(2);
        tmp[0] = i;
        tmp[1] = weights[i];
        ans.pb(tmp);
      }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 21:15:37
 * filename    : 39-combination-sum.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
private:
  void dfs(vector<int> &candidates, int val, int pos, vector<int> &temp,
           vector<vector<int>> &ans) {
    if (val == 0) {
      ans.eb(temp);
      return;
    }

    for (int i = pos; i < candidates.size(); ++i) {
      if (val - candidates[i] < 0)
        break;
      temp.eb(candidates[i]);
      dfs(candidates, val - candidates[i], i, temp, ans);
      temp.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, temp, ans);
    return ans;
  }
};

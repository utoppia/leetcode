/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 21:10:46
 * filename    : 78-subsets.cpp
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
  void solve(vector<int> &S, int cur, vector<int> curP,
             vector<vector<int>> &ans) {
    if (cur == S.size()) {
      ans.push_back(curP);
      return;
    }
    int next = cur + 1;
    while (next != S.size() && S[next] == S[cur])
      next++;
    solve(S, next, curP, ans);
    while (cur < next) {
      curP.push_back(S[cur]);
      solve(S, next, curP, ans);
      cur += 1;
    }
    return;
  }

public:
  vector<vector<int>> subsets(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    ret.clear();
    vector<int> curP;
    curP.clear();
    solve(nums, 0, curP, ret);
    return ret;
  }
};

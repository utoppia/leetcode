/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-08 00:18:31
 * filename    : 826-most-profit-assigning-work.cpp
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
  int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit,
                          vector<int> &worker) {
    int n = profit.size();
    vector<int> ind(n);
    iota(vall(ind), 0);

    sort(vall(ind),
         [difficulty](int i, int j) { return difficulty[i] < difficulty[j]; });

    sort(vall(worker));

    int ans = 0;
    int pos = 0;
    int cur = 0;
    for (int w : worker) {
      while (pos < n && difficulty[ind[pos]] <= w) {
        cur = max(cur, profit[ind[pos]]);
        pos++;
      }
      ans += cur;
    }
    return ans;
  }
};

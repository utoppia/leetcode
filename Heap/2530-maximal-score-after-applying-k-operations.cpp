/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-18 00:26:46
 * filename    : 2530-maximal-score-after-applying-k-operations.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  long long maxKelements(vector<int> &nums, int k) {
    priority_queue<int> que;
    for (int c : nums)
      que.push(c);
    ll ans = 0ll;
    int val;
    while (k--) {
      val = que.top();
      que.pop();
      ans += val;
      que.push(ceil(val / 3.));
    }
    return ans;
  }
};

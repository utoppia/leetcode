/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 09:57:03
 * filename    : 2558-take-gifts-from-the-richest-pile.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <math.h>
#include <queue>
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
  long long pickGifts(vector<int> &gifts, int k) {
    priority_queue<int> q(gifts.begin(), gifts.end());
    int val;
    while (k--) {
      val = q.top();
      q.pop();
      val = (int)sqrt(val);
      q.push(val);
    }
    ll ans = 0ll;
    while (!q.empty()) {
      ans += q.top();
      q.pop();
    }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:27:49
 * filename    : 682-baseball-game.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
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
  int calPoints(vector<string> &operations) {
    stack<int> scores;
    for (string op : operations) {
      if (op == "+") {
        int v = scores.top();
        scores.pop();
        int new_s = v + scores.top();
        scores.push(v);
        scores.push(new_s);
      } else if (op == "D") {
        scores.push(scores.top() * 2);
      } else if (op == "C") {
        scores.pop();
      } else {
        scores.push(atoi(op.c_str()));
      }
    }
    int ans = 0;
    while (!scores.empty()) {
      ans += scores.top();
      scores.pop();
    }
    return ans;
  }
};

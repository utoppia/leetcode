/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:25:51
 * filename    : 739-daily-temperatures.cpp
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
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    stack<int> st;
    int n = temperatures.sz();
    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        ans[st.top()] = i - st.top();
        st.pop();
      }

      st.push(i);
    }

    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:15:49
 * filename    : 155-min-stack.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
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

class MinStack {
private:
  stack<int> st;
  map<int, int> hs;

public:
  MinStack() { hs.clear(); }

  void push(int val) {
    hs[val]++;
    st.push(val);
  }

  void pop() {
    int val = st.top();
    st.pop();
    hs[val]--;
    if (hs[val] == 0)
      hs.erase(val);
  }

  int top() { return st.top(); }

  int getMin() { return begin(hs)->first; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

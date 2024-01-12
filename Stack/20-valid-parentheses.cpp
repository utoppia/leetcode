/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 00:12:35
 * filename    : 20-valid-parentheses.cpp
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
  bool isValid(string s) {
    stack<char> st;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        st.push(s[i]);
      else if (s[i] == ')') {
        if (!st.empty() && st.top() == '(')
          st.pop();
        else
          return false;
      } else if (s[i] == ']') {
        if (!st.empty() && st.top() == '[')
          st.pop();
        else
          return false;
      } else if (s[i] == '}') {
        if (!st.empty() && st.top() == '{')
          st.pop();
        else
          return false;
      }
    }
    return st.empty();
  }
};

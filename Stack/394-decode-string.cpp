/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-11-19 00:16:22
 * filename    : 394-decode-string.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <stack>
#include <string>
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
  string decodeString(string s) {
    stack<string> st;
    string tmp = "";
    for (auto c : s) {
      if (c == '[') {
        st.push(tmp);
        tmp = "";
      } else if (c == ']') {

        while (true) {
          string t = st.top();
          st.pop();
          if (t[0] >= '0' && t[0] <= '9') {
            int k = stoi(t);
            string add = "";
            for (int i = 0; i < k; ++i)
              add += tmp;
            st.push(add);
            tmp = "";
            break;
          }
          tmp = t + tmp;
        }
      } else if (c <= '9') {
        if (tmp != "" && tmp[0] > '9') {
          st.push(tmp);
          tmp = c;
        } else
          tmp += c;
      } else {
        tmp += c;
      }
    }
    string ans = tmp;
    while (!st.empty()) {
      ans = st.top() + ans;
      st.pop();
    }
    return ans;
  }
};

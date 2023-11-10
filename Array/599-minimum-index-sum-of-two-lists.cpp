/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-10 13:57:01
 * filename    : 599-minimum-index-sum-of-two-lists.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <string>
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
  vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
    int ans = 3000;
    vector<string> ret;
    for (int i = 0; i < list1.size(); ++i) {
      for (int j = 0; j < list2.size(); ++j) {
        if (list1[i] == list2[j]) {
          if (i + j < ans) {
            ans = i + j;
            ret.clear();
            ret.pb(list1[i]);
          } else if (i + j == ans) {
            ret.pb(list1[i]);
          }
        }
      }
    }
    return ret;
  }
};

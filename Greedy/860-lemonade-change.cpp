/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-12 17:37:09
 * filename    : 860-lemonade-change.cpp
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
#define fi first
#define snd second

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills) {
    vector<int> num(30);

    for (int b : bills) {
      if (b == 5)
        num[5]++;
      else if (b == 10) {
        if (num[5] == 0)
          return false;
        num[10]++;
        num[5]--;
      } else if (b == 20) {
        if (num[5] < 1)
          return false;
        if (num[10] > 0) {
          num[10]--;
          num[5]--;
          num[20]++;
          continue;
        }
        if (num[5] < 3)
          return false;
        num[20]++;
        num[5] -= 3;
      }
    }
    return true;
  }
};

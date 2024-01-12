/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:54:42
 * filename    : 657-robot-return-to-origin.cpp
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
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (char c : moves) {
      switch (c) {
      case 'L':
        x--;
        break;
      case 'R':
        x++;
        break;
      case 'U':
        y++;
        break;
      case 'D':
        y--;
        break;
      }
    }
    return x == 0 && y == 0;
  }
};

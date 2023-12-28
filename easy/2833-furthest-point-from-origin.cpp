/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-12-28 23:23:24
 * filename    : 2833-furthest-point-from-origin.cpp
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
  int furthestDistanceFromOrigin(string moves) {
    int add = 0, move = 0;
    for (char c : moves) {
      if (c == 'L')
        move--;
      else if (c == 'R')
        move++;
      else
        add++;
    }
    return abs(move) + add;
  }
};

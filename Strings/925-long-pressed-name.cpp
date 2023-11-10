/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-11-09 12:23:18
 * filename    : 925-long-pressed-name.cpp
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
  bool isLongPressedName(string name, string typed) {
    if (name[0] != typed[0])
      return false;
    int i = 1, j = 1;
    while (i < name.length() && j < typed.length()) {
      if (name[i] != typed[j]) {
        while (j < typed.length() && typed[j] == name[i - 1])
          j++;
      }
      if (j >= typed.length() || name[i] != typed[j])
        return false;
      i++;
      j++;
    }
    if (i != name.length())
      return false;
    while (j < typed.length() && typed[j] == name[i - 1])
      j++;
    if (j != typed.length())
      return false;
    return true;
  }
};

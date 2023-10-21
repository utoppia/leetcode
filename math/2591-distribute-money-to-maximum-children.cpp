/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-22 01:44:41
 * filename    : 2591-distribute-money-to-maximum-children.cpp
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
  int distMoney(int money, int children) {
    if (money < children)
      return -1;
    if (children == 1 && money == 4)
      return -1;
    money -= children;
    int cnt = money / 7;
    if (cnt + 1 == children && money % 7 == 3)
      cnt--;
    if (cnt >= children) {
      cnt = children - (money != 7 * children);
    }
    if (cnt < 0)
      cnt = 0;
    return cnt;
  }
};

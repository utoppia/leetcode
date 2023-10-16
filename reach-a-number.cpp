/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  :
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <utility>
#include <vector>

#define all(v) v.begin(), v.end()
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
  int reachNumber(int target) {
    if (target < 0)
      target = -target;
    int n = (int)sqrt(2 * target);
    while (n * (n + 1) / 2 < target)
      n++;
    if (n * (n + 1) / 2 == target)
      return n;
    while ((n * (n + 1) / 2 - target) % 2 != 0)
      n++;
    return n;
  }
};

int main() {
  Solution s;
  cout << s.reachNumber(4) << endl;
}

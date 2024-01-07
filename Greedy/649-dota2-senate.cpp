/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-07 20:14:19
 * filename    : 649-dota2-senate.cpp
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
  string predictPartyVictory(string senate) {
    queue<int> dire, radiant;
    int n = senate.length();
    for (int i = 0; i < n; ++i) {
      if (senate[i] == 'D')
        dire.push(i);
      else
        radiant.push(i);
    }

    while (!dire.empty() && !radiant.empty()) {
      // cout << dire.size() << " " << radiant.size() << endl;
      if (dire.front() < radiant.front()) {
        dire.push(dire.front() + n);
      } else
        radiant.push(radiant.front() + n);
      dire.pop();
      radiant.pop();
    }

    if (dire.empty())
      return "Radiant";
    else
      return "Dire";
  }
};

int main() {
  Solution S;
  cout << S.predictPartyVictory("RD") << endl;
  return 0;
}

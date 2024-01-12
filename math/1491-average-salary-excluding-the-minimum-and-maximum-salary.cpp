/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 14:48:46
 * filename    :
 *1491-average-salary-excluding-the-minimum-and-maximum-salary.cpp language    :
 *cpp editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <numeric>
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
  double average(vector<int> &salary) {
    double total = (double)accumulate(vall(salary), 0);
    total -= *max_element(vall(salary));
    total -= *min_element(vall(salary));
    return total / (salary.size() - 2);
  }
};

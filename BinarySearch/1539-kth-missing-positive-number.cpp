/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-30 00:39:11
 * filename    : 1539-kth-missing-positive-number.cpp
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
private:
  int find_lower(vector<int> &arr, int val) {
    int l = 0, r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
      int m = (l + r) >> 1;
      if (arr[m] <= val) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return ans;
  }

public:
  int findKthPositive(vector<int> &arr, int k) {
    int l = 1, r = arr.size() + k;
    while (l <= r) {
      int m = (l + r) >> 1;

      int index = find_lower(arr, m);
      if (index == -1 && arr[0] > k) {
        return k;
      }
      if (m - index - 1 == k && arr[index] != m) {
        return m;
      }
      if (m - index - 1 >= k) {
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return 0;
  }
};

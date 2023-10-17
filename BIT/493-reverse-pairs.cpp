/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 21:50:46
 * filename    : 493-reverse-pairs.cpp
 * language    : cpp
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <map>
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

struct BIT {
  vector<int> c;
  int size;

  BIT(int _size) : size(_size), c(_size + 1) {}

  static constexpr int lowbit(int x) { return x & -x; }

  void add(int index, int val) {
    while (index <= size) {
      c[index] += val;
      index += lowbit(index);
    }
  }

  int getSum(int index) {
    int ret = 0;
    while (index > 0) {
      ret += c[index];
      index -= lowbit(index);
    }
    return ret;
  }

  void make_tree(vector<int> nums) {
    size = nums.size();
    c.resize(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
      add(i, nums[i - 1]);
    }
  }
};

class Solution {
public:
  int reversePairs(vector<int> &nums) {
    set<ll> S;
    for (ll c : nums) {
      S.insert(c);
      S.insert(2 * c);
    }
    map<ll, int> dic;
    int n = 0;
    for (ll c : S) {
      dic[c] = ++n;
    }

    BIT b(n);
    int ans = 0;
    for (ll c : nums) {
      ans += b.getSum(n) - b.getSum(dic[2 * c]);
      b.add(dic[c], 1);
    }
    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-17 23:49:33
 * filename    : number-of-pairs-satisfying-inequality.cpp
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

class BIT {
private:
  vector<int> c;
  int size;

public:
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
  long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff) {
    set<int> S;
    int m = nums1.size();
    for (int i = 0; i < m; ++i) {
      S.insert(nums1[i] - nums2[i]);
      S.insert(nums1[i] - nums2[i] + diff);
    }
    map<int, int> dic;
    int n = 0;
    for (int c : S) {
      dic[c] = ++n;
    }

    BIT b(n);
    ll ans = 0ll;
    for (int i = 0, val; i < m; ++i) {
      val = nums1[i] - nums2[i];
      ans += b.getSum(dic[val + diff]);
      b.add(dic[val], 1);
    }
    return ans;
  }
};

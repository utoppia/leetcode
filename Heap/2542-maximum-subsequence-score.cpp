/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 12:56:06
 * filename    : 2542-maximum-subsequence-score.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <ios>
#include <iostream>
#include <numeric>
#include <queue>
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
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();
    vector<int> pos(n);
    iota(vall(pos), 0);
    sort(vall(pos),
         [&](const int &x, const int &y) { return nums2[x] > nums2[y]; });

    ll cnt = 0ll, ans = 0ll;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k; ++i) {
      q.emplace(nums1[pos[i]]);
      cnt += nums1[pos[i]];
    }
    ans = cnt * nums2[pos[k - 1]];

    for (int i = k; i < n; ++i) {
      if (nums1[pos[i]] > q.top()) {
        cnt += nums1[pos[i]] - q.top();
        q.pop();
        q.emplace(nums1[pos[i]]);
        ans = max(ans, cnt * nums2[pos[i]]);
      }
    }
    return ans;
  }
};

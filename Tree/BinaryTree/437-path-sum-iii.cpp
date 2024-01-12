/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:26:46
 * filename    : 437-path-sum-iii.cpp
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
#define eb emplace_back
#define fi first
#define snd second
#define sz size

#define ll long long
#define nMax 200005

#define MOD 998244353
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  int dfs(TreeNode *root, int targetSum, ll cur) {
    if (root == nullptr)
      return 0;

    int ret = 0;
    cur += root->val;
    ret += hash[cur - targetSum];

    hash[cur]++;
    ret += dfs(root->left, targetSum, cur);
    ret += dfs(root->right, targetSum, cur);
    hash[cur]--;

    return ret;
  }
  map<ll, int> hash;

public:
  int pathSum(TreeNode *root, int targetSum) {
    hash.clear();
    hash[0] = 1;
    return dfs(root, targetSum, 0ll);
  }
};

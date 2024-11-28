/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 12:59:58
 * filename    : 124-binary-tree-maximum-path-sum.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <set>
#include <unordered_map>
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
  void dfs(TreeNode *root, unordered_map<TreeNode *, int> &dp, int &ans) {
    if (root == nullptr)
      return;

    dp[root] = root->val;

    int cnt = root->val;
    if (root->left != nullptr) {
      dfs(root->left, dp, ans);
      dp[root] = max(dp[root->left] + root->val, dp[root]);
      cnt += dp[root->left];
    }
    if (root->right != nullptr) {
      dfs(root->right, dp, ans);
      dp[root] = max(dp[root->right] + root->val, dp[root]);
      cnt += dp[root->right];
    }
    ans = max(ans, dp[root]);
    ans = max(ans, cnt);
    return;
  }

public:
  int maxPathSum(TreeNode *root) {
    unordered_map<TreeNode *, int> dp;
    int ans = root->val;

    dfs(root, dp, ans);

    return ans;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:54:04
 * filename    : 102-binary-tree-level-order-traversal.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <queue>
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
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;

    queue<TreeNode *> q;
    q.push(root);
    vector<int> tmp;

    while (!q.empty()) {
      int n = q.size();
      TreeNode *t;
      tmp.clear();
      for (int i = 0; i < n; ++i) {
        t = q.front();
        tmp.pb(t->val);
        if (t->left != nullptr)
          q.push(t->left);
        if (t->right != nullptr)
          q.push(t->right);
        q.pop();
      }
      ans.pb(tmp);
    }

    return ans;
  }
};

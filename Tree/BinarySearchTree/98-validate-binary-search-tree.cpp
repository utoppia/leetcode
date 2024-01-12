/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:09:02
 * filename    : 98-validate-binary-search-tree.cpp
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
  bool solve(TreeNode *root, int &maxLeft, int &minRight) {
    if (root->left == NULL and root->right == NULL) {
      maxLeft = minRight = root->val;
      return true;
    }
    int l, r;
    maxLeft = minRight = root->val;
    if (root->left) {
      if (!solve(root->left, l, r))
        return false;
      if (l >= root->val)
        return false;
      maxLeft = max(maxLeft, l);
      minRight = min(minRight, r);
    }
    if (root->right) {
      if (!solve(root->right, l, r))
        return false;
      if (r <= root->val)
        return false;
      maxLeft = max(maxLeft, l);
      minRight = min(minRight, r);
    }
    return true;
  }

public:
  bool isValidBST(TreeNode *root) {
    if (root == NULL)
      return true;
    int l, r;
    return solve(root, l, r);
  }
};

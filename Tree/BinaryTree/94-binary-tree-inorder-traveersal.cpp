/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:32:18
 * filename    : 94-binary-tree-inorder-traveersal.cpp
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
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    TreeNode *pre;

    while (root != nullptr) {
      if (root->left) {
        pre = root->left;
        while (pre->right != nullptr && pre->right != root)
          pre = pre->right;

        if (pre->right == nullptr) {
          pre->right = root;
          root = root->left;
        } else {
          ans.pb(root->val);
          pre->right = nullptr;
          root = root->right;
        }
      } else {
        ans.pb(root->val);
        root = root->right;
      }
    }
    return ans;
  }
};

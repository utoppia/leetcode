/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 16:40:31
 * filename    :
 *105-construct-binary-tree-from-preorder-and-inorder-traversal.cpp language :
 *cpp editor      : Emacs 27.1
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
  TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int l, int r,
                int x, int y) {
    if (l > r)
      return nullptr;
    int val = preorder[l];
    TreeNode *cur = new TreeNode(val);

    int i = x;
    while (inorder[i] != val)
      i++;
    int dis = i - x;
    if (dis > 0) {
      TreeNode *left = dfs(preorder, inorder, l + 1, l + dis, x, i - 1);
      cur->left = left;
    }
    if (l + dis + 1 <= r) {
      TreeNode *right = dfs(preorder, inorder, l + dis + 1, r, i + 1, y);
      cur->right = right;
    }
    return cur;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return dfs(preorder, inorder, 0, preorder.size() - 1, 0,
               inorder.size() - 1);
  }
};

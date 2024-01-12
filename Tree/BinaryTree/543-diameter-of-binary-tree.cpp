/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 19:48:30
 * filename    : 543-diameter-of-binary-tree.cpp
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
  int ans;
  int findDiameter(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int l = findDiameter(root->left);
    int r = findDiameter(root->right);

    if (l + r > ans)
      ans = l + r;
    return max(l, r) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    ans = 0;
    findDiameter(root);
    return ans;
  }
};

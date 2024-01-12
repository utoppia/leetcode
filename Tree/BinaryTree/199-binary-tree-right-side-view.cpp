/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-12 20:19:06
 * filename    : 199-binary-tree-right-side-view.cpp
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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    vector<TreeNode *> temp;
    if (root == NULL)
      return ans;
    temp.push_back(root);
    while (temp.size() != 0) {
      vector<int> t1;
      t1.clear();
      vector<TreeNode *> t2;
      t2.clear();
      for (int i = 0; i < temp.size(); ++i) {
        t1.push_back(temp[i]->val);
        if (temp[i]->left)
          t2.push_back(temp[i]->left);
        if (temp[i]->right)
          t2.push_back(temp[i]->right);
      }
      ans.push_back(t1[t1.size() - 1]);
      temp = t2;
    }
    return ans;
  }
};

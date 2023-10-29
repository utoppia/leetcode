/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2023-10-28 15:58:45
 * filename    : 234-palindrome-linked-list.cpp
 * language    : cpp
 * editor      : Emacs 27.1
 *****************************************/
#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  bool isPalindrome(ListNode *head) {
    ListNode *pos = head;
    stack<int> q;
    while (pos != nullptr) {
      q.push(pos->val);
      pos = pos->next;
    }
    pos = head;
    while (q.size()) {
      if (q.top() != pos->val)
        return false;
      q.pop();
      pos = pos->next;
    }
    return true;
  }
};

/******************************************
 * author      : utoppia
 * description : solution for leetcode
 * updated at  : 2024-01-13 02:29:01
 * filename    : 138-copy-list-with-random-pointer.cpp
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

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;
    vector<Node *> tmp;
    unordered_map<Node *, int> hs;
    int cnt = 0;

    Node *pt = head;
    while (pt != nullptr) {
      tmp.pb(new Node(pt->val));
      hs[pt] = cnt;
      cnt++;
      pt = pt->next;
    }
    for (int i = 1; i < cnt; ++i)
      tmp[i - 1]->next = tmp[i];

    pt = head;
    while (pt != nullptr) {
      if (pt->random != nullptr)
        tmp[hs[pt]]->random = tmp[hs[pt->random]];
      pt = pt->next;
    }

    return tmp[0];
  }
};

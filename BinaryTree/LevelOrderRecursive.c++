#include <bits/stdc++.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <deque>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <complex>
#include <utility>
#include <limits>
#include <string>
#include <type_traits>
#include <chrono>
using namespace std;
#include <iostream>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; ++i)

 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
void solve(TreeNode*root, vector<vector<int>>&res,int level){
if(!root) return;
if(level>=res.size())
    res.push_back({});
    
    res[level].push_back(root->val);
    solve(root->left,res,level+1);
    solve(root->right,res,level+1);

}
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root) return res;
    solve(root,res,0);
    for(int i=1;i<res.size();i=i+2){
        reverse(res[i].begin(),res[i].end());
    }
    return res;
    }
    
};



int main() {
ios::sync_with_stdio(0);
return 0;
}
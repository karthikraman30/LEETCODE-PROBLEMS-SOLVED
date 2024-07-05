#include<iostream>
#include<vector>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 };

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result = {};
        if (root == nullptr) {
            return result;
        }
        for (auto v : inorderTraversal(root->left)) {
            result.push_back(v);
        }
        result.push_back(root->val);
        for (auto v : inorderTraversal(root->right)) {
            result.push_back(v);
        }
        return result;
    }
};
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (64.36%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 66.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <queue>
class Solution {
public:
    vector<vector<int>> v;
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        levelOB(root, 0);
        return vector<vector<int>>(v.rbegin(), v.rend());
    }
    
    void levelOB(TreeNode* root, int level){
        if(!root){
            return;
        }
        if (v.size() == level){
            v.push_back({root->val});
        }else{
            v[level].push_back(root->val);
        }
        levelOB(root->left, level + 1);
        levelOB(root->right, level + 1);
    }
};
// @lc code=end


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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            vector<int> tmp;
            int level_size = que.size();
            while(level_size--){
                TreeNode* tmp_data = que.front();
                que.pop();
                tmp.push_back(tmp_data->val);
                if(tmp_data->left)
                    que.push(tmp_data->left);
                if(tmp_data->right)
                    que.push(tmp_data->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;
    }
};
// @lc code=end


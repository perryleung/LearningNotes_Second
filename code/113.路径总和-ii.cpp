/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (60.84%)
 * Likes:    373
 * Dislikes: 0
 * Total Accepted:    99.7K
 * Total Submissions: 163.2K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
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
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void helper(TreeNode* root, int count){
        if(!root->left && !root->right && count == 0){
            res.push_back(path);
            return;
        }
        if(!root->left && !root->right){
            //path.pop_back();//这里不应该再pop，因为前面一步回溯回去后会pop
            return;
        }
        if(root->left){
            path.push_back(root->left->val);
            helper(root->left, count - root->left->val);
            path.pop_back();//hui su
        }
        if(root->right){
            path.push_back(root->right->val);
            helper(root->right, count - root->right->val);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        if(!root)
            return res;
        path.clear();
        path.push_back(root->val);
        helper(root, sum - root->val);
        return res;
    }
};
// @lc code=end


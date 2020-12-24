/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.62%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 129.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 1;
        while(!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                if(!cur->left && !cur->right)
                    return depth;
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            depth++;
        }
        return depth;
        /*
        if (root == NULL)
            return 0;
        else if(!root->left && !root->right)
            return 1;
        else if(root->left && root->right)
            return 1 + min(minDepth(root->left), minDepth(root->right));
        else
            return 1 + (root->left ? minDepth(root->left) : minDepth(root->right));
            */
    }
};
// @lc code=end


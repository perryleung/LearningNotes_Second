/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (32.17%)
 * Likes:    814
 * Dislikes: 0
 * Total Accepted:    183.5K
 * Total Submissions: 562.3K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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

/*中序遍历
void inorder(TreeNode* root, vector<int> & res){
    if(root==NULL)
        return;
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}
vector<int> question(TreeNode* root){
    vector<int> res;
    return inorder(root, res);
}
*/

class Solution {
public:
    //long lower = LONG_MIN;//要long才行，不然不能通过所有示例
    bool isValidBST(TreeNode* root) {
        /* if(!root)
            return true;
        bool left = isValidBST(root->left);
        if(root->val > lower)
            lower = root->val;
        else
            return false;
        bool right = isValidBST(root->right);
        return left && right; */
        return helper(root, nullptr, nullptr);
    }
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root)
            return true;
        if(min != nullptr && min->val >= root->val)
            return false;
        if(max != nullptr && max->val <= root->val)
            return false;
        return helper(root->left, min, root) && helper(root->right, root, max);
    }
};
// @lc code=end


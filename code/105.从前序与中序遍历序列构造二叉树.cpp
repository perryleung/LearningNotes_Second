/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (67.80%)
 * Likes:    730
 * Dislikes: 0
 * Total Accepted:    124.2K
 * Total Submissions: 181.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    /* TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR){
        if(preL > preR || inL > inR)
            return NULL;
        int pivot = preorder[preL];
        TreeNode *root = new TreeNode(pivot);
        int pivot_index_in_inorder = 0;
        while (inorder[pivot_index_in_inorder] != pivot && pivot_index_in_inorder <= inR)
            pivot_index_in_inorder++;
        root->left = helper(preorder, inorder, preL + 1, pivot_index_in_inorder - inL + preL, inL, pivot_index_in_inorder - 1);
        root->right = helper(preorder, inorder, pivot_index_in_inorder - inL + preL + 1, preR, pivot_index_in_inorder + 1, inR);
        return root;
    } */
    /* TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_size = preorder.size();
        int in_size = inorder.size();
        if (pre_size != in_size || pre_size < 0 || in_size < 0)
            return NULL;
        return helper(preorder, inorder, 0, pre_size - 1, 0, in_size - 1);
    } */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_size = preorder.size();
        int in_size = inorder.size();
        if (pre_size != in_size || pre_size < 1 || in_size < 1)
            return nullptr;
        return helper(preorder, inorder, 0, pre_size - 1, 0, in_size - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_left, int pre_right, int in_left, int in_right) {
        if(pre_left > pre_right || in_left > in_right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_left]);
        int index_in_inorder = 0;
        while(inorder[index_in_inorder] != preorder[pre_left])
            ++index_in_inorder;
        root->left = helper(preorder, inorder, pre_left + 1, index_in_inorder - in_left + pre_left, in_left, index_in_inorder - 1);
        root->right = helper(preorder, inorder, index_in_inorder - in_left + pre_left + 1, pre_right, index_in_inorder + 1, in_right);
        return root;
    }
};
// @lc code=end


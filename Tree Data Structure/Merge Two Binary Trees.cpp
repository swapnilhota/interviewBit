/*
Given two Binary Trees A and B, you need to merge them in a single binary tree.

The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

Otherwise, the non-null node will be used as the node of new tree.
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A, TreeNode* B)
{
    if(A==NULL || B==NULL)
    {
        return;
    }
    A->val += B->val;
    if(A->left==NULL && B->left!=NULL)
    {
        A->left = new TreeNode(0);
    }
    if(A->right==NULL && B->right!=NULL)
    {
        A->right = new TreeNode(0);
    }
    helper(A->left, B->left);
    helper(A->right, B->right);
}

TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {

    helper(A, B);

    return A;

}

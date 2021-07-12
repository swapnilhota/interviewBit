/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int height(TreeNode* node, int h)
{
    if(node==NULL)
    {
        return h;
    }
    h++;
    return max(height(node->left, h), height(node->right, h));
}

int helper(TreeNode* A)
{
    if(A==NULL)
    {
        return 1;
    }
    int h1 = height(A->left, 0);
    int h2 = height(A->right, 0);
    if(abs(h1-h2)>1)
    {
        return 0;
    }

    return helper(A->left)&&helper(A->right);
}

int Solution::isBalanced(TreeNode* A) {

    return helper(A);

}

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* &node, TreeNode* parent)
{
    if(node->left==NULL && node->right==NULL)
    {
        return;
    }
    else if(node->left==NULL)
    {
        if(parent==NULL)
        {
            node=node->right;
            helper(node, parent);
            return;
        }
        if(parent->left==node)
        {
            parent->left=node->right;
            helper(parent->left, parent);
        }
        else
        {
            parent->right=node->right;
            helper(parent->right, parent);
        }
    }
    else if(node->right==NULL)
    {
        if(parent==NULL)
        {
            node=node->left;
            helper(node, parent);
            return;
        }
        if(parent->left==node)
        {
            parent->left=node->left;
            helper(parent->left, parent);
        }
        else
        {
            parent->right=node->left;
            helper(parent->right, parent);
        }
    }
    else
    {
        helper(node->left, node);
        helper(node->right, node);
    }
}
 
TreeNode* Solution::solve(TreeNode* A) {
    
    TreeNode* parent=NULL;
    helper(A, parent);
    return A;
}


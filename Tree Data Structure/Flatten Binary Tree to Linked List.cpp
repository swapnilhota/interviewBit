/*
Given a binary tree, flatten it to a linked list in-place.

Example :

Given


         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Note that the left child of all nodes should be NULL.
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
TreeNode* Solution::flatten(TreeNode* A) {
    stack<TreeNode*> stk;
    TreeNode* curr = A;

    while(1)
    {
        if(curr->left)
        {
            if(curr->right)
            {
                stk.push(curr->right);
            }
            curr->right = curr->left;
            curr->left = NULL;
            curr=curr->right;
        }
        else
        {
            if(curr->right)
            {
                curr=curr->right;
            }
            else
            {
                if(stk.empty())
                {
                    break;
                }
                else
                {
                    curr->right = stk.top();
                    stk.pop();
                }
            }
        }
    }

    return A;
}

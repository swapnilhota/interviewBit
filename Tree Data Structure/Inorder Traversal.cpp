/*
Given a binary tree, return the inorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3
return [1,3,2].

Using recursion is not allowed.
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
vector<int> Solution::inorderTraversal(TreeNode* A) {

    stack<TreeNode*> stk;
    TreeNode* curr = A;
    vector<int> ans;
    while(curr!=NULL || stk.empty()==false)
    {
        while(curr!=NULL)
        {
            stk.push(curr);
            curr=curr->left;
        }

        curr = stk.top();
        stk.pop();
        ans.push_back(curr->val);
        curr=curr->right;
    }

    return ans;

}

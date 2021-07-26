/*
Given a binary tree, return the Postorder traversal of its nodes values.

NOTE: Using recursion is not allowed.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {

    stack<TreeNode*> s1;
    stack<TreeNode*> s2;

    vector<int> ans;

    s1.push(A);

    while(!s1.empty()) 
    {
        TreeNode* curr = s1.top();
        s1.pop();

        s2.push(curr);
        
        if(curr->left)
        {
            s1.push(curr->left);
        }
        if(curr->right)
        {
            s1.push(curr->right);
        }
    }

    while(!s2.empty())
    {
        ans.push_back(s2.top()->val);
        s2.pop();
    }

    return ans;

}

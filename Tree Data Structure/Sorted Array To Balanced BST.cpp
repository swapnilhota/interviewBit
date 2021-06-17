/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void helper(const vector<int> &A, TreeNode* &node, int left, int right)
{
    if(left>right)
    {
        return;
    }
    
    int mid = (right-left)/2+left;
    node = new TreeNode(A[mid]);
    helper(A, node->left, left, mid-1);
    helper(A, node->right, mid+1, right);
}
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    
    TreeNode* root = NULL;
    helper(A, root, 0, A.size()-1);
    return root;
    
}

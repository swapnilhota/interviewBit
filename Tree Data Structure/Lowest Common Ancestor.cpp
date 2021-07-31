/*
Find the lowest common ancestor in an unordered binary tree given two values in the tree.

Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants.

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4
For the above tree, the LCA of nodes 5 and 1 is 3.

LCA = Lowest common ancestor

Please note that LCA for nodes 5 and 4 is 5.

You are given 2 values. Find the lowest common ancestor of the two nodes represented by val1 and val2
No guarantee that val1 and val2 exist in the tree. If one value doesn’t exist in the tree then return -1.
There are no duplicate values.
You can use extra memory, helper functions, and can modify the node struct but, you can’t add a parent pointer.
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
void helper(TreeNode* node, int num, vector<int> &path, vector<int> tmp)
{
    if(node==NULL)
    {
        return;
    }

    if(node->val==num)
    {
        tmp.push_back(node->val);
        path=tmp;
        return;
    }

    tmp.push_back(node->val);
    helper(node->left, num, path, tmp);
    helper(node->right, num, path, tmp);
}

int Solution::lca(TreeNode* A, int B, int C) {

    if(A==NULL)
    {
        return 0;
    }

    vector<int> anc_B;
    vector<int> anc_C;

    vector<int> tmp;
    helper(A, B, anc_B, tmp);
    helper(A, C, anc_C, tmp);

    if(anc_B.size()==0 || anc_C.size()==0)
    {
        return -1;
    }

    int ans=-1;
    for(int i=anc_B.size()-1; i>=0; i--)
    {
        for(int j=anc_C.size()-1; j>=0; j--)
        {
            if(anc_B[i]==anc_C[j])
            {
                ans = anc_B[i];
                return ans;
            }
        }
    }

    return ans;

}

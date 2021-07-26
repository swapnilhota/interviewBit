/*
Problem Description

Given a binary tree A consisting of N nodes, return a 2-D array denoting the vertical order traversal of A.

Go through the example and image for more details.

NOTE:

If 2 or more Tree Nodes shares the same vertical level then the one with earlier occurence in the pre-order traversal of tree comes first in the output.
Row 1 of the output array will be the nodes on leftmost vertical line similarly last row of the output array will be the nodes on the rightmost vertical line.


Problem Constraints
0 <= N <= 104



Input Format
First and only argument is an pointer to root of the binary tree A.



Output Format
Return a 2D array denoting the vertical order traversal of A.



Example Input
Input 1:

      6
    /   \
   3     7
  / \     \
 2   5     9
Input 2:

           1
         /   \
        2     3
       / \
      4   5


Example Output
Output 1:

 [
    [2],
    [3],
    [6, 5],
    [7],
    [9]
 ]
Output 2:

 [
    [4],
    [2],
    [1, 5],
    [3]
 ]
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
void getMinCol(TreeNode* A, int &minCol, int col)
{
    if(A==NULL)
    {
        return;
    }
    minCol = min(minCol, col);
    getMinCol(A->left, minCol, col-1);
    getMinCol(A->right, minCol, col+1);
}

void getMaxCol(TreeNode* A, int &maxCol, int col)
{
    if(A==NULL)
    {
        return;
    }
    maxCol = max(maxCol, col);
    getMaxCol(A->left, maxCol, col-1);
    getMaxCol(A->right, maxCol, col+1);
}

struct Item
{
    TreeNode* node;
    int col;
};

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {

    if(A==NULL)
    {
        vector<vector<int>> tmp;
        return tmp;
    }

    int minCol = INT_MAX;
    int maxCol = INT_MIN;

    getMinCol(A, minCol, 0);
    getMaxCol(A, maxCol, 0);

    Item curr;
    curr.node = A;
    curr.col = 0;

    map<int, vector<int>> mp;
    queue<Item> q;
    q.push(curr);

    while(!q.empty())
    {
        TreeNode* curr_node = q.front().node;
        int curr_col = q.front().col;
        q.pop();

        mp[curr_col].push_back(curr_node->val);

        if(curr_node->left)
        {
            Item left;
            left.node = curr_node->left;
            left.col = curr_col-1;
            q.push(left);
        }
        if(curr_node->right)
        {
            Item right;
            right.node = curr_node->right;
            right.col = curr_col+1;
            q.push(right);
        }
    }

    vector<vector<int>> ans;
    for(int i=minCol; i<=maxCol; i++)
    {
        ans.push_back(mp[i]);
    }

    return ans;

}

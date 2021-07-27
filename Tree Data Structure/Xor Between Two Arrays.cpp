/*
Problem Description

Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

Return this maximum xor value.



Problem Constraints
1 <= |A|, |B| <= 105

1 <= A[i], B[i] <= 109



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an integer denoting the maximum xor value as described in the question.



Example Input
Input 1:

 A = [1, 2, 3]
 B = [4, 1, 2]


Example Output
Output 1:

 7
*/

class trieNode 
{
    public:
    trieNode* left;
    trieNode* right;
};

void insert(trieNode* head, int n)
{
    trieNode* curr = head;
    for(int i=31; i>=0; i--)
    {
        int bit = (n>>i)&1;
        if(bit==0)
        {
            if(!curr->left)
            {
                curr->left = new trieNode();
            }
            curr=curr->left;
        }
        else
        {
            if(!curr->right)
            {
                curr->right = new trieNode();
            }
            curr=curr->right;
        }
    }
}

int findMaxXor(trieNode* head, vector<int> A)
{
    int max_xor=0;
    for(auto num: A)
    {
        trieNode* curr = head;
        int curr_xor=0;
        for(int i=31; i>=0; i--)
        {
            int bit = (num>>i)&1;
            if(bit==0)
            {
                if(curr->right)
                {
                    curr_xor += (int)pow(2, i);
                    curr=curr->right;
                }
                else
                {
                    curr=curr->left;
                }
            }
            else
            {
                if(curr->left)
                {
                    curr_xor += (int)pow(2, i);
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
        }
        max_xor = max(max_xor, curr_xor);
    }
    return max_xor;
}

int Solution::solve(vector<int> &A, vector<int> &B) {

    trieNode* head = new trieNode();
    for(auto num: B)
    {
        insert(head, num);
    }

    return findMaxXor(head, A);

}

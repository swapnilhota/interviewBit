/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return  list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.
*/

void build(int* tree, vector<int> &ans, int node, int start, int end)
{
    if(start==end)
    {
        if(ans[start]==0)
        {
            tree[node]=1;
        }
        return;
    }

    int mid = (end-start)/2+start;

    build(tree, ans, 2*node, start, mid);
    build(tree, ans, 2*node+1, mid+1, end);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int* tree, int node, int start, int end, int infront)
{
    if(start==end)
    {
        return start;
    }
    int mid = (end-start)/2+start;
    int left = tree[2*node];
    int right = tree[2*node+1];

    if(left>infront)
    {
        return query(tree, 2*node, start, mid, infront);
    }
    else
    {
        return query(tree, 2*node+1, mid+1, end, infront-left);
    }
}

void update(int* tree, vector<int> &ans, int node, int start, int end, int idx, int val)
{
    if(start==end)
    {
        ans[idx]=val;
        tree[node]=0;
        return;
    }

    int mid = (end-start)/2+start;

    if(idx<=mid)
    {
        update(tree, ans, 2*node, start, mid, idx, val);
    }
    else
    {
        update(tree, ans, 2*node+1, mid+1, end, idx, val);
    }

    tree[node] = tree[2*node]+tree[2*node+1];

}

vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    map<int, int> mp;
    for(int i=0; i<A.size(); i++)
    {
        mp[A[i]]=B[i];
    }

    sort(A.begin(), A.end());

    vector<int> ans(A.size(), 0);

    int* tree = new int[4*ans.size()];
    build(tree, ans, 1, 0, ans.size()-1);

    for(auto h: A)
    {
        int idx = query(tree, 1, 0, ans.size()-1, mp[h]);
        ans[idx] = h;
        update(tree, ans, 1, 0, ans.size()-1, idx, h);
    }

    return ans;
}

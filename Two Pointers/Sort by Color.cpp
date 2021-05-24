void merge(vector<int> &A, int left, int mid, int right)
{
    vector<int> l;
    vector<int> r;
    
    for(int i=left; i<=mid; i++)
    {
        l.push_back(A[i]);
    }
    for(int i=mid+1; i<=right; i++)
    {
        r.push_back(A[i]);
    }
    
    int x=left;
    int i=0;
    int j=0;
    while(i<l.size() && j<r.size())
    {
        if(l[i]<r[j])
        {
            A[x]=l[i];
            i++;
        }
        else
        {
            A[x]=r[j];
            j++;
        }
        x++;
    }
    
    while(i<l.size())
    {
        A[x]=l[i];
        i++;
        x++;
    }
    
    while(j<r.size())
    {
        A[x]=r[j];
        j++;
        x++;
    }
}

void mergeSort(vector<int> &A, int left, int right)
{
    if(left<right)
    {
        int mid = (right-left)/2+left;
        mergeSort(A, left, mid);
        mergeSort(A, mid+1, right);
        merge(A, left, mid, right);
    }
}

void Solution::sortColors(vector<int> &A) {
    mergeSort(A, 0, A.size()-1);
}

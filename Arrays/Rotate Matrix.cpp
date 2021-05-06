void Solution::rotate(vector<vector<int> > &A) {
    int n = A.size();

    int m_size = n;
    
    int flag=1;
    
    int i=0;
    
    while(m_size>1)
    {
        for(int j=0; j<m_size-1; j++)
        {
            int temp=A[i][j+i];
            //cout << temp << endl;
            if(flag==1)
            {
                int t = temp;
                temp = A[i+j][m_size-1+i];
                A[i+j][m_size-1+i] = t;
                //cout << t << endl;
                //cout << "ROW, COl = " << i+j << " " << m_size-1+i << endl;
                flag=2;
            }
            if(flag==2)
            {
                int t = temp;
                temp = A[m_size-1+i][m_size-1-j+i];
                A[m_size-1+i][m_size-1 - j+i]=t;
                //cout << t << endl;
                //cout << "ROW, COl = " << m_size-1+i << " " << m_size-1-j+i << endl;
                flag=3;
            }
            if(flag==3)
            {
                int t = temp;
                temp = A[m_size-1-j+i][i];
                A[m_size-1-j+i][i] = t;
                //cout << t << endl;
                //cout << "ROW, COl = " << m_size-1-j+i << " " << i << endl;
                flag=4;
            }
            if(flag==4)
            {
                int t = temp;
                temp = A[i][j+i];
                A[i][j+i] = t;
                //cout << t << endl;
                //cout << "ROW, COl = " << i << " " << j+i << endl;
                flag=1;
            }
        }
        i++;
        m_size -= 2;
    }
}

vector<string> Solution::fullJustify(vector<string> &A, int B) {
    
    vector<vector<string>> v;
    
    vector<string> tmp;

    int len = 0;
    
    for(int i=0; i<A.size(); i++)
    {
        string curr = A[i];
        if(len+curr.length()+1<=B)
        {
            tmp.push_back(curr);
            len += curr.length()+1;
        }
        else if(len+curr.length()==B)
        {
            tmp.push_back(curr);
            v.push_back(tmp);
            tmp.clear();
            len=0;
        }
        else
        {
            v.push_back(tmp);
            tmp.clear();
            len=0;
            tmp.push_back(curr);
            len += curr.length()+1;
        }
    }
    
    if(tmp.size()>0)
    {
        v.push_back(tmp);
    }
    
    vector<string> ans;
    
    for(int i=0; i<v.size(); i++)
    {
        vector<string> curr = v[i];
        int gaps = curr.size()-1;
        if(gaps==0)
        {
            string temp="";
            string s=curr[0];
            temp += s;
            while(temp.length()<B)
            {
                temp+=" ";
            }
            ans.push_back(temp);
        }
        else
        {
            if(i==v.size()-1)
            {
                string temp="";
                for(int j=0; j<curr.size()-1; j++)
                {
                    temp += curr[j];
                    temp += " ";
                }
                temp += curr[curr.size()-1];
                while(temp.length()<B)
                {
                    temp+=" ";
                }
                ans.push_back(temp);
                continue;
            }
            int g[gaps]={0};
            int white_cnt=0;
            int stringlen=0;
            
            for(int j=0; j<curr.size(); j++)
            {
                stringlen += curr[j].length();
            }
            
            white_cnt = B-stringlen;
            
            int k=0;
            
            while(white_cnt>0)
            {
                g[k]++;
                k=(k+1)%gaps;
                white_cnt--;
            }
            
            string temp="";
            
            for(int j=0; j<curr.size()-1; j++)
            {
                temp += curr[j];
                for(int k=0; k<g[j]; k++)
                {
                    temp += " ";
                }
            }
            
            temp += curr[curr.size()-1];
            
            ans.push_back(temp);
        }
    }
    
    return ans;
    
}

/*
Platform :- Leetcode
Approach :- Take care of last index of current character , first make vector of string of all words in second string and here take care of index of last strign,
         now for ith string if the last index is not equal to lasst index of current character then return false.
         else at the end return true.
*/
   string temp1 = "";
    string temp2 = "";
    
    int cnt = 1;
    map<char , int> m1;
    map<string , int> m2;
    
    for(int i=0 ; i<pattern.size() ; i++)
    {
        char ch = pattern[i];
        
        if(m1[ch]) temp1 += to_string(m1[ch]);
        else
        {
            temp1 += to_string(cnt);
            m1[ch] = cnt;
            cnt++;
        }
    }
    
    
    
    int i=0;
    int j=0;
    cnt = 1;
    
    for(; i<=s.size() ; i++)
    {
        if(i == s.size() || s[i] == ' ' )
        {
            string temp = s.substr(j , i-j);
            j = i+1;
            
            if(m2[temp]) temp2 += to_string(m2[temp]);
            else
            {
                temp2 += to_string(cnt);
                m2[temp] = cnt;
                cnt++;
            }
            
        }
    }
    
    
    if(temp1 == temp2) return true;
    else return false;
    
}
};

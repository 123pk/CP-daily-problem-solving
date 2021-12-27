/*
Platform :- Leetcode
Approach :- Find the binary string of given number and now find the complement and then compute the value of it .
*/
class Solution {
public:
    int findComplement(int num) {
        string temp = bitset<32>(num).to_string();
        //reverse(temp.begin(),temp.end());
        string z = "";
        int f=0;
        for(int i=0;i<32;++i){
            if(f)z+=temp[i];
            else{
                if(temp[i]=='1'){
                    f=1;
                    z+=temp[i];
                }
            }
        }
        
        for(auto &x:z){
            if(x=='0')x='1';
            else x='0';
        }
        
        int ans=0;
        
        reverse(z.begin(),z.end());
        for(int i=0;i<z.size();++i){
            if(z[i]=='1')ans+=(1<<i);
        }
        
        return ans;
    }
};

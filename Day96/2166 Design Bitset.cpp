/*
Platform :- Leetcode
Approach :- We use two string 's' and 't' where 't' is compleent of 's' , if s = 010 then 't' = 101 , in the beginning we will have 's' = 0000...n and 't' = 11111...n
            for each of the fix and unfix operation we do the changes in 's' and 't' accordingly,
            for 'flip' operation we swap ('s' and 't'), and we also maintian no of set bits in 's' and change in fix and unfix opearting accordingly .
            In 'flip' operation we change the count to ( n - count ) . 
*/
class Bitset {
public:
    string s,t;
    int n,c=0,f=0;
    Bitset(int size) {
        for(int i=0;i<size;++i){
            s+='0';
            t+='1';
        }
        n = size;
    }
    
    void fix(int idx) {
        if(s[idx]=='0'){
            s[idx] = '1';
            t[idx] = '0';
            c++;
        }
    }
    
    void unfix(int idx) {
        if(s[idx]=='1'){
            s[idx] = '0';
            c--;
            t[idx] = '1';
        }
    }
    
    void flip() {
            swap(s,t);
            c = n-c;
        
    }
    
    bool all() {
        return c==n;
    }
    
    bool one() {
        return c;
    }
    
    int count() {
        return c;
    }
    
    string toString() {
         
        return s;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */

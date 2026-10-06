class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if( s[i]=='['||s[i]=='{'||s[i]=='('){   // opening case
                st.push(s[i]);  
            }
            else{                                   // closing case
                if(st.empty()==1){                    //case for close brackets more
                    return false;    
                }
                if((s[i]=='}'&& st.top()=='{')||(s[i]==']'&& st.top()=='[')||(s[i]==')'&& st.top()=='(')){
                    st.pop();
                }
                else{
                    return false;
                }
            }

        }
        if(st.empty()==1){
            return true;
        }
        return false;
        
    }
};
class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2 != 0) return false;
        stack <char> S1;
        for(char p: s){
            if(p == '{' || p == '[' || p == '('){
                S1.push(p);
            }
            else{
                if(S1.empty()) return false;
                char c = S1.top();
                if(c == '(' && p == ')'){
                    S1.pop();
                }
                else if(c == '{' && p == '}'){
                    S1.pop();
                }
                else if(c == '[' && p == ']'){
                    S1.pop();
                }
                else return false;
            }
        }
        return S1.empty();
    }
};

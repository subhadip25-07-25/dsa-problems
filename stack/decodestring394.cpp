class Solution {
public:
    string helper(string& s, stack<int>& numberst, stack<string>& strstack) {
        int num = 0;
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            // check if its a digit or not ;
            if (isdigit(s[i])) { // s[i] a digit
                num = num * 10 + (s[i] - '0');
                numberst.push(num);
            }

            // we doing pushing until we get a ]
            if (s[i] == ']') {
                string temp = "";
                // if we find it we do pop untill we get a [
                while (!strstack.empty() && strstack.top() != '[') {
                    temp += strstack.top();
                    strstack.pop();
                }
                strstack.pop(); // we deelete [
                          // we get a temp stack now we have to reperat it
                int val = numberst.top();
                numberst.pop();
                // repetation
                while (val--) {
                    ans += temp;
                }
                 strstack.push(ans);
            }
            // push it in stack ans
          else{
            // if we encounter anything else push it 
            strstack.push(s[i]);}
        }
        return strstack.top();
    }
    string decodeString(string s) {
        stack<int> numberst;
        stack<int> strstck;
        return helper(s,numberst, strstack);
    }
};
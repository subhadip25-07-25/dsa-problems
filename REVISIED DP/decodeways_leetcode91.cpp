#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dp;
    int string_to_int(string str) {
        if (str.size() == 1) {
            return str[0] - '0';
        }
        if (str.size() == 2) {
            return (str[0] - '0') * 10 + (str[1] - '0');
        }
        return 0;
    }

    int decodeways(string str, int i) {
        if (i >= str.size())
            return 0;
        // if string is 06 output - 0;
        if (str[i] == '0')
            return 0;
        // if i = last index
        if (i == str.size() - 1) {
            // if last index is 0 so 0 else 1 - 9 return 1
            if (str[i] == '0')
                return 0;
            else {
                return 1;
            }
        }
        // if string has 2 length , idx

        if (i == str.size() - 2) {
            bool can_from = string_to_int(str.substr(i, 2)) <= 26;
            if (can_from) {
                return 1 + decodeways(str, i + 1);
            }
        }
        if (dp[i] != -1)
            return dp[i];
        bool can_from = string_to_int(str.substr(i, 2)) <= 26;
        return dp[i] = decodeways(str, i + 1) +
                       ((can_from) ? decodeways(str, i + 2) : 0);
    }
    int decodeways_tbu(string& s) {
        int n = s.size();

        // if string has 1 lenght
        dp.resize(n + 5, 0);

        // handle last character
        dp[n - 1] = (s[n - 1] != '0') ? 1 : 0;
        // string has 2 char
           bool can_from = string_to_int(s.substr(n-2, 2)) <= 26;
        if(s[n-2]=='0'){
              dp[n-2]=0;
        }else{
            dp[n-2]=dp[n-1]+(can_from);
        }

        
        for (int i = n - 3; i >= 0; i--) {
            bool can_from = string_to_int(s.substr(i, 2)) <= 26;
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i + 1] + ((can_from) ? dp[i + 2] : 0);
        }
        return dp[0];
    }
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
            if(s.size()==1){
                if(s[0]=='0')return 0;
                else{
                    return 1;
                }
            }
        return decodeways_tbu(s);
    }
};
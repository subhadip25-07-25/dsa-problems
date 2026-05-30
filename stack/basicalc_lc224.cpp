#include <bits/stdc++.h>
using namespace std;


#define ll long long int

class Solution {
public:
    ll calc(ll v1, ll v2, char op) {
        if (op == '+') {
            return v1 + v2;
        }
        if (op == '-') {
            return v1 - v2;
        }
        if (op == '*') {
            return v1 * v2;
        }
        if (op == '/') {
            return v1 / v2;
        }
        return 0;
    }

    int presedency(char op) {
        if (op == '*' || op == '/')
            return 3;
        else if (op == '+' || op == '-')
            return 2;
        
        else {
            return -1;
        }
    }

    // evalute infix expression
    ll helper(string& s, stack<ll>& nums, stack<char>& opt) {
        for (int i = 0; i < s.size(); i++) {
            // if gap present
            if (s[i] == ' ')
                continue;

            // if digit also more than single digit
            if (isdigit(s[i])) {
                ll num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--; // cus i gores 1 step beyond when loop closed 12+3 i = +;
                nums.push(num);
            } else if (s[i] == '(') {
                opt.push(s[i]);
            } else if (s[i] == ')') {
                while (!opt.empty() && opt.top() != '(') {
                    char sign = opt.top();
                    opt.pop();
                    ll v2 = nums.top();
                    nums.pop();
                    ll v1 = nums.top();
                    nums.pop();
                    ll newele = calc(v1, v2, sign);
                    nums.push(newele);
                }
                opt.pop() ;// poping (
            } else {
                //"1-(     -2)" input like this 
                int j = i-1;
                while( j >=0 && s[j] == ' ')j--;// when we get something valid 
                if( s[i] =='+' || s[i]=='-')//only + and - uniary cuz probmlem
                {
                    if(j<0 || s[j] =='(' || s[j] == '+'|| s[j]=='-'|| s[j]=='*' || s[j]=='/' ){
                        nums.push(0);//why 0 0 make 0-2 = -2
                    }
                }
                // in case og no ()
                while (!opt.empty() && presedency(opt.top()) >= presedency(s[i]))
                // it precedy high we have to calu it first then push the opt
                {
                    char sign = opt.top();
                    opt.pop();
                    ll v2 = nums.top();
                    nums.pop();
                    ll v1 = nums.top();
                    nums.pop();
                    ll newele = calc(v1, v2, sign);
                    nums.push(newele);
                }
                opt.push(s[i]);
            }
            // if there is anything left
        }

        while (!opt.empty()) {
            char sign = opt.top();
            opt.pop();
            ll v2 = nums.top();
            nums.pop();
            ll v1 = nums.top();
            nums.pop();
            ll newele = calc(v1, v2, sign);
            nums.push(newele);
        }

        return nums.top();
    }

    int calculate(string s) {
        stack<ll> nums;
        stack<char> opt;
        return (int)helper(s, nums,opt);
    }
};
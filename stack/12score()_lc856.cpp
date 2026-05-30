#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);
        for (char c : s)
        {
            if (c == '(')
            {
                st.push(0);
            }
            else
            {
                int val;
                int curr = st.top();
                st.pop();
                if (curr == 0)
                {
                    val = curr + 1;
                }
                else
                {
                    val = 2 * curr;
                }

                st.top() += val;
            }
        }
        return st.top();
    }
};
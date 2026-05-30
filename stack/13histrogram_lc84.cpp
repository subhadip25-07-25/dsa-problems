#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxsize(vector<int>& v, stack<int>& st) {
        int ans = 0;
        // we need to get nse and prevsmaller ele to get the range
        for (int i = 0; i < v.size(); i++) {
            while (!st.empty() && v[i] < v[st.top()]) {
                int nse = i;
                int pse;
                int ele = v[st.top()];
                st.pop();
                if (st.empty()) {
                    pse = -1;
                } else {
                  pse = st.top();
                }
                ans = max(ans, ele * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
          int  nse = v.size();
            int ele = v[st.top()];
            st.pop();
            int pse ;
            if (st.empty()) {
                 pse = -1;
            } else {
              pse = st.top();
            }
            ans = max(ans, ele * (nse - pse - 1));
        }
        return ans ;
    }
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        return maxsize(heights, st);
    }
};
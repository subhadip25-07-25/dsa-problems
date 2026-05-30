#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxrec(vector<int>& v) {
        int ans = 0;
        stack<int>st;
        for (int i = 0; i < v.size(); i++) {
            int nse = 0;
            int pse = 0;
            while (!st.empty() && v[i] < v[st.top()]) {
                nse = i;
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
                int nse = v.size();
                int pse = 0;
                int ele = v[st.top()];
                st.pop();
                if (st.empty()) {
                    pse = -1;
                } else {
                    pse = st.top();
                }
                ans = max(ans, ele * (nse - pse - 1));
            }
        return ans ;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        stack<int>st;
        int maxrecsize = 0 ;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> prefix(col, 0);
        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {
                if (matrix[i][j] =='0') {
                    prefix[j] = 0;
                } else {
                    prefix[j] += 1;
                }
            }
           maxrecsize= max(maxrecsize, maxrec(prefix));
        }
        return maxrecsize;
    }
};
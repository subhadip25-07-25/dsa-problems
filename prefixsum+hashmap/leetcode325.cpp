// longest sub array = k , premium in leetcode so in geeksforgeeks
#include <bits/stdc++.h>    
using namespace std;
 int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int max_len = INT_MIN;
        int len = 0 ;
        int prefix = 0 ;
        unordered_map<int, int>mp;
        mp[0]= -1;
        
        for(int i = 0 ; i<n; i++ ){
            prefix +=arr[i];
            int val = prefix -k ;
            if(mp.find(val)!= mp.end()){
                max_len = max(max_len, i - mp[val]);
            }
            if(mp.find(prefix) == mp.end()) {// 2  0 0 3
    mp[prefix] = i;
}
        }
        return( max_len<0)?0:max_len;
    }
int main(){
    vector<int> nums = {-5, 8, -14, 2, 4, 12};
    int k = -5 ;
    cout<<longestSubarray(nums,k);
    return 0;
}
/*When same prefix sum appears again:

length=i−first_index

👉 Earlier index = bigger length*/
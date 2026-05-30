#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class MinStack {
public:
    stack<ll>st;
    ll minval = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
         if( st.empty()){
            st.push(val);
            minval = val;
         }else{
            st.push(val - minval);
            if( val < minval){
                minval = val;
            }
         }
    }
    
    void pop() {
          if( !st.empty()){
            if( st.top()>=0 ){
                st.pop();
            }else{
                minval = minval - st.top();
                st.pop();
            }
          }
    }
    
    int top() {
        if( st.size()==1)return st.top();
        else if( st.top() < 0){
            return minval;
        }else{
             return minval +st.top();
        }
    }
    
    int getMin() {
        return minval;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
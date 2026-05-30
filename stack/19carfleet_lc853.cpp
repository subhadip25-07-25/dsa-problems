#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // comparator function
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.first > b.first; // sort by position descending
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < speed.size(); i++) {
            v.push_back({position[i], speed[i]});
        }
        // we need sorting based on pos cuz we need closet to farest to decide impact
        sort(v.begin(), v.end(), cmp);// asending order 3, 3| 5, 2| 7,1 
        // in sort we check first, if first same check second 
        // use of cmp make it desencding 
        int fleet = 0;
        double prevtime = 0 ;
        for( auto &ele :v){
                double currtime = (double)(target - ele.first) / ele.second;
                if (currtime > prevtime) {
                    // currcar take more time then previous so new fleet
                    fleet++;
                    prevtime = currtime;
                }
                // else merge no new fleet
        }
        return fleet;
    };
 };
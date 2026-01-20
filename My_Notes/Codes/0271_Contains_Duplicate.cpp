#include<iostream>
#include<vector>    
#include<unordered_set>
#include<map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> seen;
        for(auto p=nums.begin();p!=nums.end();p++){
            if(seen.find(*p)!=seen.end()){
                return true;
            }
            seen.insert(*p);
        }
        return false;
    }
};


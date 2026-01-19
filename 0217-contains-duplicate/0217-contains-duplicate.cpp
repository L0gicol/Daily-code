class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,int> v;
        for(auto p=nums.begin();p!=nums.end();p++){
            if(v[*p]==1){
                return true;
            }
            v[*p]=1;
        }
        return false;
    }
};

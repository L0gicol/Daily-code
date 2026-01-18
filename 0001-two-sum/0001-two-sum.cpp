class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp=target-nums[i];
            if(map.find(temp)!=map.end()){
                return{map[temp],i};
            }    
            map[nums[i]]=i;
        }
        return{};
    }
};
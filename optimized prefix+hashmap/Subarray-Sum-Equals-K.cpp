class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        unordered_map<int,int> um;
        um[0]=1;
        int x=0;
        for(int num:nums){
            x+=num;
            int y=x-k;
            if(um.find(y)!=um.end()){
                count+=(um[y]);
            }
            um[x]++;
        }
        
        return count;
        
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int, int> um;
        int pre=0;
        um[0]=1;
        int ans=0;
        for(int num:nums){
            pre+=num;
            int rem=(pre%k+k)%k;
            if(um.find(rem)!=um.end()){
                ans+=um[rem];
            }
            um[rem]++;
        }
        return ans;
    }
};
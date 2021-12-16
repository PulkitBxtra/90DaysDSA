class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<int> v;
        
        int n=nums.size();
        if(n==0 || n<3)
            return {};
        
         set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]+nums[j]+nums[k]==0 && i!=j && i!=k && j!=k){
                      s.insert({nums[i],nums[j],nums[k]});
                        
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(),s.end());
         return ans;
    }
};

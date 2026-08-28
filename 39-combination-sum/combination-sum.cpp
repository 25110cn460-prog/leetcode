class Solution {
public:
    void call(vector<int>nums,int tar,int index,vector<int>&box,vector<vector<int>>&ans){
        int n=nums.size();
        if(tar==0){
            ans.push_back(box);
            return;
        }
        if(tar<0){
            return ;
        }
        for(int j=index;j<n;j++){
            box.push_back(nums[j]);
            tar=tar-nums[j];
            call(nums,tar,j,box,ans);
            box.pop_back();
            tar=tar+nums[j];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>box;
        call(candidates,target,0,box,ans);
        return ans;
        
    }
};
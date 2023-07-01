class Solution {
public:
    
    void helper(vector<int> &cookies,int i, vector<int> &subsets, int &ans){
        if(i >= cookies.size()){
            int maxSum = 0;
            for(int j=0;j<subsets.size();j++){
                maxSum = max(maxSum , subsets[j]);
            }
            ans = min(maxSum, ans);
            return ;
        }
        
        
        for(int j=0;j< subsets.size();j++){
            subsets[j] += cookies[i];
            helper(cookies, i+1,subsets, ans);
            subsets[j] -= cookies[i];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> subsets(k, 0);
        helper(cookies, 0, subsets, ans);
        return ans;
    }
};
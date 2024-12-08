class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int 0;i<nums.length();i++)
        //     mp[i]=nums[i];
        int n=nums.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                res[i]=nums[i];
            else if(nums[i]>0){
                int ind=(i+nums[i])%n;
                res[i]=nums[ind];
            }
            else{
                int neg=abs(nums[i])%n;
                int ind=(i-neg+n)%n;
                cout<<ind<<endl;
                res[i]=nums[ind];
            }
        }
        return res;
    }
};
class Solution {
public:
bool isValid(vector<int>&v,int m,int days){
    int n=v.size();
    int cnt=0,i=0,sum=0;
    while(i<n){
        sum+=v[i];
        if(v[i]>m)return false; //GOOD BASE CASE
        if(sum>m){
            cnt++;
            sum=v[i];
        }
        i++;
    }
    cnt++;
    return cnt<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int s=*min_element(weights.begin(),weights.end());
        int e=accumulate(weights.begin(),weights.end(),0);
        int ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            cout<<m<<endl;
            if(isValid(weights,m,days)){
                ans=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        return ans;
    }
};
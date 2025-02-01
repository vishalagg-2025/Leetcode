class Solution {
public:
bool isValid(vector<int>&piles,int k,int h){
    long long ans=0;
    for(int i=0;i<piles.size();i++){
        ans+=piles[i]/k;
        if(piles[i]%k)
        ans++;
    }
    return ans<=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=*max_element(piles.begin(),piles.end());
        int s=1,e=maxi,ans;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isValid(piles,m,h)){
                ans=m;
                e=m-1;
            }
            else
            s=m+1;
        }
        return ans;
    }
};
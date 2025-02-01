class Solution {
public:
bool isValid(vector<int>&v,int mid,int m,int k){
    int n=v.size();
    int curr=0,i=0,cnt=0;
    while(i<n){
      if(v[i]<=mid)
      curr++;
      else
      curr=0;
      if(curr==k){
        cnt++;
        curr=0;
      }
      i++;
    }
    return cnt>=m;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(m>n||k>n||m*k>n)return -1;
       // if(pro>n)return -1;

        int s=*min_element(bloomDay.begin(),bloomDay.end());
        int e=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            cout<<mid<<endl;
            if(isValid(bloomDay,mid,m,k)){
                ans=mid;
                e=mid-1;
            }
            else
            s=mid+1;
        }
        return ans;
    }
};
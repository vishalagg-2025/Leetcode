class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n=damage.size();
        vector<int>time(n);

        for(int i=0;i<n;i++){
            int t=health[i]/power;
            if(health[i]%power)
                t++;
            time[i]=t;
        }
        vector<pair<double,int>>vp;
        long long sum=0;
        for(int i=0;i<n;i++){
            vp.push_back({(double)damage[i]/time[i],i});
            sum+=damage[i];
        }
        // for(aut)

        sort(vp.begin(),vp.end());

        long long ans=0;
        for(int i=n-1;i>=0;i--){
            int ind=vp[i].second;
            int temp_time=time[ind];
            int temp_value=damage[ind];
            ans+=temp_time*sum;
            sum-=temp_value;
        }
        return ans;
        
        
        
    }
};
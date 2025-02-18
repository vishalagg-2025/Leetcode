class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(int i=0;i<words.size();i++)
         mp[words[i]]++;

         int ans=0,flag=0;
         for(int i=0;i<words.size();i++){
            

            if(words[i][0]!=words[i][1]){
                string temp="";
            temp+=words[i][1];
            temp+=words[i][0];
                if(mp[words[i]]&&mp[temp]){
                    ans+=4;
                    mp[words[i]]--;
                    mp[temp]--;
                }

            }
            else{
                if(mp[words[i]]>=2){
                mp[words[i]]-=2;
                ans+=4;
                }
                else if(mp[words[i]]==1)
                flag=1;
            }
         }
         if(flag==1)
         ans+=2;

         return ans;
    }
};
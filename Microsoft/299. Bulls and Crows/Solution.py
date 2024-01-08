class Solution {
public:
    string getHint(string s, string g) {
        unordered_map<char,int>mp;
        for(int i=0;i<g.size();i++){
            mp[g[i]]++;
        }
        string temp="";
        int bull=0;
        //Aditya Seth.
        unordered_set<int>v;
        for(int i=0;i<s.size();i++){
            if(s[i]==g[i]){
                v.insert(i);
                mp[s[i]]--;
                if(mp[s[i]]<=0){
                    mp.erase(s[i]);
                }
              bull++;
            }
        }
        if(v.size()){
          for(int i=0;i<s.size();i++){
              if(v.find(i)!=v.end()){
                  continue;
              }
              temp+=s[i];
          }
        }
        else{
            temp=s;
        }
        int cow=0;
        for(auto it:temp){
            if(mp.find(it)!=mp.end()){
                mp[it]--;
                if(mp[it]<=0){
                    mp.erase(it);
                }
                cow++;
            }
        }
        string ans="";
        ans=to_string(bull)+'A'+to_string(cow)+'B';
        return ans;
    }
};
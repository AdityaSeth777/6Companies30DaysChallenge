class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> v(256);
        for(int i=0;i<256;i++) v[i] = {0,0};
        for(int i=0;i<s.size();i++){
            v[s[i]].first++;
            v[s[i]].second = s[i];
        }
        //Aditya Seth.
        sort(v.begin(), v.end());
        string ans = "";
       for(int i=255;i>=0;i--){
           if(v[i].first==0) break;
           int freq = v[i].first;
           char ch = v[i].second;
           for(int i=0;i<freq;i++) ans += ch;
       }
        return ans;
    }
};
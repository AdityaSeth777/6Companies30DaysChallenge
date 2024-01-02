class Solution {
public:
    int countDistinct(vector<int>& a, int k, int p) {
        int n = a.size(), ans = 0;
        unordered_set<string>s;
        for(int i=0;i<n;i++){
          int cnt = 0;
          //Aditya Seth.
          string temp = "";
          for(int j = i; j < n; j++){
            if(a[j]%p == 0) cnt++;
             if(cnt <= k) { temp += a[j]; s.insert(temp);}
             if(cnt>k)break;
          }
        }
        return s.size();
    }
};
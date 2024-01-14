bool check(int k, string &s1, string &s2){
    set<string>s;
    for(int i = 0; i <= s1.size()-k; ++i){
        s.insert(s1.substr(i,k));
    }
    for(int i = 0; i <= s2.size()-k; ++i){
        if( s.find(s2.substr(i,k)) != s.end() ) return true;
    }
    return false;
}
class Solution {
public:
    int findLength(vector<int>& n1 , vector<int>& n2) {
        string s1,s2;
        for(int i = 0; i < n1.size(); ++i){
            s1.push_back(n1[i] + '0');
        }
        for(int i = 0; i < n2.size(); ++i){
            s2.push_back(n2[i] + '0');
        }
        int l = -1, r = min(n1.size(),n2.size()) + 1;
        //Aditya Seth.
        while(r - l > 1){
            int mid = (l+r)/2;
            if(check(mid, s1, s2)) l = mid;
            else r = mid;
        }
        return l;
    }
};
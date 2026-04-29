class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1,mp2;
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++)
        {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        bool res=true;
        for(int i=0;i<s.size();i++)
        {
            if(mp1[s[i]]!=mp2[s[i]])
            {
                res=false;
                break;
            }
        }
        return res;
    }
};

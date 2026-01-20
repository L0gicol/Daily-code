#include<iostream>
#include<cstring>
#include<set>
#include<algorithm>

using namespace std;

class Solution{
public:
     bool isAnagram_sort(string s, string t) {
        if (s.length() != t.length()) return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
     }
     bool isAnagram_array(string s, string t) {
        if (s.length() != t.length()) return false;
        int count[26]={0};
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }   
        }
        return true;
     }
};
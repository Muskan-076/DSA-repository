class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int i =0;
        string ans;

        while(i<n){
            while(i<n && s[i] == ' ')
                i++;
                
            if(i >= n) break;

            int j =i;
            while( j<n && s[j] != ' ') j++;

            reverse(s.begin() + i, s.begin()+j);

            if(!ans.empty())
                ans += " ";

            ans += s.substr(i, j -i);

            i = j;
        }
        return ans;
    }
};
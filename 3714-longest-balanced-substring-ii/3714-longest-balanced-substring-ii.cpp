class Solution {
public:
    
    int helper(string &s, char ch1, char ch2){
        int n = s.size();
        unordered_map<int, int> diffmap;
        
        int count1 = 0, count2 = 0;
        int maxl = 0;
        
        diffmap[0] = -1;   // IMPORTANT
        
        for(int i = 0; i < n; i++){
            
            if(s[i] != ch1 && s[i] != ch2){
                // reset segment
                diffmap.clear();
                diffmap[0] = i;   // restart from next index
                count1 = 0;
                count2 = 0;
                continue;
            }

            if(s[i] == ch1) count1++;
            else count2++;

            int diff = count1 - count2;

            if(diffmap.count(diff)){
                maxl = max(maxl, i - diffmap[diff]);
            }
            else{
                diffmap[diff] = i;
            }
        }
        return maxl;
    }
    
    
    int longestBalanced(string s) {
        int n = s.size();
        int maxl = 1;  // single char always balanced
        
        // --------------------------
        // 1-character case
        // --------------------------
        int count = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) count++;
            else{
                maxl = max(maxl, count);
                count = 1;
            }
        }
        maxl = max(maxl, count);

        // --------------------------
        // 2-character cases
        // --------------------------
        maxl = max(maxl, helper(s, 'a','b'));
        maxl = max(maxl, helper(s, 'a','c'));
        maxl = max(maxl, helper(s, 'b','c'));

        // --------------------------
        // 3-character case
        // --------------------------
        int counta = 0, countb = 0, countc = 0;
        unordered_map<string, int> diffmap;
        
        diffmap["0_0"] = -1;   // IMPORTANT
        
        for(int i = 0; i < n; i++){
            if(s[i] == 'a') counta++;
            else if(s[i] == 'b') countb++;
            else countc++;

            int diffab = counta - countb;
            int diffac = counta - countc;

            string key = to_string(diffab) + "_" + to_string(diffac);

            if(diffmap.count(key)){
                maxl = max(maxl, i - diffmap[key]);
            }
            else{
                diffmap[key] = i;
            }
        }

        return maxl;
    }
};


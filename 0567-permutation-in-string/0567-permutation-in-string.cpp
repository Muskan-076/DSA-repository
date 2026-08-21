class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26,0);

        for(char c: s1){
            freq1[c -'a']++;
        }

        int windowSize = s1.size();

        for(int i =0; i< windowSize; i++){
            freq2[s2[i] - 'a']++;
        }
        if(freq1 == freq2) return true;

        for(int i = windowSize; i <s2.size(); i++){
            freq2[s2[i] - 'a']++;

            freq2[s2[i -windowSize] - 'a']--;

            if(freq1 == freq2) return true;
        }
        return false;
        //creating all permutation of s1

        // this is generating substring not permutation
        // for(int i =0; i < s1.size(); i++){
        //     for(int j= i+1; j< s1.size(); j++){
        //         string s;
        //         for(int k =i; k<= j; k++){
        //             s.push_back(s1[k]);
        //         }
        //         
        //     }
        // }

        
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        // tc=o(n), sc=o(1);
        int left =0;
        int right = s.size() -1;

        while(left < right){

            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            left++;
            right--;
        }

        return true;


        // tc= o(n), sc=o(n) due to removedstr

        // string removedstr;
        // for(int i =0; i< s.length(); i++){
        //     if(isalnum(s[i])){
        //         removedstr.push_back(tolower(s[i]));
        //     }
        // }
        // int strt = 0;
        // int end = removedstr.length()-1;

        // while(strt <= end){
        //     if(removedstr[strt] != removedstr[end]){
        //         return false;
        //     }
        //     strt++;
        //     end--;
        // }
        // return true;      
    }
};
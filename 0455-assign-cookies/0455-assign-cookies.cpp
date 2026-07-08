class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort(g.begin(), g.end());
        // sort(s.begin(), s.end());
        
        // int cnt = 0;
        // int k = 0;
        

        // for (int i =0; i< g.size(); i++){
            
        //     for(int j = k ; j< s.size(); j++){
        //         if(g[i] <= s[j]){
        //             cnt++;
        //             k = j+1;
        //             break;
        //         }  
        //     }   
        // }
        // return cnt;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); 

         int i= 0, j=0;
         int cnt =0;

         while(i < g.size() && j <s.size()){
            if(g[i] <= s[j]){
                cnt++;
                i++;
                j++;
            }
            else{
                j++;
            }
         }

         return cnt;

    }
};
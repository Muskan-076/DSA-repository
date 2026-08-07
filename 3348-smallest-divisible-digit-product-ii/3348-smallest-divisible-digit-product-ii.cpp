class Solution {
public:

    //optimal solution
   
    
    long long a, b, c, d; // needed exponents of 2,3,5,7

    array<int,4> contrib(int dch) {
        switch(dch) {
            case 1: return {0,0,0,0};
            case 2: return {1,0,0,0};
            case 3: return {0,1,0,0};
            case 4: return {2,0,0,0};
            case 5: return {0,0,1,0};
            case 6: return {1,1,0,0};
            case 7: return {0,0,0,1};
            case 8: return {3,0,0,0};
            case 9: return {0,2,0,0};
        }
        return {0,0,0,0};
    }

    vector<vector<int>> dp2; // dp2[x][y] = min digits to reach e2>=x, e3>=y

    int minDig(long long a2, long long b2, long long c2, long long d2) {
        if (a2 > a) a2 = a;
        if (b2 > b) b2 = b;
        return dp2[a2][b2] + (int)c2 + (int)d2;
    }

    string build(long long ra, long long rb, long long rc, long long rd, long long k) {
        string out;
        out.reserve(k);
        for (long long pos = 0; pos < k; pos++) {
            for (int dch = 1; dch <= 9; dch++) {
                auto e = contrib(dch);
                long long na = ra > e[0] ? ra - e[0] : 0;
                long long nb = rb > e[1] ? rb - e[1] : 0;
                long long nc = rc > e[2] ? rc - e[2] : 0;
                long long nd = rd > e[3] ? rd - e[3] : 0;
                if (minDig(na, nb, nc, nd) <= (int)(k - pos - 1)) {
                    out.push_back('0' + dch);
                    ra = na; rb = nb; rc = nc; rd = nd;
                    break;
                }
            }
        }
        return out;
    }

    string smallestNumber(string num, long long t) {
        long long tt = t;
        a = b = c = d = 0;
        while (tt % 2 == 0) { tt /= 2; a++; }
        while (tt % 3 == 0) { tt /= 3; b++; }
        while (tt % 5 == 0) { tt /= 5; c++; }
        while (tt % 7 == 0) { tt /= 7; d++; }
        if (tt != 1) return "-1";

        dp2.assign(a + 1, vector<int>(b + 1, 0));
        vector<pair<int,int>> pairs = {{1,0},{0,1},{2,0},{1,1},{3,0},{0,2}};
        const int INF = INT_MAX / 2;
        for (long long x = 0; x <= a; x++) {
            for (long long y = 0; y <= b; y++) {
                if (x == 0 && y == 0) continue;
                int best = INF;
                for (auto &pr : pairs) {
                    long long nx = x > pr.first ? x - pr.first : 0;
                    long long ny = y > pr.second ? y - pr.second : 0;
                    if (nx == x && ny == y) continue; // *** BUG FIX: skip no-progress transitions ***
                    int v = 1 + dp2[nx][ny];
                    if (v < best) best = v;
                }
                dp2[x][y] = best;
            }
        }

        int L = (int)num.size();
        int Z = L;
        for (int i = 0; i < L; i++) if (num[i] == '0') { Z = i; break; }

        vector<long long> pe2(Z + 1, 0), pe3(Z + 1, 0), pe5(Z + 1, 0), pe7(Z + 1, 0);
        for (int i = 1; i <= Z; i++) {
            auto e = contrib(num[i-1] - '0');
            pe2[i] = min((long long)a, pe2[i-1] + e[0]);
            pe3[i] = min((long long)b, pe3[i-1] + e[1]);
            pe5[i] = min((long long)c, pe5[i-1] + e[2]);
            pe7[i] = min((long long)d, pe7[i-1] + e[3]);
        }

        if (Z == L && pe2[L] == a && pe3[L] == b && pe5[L] == c && pe7[L] == d) {
            return num;
        }

        int i_max = min(Z, L - 1);
        int foundI = -1, foundD = -1;
        long long fa = 0, fb = 0, fc = 0, fd = 0;

        for (int i = i_max; i >= 0; i--) {
            long long la = a - pe2[i], lb = b - pe3[i], lc = c - pe5[i], ld = d - pe7[i];
            int suffixLen = L - 1 - i;
            for (int dch = (num[i] - '0') + 1; dch <= 9; dch++) {
                auto e = contrib(dch);
                long long na = la > e[0] ? la - e[0] : 0;
                long long nb = lb > e[1] ? lb - e[1] : 0;
                long long nc = lc > e[2] ? lc - e[2] : 0;
                long long nd = ld > e[3] ? ld - e[3] : 0;
                if (minDig(na, nb, nc, nd) <= suffixLen) {
                    foundI = i; foundD = dch; fa = na; fb = nb; fc = nc; fd = nd;
                    break;
                }
            }
            if (foundI != -1) break;
        }

        if (foundI != -1) {
            string prefix = num.substr(0, foundI);
            return prefix + char('0' + foundD) + build(fa, fb, fc, fd, L - 1 - foundI);
        } else {
            int M = minDig(a, b, c, d);
            long long newLen = max((long long)(L + 1), (long long)M);
            return build(a, b, c, d, newLen);
        }
    }



    // brute force soln


    // void addOne(string &num){
    //     int i = num.size()-1;

    //     while(i>=0 && num[i] == '9'){
    //         num[i]= '0';
    //         i--;
    //     }
    //     if(i>=0){
    //         num[i]++; // because in string 1 is added to the ASCII value of the string ch
    //     }
    //     else{
    //         num = '1' + num;
    //     }
    // }

    // bool isZeroFree(string &num){
    //     for(char ch: num){
    //         if(ch == '0')
    //             return false;
    //     }
    //     return true;
    // }

    // bool check(string &num, long long t){
    //     long long prod =1;

    //     for(char ch: num){
    //         int digit = ch -'0';

    //         if(prod > t)
    //             prod %= t;

    //         prod = (prod * digit) % t;
    //     }
    //     return prod % t == 0;
    // }
    // string smallestNumber(string num, long long t) {
    //     while(true){
            
    //         if (isZeroFree(num) && check(num, t))
    //             return num;
            
    //         addOne(num);
    //     }
    // }
};
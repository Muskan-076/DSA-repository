class Solution {
public:
    long long getMinFinish(vector<int>& start, vector<int>& dur, long long T) {
        int n = start.size();

        vector<pair<int,int>> rides;
        for(int i = 0; i < n; i++)
            rides.push_back({start[i], dur[i]});

        sort(rides.begin(), rides.end());

        vector<long long> pref(n), suff(n);

        // prefix minimum duration
        pref[0] = rides[0].second;
        for(int i = 1; i < n; i++)
            pref[i] = min(pref[i-1], (long long)rides[i].second);

        // suffix minimum of (start + duration)
        suff[n-1] = (long long)rides[n-1].first + rides[n-1].second;
        for(int i = n-2; i >= 0; i--)
            suff[i] = min(suff[i+1],
                         (long long)rides[i].first + rides[i].second);

        int idx = upper_bound(
            rides.begin(),
            rides.end(),
            make_pair((int)T, INT_MAX)
        ) - rides.begin() - 1;

        long long ans = LLONG_MAX;

        // already open rides
        if(idx >= 0)
            ans = min(ans, T + pref[idx]);

        // future rides
        if(idx + 1 < n)
            ans = min(ans, suff[idx + 1]);

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        long long ans = LLONG_MAX;

        // Prepare sorted water rides once
        vector<pair<int,int>> water;
        for(int i = 0; i < waterStartTime.size(); i++)
            water.push_back({waterStartTime[i], waterDuration[i]});
        sort(water.begin(), water.end());

        int m = water.size();
        vector<long long> wpref(m), wsuff(m);

        wpref[0] = water[0].second;
        for(int i = 1; i < m; i++)
            wpref[i] = min(wpref[i-1], (long long)water[i].second);

        wsuff[m-1] = (long long)water[m-1].first + water[m-1].second;
        for(int i = m-2; i >= 0; i--)
            wsuff[i] = min(wsuff[i+1],
                          (long long)water[i].first + water[i].second);

        // land -> water
        for(int i = 0; i < landStartTime.size(); i++) {
            long long T = (long long)landStartTime[i] + landDuration[i];

            int idx = upper_bound(
                water.begin(),
                water.end(),
                make_pair((int)T, INT_MAX)
            ) - water.begin() - 1;

            long long best = LLONG_MAX;

            if(idx >= 0)
                best = min(best, T + wpref[idx]);

            if(idx + 1 < m)
                best = min(best, wsuff[idx + 1]);

            ans = min(ans, best);
        }

        // Prepare sorted land rides
        vector<pair<int,int>> land;
        for(int i = 0; i < landStartTime.size(); i++)
            land.push_back({landStartTime[i], landDuration[i]});
        sort(land.begin(), land.end());

        int n = land.size();
        vector<long long> lpref(n), lsuff(n);

        lpref[0] = land[0].second;
        for(int i = 1; i < n; i++)
            lpref[i] = min(lpref[i-1], (long long)land[i].second);

        lsuff[n-1] = (long long)land[n-1].first + land[n-1].second;
        for(int i = n-2; i >= 0; i--)
            lsuff[i] = min(lsuff[i+1],
                          (long long)land[i].first + land[i].second);

        // water -> land
        for(int i = 0; i < waterStartTime.size(); i++) {
            long long T = (long long)waterStartTime[i] + waterDuration[i];

            int idx = upper_bound(
                land.begin(),
                land.end(),
                make_pair((int)T, INT_MAX)
            ) - land.begin() - 1;

            long long best = LLONG_MAX;

            if(idx >= 0)
                best = min(best, T + lpref[idx]);

            if(idx + 1 < n)
                best = min(best, lsuff[idx + 1]);

            ans = min(ans, best);
        }

        return ans;
    }
};
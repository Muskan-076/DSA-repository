
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> available;

        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishTime, serverID}
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> busy;

        vector<int> count(k, 0);

        for(int i = 0; i < arrival.size(); i++) {

            // Step 1: Free servers whose requests are completed
            while(!busy.empty() && busy.top().first <= arrival[i]) {

                int server = busy.top().second;

                busy.pop();

                available.insert(server);
            }

            // Step 2: If no server is available, drop request
            if(available.empty()) {
                continue;
            }

            // Preferred server
            int target = i % k;

            // Find next available server
            auto it = available.lower_bound(target);

            // Wrap around if necessary
            if(it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            // Step 3: Assign request
            available.erase(it);

            count[server]++;

            long long finishTime = (long long)arrival[i] + load[i];

            busy.push({finishTime, server});
        }

        // Step 4: Find busiest servers
        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

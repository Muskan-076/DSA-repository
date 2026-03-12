class Solution {
public:

    struct DSU {
        vector<int> parent, rankv;

        DSU(int n){
            parent.resize(n);
            rankv.resize(n,0);
            for(int i=0;i<n;i++) parent[i]=i;
        }

        int find(int x){
            if(parent[x]==x) return x;
            return parent[x]=find(parent[x]);
        }

        bool unite(int a,int b){
            a=find(a);
            b=find(b);
            if(a==b) return false;

            if(rankv[a]<rankv[b]) swap(a,b);
            parent[b]=a;
            if(rankv[a]==rankv[b]) rankv[a]++;
            return true;
        }
    };

    bool can(int n, vector<vector<int>>& edges, int k, int x){
        DSU dsu(n);
        int used=0;

        vector<pair<int,int>> upgrade;

        // mandatory edges
        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];

            if(must){
                if(s < x) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }

        // optional edges
        for(auto &e:edges){
            int u=e[0], v=e[1], s=e[2], must=e[3];
            if(must) continue;

            if(s>=x){
                if(dsu.unite(u,v)) used++;
            }
            else if(2*s>=x){
                upgrade.push_back({u,v});
            }
        }

        // use upgrades
        for(auto &p:upgrade){
            if(k==0) break;
            if(dsu.unite(p.first,p.second)){
                used++;
                k--;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int lo=1, hi=0;

        for(auto &e:edges)
            hi=max(hi,2*e[2]);

        int ans=-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;

            if(can(n,edges,k,mid)){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obs;
        
        // Store obstacles
        for (auto &o : obstacles) {
            long long key = (long long)o[0] * 60001 + o[1];
            obs.insert(key);
        }
        
        // Directions: N, E, S, W
        vector<pair<int,int>> dirs = {
            {0,1}, {1,0}, {0,-1}, {-1,0}
        };
        
        int x = 0, y = 0;
        int d = 0; // start facing north
        int maxDist = 0;
        
        for (int cmd : commands) {
            if (cmd == -1) {
                d = (d + 1) % 4; // turn right
            } 
            else if (cmd == -2) {
                d = (d + 3) % 4; // turn left
            } 
            else {
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;
                    
                    long long key = (long long)nx * 60001 + ny;
                    
                    if (obs.count(key)) break;
                    
                    x = nx;
                    y = ny;
                    
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};

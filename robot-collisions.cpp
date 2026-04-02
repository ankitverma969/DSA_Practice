class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<tuple<int,int,char,int>> robots;
        for(int i = 0; i < n; i++) {
            robots.push_back({positions[i], healths[i], directions[i], i});
        }

        // Step 1: Sort by position
        sort(robots.begin(), robots.end());

        stack<int> st; // stores indices of robots in vector
        vector<int> finalHealth(n, -1);

        for(int i = 0; i < n; i++) {
            auto &[pos, health, dir, idx] = robots[i];

            if(dir == 'R') {
                st.push(i);
            } else {
                // dir == 'L'
                while(!st.empty() && health > 0) {
                    int j = st.top();
                    auto &[pos2, health2, dir2, idx2] = robots[j];

                    if(health2 < health) {
                        // stack robot dies
                        st.pop();
                        health--;
                        health2 = 0;
                    }
                    else if(health2 > health) {
                        // current robot dies
                        health2--;
                        health = 0;
                    }
                    else {
                        // both die
                        st.pop();
                        health = 0;
                        health2 = 0;
                    }
                }

                if(health > 0) {
                    finalHealth[idx] = health;
                }
            }
        }

        // Remaining stack robots survive
        while(!st.empty()) {
            int i = st.top(); st.pop();
            auto &[pos, health, dir, idx] = robots[i];
            finalHealth[idx] = health;
        }

        // Collect answer
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(finalHealth[i] != -1) {
                ans.push_back(finalHealth[i]);
            }
        }

        return ans;
    }
};
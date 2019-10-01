// find better solution
class Solution {
public:
    int minKnightMoves(int x, int y) {
        int level = 0;
        set<pair<int, int>> visited;
        vector<pair<int, int>> moves{{2,1},{2,-1}, {1,2},{-1,2}, {-2,1},{-2,-1}, {-1,-2},{1,-2}};
        list<pair<int, int>> q;

        pair<int,int> p(0,0);
        visited.insert(p);
        q.push_back(p);
        
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                p = q.front();
                q.pop_front();

                for (auto move : moves) {
                    if (p.first == x && p.second == y) return level;

                    pair<int,int> move_pair(p.first+move.first, p.second+move.second);
                    
                    if (x >= 0 && move_pair.first < -1) continue;
                    if (x < 0 && move_pair.first > 1) continue;
                    
                    if (y >= 0 && move_pair.second < -1) continue;
                    if (y < 0 && move_pair.second > 1) continue;
                    
                    auto it = visited.find(move_pair);
                    if (it == visited.end()) {
                        q.push_back(move_pair);
                        visited.insert(move_pair);
                    }
                }
            }
            level++;
        }
        
        return level;
    }
};

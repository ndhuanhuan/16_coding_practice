class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> pairs; 
        
        for(auto word : words){
            
            int pos = 0; 
            
            int i = text.find(word, pos);
            while(i != string::npos){
                pairs.push_back(vector<int>{i, i + (int) word.size() - 1});                
                pos = i + 1; 
                i = text.find(word, pos);
            }
        }
        
        sort(pairs.begin(), pairs.end());
        return pairs;         
    }
};

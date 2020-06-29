class WordDictionary {
    
public:
    /** Initialize your data structure here. */
    WordDictionary(): root_(new TrieNode()) {}
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root_.get();
        for(const char c: word) {
            if(!p->children.count(c)) {
                p->children[c] = new TrieNode();
            }
            
            p = p->children[c];
        }
        p->is_word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, root_.get(), 0);
    }
private:
    struct TrieNode {
        TrieNode(): is_word(false){}
        ~TrieNode() {
            for(auto& kv: children) {
                if(kv.second) delete kv.second;
            }
            
        }
        
        bool is_word;
        unordered_map<char, TrieNode*> children;
    };
        
    const bool find(const string& word, TrieNode *p, int i) const {
        if(i == word.size()) return p->is_word;
        if(word[i] == '.') {
            for(auto &kv: p->children) {
                if(kv.second && find(word, kv.second, i+1)) return true;
            }
            return false;
        } else {
            return p->children[word[i]] && find(word, p->children[word[i]], i+1);
        }
        return false;
    }
    std::unique_ptr<TrieNode> root_;    
};

// https://zxi.mytechroad.com/blog/tree/leetcode-745-prefix-and-suffix-search/
class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root_(new TrieNode()) {}
    
    /** Inserts a word into the trie. */
    void insert(const string& word, int index) {
        TrieNode* p = root_.get();
        for (const char c : word) {            
            if (!p->children[c - 'a'])
                p->children[c - 'a'] = new TrieNode();
            p = p->children[c - 'a'];
            // Update index
            p->index = index;
        }
        p->is_word = true;
    }
    
    
    /** Returns the index of word that has the prefix. */
    int startsWith(const string& prefix) const {
        auto node = find(prefix);
        if (!node) return -1;
        return node->index;
    }
private:
    struct TrieNode {
        TrieNode():index(-1), is_word(false), children(27, nullptr){}
        
        ~TrieNode() {
            for (TrieNode* child : children)
                if (child) delete child;
        }
        
        int index;
        int is_word;
        vector<TrieNode*> children;
    };
    
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for (const char c : prefix) {
            p = p->children[c - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
    
    std::unique_ptr<TrieNode> root_;
};
 
class WordFilter {
public:
    WordFilter(vector<string> words) {        
        for (int i = 0; i < words.size(); ++i) {
            const string& w = words[i];            
            string key = "{" + w;
            trie_.insert(key, i);            
            for (int j = 0; j < w.size(); ++j) {
                key = w[w.size() - j - 1] + key;                
                trie_.insert(key, i);
            }
        }
    }
    
    int f(string prefix, string suffix) {        
        return trie_.startsWith(suffix + "{" + prefix);
    }
private:
    Trie trie_;
};

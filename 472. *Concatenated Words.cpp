// https://www.cnblogs.com/grandyang/p/6254527.html
class Solution {
    struct Node {
      unordered_map<char, unique_ptr<Node>> nodes;
      bool isWord = false;
    };
    
    class Trie {
        Node root; 

    public:
        Trie() = default;
        
        Node* getRoot() {
            return &root;
        }
        
        /** Inserts a sentence into the trie. */
        void insert(string s) {
            Node *n = &root;
            for (char c : s) {
                auto it = n->nodes.find(c);
                if (it == n->nodes.end()) {
                    n->nodes[c] = make_unique<Node>();
                    n = n->nodes[c].get();
                }
                else {
                    n = it->second.get();
                }
            }
            n->isWord = true;
        }

        bool isConcat(const string& word, int index = 0, int numWords = 0) {
            if (index == word.size()) {
                return numWords >= 2;
            }
            
            Node *n = &root;
            for (int i = index; i < word.size(); ++i) {
                char c = word[i];
                if (n->nodes.count(c)) {
                    n = n->nodes[c].get();
                    
                    if (n->isWord) {
                        if(isConcat(word, i + 1, numWords + 1))
                            return true;
                    }
                }
                else {
                    return false;
                }
            }
            
            return false;
        }
    };
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie t;
        for (const string& s : words) {
            t.insert(s);
        }
        
        vector<string> r;
        for (const string& s : words) {
            if (t.isConcat(s)) r.push_back(s);
        }
        return r;
    }
};

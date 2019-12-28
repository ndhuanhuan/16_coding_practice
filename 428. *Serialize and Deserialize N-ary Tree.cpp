// https://www.cnblogs.com/grandyang/p/9945453.html
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string res;
        serializeHelper(root, res);
        cout << res << endl;
        return res;
    }
    
    void serializeHelper(Node* node, string& res) {
        if (!node) res += "#";
        else {
            res += to_string(node->val) + " " + to_string(node->children.size()) + " ";
            for (auto child : node->children) {
                serializeHelper(child, res);
            }
        }
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
    
    Node* deserializeHelper(istringstream& iss) {
        string val = "", size = "";
        iss >> val;
        if (val == "#") return NULL;
        iss >> size;
        Node *node = new Node(stoi(val), {});
        for (int i = 0; i < stoi(size); ++i) {
            node->children.push_back(deserializeHelper(iss));
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

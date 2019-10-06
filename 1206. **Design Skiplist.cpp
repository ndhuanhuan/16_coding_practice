// https://leetcode.com/problems/design-skiplist/discuss/393686/C%2B%2B-Top-down-searchinserterase-bottom-up-randomly-generate-inner-node
class Skiplist {
        struct Node {
            int val;
            Node* next{ NULL };
            Node* pre{ NULL };
            Node* down{ NULL };
            Node(int val = 0) {
                this->val = val;
            }
        };

        Node* heads{ NULL };
        int layers = 0;

    public:
        Skiplist() {
            srand(time(NULL));
        }

        bool search(int target) {
            if (heads == NULL) return false;
            auto p = heads; // top down
            while (p) {
                while (p->next && p->next->val < target) p = p->next;
                if (p->next && p->next->val == target) return true;
                p = p->down;
            }
            return false;
        }

        void add(int num) {
            Node* p = heads;
            vector<Node*> path(layers, NULL);
            for (int i = layers - 1; i >= 0; i--) {
                while (p->next && p->next->val < num) {
                    p = p->next;
                }
                path[i] = p;
                p = p->down;
            }

            for (int i = 0; i <= path.size(); i++) { // bottom up
                p = new Node(num);
                if (i == path.size()) {
                    Node* last = heads;
                    heads = new Node();
                    heads->down = last;
                    heads->next = p;
                    p->pre = heads;
                    layers++;
                }
                else {
                    p->next = path[i]->next;
                    p->pre = path[i];
                    path[i]->next = p;
                    if (p->next) p->next->pre = p;
                }
                if (i) {
                    p->down = path[i - 1]->next;
                }
                if (rand() % 2) {
                    break;
                }

            }
        }

        bool erase(int num) {
            auto p = heads;
            for (int i = layers - 1; i >= 0; i--) {
                while (p->next && p->next->val < num) p = p->next;
                if (p->next && p->next->val == num) {
                    p = p->next;
                    while (p) {
                        p->pre->next = p->next;
                        if (p->next) p->next->pre = p->pre;
                        p = p->down;
                    }
                    return true;
                }
                else {
                    p = p->down;
                    if (p == NULL) return false;
                }
            }
            return false;
        }
    };

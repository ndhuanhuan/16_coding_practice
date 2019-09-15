// https://zxi.mytechroad.com/blog/data-structure/leetcode-1146-snapshot-array/
class SnapshotArray {
public:
  SnapshotArray(int length): id_(0), vals_(length) {}
 
  void set(int index, int val) {
    vals_[index][id_] = val;
  }
 
  int snap() { return id_++; }
 
  int get(int index, int snap_id) const {
    auto it = vals_[index].upper_bound(snap_id);
    if (it == begin(vals_[index])) return 0;
    return prev(it)->second;
  }
private:
  int id_;
  vector<map<int, int>> vals_;
};

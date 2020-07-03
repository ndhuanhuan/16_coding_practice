/// https://zxi.mytechroad.com/blog/geometry/leetcode-1476-subrectangle-queries/
class SubrectangleQueries {
public:
  SubrectangleQueries(vector<vector<int>>& rectangle): 
    m_(rectangle) {}
 
  void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
    updates_.push_front({row1, col1, row2, col2, newValue});
  }
 
  int getValue(int row, int col) {
    for (const auto& u : updates_)
      if (row >= u[0] && row <= u[2] && col >= u[1] && col <= u[3])
        return u[4];
    return m_[row][col];
  }
private:
  const vector<vector<int>>& m_;
  deque<vector<int>> updates_;  
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

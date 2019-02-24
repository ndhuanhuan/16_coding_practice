// https://zxi.mytechroad.com/blog/hashtable/leetcode-911-online-election/
class TopVotedCandidate {
public:
  TopVotedCandidate(vector<int> persons, vector<int> times) {
    vector<int> votes(persons.size() + 1);
    int last_lead = persons.front();
    for (int i = 0; i < persons.size(); ++i) {
      if (++votes[persons[i]] >= votes[last_lead])
        last_lead = persons[i];      
      leads_[times[i]] = last_lead;      
    }
  }
 
  int q(int t) {
    return prev(leads_.upper_bound(t))->second;
  }
private:
  map<int, int> leads_; // time -> lead
};

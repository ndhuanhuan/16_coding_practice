class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i=0;i<input.length();++i)
        {
            const auto cur = input[i];
            if(cur=='+'||cur=='-'||cur=='*')
            {
                auto left = diffWaysToCompute(input.substr(0,i));
                auto right = diffWaysToCompute(input.substr(i+1));
                for(const auto& num1:left)
                {
                    for(const auto& num2:right)
                    {
                        if (cur == '+') {
                            result.push_back(num1 + num2);
                        } else if (cur == '-') {
                            result.push_back(num1 - num2);
                        } else {
                            result.push_back(num1 * num2);
                        }
                    }
                }
            }
        }
        
        if (result.empty()) {
            result.push_back(stoi(input));
        }
        return result;
        
    }
};

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result{0};
        auto it1 = height.begin();
        auto it2 = height.end() - 1;
        while (it1 != it2) {
            result = max<int>(result, (it2 - it1) * min(*it1, *it2));
            if (*it2 > *it1) {
                ++it1;
            } else {
                --it2;
            }
        }
        return result;
    }
};

int main(int argc, char ** argv) {
    Solution s;
    vector<int> height{1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height);
    return 0;
}
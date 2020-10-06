#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;

        for (auto b_it1 = s.begin(); b_it1 < s.end(); ++b_it1) {
            auto e_it1 = s.end();
            for (auto it2 = b_it1; it2 < e_it1; ++it2) {
                auto f = std::find(it2 + 1, e_it1, *it2);
                if (f != s.end()) {
                    e_it1 = f;
                }
            }
            int _m = (e_it1 - b_it1);
            if (_m > m) {
                m = _m;
            }
        }

        return m;
    }
};

int main(int argc, char ** argv) {
    Solution s;
    std::cout << endl << s.lengthOfLongestSubstring("dvdf") << endl;
    std::cout << endl << s.lengthOfLongestSubstring("abcabcbb") << endl;
}
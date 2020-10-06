#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int>& nums) {
    cout << "( ";
    for (auto it = nums.begin(); it < nums.end(); ++it) {
        cout << *it << " ";
    }
    cout << ")" << endl;
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> r;
        r.reserve(nums1.size() + nums2.size());        
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 < nums1.end() || it2 < nums2.end()) {
            if (it1 < nums1.end() && it2 < nums2.end()) {
                if (*it1 < *it2) {
                    r.push_back(*it1);
                    ++it1;
                } else if (*it2 < *it1) {
                    r.push_back(*it2);
                    ++it2;
                } else {
                    r.push_back(*it1);
                    ++it1;
                    r.push_back(*it2);
                    ++it2;
                }
            } else if (it1 < nums1.end()) {
                r.push_back(*it1);
                ++it1;
            } else if (it2 < nums2.end()) {
                r.push_back(*it2);
                ++it2;
            }
        }
        int i = r.size() / 2;
        if (r.size() % 2 == 0) {
            return double(r[i - 1] + r[i]) / 2.0;
        } else {
            return r[i];
        }
    }
};

int main(int argc, char ** argv) {
    Solution s;
    vector<int> nums1 {1, 2};
    vector<int> nums2 {3, 4};
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
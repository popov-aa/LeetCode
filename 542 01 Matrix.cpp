// https://leetcode.com/problems/01-matrix/

#include <ostream>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>> result;
        for (auto r = matrix.cbegin(); r < matrix.cend(); ++r) {
            vector<int> resultRow;
            for (auto c = r->cbegin(); c < r->cend(); ++c) {
                if (*c == 0) {
                    resultRow.push_back(0);
                } else {
                    int row = r - matrix.cbegin();
                    int column = c - r->cbegin();
                    for (int length = 1; true; ++length) {
                        bool found = false;
                        for (int dx = 0; dx <= length; ++dx) {
                          int dy = length - dx;
                          if ((row - dx >= 0 && column - dy >= 0 && *((matrix.cbegin() + row - dx)->cbegin() + column - dy) == 0) ||
                              (row - dx >= 0 && column + dy < r->size() && *((matrix.cbegin() + row - dx)->cbegin() + column + dy) == 0) ||
                              (row + dx < matrix.size() && column - dy >= 0 && *((matrix.cbegin() + row + dx)->cbegin() + column - dy) == 0) ||
                              (row + dx < matrix.size() && column + dy < r->size() && *((matrix.cbegin() + row + dx)->cbegin() + column + dy) == 0)) {
                            found = true;
                            resultRow.push_back(length);
                            break;
                          }
                        }
                        if (found) {
                            break;
                        }
                    }
                }
            }
            result.push_back(resultRow);
        }
        return result;
    }
};

void printMatrix(vector<vector<int>> & matrix) {
    for (auto r: matrix) {
        for (auto c: r) {
            cout << c << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> matrix = {
        {{1,0,1,1,0,0,1,0,0,1},{0,1,1,0,1,0,1,0,1,1},{0,0,1,0,1,0,0,1,0,0},{1,0,1,0,1,1,1,1,1,1},{0,1,0,1,1,0,0,0,0,1},{0,0,1,0,1,1,1,0,1,0},{0,1,0,1,0,1,0,0,1,1},{1,0,0,0,1,1,1,1,0,1},{1,1,1,1,1,1,1,0,1,0},{1,1,1,1,0,1,0,0,1,1}}
    };

    Solution solution;
    cout << "Source:" << endl;
    printMatrix(matrix);
    matrix = solution.updateMatrix(matrix);
    cout << "Result:" << endl;
    printMatrix(matrix);
}

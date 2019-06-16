#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class StackNode {
    public:
    int val; int maxVal;
    StackNode(int val, int maxVal) {
        this->val = val;
        this->maxVal = maxVal;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int testcases = 0;
    cin >> testcases;
    stack<StackNode*> s;
    int maxi = -9999;
    for (int i = 0; i < testcases; i++) {
        int query = 0;
        cin >> query;
        if (query == 1) {
          int x = 0;
          cin >> x;
          maxi = max(x, maxi);
          s.push(new StackNode(x, maxi));
        }
        else if (query == 2) {
          s.pop();
          if (s.empty()) {
              maxi = -9999;
          }
            else {
                maxi = s.top()->maxVal;
            }
        }
        else if (query == 3) {
            cout << s.top()->maxVal << "\n"; 
        }           
    }  
    return 0;
}

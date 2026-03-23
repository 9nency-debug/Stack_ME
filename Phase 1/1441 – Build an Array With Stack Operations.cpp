#include <iostream>
#include <vector>
using namespace std;

vector<string> buildArray(vector<int>& target, int n) {
    vector<string> result;
    int index = 0;  // pointer for target
    
    for (int num = 1; num <= n && index < target.size(); num++) {
        
        result.push_back("Push");
        
        if (num == target[index]) {
            index++;  // move to next target element
        } else {
            result.push_back("Pop");
        }
    }
    
    return result;
}

int main() {
    vector<int> target = {1, 3};
    int n = 3;
    
    vector<string> ans = buildArray(target, n);
    
    for (string op : ans) {
        cout << op << " ";
    }
    
    return 0;
}

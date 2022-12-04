#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

int main() {
    std::ifstream input("input");
    std::string s;
    std::vector<int> v;
    int i = 0;

    while(getline(input, s)) {
        if(!s.empty()) {
            std::istringstream temp(s);
            int x;
            temp >> x;
            i += x;
        }
        else {
            v.push_back(i);
            i = 0;
        }
    }
    std::sort(v.begin(), v.end(), std::greater<int>());
    
    std::cout << v.at(0); // 1.1
    std::cout << v.at(0) + v.at(1) + v.at(2); // 1.2
    
    return 0;
}
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

std::vector<std::string> string_transformer(std::string& s);
bool vec_analyzer(std::vector<std::string> v);
bool vec_analyzer_two(std::vector<std::string> v);

void ranger(int a , int b) {
    int max = std::max(a, b);
    int min = std::min(a, b);
    for(int i{min}; i <= max; i++) std::cout << i << "\n";
}

int main() {
    std::ifstream input("input");
    std::string input_line;
    std::vector<std::string> lines;
    int count_first{0};
    int count_second{0};

    while(getline(input, input_line)) {
        lines.push_back(input_line);
    }

    for(auto& el : lines) {
        auto transformed = string_transformer(el);
        if(vec_analyzer(transformed)) count_first++;
        if(vec_analyzer_two(transformed)) count_second++;
    }

    std::cout << "First Part: " << count_first << "\n";
    std::cout << "Second Part: " << count_second;
}

std::vector<std::string> string_transformer(std::string& s) {
    std::string temp;
    std::vector<std::string> first_iteration;
    std::vector<std::string> second_iteration;

    for(size_t i{0}; i < s.size(); i++) {
        if(s.at(i) != ',') temp.push_back(s.at(i));
        else {
            first_iteration.push_back(temp);
            temp = "";
        }
    }
    first_iteration.push_back(temp);
    temp = "";

    for(auto& el : first_iteration) {
        for(size_t i{0}; i < el.size(); i++) {
            if(el.at(i) != '-') temp.push_back(el.at(i));
            else {
                second_iteration.push_back(temp);
                temp = "";
            }
        }
        second_iteration.push_back(temp);
        temp = "";
    }
    return second_iteration;
}

bool vec_analyzer(std::vector<std::string> v) {
    int a = std::stoi(v.at(0));
    int b = std::stoi(v.at(1));
    int c = std::stoi(v.at(2));
    int d = std::stoi(v.at(3));
    
    if(a <= c and b >= d ) return true;
    else if(a >= c and b <= d) return true;
    else return false;
}

bool vec_analyzer_two(std::vector<std::string> v) {
    int a = std::stoi(v.at(0));
    int b = std::stoi(v.at(1));
    int c = std::stoi(v.at(2));
    int d = std::stoi(v.at(3));

    if(c < a and d < a) return false;
    else if(b < c and b < d) return false;
    else return true;
}
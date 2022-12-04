#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char string_compare(std::string first, std::string second);
int check_char(char c);
char three_string_compare(std::string first, std::string second, std::string third);

int main() {
    std::ifstream input("input");
    std::string line;
    std::vector<int> v;
    int result{0};

    std::vector<std::string> b;


    while(getline(input, line)) {
        b.push_back(line);
        std::string first = line.substr(0, (line.size()/2));
        std::string second = line.substr((line.size()/2));
        char c = string_compare(first, second);
        result += check_char(c);  
    }
    std::cout << "Part One Result: " << result << "\n";
    result = 0;

    for(int i = 0; i < b.size(); i += 3) {
        char c = three_string_compare(b.at(i), b.at(i + 1), b.at(i + 2));
        result += check_char(c);
    }
    std::cout << "Part Two Result: " << result;
    return 0;
}


char string_compare(std::string first, std::string second) {
    for(auto& c : first) {
        if(second.find(c) != std::string::npos) return c;
    }
    return ' ';
}

char three_string_compare(std::string first, std::string second, std::string third) {
    for(auto& c : first) {
        if(second.find(c) != std::string::npos and third.find(c) != std::string::npos) return c;
    }
    return ' ';
}


int check_char(char c) {
    std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return alphabet.find(c) + 1;
}
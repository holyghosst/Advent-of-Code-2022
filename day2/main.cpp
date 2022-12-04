#include <string>
#include <fstream>
#include <iostream>


int analyze(std::string input);
int analyze_second(std::string input);

int main() {
    std::ifstream input("input");
    std::string s;

    int final_score{0};
    int final_score_second{0};
    while(getline(input, s)) {
        final_score += analyze(s);
        final_score_second += analyze_second(s);
    }

    std::cout << "Part One final score: " << final_score << "\n";
    std::cout << "Part Two final score:" << final_score_second;

    return 0;
}

// A X ROCK 1
// B Y PAPER 2 
// C Z SCISSORS 3
// ROCK > SCISSORS AND PAPER > ROCK AND SCISSORS > PAPER

int analyze(std::string input) {
    int score{0};
    if(input.at(0) == 'A') {
        switch(input.at(2)) {
            case 'X':
                score += 4;
                break;
            case 'Y':
                score += 8;
                break;
            case 'Z':
                score += 3;
                break;
        }

    }
    else if(input.at(0) == 'B') {
        switch(input.at(2)) {
            case 'X':   
                score += 1;
                break;
            case 'Y':
                score += 5;
                break;
            case 'Z':
                score += 9;
                break;
        }
    }
    else if(input.at(0) == 'C') {
        switch(input.at(2)) {
            case 'X':
    	        score += 7;
                break;
            case 'Y':
                score += 2;
                break;
            case 'Z':
                score += 6;
                break;
        }
    }
    return score;
}


// A X ROCK LOSE 1
// B Y PAPER  DRAW 2 
// C Z SCISSORS WIN 3
// ROCK > SCISSORS AND PAPER > ROCK AND SCISSORS > PAPER
int analyze_second(std::string input) {
    int score{0};
    if(input.at(0) == 'A') {
        switch(input.at(2)) {
            case 'X':
                score += 3;
                break;
            case 'Y':
                score += 4;
                break;
            case 'Z':
                score += 8;
                break;
        }

    }
    else if(input.at(0) == 'B') {
        switch(input.at(2)) {
            case 'X':   
                score += 1;
                break;
            case 'Y':
                score += 5;
                break;
            case 'Z':
                score += 9;
                break;
        }
    }
    else if(input.at(0) == 'C') {
        switch(input.at(2)) {
            case 'X':
    	        score += 2;
                break;
            case 'Y':
                score += 6;
                break;
            case 'Z':
                score += 7;
                break;
        }
    }
    return score;
}
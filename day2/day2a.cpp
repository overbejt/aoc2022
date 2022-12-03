#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<unordered_map>

using Round = std::unordered_map<std::string, std::string>;
using TotalScore = int;

void parseFile(std::vector<Round>&);
TotalScore processRounds(std::vector<Round>&);
int getScore(std::string, std::string);
bool isWin(std::string, std::string);
bool isDraw(std::string, std::string);
std::string normalizeThem(std::string);
std::string normalizeMe(std::string);

std::string normalizeThem(std::string them) {
    std::string result;

    if (them == "A") {
        result = "r";
    }

    if (them == "B") {
        result = "p";
    }

    if (them == "C") {
        result = "s";
    }

    return result;
}  // End of the 'normalizeThem' function

std::string normalizeMe(std::string me) {
    std::string result;

    if (me == "X") {
        result = "r";
    }

    if (me == "Y") {
        result = "p";
    }

    if (me == "Z") {
        result = "s";
    }

    return result;
}  // End of the 'normalizeMe' function 

void parseFile(std::vector<Round>& rounds) {
    std::ifstream file ("/Users/joshoverbeck/Documents/cpp/aoc2022/day2/data.dat");
    for(std::string line; std::getline(file, line);) {
        std::stringstream ss (line);
        std::string them; std::string me;
        ss >> them >> me;

        them = normalizeThem(them);
        me = normalizeMe(me);
        
        Round round;
        round["them"] = them;
        round["me"] = me;
        rounds.push_back(round);
    }
}  // End of the 'parseFile' function

TotalScore processRounds(std::vector<Round>& rounds) {
    TotalScore total = 0;

    for (Round round : rounds) {
        total += getScore(round["them"], round["me"]);
    }

    return total;
}  // End of the 'processRounds' function

int getScore(std::string them, std::string me) {
    int score = 0;

    // Calculate score from round
    if (isWin(them, me)) {
        score += 6;
    } 

    if (isDraw(them, me)) {
        score += 3;
    }
    
    // Calculate score from shape
    if (me == "r") {
        score += 1;
    }

    if (me == "p") {
        score += 2;
    }

    if (me == "s") {
        score += 3;
    }

    return score;
}  // End of the 'getScore' method 

/*
    r > s
    s > p
    p > r
*/
bool isWin(std::string them, std::string me) {
    bool win = (me == "r" && them == "s") ||
               (me == "s" && them == "p") || 
               (me == "p" && them == "r");
    return  win;
}  // End of the 'isWin' function

/*
    r == r
    s == s
    p == p
*/
bool isDraw(std::string them, std::string me) {
    bool draw = (me == "r" && them == "r") ||
                (me == "s" && them == "s") ||
                (me == "p" && them == "p");
    return draw;
}  // End of the 'isDraw' function

int main(int argc, char** argv) {

    std::vector<Round> rounds;
    parseFile(rounds);
    TotalScore score = processRounds(rounds);  // Nailed it!
    std::cout << "Total score: " << score << std::endl;  // 12855

}  // End of the 'main' function

// END OF FILE 


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
std::string getWin(std::string);
std::string getLose(std::string);
std::string getShape(std::string, std::string);
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
        result = "l";
    }

    if (me == "Y") {
        result = "d";
    }

    if (me == "Z") {
        result = "w";
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
    if (me == "w") {
        score += 6;
    } 

    if (me == "d") {
        score += 3;
    }
    
    // Calculate score from shape
    std::string shape = getShape(them, me);
    if (shape == "r") {
        score += 1;
    }

    if (shape == "p") {
        score += 2;
    }

    if (shape == "s") {
        score += 3;
    }

    return score;
}  // End of the 'getScore' method 

std::string getShape(std::string them, std::string me) {
    std::string shape;

    if (me == "w") {
        shape = getWin(them);
    }

    if (me == "d") {
        shape = them;
    }

    if (me == "l") {
        shape = getLose(them);
    }

    return shape;
}  // End of the 'getShape' function 

/*
    r > s
    s > p
    p > r
*/
std::string getWin(std::string them) {
    std::string shape;

    if (them == "s") {
        shape = "r";
    }

    if (them == "p") {
        shape = "s";
    }

    if (them == "r") {
        shape = "p";
    }

    return shape;
}  // End of the 'getWin' function 

std::string getLose(std::string them) {
    std::string shape;

    if (them == "r") {
        shape = "s";
    }

    if (them == "s") {
        shape = "p";
    }

    if (them == "p") {
        shape = "r";
    }

    return shape;
}  // End of the 'getLose' function 

int main(int argc, char** argv) {

    std::vector<Round> rounds;
    parseFile(rounds);
    
    TotalScore score = processRounds(rounds);  // Nailed it!
    std::cout << "Total score: " << score << std::endl;  // 13726

}  // End of the 'main' function

// END OF FILE 


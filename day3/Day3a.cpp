#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<unordered_map>
#include<sstream>

struct Rucksack {
    std::string compartmentA;
    std::string compartmentB;
};

using Priorities = std::unordered_map<char, int>;
using Rucksacks = std::vector<Rucksack>;

void loadPriorities(Priorities&);
void parseFile(Rucksacks&);
Rucksack createRucksack(std::string, int row);
void validateRucksack(std::string&, int);
std::string getUniqueCharArr(std::string&);
int getProrioritiesSum(Rucksacks&, Priorities&);
int getRucksackPriority(std::string, std::string, Priorities&);

void validateRucksack(std::string& line, int row) {
    if (line.size() % 2 != 0) {
        std::cerr << "Line is unbalanced on row " << row << ": " << line << std::endl;
        exit(-1);
    }
} // End of the 'validateRucksack' function 

std::string getUniqueCharArr(std::string& compartment) {
    std::string uniqueStr;
    for(char c : compartment) {
        if (uniqueStr.find(c) == std::string::npos) {
            uniqueStr += c;
        }
    }
    return uniqueStr;
} // End of the 'getUniqueCharArr' function

Rucksack createRucksack(std::string line, int row) {
    validateRucksack(line, row);
    Rucksack rucksack;
    int middle = line.size() / 2;
    // Since we're already here, let's make these strings (char[]) unique
    std::string compA = line.substr(0, middle);
    std::string compB = line.substr(middle);
    rucksack.compartmentA = getUniqueCharArr(compA);
    rucksack.compartmentB = getUniqueCharArr(compB);
    return rucksack;
} // End of the 'createRucksack' function

void loadPriorities(Priorities& priorities) {
    std::ifstream file ("/Users/joshoverbeck/Documents/cpp/aoc2022/day3/priorities.dat");
    for(std::string line; std::getline(file, line);) {
        int priority;
        char item;

        std::stringstream ss (line);
        ss >> item >> priority;
        priorities[item] = priority;
    }
} // End of the 'loadPriorities' function

void parseFile(Rucksacks& rucksacks) {
    std::ifstream file ("/Users/joshoverbeck/Documents/cpp/aoc2022/day3/data.dat");
    int row = 0;
    for(std::string line; std::getline(file, line);) {
        Rucksack rucksack = createRucksack(line, row);
        rucksacks.push_back(rucksack);
        row++;
    }
} // End of the 'parseFile' function

int getRucksackPriority(std::string small, std::string large, Priorities& priorities) {
    int sum = 0;
    for(const char c : small) {
        if (large.find(c) != std::string::npos) {
            sum += priorities[c];
        }
    }
    return sum;
} // End of the 'getRucksackPriority' function 

int getProrioritiesSum(Rucksacks& rucksacks, Priorities& priorities) {
    int sum = 0;
    for(const Rucksack& rucksack : rucksacks) {
        if (rucksack.compartmentA.size() > rucksack.compartmentB.size()) {
            sum += getRucksackPriority(rucksack.compartmentB, rucksack.compartmentA, priorities);
        } else {
            sum += getRucksackPriority(rucksack.compartmentA, rucksack.compartmentB, priorities);
        }
    }
    return sum;
} // End of the 'getProrioritiesSum' function

int main(int argc, char** argv) {

    Priorities priorities;
    loadPriorities(priorities);

    Rucksacks rucksacks;
    parseFile(rucksacks);

    int prioritySum = getProrioritiesSum(rucksacks, priorities);
    std::cout << "Priority Sum: " << prioritySum << std::endl;  // 7990 Nailed it!

    return 0;
} // End of the 'main' function

// END OF FILE 

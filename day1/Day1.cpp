//
// Created by Josh Overbeck on 12/1/22.
//
#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>

void parseFile(std::vector<int>&);
int findIndexWithMax(std::vector<int>&);

void parseFile(std::vector<int>& elves) {
  std::ifstream file ("/Users/joshoverbeck/Documents/cpp/aoc2022/day1/input.dat");

  int sum = 0;
  for (std::string line; std::getline(file, line); ) {
    if (!line.empty()) {
      std::stringstream ss (line);
      int calories;
      ss >> calories;
      sum += calories;
    } else {
      elves.push_back(sum);
      sum = 0;
    }
  }
  if (sum > 0) {
    elves.push_back(sum);
  }
}  // End of the 'parseFile' function

int findIndexWithMax(std::vector<int>& elves) {
  int idx;
  int maxVal = 0;

  for (int i = 0; i < elves.size(); i++) {
    if (elves[i] > maxVal) {
      idx = i;
      maxVal = elves[i];
    }
  }

  return idx;
}  // End of the 'findIndexWithMax' function

int main(int argc, char** argv) {
  std::vector<int> elves;
  parseFile(elves);
  int elfWithMostIdx = findIndexWithMax(elves);

  // Nailed it
  std::cout << "elfWithMostIdx: " << elfWithMostIdx
            << "\tvalue: " << elves[elfWithMostIdx] << std::endl;
}  // End of the 'main' function

// END OF FILE
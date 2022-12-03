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

int main(int argc, char** argv) {
  std::vector<int> elves;
  parseFile(elves);

  std::sort(elves.begin(), elves.end(), [](int a, int b) {
    return a > b;
  });

  // Nailed it
  std::cout << "elfWithMost: " << elves[0] << std::endl;

  std::cout << "Elf 1: " << elves[0] << std::endl;
  std::cout << "Elf 2: " << elves[1] << std::endl;
  std::cout << "Elf 3: " << elves[2] << std::endl;

  int sumed = elves[0] + elves[1] + elves[2];
  std::cout << "sum: " << sumed << std::endl;  // 210406
}  // End of the 'main' function

// END OF FILE
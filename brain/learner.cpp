#include "learner.h"
using namespace std;
void learner(string inputPhrase) {
 string storePhrase = inputPhrase;
 std::cout << "Not Found! Tell me what to enter for " << storePhrase << " : ";
 std::string learningResponse;
 getline(std::cin, learningResponse);
 std::cout << learningResponse << endl;
 
 //open file for writing: parameters indicate that you will APPEND to end
 std::ofstream saveBrain;
 saveBrain.open("brain/brain.txt", std::ios::out | std::ios::app);
 if(!saveBrain.is_open()) {
  std::cout << "error on file open" << endl;
 } else {
  saveBrain << endl << storePhrase << "|" << learningResponse;
  saveBrain.close();
 }
 return;
}
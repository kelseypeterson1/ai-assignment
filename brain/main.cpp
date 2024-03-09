#include "learner.h"
using namespace std;
void showMessage();
int getPhrase(string phrase);
void learner(string storePhrase);
int main () {
  showMessage();
  std::string userInput;
  do {
   std::cout << "[You] : ";
   getline(std::cin, userInput);
   //x or X will close out the program
   if(userInput != "x" && userInput != "X") {
    if(getPhrase(userInput)) {;
     //keep going
    } else {
     //need to learn this phrase and response
     learner(userInput);
    }
   }
 } while (userInput != "x" && userInput != "X");
  return 0;
}

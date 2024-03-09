#include "learner.h"
using namespace std;
int getPhrase(string userInput) {
 ifstream brainFile ( "brain/brain.txt" );
 
 string phrase;
 string response;
 
 while (getline(brainFile, phrase, '|')) {
  getline(brainFile, response);
 
   if(userInput == phrase) {
    cout << "[Dory]: " << response << endl;
    brainFile.close();
    return 1;
   }
 
 }
 //quit if user types Quit
 if(userInput == "Quit") {
  std::exit(0);
 }
 
 //we couldn't find the phrase, so we'll need to go to the other function
 // After you are done with the file always close it.
 brainFile.close();
 return 0;
}
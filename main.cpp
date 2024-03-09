#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// List of survey questions
map<int, string> questions = {
  {1, "What should the government do for the economy?\nA. Cut taxes.\nB. Raise taxes.\nC. Cut spending.\nD. Increase spending."},
  {2, "What should the government do for same sex marriage?\nA. Allow it.\nB. Allow it, but allow businesses to refuse service.\nC. Ban it.\nD. Nothing."},
  {3, "What should the government do for gun control?\nA. Ban all guns.\nB. Ban assault weapons.\nC. Allow concealed carry.\nD. Nothing."},
  {4, "What should the government do for abortion?\nA. Ban it.\nB. Allow it.\nC. Allow it, but not with federal funds.\nD. Nothing."},
  {5, "What should the government do for healthcare?\nA. Create a single payer system.\nB. Allow people to buy insurance across state lines.\nC. Repeal Obamacare.\nD. Nothing."}
};

// Read party answers from files
map<string, map<string, vector<string>>> readPartyAnswers()
{
  map<string, map<string, vector<string>>> partyAnswers;
  vector<string> parties = {"democrat", "republican", "independent", "green"};

  for (const auto &party : parties)
  {
    ifstream file(party + ".txt");
    string line;

    while (getline(file, line))
    {
      istringstream iss(line);
      string question, answer;
      getline(iss, question, '|');
      getline(iss, answer);
      partyAnswers[party][question].push_back(answer);
    }
  }

  return partyAnswers;
}

// Calculate weighted results based on user answers
map<string, double> calculateWeightedResults(const map<string, map<string, vector<string>>> &partyAnswers, const map<string, string> &userAnswers)
{
  map<string, double> weightedResults;

  for (const auto &party : partyAnswers)
  {
    for (const auto &question : party.second)
    {
      for (const auto &answer : question.second)
      {
        if (userAnswers.find(question.first) != userAnswers.end() && userAnswers.at(question.first) == answer)
        {
          weightedResults[party.first]++;
        }
      }
    }
  }

  return weightedResults;
}

// Find the party with the highest weighted result
string findBestParty(const map<string, double> &weightedResults)
{
  return max_element(weightedResults.begin(), weightedResults.end(), [](const auto &a, const auto &b)
             { return a.second < b.second; })
    ->first;
}

// Guess the political party based on user answers
string guessPoliticalParty(const map<string, string> &userAnswers)
{
  auto partyAnswers = readPartyAnswers();
  auto weightedResults = calculateWeightedResults(partyAnswers, userAnswers);
  auto bestParty = findBestParty(weightedResults);

  return bestParty;
}

int main()
{
  cout << "*** Welcome to the political parties survey. ****\n";
  string userInput;
  string userAnswers;
  map<string, string> userAnswersObject;
  int questionNumber = 1;

  do
  {
    cout << questions[questionNumber] << "\n";
    cout << "[ANSWER] : ";
    getline(cin, userInput);

    // Make the user input uppercase
    transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);

    // Add answer to survey results
    userAnswers += to_string(questionNumber) + "|" + userInput + "\n";
    userAnswersObject[to_string(questionNumber)] = userInput;
    questionNumber++;

    // Exit loop when user has answered all questions
  } while (questionNumber <= questions.size());

  // Guess what political party user belongs to
  cout << "Based on your answers, you are most likely a " << guessPoliticalParty(userAnswersObject) << ".\n";

  // Ask user what political party they belong to: democrat, republican, independent, or green
  cout << "Which of these political parties do you identify with: democrat, republican, independent, or green?" << "\n";
  cout << "[ANSWER] : ";
  string party;
  getline(cin, party);

  // Validate user response
  transform(party.begin(), party.end(), party.begin(), ::tolower);
  while (party != "democrat" && party != "republican" && party != "independent" && party != "green")
  {
    cout << "Invalid party. Please enter democrat, republican, independent, or green.";
    getline(cin, party);
  }

  // Store response in corresponding .txt file
  ofstream saveAnswers(party + ".txt", ios::app); // Open the file in append mode
  if (saveAnswers.is_open())
  {
    saveAnswers << userAnswers;
    saveAnswers.close();
  }
  else
  {
    cout << "Unable to open file";
  }

  return 0;
}

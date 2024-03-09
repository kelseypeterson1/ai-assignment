// #include "learner.h"
// using namespace std;

// // List of survey questions
// std::map<int, std::string> questions = {
//     {1, "What should the government do for the economy?\nA. Cut taxes.\nB. Raise taxes.\nC. Cut spending.\nD. Increase spending."},
//     {2, "What should the government do for same sex marriage?\nA. Allow it.\nB. Allow it, but allow businesses to refuse service.\nC. Ban it.\nD. Nothing."},
//     {3, "What should the government do for gun control?\nA. Ban all guns.\nB. Ban assault weapons.\nC. Allow concealed carry.\nD. Nothing."},
//     {4, "What should the government do for abortion?\nA. Ban it.\nB. Allow it.\nC. Allow it, but not with federal funds.\nD. Nothing."},
//     {5, "What should the government do for healthcare?\nA. Create a single payer system.\nB. Allow people to buy insurance across state lines.\nC. Repeal Obamacare.\nD. Nothing."}};

// // std::map<int, std::string> readSurveyFile(std::ifstream &file)
// // {
// //   std::map<int, std::string> answers;
// //   std::string line;
// //   int questionNumber = 1;

// //   while (std::getline(file, line))
// //   {
// //     answers[questionNumber] = line;
// //     questionNumber++;
// //   }

// //   return answers;
// // }

// // #include <iostream>
// // #include <fstream>
// // #include <sstream>
// // #include <map>
// // #include <vector>
// // #include <algorithm>

// std::map<std::string, std::map<std::string, std::vector<std::string>>> readPartyAnswers()
// {
//   std::map<std::string, std::map<std::string, std::vector<std::string>>> partyAnswers;
//   std::vector<std::string> parties = {"democrat", "republican", "independent", "green"};

//   for (const auto &party : parties)
//   {
//     std::ifstream file(party + ".txt");
//     std::string line;

//     while (std::getline(file, line))
//     {
//       std::istringstream iss(line);
//       std::string question, answer;
//       std::getline(iss, question, '|');
//       std::getline(iss, answer);
//       partyAnswers[party][question].push_back(answer);
//     }
//   }

//   return partyAnswers;
// }

// std::map<std::string, double> calculateWeightedResults(const std::map<std::string, std::map<std::string, std::vector<std::string>>> &partyAnswers, const std::map<std::string, std::string> &userAnswers)
// {
//   std::map<std::string, double> weightedResults;

//   for (const auto &party : partyAnswers)
//   {
//     for (const auto &question : party.second)
//     {
//       for (const auto &answer : question.second)
//       {
//         if (userAnswers.find(question.first) != userAnswers.end() && userAnswers.at(question.first) == answer)
//         {
//           weightedResults[party.first]++;
//         }
//       }
//     }
//   }

//   return weightedResults;
// }

// std::string findBestParty(const std::map<std::string, double> &weightedResults)
// {
//   return std::max_element(weightedResults.begin(), weightedResults.end(), [](const auto &a, const auto &b)
//                           { return a.second < b.second; })
//       ->first;
// }

// std::string guessPoliticalParty(const std::map<std::string, std::string> &userAnswers)
// {
//   // for (const auto &answer : userAnswers)
//   // {
//   //   std::cout << answer.first << ": " << answer.second << "\n";
//   // }

//   auto partyAnswers = readPartyAnswers();
//   auto weightedResults = calculateWeightedResults(partyAnswers, userAnswers);
//   auto bestParty = findBestParty(weightedResults);

//   // for (const auto &party : partyAnswers)
//   // {
//   //   std::cout << party.first << ":\n";
//   //   for (const auto &question : party.second)
//   //   {
//   //     std::cout << "  " << question.first << ": ";
//   //     for (const auto &answer : question.second)
//   //     {
//   //       std::cout << answer << " ";
//   //     }
//   //     std::cout << "\n";
//   //   }
//   // }
//   // for (const auto &result : weightedResults)
//   // {
//   //   std::cout << result.first << ": " << result.second << "\n";
//   // }
//   return bestParty;
// }

// int main()
// {
//   std::cout << "*** Welcome to the political parties survey. ****\n";
//   std::string userInput;
//   std::string userAnswers;
//   std::map<std::string, std::string> userAnswersObject;
//   int questionNumber = 1;
//   do
//   {
//     std::cout << questions[questionNumber] << "\n";
//     std::cout << "[ANSWER] : ";
//     getline(std::cin, userInput);
//     // make the user input uppercase
//     std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::toupper);
//     // add answer to survey results
//     userAnswers += std::to_string(questionNumber) + "|" + userInput + "\n";
//     userAnswersObject[std::to_string(questionNumber)] = userInput;
//     questionNumber++;
//     // exit loop when user has answered all questions
//   } while (questionNumber <= questions.size());
//   // guess what political party user belongs to
//   std::cout << "Based on your answers, you are most likely a " << guessPoliticalParty(userAnswersObject) << ".\n";
//   // ask user what political party they belong to: democrat, republican, independent, or green
//   std::cout << "Which of these political parties do you identify with: democrat, republican, independent, or green?"
//             << "\n";
//   std::cout << "[ANSWER] : ";
//   std::string party;
//   getline(std::cin, party);
//   // validate user response
//   std::transform(party.begin(), party.end(), party.begin(), ::tolower);
//   while (party != "democrat" && party != "republican" && party != "independent" && party != "green")
//   {
//     std::cout << "Invalid party. Please enter democrat, republican, independent, or green.";
//     getline(std::cin, party);
//   }
//   // store response in corresponding .txt file
//   std::ofstream saveAnswers(party + ".txt", std::ios::app); // Open the file in append mode
//   if (saveAnswers.is_open())
//   {
//     saveAnswers << userAnswers;
//     saveAnswers.close();
//   }
//   else
//   {
//     std::cout << "Unable to open file";
//   }
//   return 0;
// }

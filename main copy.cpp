// #include "learner.h"
// using namespace std;

// // List of survey questions
// std::map<int, std::string> questions = {
//     {1, "What should the government do for the economy?\nA. Cut taxes.\nB. Raise taxes.\nC. Cut spending.\nD. Increase spending."},
//     {2, "What should the government do for same sex marriage?\nA. Allow it.\nB. Allow it, but allow businesses to refuse service.\nC. Ban it.\nD. Nothing."},
//     // {3, "What should the government do for gun control?\nA. Ban all guns.\nB. Ban assault weapons.\nC. Allow concealed carry.\nD. Nothing."},
//     // {4, "What should the government do for abortion?\nA. Ban it.\nB. Allow it.\nC. Allow it, but not with federal funds.\nD. Nothing."},
//     // {5, "What should the government do for healthcare?\nA. Create a single payer system.\nB. Allow people to buy insurance across state lines.\nC. Repeal Obamacare.\nD. Nothing."}
// };

// std::map<int, std::string> readSurveyFile(std::ifstream &file)
// {
//   std::map<int, std::string> answers;
//   std::string line;
//   int questionNumber = 1;

//   while (std::getline(file, line))
//   {
//     answers[questionNumber] = line;
//     questionNumber++;
//   }

//   return answers;
// }

// std::string guessPoliticalParty(std::string userAnswers)
// {
//   // get answers from .txt files
//   std::ifstream democratAnswersFile("democrat.txt");
//   std::ifstream republicanAnswersFile("republican.txt");
//   std::ifstream independentAnswersFile("independent.txt");
//   std::ifstream greenAnswersFile("green.txt");

//   std::map<std::string, std::map<int, std::string>> partyAnswers;
//   partyAnswers["democrat"] = readSurveyFile(democratAnswersFile);
//   partyAnswers["republican"] = readSurveyFile(republicanAnswersFile);
//   partyAnswers["independent"] = readSurveyFile(independentAnswersFile);
//   partyAnswers["green"] = readSurveyFile(greenAnswersFile);

//   // partyAnswers example object = {
//   //    democrat: {
//   //      1: {"A",
//   //      2: "C",
//   //      3: "A"
//   //    },
//   //    republican: {
//   //      1: "B",
//   //      2: "D",
//   //      3: "B"
//   //    },
//   //    independent: {
//   //      1: "C",
//   //      2: "A",
//   //      3: "C"
//   //    },
//   //    green: {
//   //      1: "D",
//   //      2: "B",
//   //      3: "D"
//   //    }
//   //  }

//   // make a variable totalSurveyAnswers equal the number of objects in each party's answers in the partyAnswers variable
//   int totalSurveyAnswers = 0;
//   for (const auto &party : partyAnswers)
//   {
//     totalSurveyAnswers += party.second.size();
//   }

//   // find the percentage of answers for each political party compared to all total answers
//   // create the variables. There should be 4 of these variables (example name: percentOfAnswersDemocrat)
//   // the 4 variables should equal 100% when added together
//   double percentOfAnswersDemocrat = (static_cast<double>(partyAnswers["democrat"].size()) / totalSurveyAnswers) * 100;
//   double percentOfAnswersRepublican = (static_cast<double>(partyAnswers["republican"].size()) / totalSurveyAnswers) * 100;
//   double percentOfAnswersIndependent = (static_cast<double>(partyAnswers["independent"].size()) / totalSurveyAnswers) * 100;
//   double percentOfAnswersGreen = (static_cast<double>(partyAnswers["green"].size()) / totalSurveyAnswers) * 100;

//   // example of answersKey response
//   // {
//   // question 1
//   //     "1": {
//   // answer "A"
//   //         "A": {
//   // times a democrat answered "A" for question 1
//   //             "democrat": 3,
//   //             "republican": 10,
//   //             "independent": 4,
//   //             "green": 1
//   //         },
//   //         "B": {
//   //             "democrat": 12,
//   //             "republican": 3,
//   //             "independent": 1,
//   //             "green": 6
//   //         },
//   //         "C": {
//   //             "democrat": 4,
//   //             "republican": 9,
//   //             "independent": 4,
//   //             "green": 3
//   //         },
//   //         "D": {
//   //             "democrat": 11,
//   //             "republican": 14,
//   //             "independent": 0,
//   //             "green": 8
//   //         }
//   //     },
//   //     "2": {
//   //         "A": {
//   //             "democrat": 12,
//   //             "republican": 10,
//   //             "independent": 6,
//   //             "green": 1
//   //         },
//   //         "B": {
//   //             "democrat": 12,
//   //             "republican": 10,
//   //             "independent": 9,
//   //             "green": 6
//   //         },
//   //         "C": {
//   //             "democrat": 4,
//   //             "republican": 9,
//   //             "independent": 2,
//   //             "green": 3
//   //         },
//   //         "D": {
//   //             "democrat": 13,
//   //             "republican": 14,
//   //             "independent": 0,
//   //             "green": 8
//   //         }
//   //     }
//   // }

//   // create an answersKey variable
//   std::map<std::string, std::map<std::string, std::map<std::string, int>>> answersKey;

//   // loop through each question
//   for (const auto &question : questions)
//   {
//     std::map<std::string, std::map<std::string, int>> oneQuestion;

//     // loop through each possible answer
//     for (char answer = 'A'; answer <= 'D'; answer++)
//     {
//       std::map<std::string, int> oneAnswer;

//       // loop through each party
//       for (const auto &party : partyAnswers)
//       {

//         // the key value of each party
//         // the value should be the number of times the answer shows up in the .txt file / the percentOfAnswers variable for that party
//         // add key-value pair to the oneAnswer object
//         oneAnswer[party.first] = partyAnswers[party.first][question.first].find(answer) != std::string::npos ? partyAnswers[party.first][question.first].find(answer) : 0;

//         // oneAnswer[party.first] = party.second[question.first].find(answer) != std::string::npos ? party.second[question.first].find(answer) : 0;
//       }

//       std::map<std::string, int> partyAnswer;
//     }

//     int main()
//     {
//       std::cout << "*** Welcome to the political parties survey. ****\n";
//       std::string userInput;
//       std::string answers;
//       int questionNumber = 1;
//       do
//       {
//         std::cout << questions[questionNumber] << "\n";
//         std::cout << "[ANSWER] : ";
//         getline(std::cin, userInput);
//         // add answer to survey results
//         answers += std::to_string(questionNumber) + "|" + userInput + "\n";
//         questionNumber++;
//         // exit loop when user has answered all questions
//       } while (questionNumber <= questions.size());
//       // guess what political party user belongs to
//       std::cout << "Based on your answers, you are most likely a " << guessPoliticalParty(answers) << ".\n";
//       // ask user what political party they belong to: democrat, republican, independent, or green
//       std::cout << "Which of these political parties do you identify with: democrat, republican, independent, or green?"
//                 << "\n";
//       std::cout << "[ANSWER] : ";
//       std::string party;
//       getline(std::cin, party);
//       // validate user response
//       std::transform(party.begin(), party.end(), party.begin(), ::tolower);
//       while (party != "democrat" && party != "republican" && party != "independent" && party != "green")
//       {
//         std::cout << "Invalid party. Please enter democrat, republican, independent, or green.";
//         getline(std::cin, party);
//       }
//       // store response in corresponding .txt file
//       std::ofstream saveAnswers(party + ".txt", std::ios::app); // Open the file in append mode
//       if (saveAnswers.is_open())
//       {
//         saveAnswers << answers;
//         saveAnswers.close();
//       }
//       else
//       {
//         std::cout << "Unable to open file";
//       }
//       return 0;
//     }

import json
import random



def execute_code():
    with open("./most_common_answers.json", "r") as f:
        data = json.load(f)

    parties = ["democrat", "republican", "independent", "green"]

    # for party in parties:
    #     with open(f"../{party}.txt", "w") as f:
    #         for index in range(1, random.randrange(3, 20)):
    #             for i in range(1, 6):
    #                 f.write(f"{i}|{random.choice(['A', 'B', 'C', 'D'])}\n")

    with open("./user-answers.txt", "r") as f:
        userAnswers = f.read()
    
    partyAnswers = {}
    # loop through line breaks in the .txt files
    for party in parties:
        partyAnswers[party] = {}
        with open(f"../{party}.txt", "r") as f:
            for line in f:
                # split the line into a list
                line = line.split("|")

                # if the question number is not in the dictionary, add it
                if line[0] not in partyAnswers[party]:
                    partyAnswers[party][line[0]] = []
                # add the answer to the list
                partyAnswers[party][line[0]].append(line[1].strip("\n"))



  # make a variable totalSurveyAnswers equal the number of objects in each party's answers in the partyAnswers variable
    totalSurveyAnswers = {}
    for party in parties:
        totalSurveyAnswers[party] = {"totalAnswers": 0}
        with open(f"../{party}.txt", "r") as f:
            for line in f:
                totalSurveyAnswers[party]["totalAnswers"] += 1

  # find the percentage of answers for each political party compared to all total answers
  # create the variables. There should be 4 of these variables (example name: percentOfAnswersDemocrat)
  # the 4 variables should equal 100% when added together

    for party in totalSurveyAnswers:
        totalSurveyAnswers[party]["percentOfAnswers"] = totalSurveyAnswers[party]["totalAnswers"] / sum([totalSurveyAnswers[party]["totalAnswers"] for party in totalSurveyAnswers])
    



    answerKey = {}
#   loop through each question
    for question in range(1, 5):
        question = str(question)
        # loop through each possible answer
        for answer in ["A", "B", "C", "D"]:
            # loop through each party
            for party in parties:
                # the key value of each party
                # the value should be the number of times the answer shows up in the .txt file / the percentOfAnswers variable for that party
                if question not in answerKey:
                    answerKey[question] = {}
                if answer not in answerKey[question]:
                    answerKey[question][answer] = {}
                if party not in answerKey[question][answer]:
                    answerKey[question][answer][party] = 0
                answerKey[question][answer][party] = partyAnswers[party][question].count(answer) / totalSurveyAnswers[party]["percentOfAnswers"]
    
    
    print(answerKey)
    userAnswers = userAnswers.split("\n")

    weightedResults = {
        "democrat": 0,
        "republican": 0,
        "independent": 0,
        "green": 0
    }
    for result in userAnswers:
        [question, answer] = result.split("|")
        for party in answerKey[question][answer]:
            weightedResults[party] += answerKey[question][answer][party]
    print(max(weightedResults, key=weightedResults.get))

    return max(weightedResults, key=weightedResults.get)

execute_code()
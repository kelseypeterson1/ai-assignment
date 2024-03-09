def execute_code(userAnswers):
    parties = ["democrat", "republican", "independent", "green"]

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


  # count the total survey results for each party
    totalSurveyAnswers = {}
    for party in parties:
        totalSurveyAnswers[party] = {"totalAnswers": 0}
        with open(f"../{party}.txt", "r") as f:
            for line in f:
                totalSurveyAnswers[party]["totalAnswers"] += 1

    #find the percentage of entries for each party compared to the total number of entries
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
                # add an object where the the key should be the party
                # and the value should be the number of times the answer shows up in the .txt file / the percentOfAnswers variable for that party
                # this will take into account the number of entries for each party, and adjust the weight of the answer accordingly
                if question not in answerKey:
                    answerKey[question] = {}
                if answer not in answerKey[question]:
                    answerKey[question][answer] = {}
                if party not in answerKey[question][answer]:
                    answerKey[question][answer][party] = 0
                answerKey[question][answer][party] = partyAnswers[party][question].count(answer) / totalSurveyAnswers[party]["percentOfAnswers"]
        
    # remove line breaks from userAnswers
    userAnswers = userAnswers.split("\n")

    weightedResults = {
        "democrat": 0,
        "republican": 0,
        "independent": 0,
        "green": 0
    }
    # loop through each answer and add a weighted result for each party with that answer
    for result in userAnswers:
        [question, answer] = result.split("|")
        for party in answerKey[question][answer]:
            weightedResults[party] += answerKey[question][answer][party]
    print(max(weightedResults, key=weightedResults.get))

    return max(weightedResults, key=weightedResults.get)

execute_code()
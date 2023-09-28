#pragma once
#include "clsMathGame.h"


class clsMathGameScreen
{
    short HowManQuestion()
    {
        cout << "How Many Question Do You Want To Answer : ";
        short QuestionsNumber;
        cin >> QuestionsNumber;
        while (QuestionsNumber < 1 || QuestionsNumber>100)
        {
            cin >> QuestionsNumber;
        }
        return QuestionsNumber;
    }

    short WhatIsLevel()
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix : ";
        short QuestionsLevel;
        cin >> QuestionsLevel;
        while (QuestionsLevel < 1 || QuestionsLevel>4)
        {
            cin >> QuestionsLevel;
        }
        cout << endl << endl;
        return QuestionsLevel;
    }

    short whatIsOperationsType()
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ";
        short OperationsType;
        cin >> OperationsType;
        while (OperationsType < 1 || OperationsType>5)
        {
            cin >> OperationsType;
        }
        return OperationsType;
    }

    short ReadUserAnswer()
    {
        short UserAnswer;
        cin >> UserAnswer;
        return UserAnswer;
    }

    void ShowResult(clsMathGame& Game1, short QuestionNumber)
    {
        if (Game1.IsRightAnswer(QuestionNumber))
        {
            cout << "Right Answer :-)\n\n\n";
            return;
        }

        cout << "Wrong Answer :-(\n";
        cout << "Right Answer is : " << Game1.QuestionList[QuestionNumber]._RightAnswer << "\n\n\n";
    }

    void ShowQuestions(clsMathGame& Game1, short QuestionsNumber)
    {
        for (short i = 0; i < QuestionsNumber; i++)
        {
            cout << "Question [" << i + 1 << "/" << QuestionsNumber << "]\n\n";
            cout << Game1.QuestionList[i]._FirstNumber << endl << Game1.QuestionList[i]._SecondNumber;
            cout << "    " << Game1.QuestionList[i].OperationSign << endl;
            cout << "_________________\n";
            Game1.UserAnswer = ReadUserAnswer();
            ShowResult(Game1, i);

        }
    }

    string QuestionsLevel(short Level)
    {
        string Levels[5] = { "","Easy","Med","Hard","Mix" };
        return Levels[Level];
    }

    string OperationsType(short Type)
    {
        string Types[6] = { "","Add","Sub","Mul","Div","Mix" };
        return Types[Type];
    }

    string PassOrFailMassage(bool IsPassed)
    {
        return IsPassed ? "Final Result Is Pass :-)\n" : "Final Result Is Fail :-)\n";
    }

    void ShowFinalResult(clsMathGame Game1)
    {
        cout << "____________________________\n\n";
        cout << PassOrFailMassage(Game1.IsPassed());
        cout << "____________________________\n\n";
        cout << "Number Of Questions     : " << Game1.QuestionsNumber() << endl;
        cout << "Question Level          : " << QuestionsLevel(Game1.QuestionsLevel()) << endl;
        cout << "Operation Type          : " << OperationsType(Game1.OperationsType()) << endl;
        cout << "Number Of Right Answers : " << Game1.NumberOfRightAnswers() << endl;
        cout << "Number Of Wrong Answers : " << Game1.NumberOfWrongAnswers() << endl;
        cout << "____________________________\n\n";
    }

    void StartGame()
    {
        short QuestionsNumber = HowManQuestion();
        clsMathGame Game1(QuestionsNumber, WhatIsLevel(), whatIsOperationsType());
        ShowQuestions(Game1, QuestionsNumber);
        ShowFinalResult(Game1);
    }
    void ResetScreen()
    {
        system("cls");
        system("color 0F");
    }
public:
    void Play()
    {
        char Answer = 'y';
        for (; tolower(Answer) == 'y';)
        {
            ResetScreen();
            StartGame();
            cout << "Do You Want To Play Again [Y/N] : ";
            cin >> Answer;
        }

    }
};

#pragma once
#include <iostream>
using namespace std;

class clsMathGame
{
    short _QuestionsNumber;
    enum enQuestionsLevel { EasyL = 1, MedL = 2, HardL = 3, MixL = 4 };
    enum enOperationsType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOP = 5 };
    enQuestionsLevel _QuestionsLevel;
    enOperationsType _OperationsType;
    int _UserAnswer;
    short _NumberOfRightAnswers = 0;
    short _NumberOfWrongAnswers = 0;
    struct QuestionDetails
    {
        short _FirstNumber;
        short _SecondNumber;
        int _RightAnswer;
        char OperationSign;
    };

    int RandomNumber(int From, int To)
    {
        //Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    void QuestionNumberValidation(short& QuestionsNumber)
    {
        while (QuestionsNumber < 1 || QuestionsNumber>100)
        {
            cin >> QuestionsNumber;
        }
    }

    void QuestionLevelValidation(short& QuestionsLevel)
    {
        while (QuestionsLevel < 1 || QuestionsLevel>4)
        {
            cin >> QuestionsLevel;
        }
    }

    void OperationTypeValidation(short& OperationsType)
    {
        while (OperationsType < 1 || OperationsType>5)
        {
            cin >> OperationsType;
        }
    }

    void GenerateEasyLevelNumbers(QuestionDetails& QuestionList)
    {
        QuestionList._FirstNumber = RandomNumber(1, 10);
        QuestionList._SecondNumber = RandomNumber(1, 10);
    }

    void GenerateMedLevelNumbers(QuestionDetails& QuestionList)
    {
        QuestionList._FirstNumber = RandomNumber(11, 50);
        QuestionList._SecondNumber = RandomNumber(11, 50);
    }

    void GenerateHardLevelNumbers(QuestionDetails& QuestionList)
    {
        QuestionList._FirstNumber = RandomNumber(51, 100);
        QuestionList._SecondNumber = RandomNumber(51, 100);
    }

    bool IsMixLevel()
    {
        return _QuestionsLevel == MixL;
    }

    void GenerateNumbers(short QuestionNumber)
    {
        enQuestionsLevel TempQuestionsLevel = _QuestionsLevel;
        if (IsMixLevel())
        {
            TempQuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
        }
        switch (TempQuestionsLevel)
        {
        case clsMathGame::EasyL:
            GenerateEasyLevelNumbers(QuestionList[QuestionNumber]);
            break;
        case clsMathGame::MedL:
            GenerateMedLevelNumbers(QuestionList[QuestionNumber]);
            break;
        case clsMathGame::HardL:
            GenerateHardLevelNumbers(QuestionList[QuestionNumber]);
            break;
        default:
            break;
        }
    }

    int AddOperation(QuestionDetails QuestionList)
    {
        return QuestionList._FirstNumber + QuestionList._SecondNumber;
    }

    int SubOperation(QuestionDetails QuestionList)
    {
        return QuestionList._FirstNumber - QuestionList._SecondNumber;
    }

    int MulOperation(QuestionDetails QuestionList)
    {
        return QuestionList._FirstNumber * QuestionList._SecondNumber;
    }

    int DivOperation(QuestionDetails QuestionList)
    {
        return QuestionList._FirstNumber / QuestionList._SecondNumber;
    }

    bool IsMixOperations()
    {
        return _OperationsType == MixOP;
    }

    void CalcRightAnswers(short QuestionNumber)
    {
        enOperationsType TempOperationsType = _OperationsType;
        if (IsMixOperations())
        {
            TempOperationsType = (enOperationsType)RandomNumber(1, 4);
        }
        switch (TempOperationsType)
        {
        case clsMathGame::Add:
            QuestionList[QuestionNumber]._RightAnswer = AddOperation(QuestionList[QuestionNumber]);
            QuestionList[QuestionNumber].OperationSign = '+';
            break;
        case clsMathGame::Sub:
            QuestionList[QuestionNumber]._RightAnswer = SubOperation(QuestionList[QuestionNumber]);
            QuestionList[QuestionNumber].OperationSign = '-';
            break;
        case clsMathGame::Mul:
            QuestionList[QuestionNumber]._RightAnswer = MulOperation(QuestionList[QuestionNumber]);
            QuestionList[QuestionNumber].OperationSign = '*';
            break;
        case clsMathGame::Div:
            QuestionList[QuestionNumber]._RightAnswer = DivOperation(QuestionList[QuestionNumber]);
            QuestionList[QuestionNumber].OperationSign = '/';
            break;
        default:
            break;
        }
    }

    void GenerateQuestionList()
    {
        for (short i = 0; i < _QuestionsNumber; i++)
        {
            GenerateNumbers(i);
            CalcRightAnswers(i);
        }
    }

public:
    QuestionDetails QuestionList[100];
    clsMathGame(short QuestionsNumber, short QuestionsLevel, short OperationsType)
    {
        QuestionNumberValidation(QuestionsNumber);
        QuestionLevelValidation(QuestionsLevel);
        OperationTypeValidation(OperationsType);
        _QuestionsNumber = QuestionsNumber;
        _QuestionsLevel = (enQuestionsLevel)QuestionsLevel;
        _OperationsType = (enOperationsType)OperationsType;
        GenerateQuestionList();
    }

    void SetUserAnswer(short UserAnswer)
    {
        _UserAnswer = UserAnswer;
    }
    short GetUserAnswer()
    {
        return _UserAnswer;
    }
    __declspec(property(get = GetUserAnswer, put = SetUserAnswer)) short UserAnswer;

    short QuestionsNumber()
    {
        return _QuestionsNumber;
    }
    short NumberOfRightAnswers()
    {
        return _NumberOfRightAnswers;
    }
    short NumberOfWrongAnswers()
    {
        return _NumberOfWrongAnswers;
    }
    short QuestionsLevel()
    {
        return _QuestionsLevel;
    }
    short OperationsType()
    {
        return _OperationsType;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    bool IsRightAnswer(short QuestionNumber)
    {
        if (QuestionList[QuestionNumber]._RightAnswer == UserAnswer)
        {
            _NumberOfRightAnswers++;
            return true;
        }
        _NumberOfWrongAnswers++;
        return false;
    }

    bool IsPassed()
    {
        return _NumberOfRightAnswers >= _NumberOfWrongAnswers;
    }
};
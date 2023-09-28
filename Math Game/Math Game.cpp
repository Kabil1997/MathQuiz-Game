#include "clsMathGameScreen.h"

struct Question
{
    int FirstNumber;
    int SecondNumber;
    int RightAnswer;
    int Operation;
};
int RandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void GeneratQuestionList(short QuestionNumber)
{
    Question Questions[100];
    for (short i = 0; i < QuestionNumber; i++)
    {
        Questions[i].FirstNumber = RandomNumber(1, 100);
    }
}


int main()
{
    clsMathGame::Srand();
    clsMathGameScreen Game;
    Game.Play();
}

//This Project will be a game of Stone, Paper, Scissor The User should input how many rounds and will be facing the Computer
//After each round the result will be shown
//If computer wins the round a bill shall be rang and the screen shalll be red 
//If Player wins the round show gree screnn
//After all rounds show game over than print game results, then ask the user if it want to play again

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <windows.h>
using namespace std;



enum enChoice
{
	Stone = 1,
	Paper = 2,
	Scisoor = 3
};

int RandNum(int From, int To)
{
	int Num;
	Num = rand() % (To - From + 1) + From;
	return Num;
}
int NumofRounds()
{
	int NumOfRounds;
	do
	{
		cout << "How many rounds 1 to 10 : " << endl;
		cin >> NumOfRounds;
	} while (NumOfRounds <= 0||NumOfRounds>10);
	return NumOfRounds;
}


enChoice ComputerChoice()
{
	short Choice;
	Choice = RandNum(1, 3);
	return enChoice(Choice);
}
enChoice GetPlayer1Choise()
{
	short Player1Choice;
	do
	{
		cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissor ?";
		cin >> Player1Choice;
	} while (Player1Choice > 3 || Player1Choice < 1);
	return enChoice(Player1Choice);
}


string GetChoiceTurnIntoString(enChoice Choice)
{
	switch (Choice)
	{
	case enChoice::Paper:
	{
		return "Paper";
		break;
	}
	case enChoice::Stone:
	{
		return "Stone";
		break;
	}
	case enChoice::Scisoor:
	{
		return "Scisoor";
		break;
	}
	}
}
string GetRoundWinner(enChoice Player1Choice, enChoice ComputerChoice, int& Player1WinCount, int& ComputerWinCount, int& DrawCount)
{
	int Result = (Player1Choice - ComputerChoice + 3) % 3;

	if (Result == 1)
	{
		system("Color 2F");
		Player1WinCount++;
		return "Player1 Wins";
	}
	else if (Result == 0)
	{
		system("color 6F");
		DrawCount++;
		return "Draw";
	}
	else
	{
		system("color 4F");
		ComputerWinCount++;
		return "Computer wins";
	}
}


void Result(int RoundNum, int Player1WinCount, int ComputerWinCount, int DrawCount)
{
	cout << "\t\t-------------------------------------------------------------\n" << endl;
	cout << "                \t\t +++ G a m e   O v e r +++                     ";
	cout << "\n\n\t\t-------------------------------------------------------------" << endl;
	cout << "\n\n";
	cout << "\t\t_______________________ [ Game Results  ]____________________\n" << endl;
	cout << "\t\tGame Rounds           : " << RoundNum << endl;
	cout << "\t\tPlayer1 Won timmes    : " << Player1WinCount << endl;
	cout << "\t\tComputer won times    : " << ComputerWinCount << endl;
	cout << "\t\tDraw times            : " << DrawCount << endl;
	cout << "\t\tFinal Winner          : ";
	if (Player1WinCount > ComputerWinCount)
	{
		system("color 2F");
		cout << "Player1" << endl;
		
	}
	else if (ComputerWinCount > Player1WinCount)
	{
		system("color 4F");
		cout << "Computer" << endl;
		
	}
	else
	{
		system("color 6F");
		cout << "Draw" << endl;
		
	}
	cout << "\t\t-------------------------------------------------------------\n" << endl;

}
void RoundResults(int RoundNum, int &Player1WinCount, int &ComputerWinCount, int &DrawCount)
{
	enChoice Player1Choice = GetPlayer1Choise();
	enChoice PcChoice = ComputerChoice();


	cout << "\n\nRound [" << RoundNum << "] Begins :" << endl;
	cout << "\n--------------Round[" << RoundNum << "]--------------" << endl;
	cout << "\nPlayer 1 Choice : " << GetChoiceTurnIntoString(Player1Choice);
	cout << "\nComputer Choice : " << GetChoiceTurnIntoString(PcChoice);
	cout << "\nRound Winner : " << GetRoundWinner(Player1Choice, PcChoice, Player1WinCount, ComputerWinCount, DrawCount);
	cout << "\n----------------------------------------------";
	cout << "\n\n\n";
}

void StartGame()
{

	int Player1WinCount = 0, ComputerWinCount = 0, DrawCount = 0;
	char Newgame = 'Y';

	do
	{
		int NumberOfRounds = NumofRounds();

		for (int i = 1; i <= NumberOfRounds; i++)
		{
			RoundResults(i, Player1WinCount, ComputerWinCount, DrawCount);
		}

		Result(NumberOfRounds, Player1WinCount, ComputerWinCount, DrawCount);

		cout << " Play Again : \n Y/N :";
		cin >> Newgame;

	}while(Newgame == 'y' || Newgame == 'Y');


}



int main()
{
	srand((unsigned)time(NULL));

	StartGame();
	
}


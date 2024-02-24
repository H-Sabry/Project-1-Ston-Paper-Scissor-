// Project [1]  [Ston-Paper-Scissor].cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;
struct stGeameResoult
{
	string Ston = "Ston";
	string Paper = "Paper";
	string Scissor = "Scissor";
	string PlayerName = "Hassan";
	string ComputerName = "Computer";
	string NotWinner = "No Winner";
	short ManyRounds;
	short PlayersNumber;
	short ComputerNumber;
	short ChackWinnerPlayers;
	
};
enum enGeamsResoult
{
	Ston = 1,
	Paper = 2,
	Scissor = 3
	
};
enum enGeamsPlayers {
	Player = 1,
	Computer = 2,
	NoWinner = 3
};
static short ReadPositiveNumber(string Message,short From,short To)
{
	short Number;
	do
	{
		cout << Message ;
		cin >> Number;
	} while (Number < From || Number > To);
	return Number;
}
static bool ReadPlayAgain()
{
	char Read;
	cout << "\t\t\tDo You Want To Play Again Y/N : ";
	cin >> Read;
	if (Read == 'y' || Read == 'Y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
static int CriatRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
static string Tabs(short NumberOfTabs)
{
	stGeameResoult Name;
	switch (NumberOfTabs)
	{
	case enGeamsResoult::Ston:
		return Name.Ston;
	case enGeamsResoult::Paper:
		return Name.Paper;
	case enGeamsResoult::Scissor:
		return Name.Scissor;
	}
}
static string PlayerResoult(short NumberOfTabs)
{
	stGeameResoult Name;
	switch (NumberOfTabs)
	{
	case enGeamsPlayers::Player:
		return Name.PlayerName;
	case enGeamsPlayers::Computer:
		return Name.ComputerName;
	case enGeamsPlayers::NoWinner:
		return Name.NotWinner;
	}
}
static void ShowScrianRound(short Round,string HSPlayerChoice,string ComputerChoice,string RoundWinner)
{
	cout << "\n\n-------------------Round[" << Round << "]---------------------\n";
	cout << "HSPlayer Choice: " << HSPlayerChoice << endl;
	cout << "Computer Choice: " << ComputerChoice << endl;
	cout << "  Round Winner : [" << RoundWinner << "]" << endl;
	cout << "------------------------------------------------\n\n";
}
static void ShowScrianGameOver(short ManyRounds, short PlayerResoults ,short ComputerResult,short NotWinnerResoult,string NameWinner)
{
	cout << "\t\t\t-------------------------------------------------------------------\n";
	cout << "\t\t\t\t                  |-- Game Over --|                              \n";
	cout << "\t\t\t-------------------------------------------------------------------\n\n";
	cout << "\t\t\t-------------------------|[ Game Resoults ]|-----------------------\n";
	cout << "\t\t\tGame Rounds           :" << ManyRounds << "\n";
	cout << "\t\t\tPlayers won Times     :" << PlayerResoults << "\n";
	cout << "\t\t\tComputer won Times    :" << ComputerResult << "\n";
	cout << "\t\t\tDraw Times            :" << NotWinnerResoult << "\n";
	cout << "\t\t\tFinal Winner          :" << NameWinner << "\n";
	cout << "\t\t\t-------------------------------------------------------------------\n";
}
static short ChackWinnerPlayers(short Players, short Computer)
{
	if (Players == Computer)
	{
		return enGeamsPlayers::NoWinner;
	}
	else if (
		Players == enGeamsResoult::Ston &&
		Computer == enGeamsResoult::Paper ||
		Players == enGeamsResoult::Scissor &&
		Computer == enGeamsResoult::Ston ||
		Players == enGeamsResoult::Paper && 
		Computer == enGeamsResoult::Scissor )
	{
		return enGeamsPlayers::Computer;
	}
	else 	
		return enGeamsPlayers::Player;
}
static void ColorTheGames(short Chack)
{
	switch (Chack)
	{
	case enGeamsPlayers::Player:
		system("Color 2F"); 
		break;
	case enGeamsPlayers::Computer:
		system("Color 4F ");
		cout << "\a";
		break;
	case enGeamsPlayers::NoWinner:
		system("Color 6F");
		break;
	default:
		system("Color 0F") && system("Cls");
		break;
	}
}
static void ChackResoultGame(short Resoult,short &PlayerResoult,short &ComputerResult,short &NotWinnerResoult)
{
	
	switch (Resoult)
	{
	case enGeamsPlayers::Player:
		PlayerResoult += 1;
		break;
	case enGeamsPlayers::Computer:
		ComputerResult += 1;
		break;
	case enGeamsPlayers::NoWinner:
		NotWinnerResoult += 1;
		break;
	}
}
static void RoundBegins(short ManyRounds)
{
	stGeameResoult PlayersNumber;
	short PlayerResoults = 0, ComputerResult = 0, NotWinnerResoult = 0,Winner;
	for (short i = 1; i <= ManyRounds; i++)
	{
		cout << "Round[" << i << "]Begins:" << endl;
		PlayersNumber.PlayersNumber = ReadPositiveNumber("Your Choice: [1]:Ston [2]:Paper [3]:Scissor ? ",1,3);
		PlayersNumber.ComputerNumber = CriatRandomNumber(1, 3);
		PlayersNumber.ChackWinnerPlayers = ChackWinnerPlayers(PlayersNumber.PlayersNumber, PlayersNumber.ComputerNumber);
		
		ChackResoultGame(PlayersNumber.ChackWinnerPlayers,PlayerResoults,ComputerResult,NotWinnerResoult);
		ColorTheGames(PlayersNumber.ChackWinnerPlayers);
		ShowScrianRound(i, Tabs(PlayersNumber.PlayersNumber), Tabs(PlayersNumber.ComputerNumber), PlayerResoult(PlayersNumber.ChackWinnerPlayers));
	}
	if (PlayerResoults > ComputerResult)
		Winner = 1;
	else if (ComputerResult > PlayerResoults)
		Winner = 2;
	else 
		Winner = 3;
	ShowScrianGameOver(ManyRounds,PlayerResoults,ComputerResult,NotWinnerResoult,PlayerResoult(Winner));

}
static void StartGeams()
{
	stGeameResoult GameResoult;
	char Start = 'Y';
	do
	{
		GameResoult.ManyRounds = ReadPositiveNumber("How Many Round 1 To 10 ? ", 1, 10);
		RoundBegins(GameResoult.ManyRounds);
		Start = ReadPlayAgain();
		if (Start > 0)
		{
			ColorTheGames(4);
		}
	} while (Start == 'Y' || Start == 'y');

}
int main()
{
	srand((unsigned)time(NULL));
	StartGeams();
	

}

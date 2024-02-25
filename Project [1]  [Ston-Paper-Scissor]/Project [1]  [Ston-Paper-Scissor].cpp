// Project [1]  [Ston-Paper-Scissor].cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
using namespace std;
enum enGameChoice { Ston = 1,Paper = 2,Scissor = 3	};
enum enWinner { Player = 1,Computer = 2,NoWinner = 3 };
struct stRoundInfo 
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName; 
}; 
struct stGameResults
{
	short GameRounds = 0;
	short Player1WinTimes = 0;
	short Computer2WinTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string WinnerName = "";
};
static void ResetScreen()
{
	system("cls");
	system("color f0");
}
static string Tabs(short LengthTab)
{
	string Tabs = "";
	for (short i = 0; i < LengthTab; i++)
	{
		Tabs += "\t";
		cout << Tabs;
	}
	return Tabs;
}
static enGameChoice ReadPlayer1Choice() 
{
	short Choice = 1;
	do 
	{ 
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? "; 
		cin >> Choice; 
	} 
	while (Choice < 1 || Choice >3);
	return (enGameChoice)Choice; 
}
static int CriatRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}
static enGameChoice GitComputerChoice()
{
	return (enGameChoice)CriatRandomNumber(1, 3);
}
static string WennirName(short NumberOfTabs)
{
	string WennirName[3] = {" Player "," Computer "," NotWennir "};
	return WennirName[NumberOfTabs - 1];
}
static string ChoiceName(enGameChoice Choice)
{
	string WennirName[3] = { " Ston "," Paper "," Scissor " };
	return WennirName[Choice - 1];
}
static void ShowScrianRound(stRoundInfo RoundInfo)
{
	cout << "\n\n-------------------Round[" << RoundInfo.RoundNumber << "]---------------------\n";
	cout << "HSPlayer Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "  Round Winner : [" << RoundInfo.WinnerName << "]" << endl;
	cout << "------------------------------------------------\n\n";
}
static void ShowGameOverScreen() 
{ 
	cout << Tabs(2) << "__________________________________________________________\n\n";  
	cout << Tabs(2) << "                 +++ G a m e  O v e r +++\n";   
	cout << Tabs(2) << "__________________________________________________________\n\n"; 
}
static void SetWinnerScreenColor(enWinner Winner) 
{
	switch (Winner) 
	{
	case enWinner::Player: 
		system("Color 2F "); //turn screen to Greenbreak;
		break;
	case enWinner::Computer: 
		system("Color 4F ");  //turn screen to Red  
			cout << "\a";
		break;
	default:     
		system("Color 6F "); //turn screen to Yellowbreak; 
    }
}
static void ShowFinalGameResults(stGameResults GameResults) 
{ 
	cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n"; 
	cout << Tabs(2) << "Game Rounds        : " << GameResults.GameRounds << endl;   
	cout << Tabs(2) << "Player1 won times  : " << GameResults.Player1WinTimes << endl;   
	cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl;  
	cout << Tabs(2) << "Draw times         : " << GameResults.DrawTimes << endl;   
	cout << Tabs(2) << "Final Winner       : " << GameResults.WinnerName << endl;  
	cout << Tabs(2) << "___________________________________________________________\n"; 
	SetWinnerScreenColor(GameResults.GameWinner); 
}
static enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::NoWinner;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Ston:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissor)
		{
			return enWinner::Computer;
		}
		break;
	case enGameChoice::Scissor:
		if (RoundInfo.ComputerChoice == enGameChoice::Ston)
		{
			return enWinner::Computer;
		}
		break;
	}
	return enWinner::Player;
	
}
static enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes) 
{
	if (Player1WinTimes > ComputerWinTimes) 
		return enWinner::Player;
	else if(ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else 
		return enWinner::NoWinner;
}
static stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes) 
{ 
	stGameResults GameResults; 
	GameResults.GameRounds = GameRounds; 
	GameResults.Player1WinTimes = Player1WinTimes; 
	GameResults.Computer2WinTimes = ComputerWinTimes;   
	GameResults.DrawTimes = DrawTimes;  
	GameResults.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);  
	GameResults.WinnerName = WennirName(GameResults.GameWinner);
	return GameResults; }


static stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short PlayerResoults = 0, ComputerResult = 0, NotWinnerResoult = 0,Winner;
	
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "Round[" << GameRound << "]Begins:" << endl;
		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GitComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WennirName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player)
			PlayerResoults++;
		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerResult++;
		else
			NotWinnerResoult++;

	
		ShowScrianRound(RoundInfo);
	}
	return FillGameResults(HowManyRounds, PlayerResoults, ComputerResult, NotWinnerResoult);
}
static void StartGeams()
{
	stGameResults GameResoult;
	char Start = 'Y';
	do
	{
		ResetScreen();
		GameResoult = PlayGame(ReadPlayer1Choice());

		ShowGameOverScreen();
		ShowFinalGameResults(GameResoult);

		cout << endl << Tabs(3) << " Do you want to play again? Y/N? ";
		cin >> Start;
		
	} while (Start == 'Y' || Start == 'y');

}
int main()
{
	srand((unsigned)time(NULL));
	StartGeams();
	

}

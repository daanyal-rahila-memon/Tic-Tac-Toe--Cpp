#include <iostream>
#include <cstring>
#include <string>
#include <ctime>

using namespace std;

string player_one, player_two, choice = "y";
bool mark = true;
int drawn = 0, playerOne_win = 0, playerTwo_win = 0, tiles = 0;

void main_menu();
void play_game();
int player_toss();
void playerOne_turn(string str[3][3], int toss);
void playerTwo_turn(string str[3][3], int toss);
void check(string str[3][3], int i, int toss);
void check_to_win(int toss, string str[3][3]);
void score();
void instructions();
void credits();

int main()
{
	srand(time(0));
	while (choice == "y" || choice == "Y")
	{
		main_menu();
	}
	system("pause");
	return 0;
}

//Main Menu Function leads you to Game, Instructions, scores & Credits
void main_menu()
{
	char choose;
	cout << "===========Welcome to 'TIC TAC TOE!' (PLAYER vs PLAYER)============" << endl;
	cout << "Below is the 'Main Menu' for you;" << endl;
	cout << "Press 1 for Play Game" << endl;
	cout << "Press 2 for Instructions" << endl;
	cout << "Press 3 for Score" << endl;
	cout << "Press 4 for Credits" << endl;
	cout << "Choose one of the above: ";
	cin >> choose;

	while (choose < '1' || choose > '4')
	{
		cout << "Enter one of the above options ( 1 To 4): ";
		cin >> choose;
	}
	switch (choose)
	{
	case '1':
	{
		play_game();
		break;
	}
	case '2':
	{
		instructions();
		break;
	}
	case '3':
	{
		score();
		break;
	}
	case '4':
	{
		credits();
		break;
	}
	default:
	{
		cout << "You've entered wrong option...Enter again :)" << endl;
		cout << "Do you want to go to 'Main Menu'?" << endl;
		cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'No': ";
		cin >> choice;
		if (choice == "y" || choice == "Y")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}
		break;
	}
	}
}

//Play Game Function lead you to play game Player Vs Player
void play_game()
{
	cout << "Welcome to Game!" << endl;

	cin.ignore();

	cout << "Enter the Name of Player 1: ";
	getline(cin, player_one);

	cout << "Enter the Name of Player 2: ";
	getline(cin, player_two);

	string str[3][3] = { {"1","2","3"},{"4","5","6"},{"7","8","9"} };
	int toss = player_toss();
	if (toss == 0)
	{
		cout << player_one << " won the Toss!" << endl;
	}
	else
	{
		cout << player_two << " won the Toss!" << endl;
	}
	if (toss == 0)
	{
		playerOne_turn(str, toss);
	}
	else
	{
		playerTwo_turn(str, toss);
	}
}

/*Player toss Function helps to determine which player will do the turn 1st
=> Toss is '0', it represents the turn of Player One whereas Toss '1' represents the turn of Player Two*/

int player_toss()
{
	return rand() % 2;
}

//playerOne_turn Function helps Player One to Play its Turn.
void playerOne_turn(string str[3][3], int toss)
{
	system("cls");		// clear the screen

	toss = 0;

	// Drawing Game-Board
	cout << " " << str[0][0] << " | " << str[0][1] << " | " << str[0][2] << " " << endl;
	cout << "___ ___ ___" << endl;
	cout << " " << str[1][0] << " | " << str[1][1] << " | " << str[1][2] << " " << endl;
	cout << "___ ___ ___" << endl;
	cout << " " << str[2][0] << " | " << str[2][1] << " | " << str[2][2] << " " << endl;

	int turn;
	cout << "'" << player_one << "'" << " Turn. At which place you want to put your Mark: ";
	cin >> turn;

	while (turn < 1 || turn > 9)		// check for a valid position
	{
		cout << "You got only 9 places to choose, choose one of them: ";
		cin >> turn;
	}

	switch (turn)
	{
	case 1:
	{
		check(str, turn, toss);			// check() inspects if the place has already been marked or not.
		str[0][0] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 2:
	{
		check(str, turn, toss);
		str[0][1] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 3:
	{
		check(str, turn, toss);
		str[0][2] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 4:
	{
		check(str, turn, toss);
		str[1][0] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 5:
	{
		check(str, turn, toss);
		str[1][1] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 6:
	{
		check(str, turn, toss);
		str[1][2] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 7:
	{
		check(str, turn, toss);
		str[2][0] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 8:
	{
		check(str, turn, toss);
		str[2][1] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	case 9:
	{
		check(str, turn, toss);
		str[2][2] = "O";
		check_to_win(toss, str);
		playerTwo_turn(str, toss);
		break;
	}
	default:
		break;
	}
}
//playerTwo_turn Function helps Player Two to Play its Turn.
void playerTwo_turn(string str[3][3], int toss)
{
	system("cls");
	toss = 1;
	cout << " " << str[0][0] << " | " << str[0][1] << " | " << str[0][2] << " " << endl;
	cout << "___ ___ ___" << endl;
	cout << " " << str[1][0] << " | " << str[1][1] << " | " << str[1][2] << " " << endl;
	cout << "___ ___ ___" << endl;
	cout << " " << str[2][0] << " | " << str[2][1] << " | " << str[2][2] << " " << endl;
	bool mark = true;
	int turn;
	cout << player_two << " Turn: ";
	cout << "At which place you want to put your Mark: ";
	cin >> turn;
	while (turn<1 || turn>9)
	{
		cout << "You got only 9 places to choose, kindly choose one of them: ";
		cin >> turn;
	}
	
	switch (turn)
	{
	case 1:
	{
		check(str, turn, toss);
		str[0][0] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 2:
	{
		check(str, turn, toss);
		str[0][1] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 3:
	{
		check(str, turn, toss);
		str[0][2] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 4:
	{
		check(str, turn, toss);
		str[1][0] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 5:
	{
		check(str, turn, toss);
		str[1][1] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 6:
	{
		check(str, turn, toss);
		str[1][2] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 7:
	{
		check(str, turn, toss);
		str[2][0] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 8:
	{
		check(str, turn, toss);
		str[2][1] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	case 9:
	{
		check(str, turn, toss);
		str[2][2] = "X";
		check_to_win(toss, str);
		playerOne_turn(str, toss);
		break;
	}
	default:
		break;
	}
}

// Check Function inspect if that place has already been marked or not.
void check(string str[3][3], int i, int toss)
{
	if (toss == 0)
	{
		if (i == 1)
		{
			if (str[0][0] == "O" || str[0][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 2)
		{
			if (str[0][1] == "O" || str[0][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 3)
		{
			if (str[0][2] == "O" || str[0][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 4)
		{
			if (str[1][0] == "O" || str[1][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 5)
		{
			if (str[1][1] == "O" || str[1][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 6)
		{
			if (str[1][2] == "O" || str[1][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 7)
		{
			if (str[2][0] == "O" || str[2][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 8)
		{
			if (str[2][1] == "O" || str[2][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
		else if (i == 9)
		{
			if (str[2][2] == "O" || str[2][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerOne_turn(str, toss);
			}
		}
	}
	else
	{
		if (i == 1)
		{
			if (str[0][0] == "O" || str[0][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 2)
		{
			if (str[0][1] == "O" || str[0][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 3)
		{
			if (str[0][2] == "O" || str[0][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 4)
		{
			if (str[1][0] == "O" || str[1][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 5)
		{
			if (str[1][1] == "O" || str[1][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 6)
		{
			if (str[1][2] == "O" || str[1][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 7)
		{
			if (str[2][0] == "O" || str[2][0] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 8)
		{
			if (str[2][1] == "O" || str[2][1] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
		else if (i == 9)
		{
			if (str[2][2] == "O" || str[2][2] == "X")
			{
				cout << "This place has already marked, choose another one :)" << endl;
				cout << "Press any key to continue..." << endl;
				int c = getchar();
				playerTwo_turn(str, toss);
			}
		}
	}
}

//check_to_win Function helps to recogonise which Player has won the game or either it is drawn.
void check_to_win(int toss, string str[3][3])
{
    tiles++;
	if (toss == 0)
	{
		if (str[0][0] == "O" && str[0][1] == "O" && str[0][2] == "O" || str[0][0] == "O" && str[1][0] == "O" && str[2][0] == "O" || str[0][0] == "O" && str[1][1] == "O" && str[2][2] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "O" && str[0][1] == "O" && str[0][2] == "O" || str[0][1] == "O" && str[1][1] == "O" && str[2][1] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "O" && str[0][1] == "O" && str[0][2] == "O" || str[0][2] == "O" && str[1][2] == "O" && str[2][2] == "O" || str[0][2] == "O" && str[1][1] == "O" && str[2][0] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "O" && str[1][0] == "O" && str[2][0] == "O" || str[1][0] == "O" && str[1][1] == "O" && str[1][2] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "O" && str[1][0] == "O" && str[2][0] == "O" || str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[2][0] == "O" && str[1][1] == "O" && str[0][2] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[0][1] == "O" && str[1][1] == "O" && str[2][1] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[0][2] == "O" && str[1][2] == "O" && str[2][2] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[1][0] == "O" && str[1][1] == "O" && str[1][2] == "O" || str[0][2] == "O" && str[1][2] == "O" && str[2][2] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[1][0] == "O" && str[1][1] == "O" && str[1][2] == "O" || str[0][1] == "O" && str[1][1] == "O" && str[2][1] == "O")
		{
			cout << "Congratulations!" << player_one << " has won the Game" << endl;
			playerOne_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
	}
	else if (toss == 1)
	{
		if (str[0][0] == "X" && str[0][1] == "X" && str[0][2] == "X" || str[0][0] == "X" && str[1][0] == "X" && str[2][0] == "X" || str[0][0] == "X" && str[1][1] == "X" && str[2][2] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "X" && str[0][1] == "X" && str[0][2] == "X" || str[0][1] == "X" && str[1][1] == "X" && str[2][1] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "X" && str[0][1] == "X" && str[0][2] == "X" || str[0][2] == "X" && str[1][2] == "X" && str[2][2] == "X" || str[0][2] == "X" && str[1][1] == "X" && str[2][0] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "X" && str[1][0] == "X" && str[2][0] == "X" || str[1][0] == "X" && str[1][1] == "X" && str[1][2] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[0][0] == "O" && str[1][0] == "O" && str[2][0] == "O" || str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[2][0] == "O" && str[1][1] == "O" && str[0][2] == "O")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[0][1] == "O" && str[1][1] == "O" && str[2][1] == "O")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[2][0] == "O" && str[2][1] == "O" && str[2][2] == "O" || str[0][2] == "O" && str[1][2] == "O" && str[2][2] == "O")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[1][0] == "X" && str[1][1] == "X" && str[1][2] == "X" || str[0][2] == "X" && str[1][2] == "X" && str[2][2] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
		else if (str[1][0] == "X" && str[1][1] == "X" && str[1][2] == "X" || str[0][1] == "X" && str[1][1] == "X" && str[2][1] == "X")
		{
			cout << "Congratulations! " << player_two << " has won the Game" << endl;
			playerTwo_win++;
			cout << "Do you want to Play Again?" << endl;
			cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				main_menu();
			}
			else
			{
				exit(0);
			}
		}
	}

	if(tiles == 9)			// check for if all the tiles are filled or not
	{
		cout << "The game has drawn...Try again Next Time :)" << endl;
		drawn++;
		cout << "Do you want to Play Again?" << endl;
		cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'Exit': ";
		cin >> choice;
		if (choice == "y" || choice == "Y")
		{
			main_menu();
		}
		else
		{
			exit(0);
		}
	}
}

 //Instructions Function tells you the Instruction of Game.
 void instructions()
 {
	 cout << "The Mark of Player 1 is: O" << endl;
	 cout << "The Mark of Player 2 is: X" << endl;
	 cout << "Do you want to go to 'Main Menu'?" << endl;
	 cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'No': ";
	 cin >> choice;
	 if (choice == "y" || choice == "Y")
	 {
		 main_menu();
	 }
	 else
	 {
		 exit(0);
	 }
 }

//Score Function shows you the Score Board.
 void score()
{
	cout << "'Welcome to Score Board'" << endl;
	cout << "Games won by" << player_one << ": " << playerOne_win << endl;
	cout << "Games won by" << player_two << ": " << playerTwo_win << endl;
	cout << "Games that have been drawn: " << drawn << endl;
	cout << "Do you want to go to 'Main Menu'?" << endl;
	cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'No': ";
	cin >> choice;
	if (choice == "y" || choice == "Y")
	{
		main_menu();
	}
	else
	{
		exit(0);
	}
}

 //Credits Function shows you by whom this game is been made.
 void credits()
 {
	 cout << "This game is made by 'Muhammad Daanyal'" << endl;
	 cout << "We'll meet soon with better games :)" << endl;
	 cout << "Do you want to go to 'Main Menu'?" << endl;
	 cout << "Press 'y' for 'Yes' & 'Any Other Key' for 'No': ";
	 cin >> choice;
	 if (choice == "y" || choice == "Y")
	 {
		 main_menu();
	 }
	 else
	 {
		 exit(0);
	 }
 }
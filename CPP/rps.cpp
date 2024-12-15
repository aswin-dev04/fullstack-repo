#include <ctime>
#include <iostream>
#include <cstdlib>
#include <limits>


int main()
{
	system("clear");
	std::srand(std::time(0));
	char again;
	int playerWon{0},compWon{0};
	do
	{
		std::string choice[] = {"Rock","Paper","Scissors"};
		int compChoice=rand()%3,playerChoice{0};
		std::cout << "Enter your choice: (0 = Rock, 1 = Paper, 2 = Scissors): ";
		while (!(std::cin >> playerChoice) || playerChoice < 0 || playerChoice > 2) {
            std::cout << "Invalid input! Please enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
		if(playerChoice==compChoice)std::cout<<"It is a tie! Go again!\n";
		else if((playerChoice==0&&compChoice==2)||(playerChoice==1&&compChoice==0)||(playerChoice==2&&compChoice==1)){std::cout<<"You win!\n";playerWon++;}
		else {std::cout<<"You lose!\n";compWon++;}
		std::cout<<"Score:  Player: "<<playerWon<<"  Computer: "<<compWon<<"\n";
		std::cout<<"Do you want to play again? : ";
		std::cin>>again;
	}while(again=='y'||again=='Y');
	if(again!='y'&&again!='Y')system("clear");
	return 0;
}


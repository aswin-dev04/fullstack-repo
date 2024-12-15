#include <ctime>
#include <iostream>
#include <cstdlib>
#include <limits>

int main()
{
	std::srand(std::time(0));
	const int key=std::rand()%10;
	int tries{0},guess{0};
	std::cout<<"How many tries would you like? : ";
	while (!(std::cin>>tries)||tries <= 0) 
	{
        std::cout << "Please enter a valid positive number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
	do
	{
		sub:
		std::cout<<"Enter your guess(0-9): ";
		std::cin>>guess;
		if(guess<0||guess>9){std::cout<<"Please enter a valid guess!\n";goto sub;}
		if(key==guess){std::cout<<"Great! You guessed right!\n";return 0;}
		else std::cout<<"Wrong! Try again!\n";
		--tries;
	}while(tries>0);
	std::cout<<"Ran out of tries! You lost!\n";
	std::cout<<"The correct answer is: "<<key<<"\n";

	return 0;
}


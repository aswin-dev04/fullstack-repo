#include <ctime>
#include <iostream>
#include <cstdlib>
#include <string>


std::string genPasswd(int length)
{
	std::srand(std::time(0));
	const std::string lower = "abcdefghijklmnopqrstuvwxyz";
	const std::string upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const std::string num = "0123456789";
	const std::string symbols = "-_!@#*()/?.><[]{},";
	const std::string allChar = lower+upper+num+symbols;

	std::string pass{""};
	int ind{0};
	for(int i{0};i<length;++i)
	{
		ind=std::rand()%allChar.length();
		pass+=allChar[ind];
	}
	return pass;
}
		



int main()
{
	int len{0};
sub:
	std::cout<<"Enter the password length of choice: ";
	std::cin>>len;
	if(len>0)std::cout<<"\nYour password is: "<<genPasswd(len)<<"\n";
	else{std::cout<<"Length cannot be 0 or less!\n";goto sub;}
	return 0;
}




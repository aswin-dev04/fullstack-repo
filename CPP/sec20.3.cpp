#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include <utility>



void display(const std::map<std::string,int> &words) 
{
	std::cout<<std::setw(15)<<std::left<<"Word"<<std::setw(5)<<std::right<<"Count\n";
	std::cout<<std::setw(21)<<std::setfill('=')<<"\n";
	std::cout<<std::setfill(' ');
	for(auto pair:words)
	{
	std::cout<<std::setw(15)<<std::left<<pair.first<<std::setw(5)<<std::right<<pair.second<<"\n";
	}
}




void part1()
{
	std::map<std::string, int> words;
	std::string word;
	std::ifstream file{"oz.txt"};

	if(file)
	{
		int word_count{};
		while(file>>word){
			word_count++;
			words.insert(std::make_pair(word,word_count));
		}
		file.close();
		display(words);
	}
	else std::cerr<<"\nError opening the file\n";
}

int main()
{
	part1();
	return 0;
}





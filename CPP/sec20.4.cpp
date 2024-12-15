#include <ios>
#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <queue>
#include <vector>



bool is_palindrome(std::string s)
{
	std::stack<char> stk;
	std::queue<char> q;
	char c1{};
	char c2{};
	for(char c:s){
		if(std::isalpha(c)){
			stk.push(std::toupper(c));
			q.push(std::toupper(c));
		}
	}
	while(!q.empty())
	{
		c1=stk.top();
		stk.pop();
		c2=q.front();
		q.pop();
		if(c1!=c2) return false;
	}
	return true;
}


int main()
{
	std::cout<<std::boolalpha;
	std::vector<std::string> vec{"mom","Dad","RaDar","madaM","nah"};
	for(auto v:vec)
	{
		std::cout<<v<<' '<<is_palindrome(v)<<"\n";
	}
	return 0;
}


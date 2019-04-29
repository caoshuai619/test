#include <iostream>
#include <string>
#include <stack>
using namespace std;


void ReverseString(string &str){
	stack<char> s;
	for(int i=0;i<str.size();i++ ){
		s.push(str[i]);
		
	}
	int i=0;
	while(!s.empty()){
		str[i] = s.top();
		s.pop();
		i++;
	}
}

int main()
{
	string s="hello";
	ReverseString(s);
	cout<<s<<endl;
	return 0;
}
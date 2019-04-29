#include "iostream"
#include "stack"
#include "string"
using namespace std;
void Swap(char &a,char &b)
{
	char temp=a;
	a=b;
	b=temp;
}

void Reverse(string &s){
	int i=0;
	int j=s.size()-1;
	while(i<j){
		Swap(s[i++],s[j--]);
	}
}
int main()
{
	string s="hello";
	Reverse(s);
	cout<<s<<endl;
	return 0;
}
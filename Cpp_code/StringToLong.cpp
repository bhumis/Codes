//============================================================================
// Name        : StringToLong.cpp
// Author      : Bhumi Sabarwal
//============================================================================

//You can modify the string "s" in main() which would be converted to long by function stringToLong()

#include <iostream>
using namespace std;

long stringToLong(const string &s)
{
	bool isneg=false;
	int ind=0;
	long num=0;

// We define valid strings as the ones matching the Regexp -?[0-9]+
	if(s=="-")
		throw invalid_argument("\n Invalid input: contains only sign and no number");

	if(s[0]=='-')
	{
		isneg=true;
		ind++;
	}

	while(ind<s.length())
	{
		if(isdigit(s[ind]))
		{
		num=num*10+(s[ind]-'0');
		ind++;
		}
		else{
			throw invalid_argument("invalid input: contains character");
		}
	}

	if(isneg==true)
	{
		num=num*(-1);
	}


	return(num);
}

int main() {

	string s="-1234";

	long num= stringToLong(s);

	cout<<"\n Generated number is  "<<num;
    
    long i= stringToLong("123");
    if(i==123)
       cout<<"\n success";
    else
        cout<<"\n failure";
    
	return 0;
}

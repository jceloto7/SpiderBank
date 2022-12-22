#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
using namespace std;

class Client{
    string name;
	int CPF;
	int password;

public:
	Client();
	Client(string name,int CPF, int password);

	
	string getPersonalData();
	int getPassword();
	
};


#endif;
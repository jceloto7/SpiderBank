#include "Client.hpp"
#include <string>
using namespace std;



Client::Client(){

	}
	

Client::Client(string name, int CPF, int password){
	this->name = name;
	this->CPF = CPF;
	this->password = password;
	}
	
	string Client::getPersonalData(){
	 std::string personalData = "Name: " + name + "\n" + "CPF: " + std::to_string(CPF);
	
		return personalData;
		}
	
	int Client::getPassword(){
		return password;
		}
		
	
		
	
	
	
	


#include <iostream>
#include <string>
#include <iomanip>
#include "Client.hpp"
#include "ClientList.hpp"
using namespace std;

ClientList *clientList = new ClientList;
Client *clientData;
int clientPassword;
string name;
int CPF;
int password;
int index =0;
int opt = 0;

void clientMenu(int index){
int opt = 0;
float balance =0;
float deposit;
float withdraw;


while (opt !=6){
	cout<< "Client Menu. Please, choose your option" <<endl;
	cout << "1 - See balance." << endl;
	cout << "2 - Withdraw money." << endl;
	cout << "3 - See my personal data." << endl;
	cout << "4 - Make deposit." << endl;
	cout << "5 - Erase account." << endl;
	cout << "6 - Return to main menu." << endl;
	cin >> opt;

	switch(opt){
		case 1:
		if (balance == 0){
			 cout<< "Your balance is $" <<balance<< endl; 
			}
		else{
			cout<< fixed << setprecision(2);
			cout<< "Your balance is $" <<balance<< endl;  
			}
		break;
		
		case 2:
		cout<< "How much money do you want to withdraw: "<<endl;
		cin>> withdraw;
		if (balance<withdraw){
			cout<< "Insufficient funds. Please see your balance."<<endl; 
			}
		else{
			balance = balance - withdraw;
			cout<< "Withdrawal successful. You're not getting the dirty name, are you?"<<endl;
			}	
		break;
		
		case 3:
		cout<< "Your personal data: \n"<<clientData->getPersonalData()<<endl;
		break;
		
		case 4:
		cout<< "How much money do you want to deposit: ";
		cin>> deposit;
		balance = balance + deposit;
		cout<<  "Deposit made successfully. You are getting rich!" <<endl;
		break;
		
		case 5:
		clientList->remove(index);
		cout<< "Account removed!"<<endl;
		opt =6;
		break;
		
		case 6:
		cout<< "Bye!" << endl;
		break;
		
		default:
		cout<< "Invalid option";
		}
	}	 
}	
	
void mainMenu(){
int opt =0;	

cout<< "Welcome to Spider Bank ^-^ "<< endl;
while (opt !=3){
		cout << "Main Menu. Please choose an option:"<< endl;
		cout << "1 - Create account"<< endl;
		cout << "2 - Enter in your account"<< endl;
		cout << "3 - Exit"<<endl;
		cin>>opt;
		
		switch(opt){
			case 1:
			cout<<"What's your name? ";
			cin>> name;
			cout<< "What's your CPF? Please, only type numbers. ";
			cin>> CPF;
			cout<<"Type your number password:";
			cin>> password;
			
			clientData = new Client(name,CPF,password);
			clientList->add(clientData);
			break;
			
			case 2:
			cout<< "Type your index: ";
			cin>> index;
			clientData = clientList->get(index);
			
			while(clientData == NULL ){
				cout << "Account unknown. Please review your data."<<endl;
				cout<< "Type your index:"<<endl;
				cin>> index;
				}
			
			cout<< "Type your password: ";
			cin>> password;
			clientPassword=clientData->getPassword();
			
			while(password!=clientPassword){
				cout<<"Wrong password. Please try again."<<endl;
				cout<<"Type your password: ";
				cin>> password;
				}
			
			clientMenu(index);
			break;	
			
			case 3:
			cout <<"Thanks for using Spider Bank"<< endl;
			break;

			default:
			cout<< "Invalid option!"<< endl;	
			}			
			
	} 
}
	
int main(int argc, char **argv){
	mainMenu();
	}
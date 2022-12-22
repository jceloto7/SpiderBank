#include "NodeClient.hpp"

NodeClient::NodeClient(Client* data){
	this->data=data;
	this->next = NULL;
}

NodeClient* NodeClient::getNext(){
	return this->next;
}

Client* NodeClient::getData(){
	return this->data;
}

void NodeClient::setNext(NodeClient* next){
	this->next = next; 
}
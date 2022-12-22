#include "ClientList.hpp"
#include "Client.hpp"
#include "NodeClient.hpp"
#include <iostream>
using namespace std;

ClientList::ClientList(){
	this->first= NULL;
}

Client* ClientList::get(int index){
	NodeClient *target = this->first;
	int i;
	if(target == NULL){
        return NULL;
    }
    for(i = 0; i < index; i++){
        target = target->getNext();
        if(target==NULL){
            break;
        }
    }
    if(target != NULL){
        return target->getData();
    }else{
        return NULL;
    }
	
}
	
	
	void ClientList::add(Client *data){
    
	NodeClient *target;
    NodeClient *newData = new NodeClient(data);
    
	if(first==NULL){
        first = newData;
    }else{
        target = first;
        while(target->getNext() != NULL){
            target = target->getNext();
        }
        target->setNext(newData);
    }
}

bool ClientList::remove(int index){
    NodeClient *target = first;
    NodeClient *aux;
    int i;
    if(target==NULL){
        return false;
    }
    if(index == 0){
        first = first->getNext();
        target->setNext(NULL);
        delete target;
    }else{
        for(i=0; i<index-1; i++){
            target = target->getNext();
            if(target==NULL){
                break;
            }
        }
        if(target==NULL){
            return false;
        }else if(target->getNext()==NULL){
            return false;
        }else{
            aux = target->getNext();
            target->setNext(target->getNext()->getNext());
            aux->setNext(NULL);
            delete aux;
        }
    }
    return true;
	
}	

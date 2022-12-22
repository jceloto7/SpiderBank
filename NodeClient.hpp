#ifndef NODECLIENT_HPP
#define NODECLIENT_HPP
#include "Client.hpp"

class NodeClient{
	Client *data;
	NodeClient *next;
	
public:
	NodeClient(Client *Data);
	
	void setNext(NodeClient *next);
	NodeClient* getNext();
	Client* getData();
	
};

#endif
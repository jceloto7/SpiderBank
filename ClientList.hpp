#ifndef CLIENTLIST_HPP
#define CLIENTLIST_HPP

#include "NodeClient.hpp"
#include "Client.hpp"

class ClientList{
	NodeClient *first;
	
public:
	ClientList();
	Client* get(int index);
	void add(Client *data);
	bool remove (int index);
};

#endif
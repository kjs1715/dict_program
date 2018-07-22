#include "Client.h"

Client::Client() : _funcbase(NULL)
{

}

Client::~Client()
{

}

void Client::setStrategy(Funcbase* funcbase)
{
    this->_funcbase = funcbase;
}

void Client::Menu()
{
    this->_funcbase->initialize();
}

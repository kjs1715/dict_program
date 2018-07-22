#ifndef CLIENT_H
#define CLIENT_H

#include "Funcbase.h"
#include "jiyi.h"
#include "Graph.h"
#include "Database.h"
#include "ManageWords.h"
#include "NewFrame.h"
#include "Referdic.h"
#include "WordNode.h"
#include "Viewfunc.h"
#include <iostream>

class Client
{
public:
    Client();
    ~Client();
    void setStrategy(Funcbase*);
    void Menu();
private:
    Funcbase *_funcbase;
};

#endif

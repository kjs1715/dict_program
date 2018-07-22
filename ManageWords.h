#ifndef MANAGEWORDS_H
#define MANAGEWORDS_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Database.h"
#include "WordNode.h"
#include"Funcbase.h"

using namespace std;

class ManageWords:public Funcbase
{
public:
    ManageWords();
    void addWord();
    void deleteWord();
    void modifyWord();
    virtual void initialize();
    virtual void browseDic();
};



#endif

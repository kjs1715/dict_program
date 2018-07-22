#ifndef FUNCBASE_H_
#define FUNCBASE_H_

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Database.h"
#include"WordNode.h"

using namespace std;

class Funcbase 
{
public:
    virtual void initialize()=0;
    virtual void browseDic()=0;
    void exitSystem();
    void printBlankLines(int n);
    DataBase dataBase;
    DataBase dataBase2;
};

#endif //FUNCBASE_H_

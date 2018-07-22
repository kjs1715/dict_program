#ifndef NEWFRAME_H
#define NEWFRAME_H

#include "WordNode.h"
#include "DataBase.h"
#include "Funcbase.h"
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

class NewFrame : public Funcbase
{
public:
    NewFrame();
    ~NewFrame();
    void initialize();
    void browseDic();
    void RemindMe();
    void Pause();
    void Pause(int);
    void Mnemonics();
    void search(string);
    void exam();
    //背单词练习
    void exercise();
    //阅读文件
    void readfile();
private:
    DataBase dataBase;
    DataBase dataBase2;
};

#endif

#ifndef VIEWFUNC_H
#define VIEWFUNC_H

#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "Database.h"
#include "WordNode.h"
#include"Funcbase.h"
#include"Referdic.h"

using namespace std;

//与前台显示有关的功能在该类中声明并实现
class Viewfunc:public Funcbase{
public:
    //空构造函数
    Viewfunc();
    //初始化整个界面
    void initialize();
    //浏览词典
    void browseDic();
private:
    Referdic referdic;
    static int order;

};

#endif

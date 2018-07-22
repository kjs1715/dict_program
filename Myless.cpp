#include<iostream>
#include<string>
#include "WordNode.h"

using namespace std;

//用来辅助排序
class myless
{
public:
    //重载运算符，为排序做准备
    bool operator()(WordNode a, WordNode b) {
        //按照字典序排列
        return a.getEnglish() < b.getEnglish();
    }
};

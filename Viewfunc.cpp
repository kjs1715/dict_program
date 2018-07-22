#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include "DataBase.h"
#include "WordNode.h"
#include"Viewfunc.h"

using namespace std;

int Viewfunc::order = 0;

Viewfunc::Viewfunc():referdic("dictionary.txt")
{
}
void Viewfunc::initialize()
{
    bool valid=true;
    //循环执行
    while(1){
        
        this->printBlankLines(5);
        cout<<"********************************轻松查单词************************************"<<endl;
        this->printBlankLines(5);
        cout<<"                                1.查看词典                                     "<<endl;
        cout<<"                                2.返回主菜单                                     "<<endl;
        this->printBlankLines(2);
        //判断上次输入是否有效
        if(valid == true)
            cout<<"请输入您的选择：";
        else cout<<"输入无效，请重新输入：";
        
        cin>>order;
        //判断输入是否有效
        if((order>0) && (order<3))
            valid=true;
        //无效则需要重新输入
        else{
            valid=false;
            
            continue;
        }
        
        //根据用户输入选择不同功能
        if(order == 1)
            this->browseDic();
        else if(order == 2)
            return;
    }
}
void Viewfunc::browseDic()
{
    this->printBlankLines(5);
       if(order == 1){
        
        cout<<"请输入要查询的单词：";
        string english;
        int number;
        cin>>english;
        //未找到相应单词
        number=this->referdic.binarySearch(english);
        if(number < 0){
            cout<<"找不到单词"<<english<<endl;
            
            return;
        }
        //找到了相应的单词
        else{
            cout<<endl;
            cout<<"释义、词性及例句："<<this->referdic.getWordNode(number).getChinese()<<endl;
            cout<<this->referdic.getWordNode(number).getSynonyms()<<endl;
            
            return;
        }
    }
}

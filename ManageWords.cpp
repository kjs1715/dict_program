#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<ctime>
#include<cstring>
#include<iomanip>
//#include"MyFrame.h"
#include<fstream>
#include<memory.h>
#include<cstdio>
#include"ManageWords.h"

using namespace std;

ManageWords::ManageWords()
{
    
}

//添加新单词
void ManageWords::addWord(){
    string english;
    string chinese;
    string synonyms;
    string antonyms;
    
    this->printBlankLines(3);
    cout<<"请输入待添加的新单词：";
    cin>>english;
    //查找该单词是否已经存在
    if(this->dataBase.binarySearch(english)>=0){
        cout<<"单词"<<english<<"已经存在！"<<endl;
        cout<<"添加失败"<<endl;
        
        return;
    }
    cout<<"请输入单词的中文解释：";
    cin>>chinese;
    cout<<"请输入单词的近义词";
    cin>>synonyms;
    cout<<"请输入单词的反义词";
    cin>>antonyms;
    WordNode wordNode(english,chinese,synonyms,antonyms);
    this->dataBase.addWordNode(wordNode);
    ofstream ofile("dic.txt",ios_base::app);
    ofile<<english<<" "<<chinese<<" "<<synonyms<<" "<<antonyms<<endl;
    ofile.close() ;
    cout<<"成功添加单词！"<<endl;
    //重新对单词进行排序
    this->dataBase.sortWords();
    
    return;
}

//删除已有的单词
void ManageWords::deleteWord(){
    string english;
    string chinese;
    
    this->printBlankLines(3);
    cout<<"请输入要删除的单词：";
    cin>>english;
    //查找相应的单词是否存在
    int number=this->dataBase.binarySearch(english);
    //单词不存在
    if(number<0){
        cout<<"单词"<<english<<"不存在！"<<endl;
        cout<<"删除失败！"<<endl;
        
        return;
    }
    //查找到了相应单词
    else{
        this->dataBase.deleteWordNode(number);
        cout<<"成功删除单词！"<<endl;
        
        return;
    }
    return;
}

//修改现有的单词
void ManageWords::modifyWord(){
    string english;
    string chinese;
    string synonyms;
    string antonyms;
    
    this->printBlankLines(3);
    cout<<"请输入要修改的单词：";
    cin>>english;
    //二分查找相应的单词
    int number=this->dataBase.binarySearch(english);
    //未找到输入的单词
    if(number<0){
        cout<<"单词"<<english<<"不存在！"<<endl;
        cout<<"修改单词失败！"<<endl;
        
        return;
    }
    //找到单词
    else{
        cout<<"请输入新的解释:";
        cin>>chinese;
        cout<<"请输入新的近义词:";
        cin>>synonyms;
        cout<<"请输入新的反义词:";
        cin>>antonyms;
        WordNode wordNode(english,chinese,synonyms,antonyms);
        //修改相应的单词
        this->dataBase.setWordNode(number,wordNode);
        cout<<"成功修改单词！"<<endl;
        
        return;
    }
    return;
}

void ManageWords::browseDic()
{
    
}

void ManageWords::initialize()
{
    int order;
    bool valid=true;
    //循环执行
    while(1){
        
        this->printBlankLines(5);
        cout<<"********************************管理单词本************************************"<<endl;
        this->printBlankLines(5);
        cout<<"                                1.添加单词                                     "<<endl;
        cout<<"                                2.删除单词                                     "<<endl;
        cout<<"                                3.修改单词                                     "<<endl;
        cout<<"                                4.返回主菜单                                     "<<endl;
        this->printBlankLines(2);
        //判断上次输入是否有效
        if(valid == true)
            cout<<"请输入您的选择：";
        else cout<<"输入无效，请重新输入：";
        
        cin>>order;
        //判断输入是否有效
        if((order>0) && (order<5))
            valid=true;
        //无效则需要重新输入
        else{
            valid=false;
            
            continue;
        }
        
        //根据用户输入选择不同功能
        if(order == 1)
            this->addWord();
        else if(order == 2)
            this->deleteWord();
        else if(order == 3)
            this->modifyWord();
        else if(order == 4)
            return;
    }
}

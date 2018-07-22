#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include "DataBase.h"
#include "WordNode.h"
#include "Myless.cpp"

using namespace std;

//默认构造函数
DataBase::DataBase()
{
}

DataBase::DataBase(string a){
    string english;
    string chinese;
    string synonyms;
    string antonyms;
    //打开词典文件
    ifstream file(a);
    while(file>>english>>chinese>>synonyms>>antonyms){
        this->wordNode.setChinese(chinese);
        this->wordNode.setEnglish(english);
        this->wordNode.setSynonyms(synonyms);
        this->wordNode.setAntonyms(antonyms);
        //将相应节点插入数据库中
        (this->words).push_back(this->wordNode);
    }
    //关闭文件
    file.close();
}

//返回单词的总数目
int DataBase::getDicSize(){
    return this->words.size();
}

//判断字典是否为空
bool DataBase::isEmpty(){
    if((this->getDicSize())<=0)
        return true;
    return false;
}

//返回下标为i的单词，i不合法则返回空
WordNode DataBase::getWordNode(int i){
    if(i<0 || (i>= (this->getDicSize()))){
        cout<<"下标不合法！"<<endl;
        return *(new WordNode());
    }
    return this->words[i];
}

//修改第i个WordNode节点，失败则返回值为负数
int DataBase::setWordNode(int i,WordNode newWordNode){
    if((i<0) || (i>=this->getDicSize())){
        //cout<<"下标不合法！"<<endl;
        return -1;
    }
    this->words[i]=newWordNode;
    this->sortWords();
    return 1;
}

//添加一个新单词
int DataBase::addWordNode(WordNode wordNode){
    this->words.push_back(wordNode);
    this->sortWords();
    return 0;
}

//删除第i个WordNode节点，失败则返回值为负数
int DataBase::deleteWordNode(int i){
    if((i<0) || (i>=(int)(this->words.size()))){
        //cout<<"下标不合法！"<<endl;
        return -1;
    }
    this->words.erase((this->words.begin())+i);
    return 1;
}

//根据单词二分查找相应的条目，查找失败返回空
int DataBase::binarySearch(string word){
    int left=0;
    int right=this->getDicSize()-1;
    //进行二分查找
    while(left<=right){
        //中间元素
        int middle=(left+right)/2;
        //找到目标
        if(this->words[middle].getEnglish() == word)
            return middle;
        //目标在左半部分
        else if(this->words[middle].getEnglish() > word)
            right=middle-1;
        //目标在右半部分
        else left=middle+1;
    }
    return -1;
    //cout<<"查找失败！"<<endl;
    //return *(new WordNode());
}


//重新对单词按字典序进行排序
void DataBase::sortWords(){
    sort(this->words.begin(), this->words.end(), myless());
    return;
}

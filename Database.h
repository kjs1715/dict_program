#ifndef DATABASE_H
#define DATABASE_H

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "WordNode.h"

using namespace std;

//存放与单词相关的数据
class DataBase{
public:
    //默认构造函数
    DataBase();
    DataBase(string);
    //返回单词的总数目
    int getDicSize();
    //判断字典是否为空
    bool isEmpty();
    //返回下标为i的单词，i不合法则返回空
    WordNode getWordNode(int i);
    //修改第i个WordNode节点，失败则返回值为负数
    int setWordNode(int i,WordNode newWordNode);
    //添加一个新单词
    int addWordNode(WordNode wordNode);
    //删除第i个WordNode节点，失败则返回值为负数
    int deleteWordNode(int i);
    //根据单词二分查找相应的条目，查找失败返回负数
    int binarySearch(string word);
    //重新对单词按字典序进行排序
    void sortWords();
    
private:
    //存放单词，向量内的元素为WordNode类对象
    vector<WordNode> words;
    WordNode wordNode;
};

#endif

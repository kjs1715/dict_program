#ifndef WORDNODE_H
#define WORDNODE_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class WordNode{
public:
    //默认空构造函数
    WordNode();
    //给出英文单词和中文解释的构造函数
    WordNode(string english, string chinese,string synonyms,string antonyms);
    //获取英文内容
    string getEnglish();
    //获取中文内容
    string getChinese();
    //获取近义词
    string getSynonyms();
    //获取反义词
    string getAntonyms();
    //重新设置英文内容
    void setEnglish(string english);
    //重新设置中文内容
    void setChinese(string chinese);
    //重新设置近义词
    void setSynonyms(string synonyms);
    //重新设置反义词
    void setAntonyms(string antonyms);
private:
    //英文单词
    string english;
    //对应的中文语义
    string chinese;
    //近义词
    string synonyms;
    //反义词
    string antonyms;
    
    
};

#endif

#include<iostream>
#include<string>
#include<vector>
#include "WordNode.h"

using namespace std;

//默认空构造函数
WordNode::WordNode(){
}

//给出英文单词和中文解释的构造函数
WordNode::WordNode(string english, string chinese,string synonyms,string antonyms){
    this->english=english;
    this->chinese=chinese;
    this->synonyms=synonyms;
    this->antonyms=antonyms;
    
}

//获取英文内容
string WordNode::getEnglish(){
    return this->english;
}

//获取中文内容
string WordNode::getChinese(){
    return this->chinese;
}

//获取近义词
string WordNode::getSynonyms() {
    return this->synonyms;
}

//获取反义词
string WordNode::getAntonyms() {
    return this->antonyms;
}

//重新设置英文内容
void WordNode::setEnglish(string english){
    this->english=english;
}

//重新设置中文内容
void WordNode::setChinese(string chinese){
    this->chinese=chinese;
}
void WordNode::setSynonyms(string synonyms){
    this->synonyms =synonyms;
}
void WordNode::setAntonyms(string antonyms)
{
    this->antonyms =antonyms;
}

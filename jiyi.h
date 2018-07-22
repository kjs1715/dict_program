#ifndef  JIYI_H
#define  JIYI_H

#include<iostream>
using namespace std;


class jiyi
{
	public:
		void print(int num,int div);									 //输出提示			
		void rowPrint(int num,int static_num,int div );                  //复习内容 
		void newPrint(int ,int ,int);                                    //新学内容 
		bool isDividedEvenly(int ,int);
		void initialize(int ,int );
    private:
		int num;
		int div;                                
};


#endif

#ifndef  JIYI_H
#define  JIYI_H

#include<iostream>
using namespace std;


class jiyi
{
	public:
		void print(int num,int div);									 //�����ʾ			
		void rowPrint(int num,int static_num,int div );                  //��ϰ���� 
		void newPrint(int ,int ,int);                                    //��ѧ���� 
		bool isDividedEvenly(int ,int);
		void initialize(int ,int );
    private:
		int num;
		int div;                                
};


#endif

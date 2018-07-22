#include<iostream>
#include<string>
#include<vector>
#include"Database.h"
#include"WordNode.h"
//#include"MyFrame.h"
#include"Referdic.h"
#include<fstream>
using namespace std;

Referdic::Referdic()
{
    
}
Referdic::Referdic(string s)
{
    ifstream file(s);
    
    char a;
    string b;
    
    string english = "NULL";
    string details = "NULL";
    string sentence = "NULL";
    
    while(getline(file,b,'\r'))
    {
        //cout << b.size() << endl;
        if(b[0]>='0'&&b[0]<='9')
        {
            int i,j;
            for(i=0;i<b.size();i++)
            {
                if(b[i]>='a'&&b[i]<='z')
                    break;
            }
            for(j=i;j<b.size();j++)
            {
                if(!(b[j]>='a'&&b[j]<='z'))
                    break;
            }
            //cout <<"b[j]"<< b[j]<< endl;
            english = b.substr(i,j-i);
            details = b.substr(j+1,b.size()-1-j);
            //cout <<"english:"<< english << endl;
            //cout <<"details:"<< details << endl;
        }
        for(int o=0;o<10;o++)
        {
            if(b[o]=='*')
            {
                sentence = b.substr(o+4,b.size()-o-4);
                //cout << "sentence:" << sentence << endl;
                this->addWordNode(WordNode(english,details, sentence, "NULL"));
                english="NULL";
                details="NULL";
                sentence="NULL";
            }
        }
        
    }
    file.close();
}

#ifndef Graph_H
#define Graph_H

#include<iostream>
#include"Funcbase.h"
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
#include"WordNode.h"
#include"Database.h"

using namespace std;

class Graph
{
public:
    char* strsub( char const* pStrSrc, int iStart, int iLen );
    int maxComm( char* pStrLeft, char* pStrRight );
    void realize();
    void Cin();
    static char* pStrLeft;
    //static char* pStrRight;
    //static char* strMaxComm;
private:
};


#endif

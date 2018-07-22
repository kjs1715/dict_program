#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include"Database.h"
#include"WordNode.h"
#include"Funcbase.h"

using namespace std;

void Funcbase:: printBlankLines(int n)
    {
        for(int i=0;i<n;i++)
            cout<<endl;
        return;
    }
void Funcbase:: exitSystem()
    {
        exit(0);
    }

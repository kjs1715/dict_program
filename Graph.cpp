#include<iostream>
#include"Funcbase.h"
#include<string>
#include<vector>
#include<algorithm>
#include"WordNode.h"
#include"Database.h"
#include<cstring>
#include<fstream>
#include"Graph.h"

using namespace std;

char* Graph:: pStrLeft = new char[1000];
//char* Graph:: pStrRight = NULL;
//char* Graph:: strMaxComm = NULL;

char* Graph:: strsub( char const* pStrSrc, int iStart, int iLen )
{
    if( !pStrSrc || iStart <  0 )
        return NULL;
    int iStrLen = strlen( pStrSrc );
    char* pStrRes = NULL;
    if( iLen >= iStrLen - iStart )
    {
        pStrRes = (char*)malloc( iStrLen - iStart + 1 );
        if( !pStrRes )
            return NULL;
        memset( pStrRes, 0,  iStrLen - iStart + 1 );
        strncpy( pStrRes, pStrSrc + iStart, iStrLen  - iStart );
        return pStrRes;
    }
    else
    {
        pStrRes = (char*)malloc( iLen + 1 );
        if( !pStrRes )
            return NULL;
        memset( pStrRes, 0, iLen + 1 );
        strncpy( pStrRes, pStrSrc + iStart, iLen );
        return pStrRes;
    }
}

int Graph:: maxComm( char* pStrLeft, char* pStrRight )
{
    if( !pStrLeft || !pStrRight )
    {
        return 0;
    }
    char* pStrLess = NULL;
    char* pStrMore = NULL;
    char* pStrRes= NULL;
    int iLeft = strlen( pStrLeft );
    int iRight = strlen( pStrRight );
    int iLess = ( iLeft <= iRight ) ? iLeft : iRight;
    int i,j;
    if( iLeft <= iRight )
    {
        pStrLess = pStrLeft;
        pStrMore = pStrRight;
    }
    else
    {
        pStrLess = pStrRight;
        pStrMore = pStrLeft;
    }
    for( i = iLess; i > 0; i-- )
    {
        for( j = 0; j <= iLess - i; j++ )
        {
            pStrRes = strsub( pStrLess, j, i );
            if( strstr( pStrMore, pStrRes ) )
                return strlen(pStrRes);
            free( pStrRes );
            pStrRes = NULL;
        }
    }
    return 0;
}

void Graph:: realize()
{
    ifstream fin("dictionary.txt");
    string b;
    string English = "NULL";
    bool xx = 0;
    while(getline(fin,b,'\r'))
    {
        int ans=0;
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
            English = b.substr(i,j-i);
            char* mmm = (char*)English.c_str();
            ans = maxComm( pStrLeft, mmm );
            if(ans>=3)
            {
                xx=1;
                cout << English << "--->";
            }
        }
    }
    if(xx)
    {
        cout << " 是单词 " << pStrLeft << " 的亲缘图" <<endl;
    }
    else
    {
        cout<<" 未找到与单词 "<< pStrLeft << " 拼写上相近的单词"<<endl;
    }
    
    
    fin.close();
    
}

void Graph::Cin()
{
    cout<<"请输入要生成关系图的单词："<<endl;
    cin >> pStrLeft;
}

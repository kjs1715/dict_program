#include<iostream>
#include<string>
#include<vector>
#include "DataBase.h"
#include "WordNode.h"
#include "NewFrame.h"
#include "Funcbase.h"
#include "Graph.h"
#include "Viewfunc.h"
#include "tinyxml.h"
#include "tinystr.h"
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include "jiyi.h"
#include "ManageWords.h"
#include "Client.h"
#include <unistd.h>
using namespace std;

struct word {  //------------xml文件导入的结构
    string dc;
    string meaning;
};

struct book {  //------------txt文件导入的结构
    char num[6];
    char word[20];
    char Phonogram[20];
    char pos[7];
    char meaning[50];
};

void XML() { //--------------xml文件导入函数
    word A[500];
    ofstream fout("rword.txt",ios::app);
    if (!fout) {
        cout << "Fail to open the file" << endl;

    }
    system("chcp 65001");
    const char*filepath = "word.xml";
    TiXmlDocument doc(filepath);
    bool loadOkay = doc.LoadFile();
    if (!loadOkay) {
        cout << "Fail to open the file" << endl;

    }
    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    pElem = hDoc.FirstChildElement().Element();
    TiXmlHandle hRoot(pElem);
    TiXmlElement* itemElem = hRoot.FirstChild("item").Element();
    int count = 0;
    for (itemElem; itemElem; itemElem = itemElem->NextSiblingElement()) {
        TiXmlHandle item(itemElem);
        TiXmlElement* wordElem = item.FirstChild("word").Element();
        TiXmlElement* transElem = item.FirstChild("trans").Element();
        A[count].dc = wordElem->GetText();
        A[count].meaning = transElem->GetText();
        count++;
    }
    for (int i=0; i < 500; i++) {
        fout << A[i].dc <<endl<< A[i].meaning << endl<<endl;
    }
    cout<<"导入文件成功！"<<endl;
}

void TXT() {//--------------TXT文件导入函数
    ifstream fin("word.txt");
    if (!fin) {
        cout << "Fail to open the file\n";

    }
    ofstream fout("rword.txt", ios::app);
    if (!fout) {
        cout << "文件打开失败\n";

    }

    system("chcp 65001");
    book A;
    while (fin >> A.num >> A.word >> A.Phonogram >> A.pos >> A.meaning)
    {
        fout << A.num << "  "
        << A.word << "  "
        << A.pos << "  "
        << A.meaning << endl;
    }

    fin.close();
    fout.close();
    cout<<"导入文件成功！"<<endl;
}

void import()
{
    int g = 0;
    cout << "请问您想导入什么类型的文件（XML类型文件请输入1；TXT文件请输入2；输入0跳过）"<<endl;
    cin >> g;
    if(g==0){
    }
    else if (g==1) {
        XML();
    }
    else if (g==2) {
        TXT();
    }
}

//主函数
int main(){
    while(1)
    {
        int choice, div, num;
        Client * client = new Client();
        for(int i=0;i<5;i++)
        {
            cout<<endl;
        }
        cout<<"********************************轻松背单词************************************"<<endl;
        for(int i = 0; i < 5; i++)
            cout << endl;
        cout<<"                              1.管理单词本                                  "<<endl;
        cout<<"                              2.轻松背单词                                  "<<endl;
        cout<<"                              3.查词典                                     "<<endl;
        cout<<"                              4.生成单词亲缘图                               "<<endl;
        cout<<"                              5.导入其他词典生成的词库         "<<endl;
        cout<<"                              6.艾宾浩斯遗忘曲线助记                 "<<endl;
        cout<<"                              7.退出系统                                    "<<endl;
        for(int i=0;i<3;i++)
            cout<<endl;
        cout<<"请输入你的选择 (1~7) ：";
        cin >> choice;
        if(choice < 1 || choice > 7)
        {
            cout<<"请重新输入..."<<endl;
            cin>>choice;
        }

        if(choice == 1)
        {
            Funcbase * managewords = new ManageWords();
            client->setStrategy(managewords);
            client->Menu();
        }else if(choice == 2){
            Funcbase * newframe = new NewFrame();
            client->setStrategy(newframe);
            client->Menu();
        }else if(choice == 3){
            Funcbase * viewfunc = new Viewfunc();
            client->setStrategy(viewfunc);
            client->Menu();
        }else if(choice == 4){
            Graph graph;
            graph.Cin();
            graph.realize();
        }else if(choice == 5){
            import();
        }else if(choice == 6){
            jiyi Jiyi;
            Jiyi.initialize(div, num);
        }else{
            exit(0);
        }
        system("clear");
    }


    return 0;
}

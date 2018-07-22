#include "NewFrame.h"
#include<iostream>
#include<vector>
#include<string>
#include<vector>
#include<ctime>
#include<cstring>
#include<iomanip>
#include<fstream>
#include<memory.h>
#include<cstdio>
#include<time.h>


NewFrame::NewFrame():dataBase("dic.txt") , dataBase2("alreadylearnt.txt")
{

}

bool alreadyseen(string aa,const vector<string>& xx)
{
    int g=0;
    for(vector<string>::const_iterator iter=xx.begin() ;iter!=xx.end() ;++iter)
    {
        if((*iter)==aa)
        {
            g=1;break;
        }
    }
    if(g==1)return true;
    return false;
}

void NewFrame::initialize(){
    int order;
    bool valid=true;
    //循环执行
    RemindMe();
    for(int i = 0; i < 5; i++)
        sleep(1);
    while(1){

        this->printBlankLines(5);
        cout<<"********************************轻松背单词************************************"<<endl;
        this->printBlankLines(5);
        cout<<"                                1.单词练习                                     "<<endl;
        cout<<"                                2.模拟考试                                     "<<endl;
        cout<<"                                3.查看词典                                     "<<endl;
        cout<<"                                4.助记功能                                     "<<endl;
        cout<<"                                5.阅读文件                                     "<<endl;
        cout<<"                                6.返回主菜单                                     "<<endl;
        this->printBlankLines(2);
        //判断上次输入是否有效
        if(valid == true)
            cout<<"请输入您的选择：";
        else cout<<"输入无效，请重新输入：";

        cin>>order;
        //判断输入是否有效
        if((order>0) && (order<7))
            valid=true;
        //无效则需要重新输入
        else{
            valid=false;

            continue;
        }

        //根据用户输入选择不同功能
        if(order == 1)
            this->exercise();
        else if(order == 2)
            this->exam();
        else if(order == 3)
            this->browseDic();
        else if(order == 6)
            return ;
        else if(order == 5)
            this->readfile();
        else if(order == 4)
            this->Mnemonics();
    }
}

// 打开程序时会提醒
void NewFrame::RemindMe()
{
    this->printBlankLines(3);
    srand(unsigned(time(0)));
    cout<<"********************************每日一提醒************************************"<<endl;
    this->printBlankLines(2);
    int number=rand()%(this->dataBase2.getDicSize());
    cout<<"单词：   "<<this->dataBase2.getWordNode(number).getEnglish()<<endl;
    cout<<endl;
    cout<<"解释：   "<<this->dataBase2.getWordNode(number).getChinese()<<endl;
    cout<<endl;
    cout<<"近义词：  "<<this->dataBase2.getWordNode(number).getSynonyms()<<endl;
    cout<<endl;
    cout<<"反义词：  "<<this->dataBase2.getWordNode(number).getAntonyms()<<endl;
    this->printBlankLines(2);
    return ;
}

// 助记功能
void NewFrame::Mnemonics()
{
    this->printBlankLines(2);
    string english;
    cout<<"请输入需要助记的单词 ： ";
    cin>>english;
    this->printBlankLines(2);
    search(english);
}

void NewFrame::search(string word)
{
    ifstream fin("root.txt");
    string b;
    string English = "NULL";
    bool xx = 0;
    while(getline(fin,b))
    {
        if(b[0]>='0'&&b[0]<='9')
            continue;
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
        if(English == word)
        {
            cout << "方法 ：" << b << endl;
            xx = 1;
            break;
        }
        else
            xx = 0;

        }
    if(xx == 0)
    cout << "找不到" << word << "!!" << endl;
    this->printBlankLines(2);
    int choice;
    cout<<"输入1继续使用助记功能，输入0回到菜单 ："<<endl;
    cin>>choice;
    if(choice == 1)
        Mnemonics();
    else
        return ;

}

void NewFrame::Pause(int i)
{
    cout<<"请按回车键回到主菜单！！"<<endl;
    fgetc(stdin);
}
void NewFrame::browseDic()
{
    int order;

    this->printBlankLines(5);
    //输出提示信息
    cout<<"********************************请选择查看方式*********************************"<<endl;
    this->printBlankLines(5);
    cout<<"                                1.单个查询                                     "<<endl;
    cout<<"                                2.多个浏览                                     "<<endl;
    cout<<"                                3.浏览全部（单屏无法容纳）                     "<<endl;
    this->printBlankLines(3);
    cout<<"请选择浏览方式：";
    cin>>order;
    //检查输入的有效性
    if(!(order>=1 && order<=3)){
        cout<<"输入无效！"<<endl;

        return;
    }

    //分不同输入提供不同功能
    if(order == 1){

        cout<<"请输入要查询的单词：";
        string english;
        int number;
        cin>>english;
        //未找到相应单词
        number=this->dataBase.binarySearch(english);
        if(number < 0){
            cout<<"找不到单词"<<english<<endl;

            return;
        }
        //找到了相应的单词
        else{
            cout<<endl;
            cout<<"释义："<<this->dataBase.getWordNode(number).getChinese()<<endl;

            return;
        }
    }
    //浏览部分单词
    else if(order == 2){
        int begin;
        int length;
        cout<<"请输入要查看单词的起始位置：";
        cin>>begin;
        cout<<"请输入要查看的单词个数：";
        cin>>length;
        if((begin<0) || (length<=0) || (begin+length)>this->dataBase.getDicSize()){
            cout<<"输入无效！无法满足查看要求！"<<endl;

            return;
        }

        for(int i=0;i<length;i++){
            cout<<this->dataBase.getWordNode(begin+i).getEnglish()
            <<"   "<<this->dataBase.getWordNode(begin+i).getChinese()<<endl;
            cout<<"近义词："<<this->dataBase.getWordNode(begin+i).getSynonyms()<<endl;
            cout<<"反义词："<<this->dataBase.getWordNode(begin+i).getAntonyms()<<endl;
        }

        return;
    }
    //浏览全部单词
    else if(order == 3){
        int length=this->dataBase.getDicSize();
        for(int i=0;i<length;i++){
            cout<<this->dataBase.getWordNode(i).getEnglish()
            <<"   "<<this->dataBase.getWordNode(i).getChinese()<<endl;
            cout<<"近义词："<<this->dataBase.getWordNode(i).getSynonyms()<<endl;
            cout<<"反义词："<<this->dataBase.getWordNode(i).getAntonyms()<<endl;
        }

        return;
    }
    return;
}

void NewFrame::exam(){
    int rightorwrong[21];
    memset(rightorwrong,-1,sizeof(int)*21);

    this->printBlankLines(3);
    cout<<"********************************考试说明************************************"<<endl;
    this->printBlankLines(3);
    cout<<"  本考试共有20题，全部为选择题，每题5分。选择你认为正确的答案并输入，回车确认之后即可进入下一题"
    <<endl;
    cout<<"                                Good Luck!                                  "<<endl;
    this->printBlankLines(10);
    //存放单词所对应的编号
    int number[20];
    //记录得分
    int score;
    srand(unsigned(time(0)));
    //随机选取20个单词
    for(int i=0;i<20;i++){
        int tmp=rand()%(this->dataBase.getDicSize());
        bool flag=false;
        //检查随机生成的单词是否重复
        for(int j=0;j<i;j++){
            if(number[j] == tmp)
                flag=true;
        }
        if(flag == true)
            i--;
        else
            number[i]=tmp;
    }

    score=0;
    //开始考试
    for(int i=0;i<20;i++){
        this->printBlankLines(1);
        int meaning[4];
        //随机生成错误答案
        for(int j=0;j<4;j++){
            int tmp=rand()%(this->dataBase.getDicSize());
            bool flag=false;
            //检查是否有重复的情况
            for(int k=0;k<j;k++){
                if(meaning[k] == tmp)
                    flag=true;
            }
            if((flag == true) || (tmp == number[i]))
                j--;
            else
                meaning[j]=tmp;
        }
        //生成正确答案
        int ans=rand()%4;
        meaning[ans]=number[i];
        cout<<"第"<<(i+1)<<"题："<<endl<<endl;
        cout<<"单词"<<this->dataBase.getWordNode(number[i]).getEnglish()
        <<"的意思与下列那个选项符合？"<<endl;
        this->printBlankLines(2);
        for(int j=0;j<4;j++){
            cout<<(char)(j+'A')<<"  "<<this->dataBase.getWordNode(meaning[j]).getChinese()
            <<endl;
        }


        this->printBlankLines(8);
        cout<<"请输入你的答案：";
        while(1){
            string yourAns;
            cin>>yourAns;
            //输入的答案无效
            if( (yourAns.size()!=1) ||
               (yourAns!="A" && yourAns!="B"
                && yourAns!="C" && yourAns!="D")){
                   cout<<"输入无效，请重新输入：";
                   continue;
               }
            else{
                //答案正确
                if(yourAns[0] == (ans+'A'))
                {
                    score+=5;rightorwrong[i+1]=1;
                    break;
                }
                else break;
            }
        }//结束while循环
    }// 结束for循环


    this->printBlankLines(3);
    if(score < 60){
        cout<<"您只得了"<<score<<"分><, 尚需努力！"<<endl;
    }
    else if((score>=60) && (score<85)){
        cout<<"您得了"<<score<<"分， 及格颇有余，优秀尚不足，加油！"<<endl;
    }
    else if((score>=85) && (score<100)){
        cout<<"您得了"<<score<<"分， 非常优秀，加油！"<<endl;
    }
    else if(score==100){
        cout<<"您得了满分100！ 膜拜神牛！"<<endl;
    }
    cout<<endl<<"下面是所有正确答案:"<<endl;
    for(int i=0;i<20;i++){
        cout<<i+1<<": "<<this->dataBase.getWordNode(number[i]).getEnglish()
        <<"   "<<this->dataBase.getWordNode(number[i]).getChinese();
        if(rightorwrong[i+1]==1)cout<<"    "<<"You are right!";
        else cout<<"    "<<"You are wrong!";
        cout<<endl;
    }

    return;
}

void NewFrame::exercise(){
    srand(unsigned(time(0)));
    while(1){
        char cmd[100];

        this->printBlankLines(5);
        int number=rand()%(this->dataBase.getDicSize());
        cout<<"单词：   "<<this->dataBase.getWordNode(number).getEnglish()<<endl;
        cout<<endl;
        cout<<"解释：   "<<this->dataBase.getWordNode(number).getChinese()<<endl;
        cout<<endl;
        cout<<"近义词：  "<<this->dataBase.getWordNode(number).getSynonyms()<<endl;
        cout<<endl;
        cout<<"反义词：  "<<this->dataBase.getWordNode(number).getAntonyms()<<endl;
        string choice;
        cout<<"你是否确定已掌握该单词？"<<endl;
        cout<<"输入1表示已掌握,否则输入0"<<endl;
        cin>>choice;
        if(choice=="1")
        {
            string English=this->dataBase.getWordNode(number).getEnglish();
            WordNode wordNode(this->dataBase.getWordNode(number).getEnglish(),
                              this->dataBase.getWordNode(number).getChinese() ,
                              this->dataBase.getWordNode(number).getSynonyms(),
                              this->dataBase.getWordNode(number).getAntonyms());
            this->dataBase2.addWordNode(wordNode);
            ofstream ofile2("alreadylearnt.txt",ios_base::app);
            ofile2<<this->dataBase.getWordNode(number).getEnglish()<<" "<<dataBase.getWordNode(number).getChinese()<<" "<<this->dataBase.getWordNode(number).getSynonyms()<<" "<<this->dataBase.getWordNode(number).getAntonyms()<<endl;
            ofile2.close() ;
            this->dataBase.deleteWordNode(number);
            vector<string> wordlist;
            string _string;
            ifstream infile("dic.txt");
            while(infile>>_string)
            {
                wordlist.push_back(_string);
            }

            for(vector<string>::iterator iter=wordlist.begin() ;iter!=wordlist.end() ;++iter)
            {

                if((*iter)==English)
                {
                    wordlist.erase(iter,iter+4) ;
                }
            }
            ofstream ofile3("dic.txt");
            int tt=0;
            for(vector<string>::iterator iter=wordlist.begin() ;iter!=wordlist.end();++iter)
            {
                ofile3<<(*iter)<<" ";
                tt=(tt+1)%4;
                if(tt==0)ofile3<<endl;

            }

        }
        else
        {
        }

        this->printBlankLines(15);
        cout<<"输入quit退出练习，输入next可查看下一个单词\n";
        //cin.sync();
        //cin.getline(cmd,100);
        cin >> cmd;
        //退出背单词的模式
        if(strcmp(cmd,"quit")==0){

            return;
        }
        else
            continue;
    }
    return;
}


void NewFrame::readfile() {
    cout<<"请输入需要阅读的文件名称"<<endl;
    string filename;
    cin>>filename;
    ifstream ifs(filename.c_str());
    if(!ifs)cout<<"打开文件失败！";
    vector<string> temp;
    string nowstring;
    int count=0;
    while(ifs>>nowstring)
    {
        if(this->dataBase2.binarySearch(nowstring)<0 &&!(alreadyseen(nowstring,temp)))
        {
            count++;

            for(int i=0;;i++)
            {
                if(this->dataBase.getWordNode(i).getEnglish()==nowstring )
                {
                    temp.push_back(this->dataBase.getWordNode(i).getEnglish());
                    cout<<"生词"<<count<<':'<<this->dataBase.getWordNode(i).getEnglish()  <<endl;
                    cout<<"释义 :"<< this->dataBase.getWordNode(i).getChinese() <<endl;
                    cout<<"近义词 :"<<this->dataBase.getWordNode(i).getSynonyms() <<endl;
                    cout<<"反义词 :"<<this->dataBase.getWordNode(i).getAntonyms() <<endl;
                    printBlankLines(5);
                    break;
                }
            }
        }
    }

    return;
}

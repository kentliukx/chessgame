#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <unistd.h>

using namespace std;
void randomchess(int hang,int lie,bool chess[26][100])
{
    srand(time(0));
    for(int i=0;i<hang;i++)
        for(int j=0;j<lie;j++)
            chess[i][j]=rand()%2;
}

void reverse_hang(int hang,int lie,bool chess[26][100],char tgt_hang)
{
    for(int i=0;i<lie;i++)
        if(chess[tgt_hang-'a'][i]==1)  chess[tgt_hang-'a'][i]=0;
        else chess[tgt_hang-'a'][i]=1;
}

void reverse_lie(int hang,int lie,bool chess[26][100],int tgt_lie)
{
    for(int i=0;i<hang;i++)
        if(chess[i][tgt_lie-1]==1)  chess[i][tgt_lie-1]=0;
        else chess[i][tgt_lie-1]=1;
}

void showchess(int hang,int lie,bool chess[26][100])
{
    system("cls");
    cout<<"当前棋盘状态为"<<endl;
    cout<<"   ";
    for(int i=1;i<=lie;i++)
    {
        cout<<i;
        if(i>=10) cout<<" ";
        else cout<<"  ";
    }

    cout<<endl;

    for(int i=0;i<hang;i++)
    {
        cout<<char(i+'a')<<"  ";
        for(int j=0;j<lie;j++)
            if (chess[i][j]==1) cout<<'X'<<"  ";
            else cout<<"   ";
        cout<<endl;
    }
}
int main()
{
    cout<<endl<<endl<<endl;
    cout<<"            Chessgame Simulation"<<endl;
    cout<<"--an auxiliary tool for <Linear Algebra (Honor)>"<<endl;
    cout<<"           Programed by kentliukx"<<endl;
    cout<<endl<<endl<<endl;
    sleep(3);
    system("cls");

    int hang,lie,temp,tgt_lie;
    char tgt_hang;
    bool chess[26][100]={0};
    while(1)
    {
        cin.sync();
        cout<<"请输入行数（1-26）"<<endl;
        cin>>hang;
        if(hang<=26&&hang>=1) break;
        cout<<"无效输入"<<endl;
    }
    while(1)
    {
        cin.sync();
        cout<<"请输入列数（1-99）"<<endl;
        cin>>lie;
        if(lie<=99&&lie>=1) break;
        cout<<"无效输入"<<endl;
    }
    cout<<"请输入初始棋盘状态（0或1，空格隔开），无效输入则为随机生成"<<endl;
    int i=0;
    for(i=0;i<hang;i++)
    {
        int j=0;
        for(j=0;j<lie;j++)
        {
            cin>>temp;
            if(temp==0) chess[i][j]=0;
            else if(temp==1) chess[i][j]=1;
            else break;
        }
        if (j!=lie) break;
    }
    if (i!=hang) randomchess(hang,lie,chess);
    showchess(hang,lie,chess);

    while(1)
    {
        cin.sync();
        cout<<"输入需要翻的行或者列的序号"<<endl;
        if(cin>>tgt_lie)
        {
            if(tgt_lie>=1 && tgt_lie<=lie)
                reverse_lie(hang,lie,chess,tgt_lie);
            else
            {
                cout<<"无效输入"<<endl;
                continue;
            }
        }
        else
        {
            cin.clear();
            cin>>tgt_hang;
            if(tgt_hang>='a'&&tgt_hang<='a'+hang-1)
                reverse_hang(hang,lie,chess,tgt_hang);
            else
            {
                cout<<"无效输入"<<endl;
                continue;
            }
        }
        showchess(hang,lie,chess);
    }
}

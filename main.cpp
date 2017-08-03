#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
#include <string>

using namespace std;

bool Palindrom(const string text);
bool Palindrom2(const string text);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string text;
    bool eredmeny;
    QTextStream qtin(stdin);

    while (true)
    {
        cout<<"Adj meg egy szót vagy mondatot, és eldöntöm, palindrom-e?"<<endl;
        text="";
        cin>>text;

        if (Palindrom2(text)) cout<<"Ez a szó palindrom."<<endl;
        else cout<<"Nem palindrom."<<endl;
        cout<<endl;
    }

    return a.exec();
}

bool Palindrom(const string text)
{
    int length, halflength;
    string w1,w3;

    length= text.length();

    if (length%2>0) halflength=(length/2)+1;
    else halflength=length/2;

    w1=text.substr(0,halflength);

    for (int i=length-1; i>length-halflength-1; i--)
    {
        w3+=text.at(i);
    }

    return w1==w3;
}

bool Palindrom2(const string text)
{
    int p1=0;
    int p2=text.length()-1;
    bool palindrom=false;

    while (!(p1>p2))
    {
        if (text.at(p1)==text.at(p2))
        {
            p1+=1;
            p2-=1;
            palindrom=true;
        }
        else break;
    }

    return palindrom;
}

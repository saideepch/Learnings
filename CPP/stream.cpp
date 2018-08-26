#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;
double power(double m,int p)
{
    int i=1, res=m;
    for(i=1;i<p;i++)
    {
        res = res * m;
    }
    return res;
}

int main ()
{
    int nValue;
    double dValue=2;
    stringstream os;
    string strng;
    cout << "Enter number and its power separated with a space: ";
    getline(cin,strng);
    os << strng; // insert a string of numbers into the stream

    //cout << strng;

    os >> nValue >> dValue;

    cout << nValue <<" power " << dValue <<" is " << power(nValue,dValue);
    //cout << dValue;


    getchar();
    return 0;
}

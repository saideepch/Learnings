#include <iostream>

using namespace std; //Not good practise!!

void Increment (int& x)
{
    x++;
}

int main ()
{
    int i = 57;
    int& i_ref = i; //Though int &x works, & is part of. int& is one single type

    cout << "i is " << i << endl << "i_ref is " << i_ref << endl;
    cout << &i << endl << &i_ref << endl; //Addresses are same since aliases

    Increment (i);
    cout << "i is " << i <<", i_ref is " << i_ref << endl;

    return 0;
}

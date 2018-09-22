#include <iostream>

using namespace std; //Not good practise!!

class Entity    //Can use struct too
{
public:
    static int a, b;

    static void Print()
    {
        cout << a << endl << b << endl;
    }
};

//Since a,b are static, need below definition to avoid undefined reference error.
int Entity::a;
int Entity::b;

int main ()
{
    Entity e1, e2;

    Entity::a = 9;
    Entity::b = 151;
//  Since e1.a and e2.a are same and similarly for b
//    e1.a = 3; e1.b = 57;
//    e2.a = 9; e2.b = 150;

    e1.Print();
    e2.Print(); //Both e1, e2 values are same since static

    //If Print is static
    Entity::Print();

    //NOTE: Static methods cannot access non-static variables because static things doesn't have class 'linkage'

    return 0;
}

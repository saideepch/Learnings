#include <iostream>

using namespace std; //Not good practise!!

class Entity    //Can use struct too
{
public:
    float X, Y;

//    Entity()
//    {
//        X=57.72, Y=143.225;
//    }

//    Entity(float x, float y)
//    {
//        X = x; Y = y;
//    } //Use initializer list like below, always recommended for performance reason. Reason: See this link (https://youtu.be/1nfuYMXjZsA?t=227)

    Entity()
        : X(99.99), Y(100.100)
    {
    }   //NOTE: Values will be assigned in the order declared in the class, no matter what variable you mention.

    // If we don't want to allow instantiating objects of a class like Log class which is designed to be wholly static, then make constructor private or just give public constructor like below:
    //Entity() = delete;

    void Print()
    {
        cout << X << ", " << Y << endl;
    }
};

int main ()
{
    Entity e1;
    //Entity e2(9.9, 10.6);
    // If we don't want to allow instantiating objects of a class like Log class which is designed to be wholly static, then make constructor private or just give constructor like below:

    e1.Print();
    //e2.Print();

    return 0;
}

#include <iostream>

using namespace std; //Not good practise!!

//using String = std::string; //This works, so do this for cout endl etc. to avoid prefixing std::

class Entity
{
private:
    string m_Name;
    int m_Age;
public:
    Entity(const string& name)
        : m_Name(name), m_Age(-1) {}

    explicit Entity(int age)
        : m_Name("Unknown"), m_Age(age) {}

};

void PrintEntity(const Entity& entity)
{

}

int main ()
{
//    Entity a("Saideep");
//    Entity b(23);
// Below is weird way but it works as it implicitly converts
    Entity a = (string)"Saideep";
    Entity b = 23; //Remove explicit in Entity constructor for int, then works

//Also this works because 23 can be converted to Entity, its defined in the class, so implicitly it will convert 23 to entity
    PrintEntity(23);

    return 0;
}

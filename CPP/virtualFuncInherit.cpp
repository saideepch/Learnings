#include <iostream>

using namespace std; //Not good practise!!

class Entity
{
public:
    float X, Y;

    virtual string GetName() const    //Here const means method doesn't change class variables, this works only for methods in class.
    //For virtual, v-table reqd. so performance hits, but not that costly so safely use it
    //const mainly to allow const objects creation in main
    {
        return "Entity";
    }   //  virtual string GetName() = 0; //Pure virtual aka Interface
};

class Player : public Entity
{
private:
    //const char* Name; //const char* because strings in C++ are stored in RO memory so immutable
    //See const video (https://www.youtube.com/watch?v=4fJBrditnJU)
    string m_Name;
public:
    Player(const string& name)
        : m_Name(name) {}

    string GetName() const
    {
        return m_Name;
    }
};

void PrintName2(Entity* entity)
{
    cout << entity->GetName() << endl;
}

int main ()
{
    Entity* e = new Entity();
 //   cout << e->GetName() << endl;
    PrintName2(e);

    Player* p = new Player("Saideep");
  //  cout << p->GetName() << endl;
    PrintName2(p); //This is where the problem starts, so use virtual

   // Entity* entity = p;
  //  cout << entity->GetName() << endl; //Prints entity but we need player
  //  PrintName(entity);


    return 0;
}

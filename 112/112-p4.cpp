#include<iostream>
#include<string>
using namespace std;

class Animal{   /* Abstract Class */
    public:
        void makeSound(){ cout<<"animal sound"<<endl; };
        virtual void food(){ cout<<"water"<<endl; };         // virtual function
        virtual string getColor() = 0;          // pure virtual function    /* 4-1 */
};

class Cat:public Animal{
    private:
        string color;
    
    public:
        Cat(string co = "white"):color(co){};         /* 4-2 */
        Cat(const Cat &a){    // copy constructor     /* 4-3 */
            color /* 4-4 */ = a.color;                     /* 4-4 */
        };
        void makeSound(){ cout<<"cat sound"<<endl; };
        virtual void food(){ cout<<"mouse"<<endl; };
        virtual string getColor(){ return color; };
        Cat /* 4-5 */ operator + (Cat &other){                /* 4-5 */
            return Cat(getColor() + other.getColor());
        }

};

int main(){
    Animal *p1 = new Cat("black");
    Cat *p2 = new Cat();
    Cat cat = Cat("silver") + *p2;
    cout<<cat.getColor()<<endl;         /* 4-6: silverwhite */
    p1->makeSound();                    /* 4-7: animal sound */
    p1->food();                         /* 4-8: mouse */
    p2->makeSound();                    /* 4-9: cat sound */
    p2->food();                         /* 4-10: mouse */
}
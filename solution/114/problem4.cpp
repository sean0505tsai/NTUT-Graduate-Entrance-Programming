#include<iostream>
#include<vector>
using namespace std;
class Product{
    protected:
        int value;
    public:
        Product(int v): value(v){value+=10;}
        /* Problem 4-1: Fill in the code for a pure virtual function declaration */
        virtual int computeTax() = 0;               // 4-1: virtual int computeTax() = 0;
        int getValue(){return computeTax() + _____;};    // Problem 4-2
};

class Food: public Product{
    public:
        Food(int v): Product(v){value += 10;}
        int computeTax() override{return value * __________;}   // Problem 4-3 (Integer)
};

class House: public Product{
    public:
        House(int v): Product(v){}
        int computeTax() override{return value*0.2 + __________;}   // Problem 4-4 (Integer)
};

class Car: public Product{
    public:
        Car(int v): Product(v){}
        int computeTax() override{return value%80 - __________;}    // Problem 4-5 (Integer)
};

int sumOfComputes(const vector<Product*>__________){                // Problem 4-6
    int sum = 0;
    for(const auto& obj: objects)
        sum += obj->__________;                                     // Problem 4-7
    return sum;
}

int main(){
    Food f1(10), f2(20);
    House h1(20), h2(30);
    Car c1(30), c2(10);
    vector<Product*> objects = {&f1, &h1, &c1};
    cout<<f1.computeTax()<<endl;                // Output is 60
    cout<<h1.computeTax()<<endl;                // Output is 16
    cout<<c1.computeTax()<<endl;                // Output is 22
    cout<<f1.getValue()<<endl;                  // Output is 90
    cout<<sumOfComputes(objects)<<endl;         // Output is 98
    cout<<f2.computeTax()<<endl;                // Problem 4-8
    cout<<h2.computeTax()<<endl;                // Problem 4-9
    cout<<c2.computeTax()<<endl;                // Problem 4-10
    cout<<f2.getValue()<<endl;                  // Problem 4-11
}
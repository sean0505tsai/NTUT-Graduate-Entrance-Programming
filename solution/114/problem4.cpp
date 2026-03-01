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
        int getValue(){return computeTax() + value;};    // 4-2: computeTax() + value
};

class Food: public Product{
    public:
        Food(int v): Product(v){value += 10;}
        int computeTax() override{return value * 2;}    // 4-3: 2
        // f1(10) -> value = (10 + 10)+10 =30, computeTax() = 30*2=60
};

class House: public Product{
    public:
        House(int v): Product(v){}
        int computeTax() override{return value*0.2 + 10;}   // 4-4: 10
        // h1(20) -> value = 20 + 10 =30, computeTax() = 30*0.2+10 = 16
};

class Car: public Product{
    public:
        Car(int v): Product(v){}
        int computeTax() override{return value%80 - 18;}    // 4-5: 18
        // c1(30) -> value = 30 + 10 =40, computeTax() = 40%80 - 18 = 22
};

int sumOfComputes(const vector<Product*> objects){      // 4-6: objects
    int sum = 0;
    for(const auto& obj: objects)
        sum += obj->computeTax();                        // 4-7: computeTax()
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
    cout<<f2.computeTax()<<endl;                // 4-8: 80
    cout<<h2.computeTax()<<endl;                // 4-9: 18
    cout<<c2.computeTax()<<endl;                // 4-10: 2
    cout<<f2.getValue()<<endl;                  // 4-11: 120
}
#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;
template<class T>
class Box{
    private:
        T content;
        __________ boxCount;              // Problem 5-1
    public:
        Box(__________ c):content(c){boxCount++;}    // Problem 5-2
        T getContent() const {return content;}
        static int getCount() {return boxCount;}
        ~Box(){boxCount--;}
};

template<class T>
int Box<T>::boxCount = 0;              /* Static member initialization */
class Shape{
    protected:
        __________;                     // Problem 5-3
    public:
        Shape(string n): name(n){}
        virtual string getName() const = 0;
        virtual ~Shape(){};
};

class Square: public Shape{
    private:
        int side;
    public:
        Square(string n, int s): Shape(n), side(s){}
        string getName() const override{return "C:" + name;}
        int getArea() const {return side*side;}
};

class Rectangle: public Shape{
    private:
        int length, width;
    public:
        Rectangle(): Shape("d"), length(1), width(1){}
        Rectangle(string n, int l, int w): Shape(n), length(l), width(w){}
        string getName() const override{return "R:" + name;}
        double getArea() const {return length*width;}
};

int main(){
    try{
        Box<Square> sBox1(Square("S1", 3));
        Box<Square> sBox2(Square("S2", 2));
        Box<Rectangle> rBox(Rectangle("R1", 4, 5));
        Rectangle rect;

        cout<<"RName:"<<rect.getName()<<endl;           // Problem 5-4
        cout<<"RArea:"<<rect.getArea()<<endl;           // Problem 5-5
        cout<<"SArea:"<<sBox1.getContent().getArea()<<endl;   // Problem 5-6
        cout<<"RArea:"<<rBox.getContent().getArea()<<endl;    // Problem 5-7
        cout<<"sBoxes:"<<Box<Square>::getCount()<<endl;          // Problem 5-8
        cout<<"rBoxes:"<<Box<Rectangle>::getCount()<<endl;       // Problem 5-9
        Square square = sBox1.getContent();
        Rectangle rectangle = rBox.getContent();
        vector<Shape*> shapes = {&square, &rectangle};
        for(auto shape: shapes) cout<<shape->getName()<<endl;    // Problem 5-10
        cout<<shapes.at(2)->getName()<<endl;
    }catch(const exception& e){
        cout<<"E: "<<"Out of Index"<<endl;                      // Problem 5-11
    }
}
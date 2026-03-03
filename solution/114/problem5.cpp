#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>
using namespace std;
template<class T>
class Box{
    private:
        T content;
        static int boxCount;              // 5-1: static int boxCount;
    public:
        Box(const T& c):content(c){boxCount++;}    // 5-2: const T& c
        T getContent() const {return content;}
        static int getCount() {return boxCount;}
        ~Box(){boxCount--;}
};

template<class T>
int Box<T>::boxCount = 0;              /* Static member initialization */
class Shape{
    protected:
        string name;                     // 5-3: string name
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

        cout<<"RName:"<<rect.getName()<<endl;           // 5-4: RName:R:d
        cout<<"RArea:"<<rect.getArea()<<endl;           // 5-5: RArea:1
        cout<<"SArea:"<<sBox1.getContent().getArea()<<endl;   // 5-6: SArea:9
        cout<<"RArea:"<<rBox.getContent().getArea()<<endl;    // 5-7: RArea:20
        cout<<"sBoxes:"<<Box<Square>::getCount()<<endl;          // 5-8: sBoxes:2
        cout<<"rBoxes:"<<Box<Rectangle>::getCount()<<endl;       // 5-9: rBoxes:1
        Square square = sBox1.getContent();
        Rectangle rectangle = rBox.getContent();
        vector<Shape*> shapes = {&square, &rectangle};
        for(auto shape: shapes) cout<<shape->getName()<<endl;    // 5-10: C:S1 R:R1
        cout<<shapes.at(2)->getName()<<endl;
    }catch(const exception& e){
        cout<<"E: "<<"Out of Index"<<endl;                      // 5-11: E: Out of Index
    }
}
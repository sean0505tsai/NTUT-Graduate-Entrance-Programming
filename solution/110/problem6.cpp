#include<iostream>
#include<string>
#define PI 3
using namespace std;
class MathVector{
private:
    double *_content;
    int _size;
public:
    MathVector(){ }
    MathVector(double* input, int size=0){
        _content = new double[size];
        _size = size;
        for(int i=0; i<_size; i++){
            _content[i] = input[i];
        }
    }
    MathVector(__________input){        /* Problem 6-1 */
        _content = new double[input._size];
        _size = input._size;
        for(int i=0; i<_size; i++){
            _content[i] = input._content[i];
        }
    }
    ~MathVector{
        if(_content != NULL){
            delete[] _content;
        }
        ____________________;        /* Problem 6-2 */
    }
    MathVector & operator=(__________input){        /* Problem 6-3 */
        if(_content != NULL){
            delete[] _content;
        }
        ____________________;        /* Problem 6-4 */
        _size = input._size;
        for(int i=0; i<_size; i++){
            _content[i] = input._content[i];
        }
        return __________;        /* Problem 6-5 */
    }
    double & component(int index) const{
        return _content[index-1];
    }
};

class Shape{
protected:
    MathVector _center;
public:
    Shape(MathVector center){
        _center = center;
    }
    virtual double perimeter() __________;        /* Problem 6-6 */
    __________~Shape(){ }        /* Problem 6-7 */
};

class Circle ____________________{  /* Problem 6-8 */
private:
    double _radius;
public:
    Circle(double radius, MathVector center):__________{ /* Problem 6-9 */
        _radius = radius;
    }
    ~Circle() override{ }
    double perimeter() const override{
        return 2*_radius*PI;
    }
};

int main(){
    double y[2] = {1, 90};
    MathVector output = MathVector(y, 2);
    cout << output.component(2) << endl;        /* problem 6-10 */
    Shape* output2 = new _____(5, output);      /* problem 6-11 */
    cout << output2->perimeter() << endl;        /* problem 6-12 */
    delete output2;
    return 0;
}
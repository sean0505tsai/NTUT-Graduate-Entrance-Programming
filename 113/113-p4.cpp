#include <iostream>
#include <string>
using namespace std;
class Shape
{ /* Abstract Class */
protected:
    string c; // color
    int w;    // weight
public:
    string getC()
    {
        return "white";
    };
    virtual int getW() { return 0; }; // virtual function
    virtual int getV() = 0;           // pure virtual function  /* Problem 4-1 */
};
class Cube : public Shape
{
private:
    int s; // side
public:
    Cube(string vl, int v2, int v3) : s(v3)
    {
        setC(vl);
        setW(v2);
    };
    void setC(string v)
    {
        c = v;
    };
    void setW(int v)
    {
        w = v;
    };
    int getS()
    {
        return s;
    };
    string getC()
    {
        return c;
    };
    string getC(Cube *o)
    {
        return c + o->getC();
    }; // function overloading
    virtual int getW()
    {
        return w;
    }; // virtual function
    virtual int getV() { return s * s * s; };
    Cube operator+(Cube &o)
    { // operator overloading /* Problem 4-2 */
        return Cube(getC() + o.getC(), getW() + o.getW(), getS() + o.getS());
    }
};
int main()
{
    Shape *pl = new Cube("cyan", 1, 2);
    Cube *p2 = new Cube("blue", 3, 4);
    Cube cube = Cube("red", 5, 6) + *p2;
    cout << pl->getC() << endl;    /* Problem 4-3 */
    cout << pl->getW() << endl;    /* Problem 4-4 */
    cout << p2->getC() << endl;    /* Problem 4-5 */
    cout << p2->getW() << endl;    /* Problem 4-6 */
    cout << cube.getC() << endl;   /* Problem 4-7 */
    cout << cube.getC(p2) << endl; /* Problem 4-8 */
    cout << cube.getV() << endl;   /* Problem 4-9 */
}
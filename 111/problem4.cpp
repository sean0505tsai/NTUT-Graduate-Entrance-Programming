#include<iostream>
#include<string>
using namespace std;
class Fruit{
    private:
        string color;
    public:
        void setColor(string value){ color = value; };
        string getColor(){ return color; };
        _____ void taste()_____;    // pure virtual function        /*Problems 4-1, 4-2*/
        void pringInfo(){ cout<<color<<endl; };
        _____ void printData(){cout<<color<<endl;};    // virtual function  /*Problem 4-3*/
};
class Apple: public Fruit{
    private:
        string cultivar;
    public:
        Apple(string co = "red", string cu = "Fuji"): cultivar(cu){ setColor(co); };
        Apple(const Apple _________ a){ //copy constructor          /*Problem 4-4*/
            setColor(a.__________);     // obtain object a's color  /*Problem 4-5*/
            cultivar = a.__________;    // obtain object a's cultivar   /*Problem 4-6*/
        };
        __________Apple(){};        // destructor                /*Problem 4-7*/
        void taste(){ cout<<"sweet"<<endl; };
        void setCultivar(string cu){ cultivar = cu; };
        void setCultivar(){string cu, string co}{ cultivar = cu; setColor(co); };
        void printInfo(){cout<<cultivar<<endl;};
        void printData(){cout<<cultivar<<endl;};
};

int main(){
    
}
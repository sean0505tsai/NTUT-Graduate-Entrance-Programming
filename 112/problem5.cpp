#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class RedTea{
protected:
    string _name = "Unknown";
    int _price =0;
    double _content= 0;
public:
    RedTea() = default;
    RedTea(string name, int price, double content) : _name(name), _price(price), _content(content){}
    
    virtual ~RedTea(){};         /* 5-1 */
    virtual void dilute()= 0;      /* 5-1 */ /* 5-2 */
    int get_price() const{
        return _price;
    }

    string get_name() const{
        return _name;
    }

    double get_alcohol_content() const{
        return _content;
    }
};

class LongIsland : public RedTea{
public:
    LongIsland() = default;
    LongIsland(string name, int price, double alcohol_content):
        RedTea(name, price, alcohol_content){}
    ~LongIsland() = default;
    void dilute() override{
        this->_content *= 0.7;
    }
};

class NewBloodyMary;
static NewBloodyMary CreareNewBloodyMary(string name, int price, double content);

class NewBloodyMary: public RedTea{
    friend NewBloodyMary CreareNewBloodyMary(string name, int price, double content);    /* 5-3 */

private:
    NewBloodyMary(string name, int price, double content):
                RedTea(name, price, content){}

public:
    NewBloodyMary() = default;
    ~NewBloodyMary() = default;
    void dilute() override {
        this->_content *= 0.95;
    }
    static NewBloodyMary *CreareNewBloodyMaryPtr(string name, int price, double content){
        return new NewBloodyMary(name, price, content);
    }
    NewBloodyMary & operator = (const NewBloodyMary &other){         /* 5-4 */
        this->_name = other._name;
        this->_price = other._price;
        this->_content = other._content;
        return *this; 
    }
    NewBloodyMary operator+(const NewBloodyMary &other){                                /* 5-4 */
        return NewBloodyMary(this->_name, 
                this->_price + other._price, (this->_content+other._content)/2);
    }
};
static NewBloodyMary CreareNewBloodyMary(string n, int p, double c){
    return NewBloodyMary(n, p, c);
}
class Order{
private:
    std::vector< RedTea* > vec;            /* 5-5 */
public:
    Order() = default;
    ~Order(){
        for(int i = 0; i< vec.size(); i++){   /* 5-6 */
            delete vec[i];
        }
    }
    void append_alcohol(RedTea* alcohol){
        vec.push_back(alcohol);
    }

    int get_total_price(){
        int total = 0;
        for(int i = 0; i< vec.size(); i++){
            total += vec[i]->get_price();
        }
        return total;
    }
};

int main(){
    Order order;
    order.append_alcohol(NewBloodyMary::
                        CreareNewBloodyMaryPtr("A", 870, 0.7));
    order.append_alcohol(new LongIsland("B", 230, 0.7));
    vector<RedTea*> alcohol_vec = {
        new LongIsland("C", 77, 0.7),
        NewBloodyMary::CreareNewBloodyMaryPtr("D", 88, 0.8),       /* 5-7 */
        NewBloodyMary::CreareNewBloodyMaryPtr("E", 12, 0.8)        /* 5-7 */
        };
    std::sort(alcohol_vec.begin(), alcohol_vec.end(), [](RedTea *a, RedTea *b){     /* 5-8 */
        return a->get_price() < b->get_price();
        }
    );
    NewBloodyMary H = CreareNewBloodyMary("F", 90, 0.8) + CreareNewBloodyMary("G", 10, 0.8);      /* 5-9 */
    cout<< alcohol_vec.at(0)->get_price()<<endl;                    /* 5-10 */
    cout<< alcohol_vec.at(1)->get_price()<<endl;                    /* 5-11 */
    cout<<order.get_total_price()<<endl;                            /* 5-12 */
    cout<<H.get_name()<<endl;                                       /* 5-13 */
    cout<<H.get_price()<<endl;                                      /* 5-14 */
    cout<<H.get_alcohol_content()<<endl;                            /* 5-15 */
    return 0;
}
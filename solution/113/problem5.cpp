#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Vehicle{
private:
    int rentPrice;
protected:
    int GetRentPrice() const {return this->rentPrice;   }
    void SetRentPrice(int _rentPrice){
        if(_rentPrice < 0) throw string("not be negative");
        this->rentPrice = _rentPrice;
    }
public:
    Vehicle(int _rentPrice){ SetRentPrice(_rentPrice); }
    virtual int Rent(int hour) = 0;
    virtual ~Vehicle() {}
};

class UBicycle final: public Vehicle{
public:
    UBicycle(int rentPrice): Vehicle(rentPrice) {}
    UBicycle &operator=(const UBicycle& bicycle){
        this->SetRentPrice(bicycle.GetRentPrice());
        return *this;
    }
    int Rent(int hour) override{ return GetRentPrice() * hour; }
    ~UBicycle() {}
};

class EBicycle final: public Vehicle{
private:
    int battery;
public:
    EBicycle(int rentPrice, int battery): Vehicle(rentPrice){
        this->battery = battery;
    }
    ~EBicycle() {}
    EBicycle &operator=(const EBicycle& bicycle){
        this->SetRentPrice(bicycle.GetRentPrice());
        return *this;
    }
    int GetChargeFee() {return battery * __________;}       // Problem 5-1
    int Rent(int hour) override{ 
        return GetRentPrice() * hour + __________; }        // Problem 5-2
};
class ParkingSystem{
private:
    vector<Vehicle*> __________;                     // Problem 5-3
public:
    ParkingSystem(vector<Vehicle*> &vehicles){this->vehicles = vehicles; }
    ~ParkingSystem() {};
    int ____________________{                       // Problem 5-4
        int total = 0;
        for(int i=0; i<vehicles.size(); i++){
            total += vehicles[i]__________;;               // Problem 5-5
        }
        return total;
    }
};
void test01(){
    EBicycle* eBil = new EBicycle(15, 5);
    UBicycle* uBil = new UBicycle(5);
    vector<Vehicle*> vehicles = {eBil, uBil};
    ParkingSystem parkingSystem(vehicles);
    cout<<parkingSystem.GetTotalRentPrice(5)<<", ";
    cout<<parkingSystem.GetTotalRentPrice(10)<<endl;
    delete eBil, uBil;
}
void test02(){
    EBicycle* eBil = new EBicycle(15, 5);
    UBicycle* uBil = new UBicycle(10);
    UBicycle  uBil2 = *uBil;
    vector<Vehicle*> vehicles = {eBil, uBil, &uBil2};
    ParkingSystem parkingSystem(vehicles);
    cout << parkingSystem.GetTotalRentPrice(5) << endl;  // Problem 5-6
    try { UBicycle uBil2 = new UBicycle(-5); }
    catch (string e) { cout<<e<<endl; }                 // Problem 5-7
    delete eBil, uBil;
}
void test03(){
    // Vehicle* eBil = new EBicycle(15, 5);
    // Vehicle* uBil = new UBicycle(10);
    // Vehicle* vehl = new Vehicle(10);
    // cout<<eBil.GetChargeFee()<<endl;
    // cout<<uBil->GetRentPrice()<<endl;
}
int main(){ test01(); test02(); test03(); }
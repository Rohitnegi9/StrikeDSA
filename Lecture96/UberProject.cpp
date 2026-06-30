#include <iostream>

using namespace std;

//Abstract class

class Vehcile {
protected:
    string type;
    double baseFare;
    double perKmFare;
    double perMinFare;
    int capacity;

public:
    Vehcile() {
        this->type = "";
        this->baseFare = 0.0;
        this->perKmFare = 0.0;
        this->perMinFare = 0.0;
        this->capacity = 0;
    }

    ~Vehcile() = default;

    string getType() {
        return this->type;
    }
    double getBaseFare() {
        return this->baseFare;
    }
    double getPerKmFare() {
        return this->perKmFare;
    }
    double getPerMinFare() {
        return this->perMinFare;
    }
    int getCapacity() {
        return this->capacity;
    }
};

class Auto : public Vehcile {
public:
    Auto() {
        this->type = "Auto";
        this->baseFare = 25.0;
        this->perKmFare = 8.0;
        this->perMinFare = 1.5;
        this->capacity = 3;
    }
};

class Bike : public Vehcile {
public:
    Bike() {
        this->type = "Bike";
        this->baseFare = 15.0;
        this->perKmFare = 5.0;
        this->perMinFare = 0.5;
        this->capacity = 1;
    }
};

class Sedan : public Vehcile {
public:
    Sedan() {
        this->type = "Sedan";
        this->baseFare = 45.0;
        this->perKmFare = 12.0;
        this->perMinFare = 2.5;
        this->capacity = 4;
    }
};

class SUV : public Vehcile {
    public:
        SUV() {
            this->type = "SUV";
            this->baseFare = 55.0;
            this->perKmFare = 15.0;
            this->perMinFare = 3.0;
            this->capacity = 7;
        }
};

class VehicleFactory {
public:
    Vehcile* createVehicle(string type) {
        if (type == "Auto") {
            return new Auto();
        }
        else if (type == "Bike") {
            return new Bike();
        }
        else if (type == "Sedan") {
            return new Sedan();
        }
        else if (type == "SUV") {
            return new SUV();
        }
        else {
            Sedan *s = new Sedan();
            cout << "Invalidid type" <<" "<<"Defaulting to Sedan" <<endl;
            return s;
        }
    }
};

class Rider {
private:
    string id;
    string name;

public:
    Rider(string id, string name) {
        this->id = id;
        this->name = name;
    }
    string getId() {
        return this->id;
    }
    string getName() {
        return this->name;
    }
};

enum DriverStatus {
    AVAILABLE,
    OFF_DUTY,
    ON_RIDE
};

class Driver {
private:
    string id;
    string name;
    Vehcile* vehicle;
    Location* currentLocation;
    DriverStatus status;

public:
    Driver(string id, string name, Vehcile* vehicle, Location* currentLocation) {
        this->id = id;
        this->name = name;
        this->vehicle = vehicle;
        this->currentLocation = currentLocation;
        this->status = DriverStatus::AVAILABLE;
    }

    DriverStatus getStatus() {
        return this->status;
    }
    void setStatus(DriverStatus status) {
        this->status = status;
    }
};

//-----------------------------------------------------------------------------

// Location & City Graph

int main() {

    cout << "Hello, World!" << endl;

    return 0;
}
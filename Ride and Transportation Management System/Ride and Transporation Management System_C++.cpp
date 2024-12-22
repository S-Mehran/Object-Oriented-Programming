#include<iostream>
#include<string>
#include<cstring>
//#include <chrono>
//#include <ctime>
//#include <map>

using namespace std;


class Name {
private:
    string fname;
    string lname;
public:
    Name(string fn = "", string ln = "") : fname(fn), lname(ln) {}

    void setFirstName(string fN) { fname = fN; }
    void setLastName(string lN) { lname = lN; }

    string getFirstName() { return fname; }
    string getLastName() { return lname; }

    friend ostream& operator<<(ostream& out, const Name& n) {
        out << n.fname << " " << n.lname;
        return out;
    }

    void display() const
    {
        cout << "Name: " << fname << " " << lname << endl;
    }
};



class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int d = 0, int m = 0, int y = 0) : day(d), month(m), year(y) {}
    void setdate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    ~Date()
    {

    }
    inline int getday() const { return day; }
    inline int getmonth() const { return month; }
    inline int getyear() const { return year; }

    friend ostream& operator<<(ostream& os, const Date& d) {
        static const char* months[] = { "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
        os << d.day << " / " << months[d.month - 1] << " / " << d.year;
        return os;
    }
    void display() const
    {
        cout << "Date: " << day << " " << month << " " << year << endl;
    }
};

class mTime {
private:
    int hour;
    int min;
    int sec;

public:
    mTime(int h = 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

    void setTime(int h, int m, int s) { hour = h; min = m; sec = s; }

    friend ostream& operator<<(ostream& COUT, const mTime& t) {
        COUT << t.hour << " : " << t.min << " : " << t.sec;
        return COUT;
    }
};

class Service {
protected:
    int serviceID;
    char* source;
    char* destination;
    float distance;
    Date bookingDate;
    mTime bookingTime;
    int status;
    float fuelRate;
    int cId;
    int dId;
    int vId;

public:
    Service(int servicID, char* src, char* dest, float dist, Date bDate, mTime bTime, float fRate, int custId, int drvId, int vehId)
        : source(src), destination(dest), distance(dist), bookingDate(bDate), bookingTime(bTime), fuelRate(fRate), cId(custId), dId(drvId), vId(vehId), status(0), serviceID(servicID) {
    }

    virtual void displayServiceDetails() {
        cout << "Source: " << source << "\nDestination: " << destination << "\nDistance: " << distance << " km\n";
        cout << "Booking Date: " << bookingDate << "\nBooking Time: " << bookingTime << endl;
    }

    int getStatus() { return status; }
    void setStatus(int s) { status = s; }


    inline char* getsource()
    {
        return source;
    }
    inline char* getdestination()
    {
        return destination;
    }
    inline int getcid()
    {
        return cId;
    }

    int getvId()
    {
        return vId;
    }

    void setcId(int CUID)
    {
        cId = CUID;
    }
    void setvId(int VeId)
    {
        vId = VeId;
    }


    void setdId(int dRid)
    {
        dId = dRid;
    }
    int getdId()
    {
        return dId;
    }

    int getServiceId()
    {
        return serviceID;
    }

    float getDistance()
    {
        return distance;
    }

    Date getBookingDate()
    {
        return bookingDate;
    }

};

class Ride : public Service {
private:
    int noofPassengers;
    char* rideType;
    float driverRanking;
    float vehicleRanking;

public:
    Ride(int serviceID, char* src, char* dest, float dist, Date bDate, mTime bTime, float fRate, int custId, int drvId, int vehId, int passengers, char* type)
        : Service(serviceID, src, dest, dist, bDate, bTime, fRate, custId, drvId, vehId), noofPassengers(passengers), driverRanking(0), vehicleRanking(0)
    {
        rideType = new char[strlen(type) + 1];
        strcpy(rideType, type);
    }
    ~Ride() {
        delete[] rideType;
    }
    int getNoOfPassengers() const { return noofPassengers; }
    const char* getRideType() const { return rideType; }
    float getDriverRanking() const { return driverRanking; }
    float getVehicleRanking() const { return vehicleRanking; }
    void setNoOfPassengers(int passengers) { noofPassengers = passengers; }
    void setRideType(const char* type) {
        delete[] rideType;
        rideType = new char[strlen(type) + 1];
        strcpy(rideType, type);
    }
    void setDriverRanking(float ranking) { driverRanking = ranking; }
    void setVehicleRanking(float ranking) { vehicleRanking = ranking; }



    void displayServiceDetails() override {
        Service::displayServiceDetails();
        cout << "Passengers: " << noofPassengers << "\nRide Type: " << rideType << "\nDriver Ranking: " << driverRanking << "\nVehicle Ranking: " << vehicleRanking << endl;
    }
};




class Delivery : public Service {
private:
    float goodsWeight;
    char* goodsType;

public:
    Delivery(int serviceID, char* src, char* dest, float dist, Date bDate, mTime bTime, float fRate, int custId, int drvId, int vehId, float weight, char* type)
        : Service(serviceID, src, dest, dist, bDate, bTime, fRate, custId, drvId, vehId), goodsWeight(weight)
    {
        goodsType = new char[strlen(type) + 1];
        strcpy(goodsType, type);
    }




    ~Delivery() {
        delete[] goodsType;
    }


    float getGoodsWeight() const { return goodsWeight; }
    void setGoodsWeight(float weight) { goodsWeight = weight; }


    const char* getGoodsType() const
    {
        return goodsType;
    }
    void setGoodsType(const char* type) {
        delete[] goodsType;
        goodsType = new char[strlen(type) + 1];
        strcpy(goodsType, type);
    }

    void displayServiceDetails() override {
        Service::displayServiceDetails();
        cout << "Goods Weight: " << goodsWeight << "\nGoods Type: " << goodsType << endl;
    }
};

class LicenseType {
public:
    static const int MOTORCAR_JEEP = 1;
    static const int MOTORBIKE_RICKSHAW = 2;
    static const int LTV = 3;
    static const int HTV = 4;
    static const int TRACTOR = 5;
    static const int PSV = 6;
    static const int INTERNATIONAL = 7;
};
class Person {
private:
    Name pName;
    Date DOB;
    int Age;
    int Nid;
public:
    Person() : pName("Unknown", "Unknown"), DOB(1, 1, 2000), Age(0), Nid(0) {}
    Person(Name name, Date dob, int age, int nid)
        : pName(name), DOB(dob), Age(age), Nid(nid) {
    }
    Person(const Person& other)
        : pName(other.pName), DOB(other.DOB), Age(other.Age), Nid(other.Nid) {
    }
    virtual ~Person() {


    }
    Name getName() const { return pName; }
    Date getDOB() const { return DOB; }
    int getAge() const { return Age; }
    int getNid() const { return Nid; }
    void setName(const Name& name) { pName = name; }
    void setDOB(const Date& dob) { DOB = dob; }
    void setAge(int age) { Age = age; }
    void setNid(int nid) { Nid = nid; }
    friend ostream& operator<<(ostream& os, const Person& person) {
        os << "Name: ";
        //  person.pName.display();
        cout << person.pName;
        cout << person.DOB << endl;
        //       os << "\nDOB: "; person.DOB.display();
        os << "\nAge: " << person.Age << "\nNID: " << person.Nid;
        return os;
    }

    void displayPersonDetails() const {

        pName.display();
        DOB.display();
        cout << "\nAge: " << Age << "\nNID: " << Nid << endl;
    }
};
class Customer : public Person {
private:
    int cId;
    Service** bookingHistory;
    int bookingCount;

public:

    Customer() : cId(0), bookingHistory(nullptr), bookingCount(0) {}
    Customer(Name name, Date dob, int age, int nid, int id)
        : Person(name, dob, age, nid), cId(id), bookingHistory(new Service* [0]), bookingCount(0) {
    }
    ~Customer() {
        if (bookingHistory) {
            for (int i = 0; i < bookingCount; ++i) {
                delete bookingHistory[i];
            }
            delete[] bookingHistory;
        }
    }
    Customer(const Customer& other)
        : Person(other), cId(other.cId), bookingCount(other.bookingCount) {
        if (other.bookingHistory) {
            bookingHistory = new Service * [other.bookingCount];
            for (int i = 0; i < other.bookingCount; ++i) {
                bookingHistory[i] = new Service(*other.bookingHistory[i]);
            }
        }
        else {
            bookingHistory = nullptr;
        }
    }
    friend ostream& operator<<(ostream& os, const Customer& customer) {
        os << static_cast<const Person&>(customer);
        os << "\nCustomer ID: " << customer.cId << "\nBooking Count: " << customer.bookingCount;
        os << "\nBooking History:\n";
        for (int i = 0; i < customer.bookingCount; ++i) {
            os << "Service " << i + 1 << ":\n";
            customer.bookingHistory[i]->displayServiceDetails();
            os << "\n";
        }
        return os;
    }


    void addBooking(Service* service) {

        Service** newHistory = new Service * [bookingCount + 1];
        for (int i = 0; i < bookingCount; ++i) {
            newHistory[i] = bookingHistory[i];
        }
        newHistory[bookingCount] = service;

        if (bookingHistory) {
            delete[] bookingHistory;
        }

        bookingHistory = newHistory;
        bookingCount++;
        cout << "Booking added" << endl;
    }

    void removeBooking(int index) {
        if (index < 0 || index >= bookingCount) {
            cout << "Invalid index for booking removal.\n";
            return;
        }

        // Shift bookings left to remove the service at the given index
        for (int i = index; i < bookingCount - 1; i++) {
            bookingHistory[i] = bookingHistory[i + 1];
        }

        bookingCount--; // Reduce the size of the booking history
    }



    int getCustomerId() const { return cId; }
    void setCustomerId(int id) { cId = id; }
    int getBookingCount() const { return bookingCount; }

    Service** getBookingHistory()
    {
        return bookingHistory;
    }
};

class Driver : public Person {
private:
    int dId;
    string* LisencesList;
    int noofLisences;
    float overallRanking;
    float salary;
    int experience;
    int status;
    Service** serviceHistory;
    int serviceCount;
    float ranking;

public:

    Driver() : dId(0), LisencesList(nullptr), noofLisences(0), overallRanking(0.0), salary(0.0),
        experience(0), status(1), serviceHistory(nullptr), serviceCount(0) {
    }

    void printLisenceList()
    {
        for (int i = 0; i < noofLisences; i++)
        {
            cout << LisencesList[i] << " ";
        }
        cout << endl;

    }

    void assignLicenses(const std::string* licenses, int numberOfLicenses) {
        noofLisences = numberOfLicenses;
        LisencesList = new std::string[noofLisences];  // Dynamically allocate memory for the license list
        for (int i = 0; i < noofLisences; ++i) {
            LisencesList[i] = licenses[i];  // Assign license values
        }
    }

    Driver(const Name name, Date dob, int age, int nid, int id, float sal, int exp, int status, float rank)
        : Person(name, dob, age, nid), dId(id), overallRanking(rank), salary(sal), experience(exp),
        status(status), serviceCount(0), noofLisences(0) {
        LisencesList = nullptr;
        serviceHistory = nullptr;
    }

    float getRanking() const {
        return ranking;
    }


    void setRanking(float newRanking) {
        ranking = newRanking;
    }
    int getdriverId()
    {
        return dId;
    }


    int getNoOfLisences()
    {
        return noofLisences;
    }


    float getOverAllRatings()
    {
        return overallRanking;
    }


    ~Driver() {

        if (LisencesList) {

            delete[] LisencesList;
        }


        if (serviceHistory) {
            for (int i = 0; i < serviceCount; ++i) {
                delete serviceHistory[i];
            }
            delete[] serviceHistory;
        }
    }


    void addServiceHistory(Service* service) {

        Service** tempHistory = new Service * [serviceCount + 1];
        for (int i = 0; i < serviceCount; ++i) {
            tempHistory[i] = serviceHistory[i];
        }


        tempHistory[serviceCount] = service;
        if (serviceHistory) {
            delete[] serviceHistory;
        }
        serviceHistory = tempHistory;
        serviceCount++;
    }


    void printDriverDetails() const {

        Person::displayPersonDetails();


        cout << "Driver ID: " << dId << endl;
        cout << "Overall Ranking: " << overallRanking << endl;
        cout << "Salary: " << salary << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Status: " << (status == 1 ? "Free" : status == 2 ? "Booked" : "Canceled") << endl;


        cout << "Licenses Held: " << endl;
        for (int i = 0; i < noofLisences; ++i) {
            cout << "\t" << LisencesList[i] << endl;
        }


        if (serviceCount > 0) {
            cout << "Service History: " << endl;
            for (int i = 0; i < serviceCount; ++i) {
                serviceHistory[i]->displayServiceDetails();
            }
        }
        else {
            cout << "No service history available." << endl;
        }
    }


    friend ostream& operator<<(ostream& os, const Driver& driver) {
        driver.printDriverDetails();
        return os;
    }

    int getStatus()
    {
        return status;
    }

    void setStatus(int s)
    {
        status = s;
    }


    void updateRanking(float newRank)
    {
        overallRanking = (overallRanking + newRank) / 2;
        cout << "Driver's Overall Ranking is updated to: " << overallRanking << endl;
    }


    void incrementServiceCount()
    {
        serviceCount = serviceCount++;
    }

    int getServiceCount()
    {
        return serviceCount;
    }

    Service** getServiceHistory()
    {
        return serviceHistory;
    }



};



class Feature
{
private:
    int fId;
    char* description;
    float cost;

public:
    Feature(int id, const char* descr, float cst) : fId(id), cost(cst) {
        description = new char[strlen(descr) + 1];
        strcpy(description, descr);
    }

    ~Feature() {
        delete[] description;
    }

    void displayFeature() const {
        cout << "Feature ID: " << fId << "\nDescription: " << description << "\nCost: " << cost << endl;
    }
};
class Vehicle {
protected:
    int vId;
    int registrationNo;
    float avgMileage;
    char* LicenceType;
    bool status;
    char* fuelType;
    float overallRanking;
    Date manufacturingDate;
    Service** serviceHistory;  // Array of Service objects
    int serviceCount;
    int maxServiceSlots;
    string vehicleType;

public:
    // Constructor
    Vehicle()
        : vId(0), registrationNo(0), avgMileage(0.0), LicenceType(nullptr),
        status(false), fuelType(nullptr), overallRanking(0.0),
        manufacturingDate(), serviceHistory(nullptr), serviceCount(0), vehicleType("Unknown") {
    }
    Vehicle(int id, int regNo, float mileage, const char* license, bool stat, const char* fuel, float rank, Date mfgDate)
        : vId(id), registrationNo(regNo), avgMileage(mileage), status(stat), overallRanking(rank),
        manufacturingDate(mfgDate), serviceCount(0), serviceHistory(nullptr) {

        LicenceType = new char[strlen(license) + 1];
        strcpy(LicenceType, license);

        fuelType = new char[strlen(fuel) + 1];
        strcpy(fuelType, fuel);
    }

    string getVehicleType() const {
        return vehicleType;
    }


    int getRegistrationNo() const {
        return registrationNo;
    }

    float getAvgMileage() const {
        return avgMileage;
    }

    const char* getFuelType() const {
        return fuelType;
    }

    const char* getLicenseType() const {
        return LicenceType;
    }

    Date getManufacturingDate() const {
        return manufacturingDate;
    }

    float getOverallRanking() const {
        return overallRanking;
    }
    // Destructor
    virtual ~Vehicle() {
        delete[] LicenceType;
        delete[] fuelType;

        // Cleanup service history memory
        if (serviceHistory) {
            for (int i = 0; i < serviceCount; ++i) {
                delete serviceHistory[i];  // Cleanup each service object
            }
            delete[] serviceHistory;
        }
    }
    bool hasAvailableSlots() const {
        return serviceCount < maxServiceSlots;
    }
    int getVehicleId() const {
        return vId;
    }

    // Method to get the overall rating of the vehicle
    float getOverallRating() const {
        return overallRanking;
    }

    void addServiceHistory(Service* service) {
        if (!hasAvailableSlots()) {
            cout << "Sorry, No Slots available for Vehicle ID: " << vId << endl;
            return;
        }

        Service** tempHistory = new Service * [serviceCount + 1];
        for (int i = 0; i < serviceCount; ++i) {
            tempHistory[i] = serviceHistory[i];
        }
        tempHistory[serviceCount] = service;

        delete[] serviceHistory;
        serviceHistory = tempHistory;
        serviceCount++;
    }
    void displayServiceHistory() const {
        cout << "Service History for Vehicle ID: " << vId << "\n";
        if (serviceCount == 0) {
            cout << "No services available for this vehicle.\n";
            return;
        }

        for (int i = 0; i < serviceCount; ++i) {
            serviceHistory[i]->displayServiceDetails();
        }
    }

    // Method to print vehicle details
    virtual void printVehicleDetails() const {
        cout << "Vehicle ID: " << vId << endl;
        cout << "Registration No: " << registrationNo << endl;
        cout << "Average Mileage: " << avgMileage << " km/l" << endl;
        cout << "License Type: " << LicenceType << endl;
        cout << "Status: " << (status ? "Booked" : "Available") << endl;
        cout << "Fuel Type: " << fuelType << endl;
        cout << "Overall Ranking: " << overallRanking << endl;
        cout << "Manufacturing Date: " << manufacturingDate << endl;
    }

    // Method to update vehicle ranking
    void updateRanking(float newRank) {
        overallRanking = (overallRanking + newRank) / 2;
        cout << "Vehicle's Overall Ranking is updated to: " << overallRanking << endl;
    }

    // Getter and Setter methods for vehicle status
    bool getStatus() const {
        return status;
    }

    void setStatus(bool s) {
        status = s;
    }

    // Getter for service count
    int getServiceCount() const {
        return serviceCount;
    }

    // Increment service count method (for internal purposes, if needed)
    void incrementServiceCount() {
        serviceCount++;
    }

    // Method to print the vehicle as a stream
    friend ostream& operator<<(ostream& os, const Vehicle& vehicle) {
        vehicle.printVehicleDetails();
        return os;
    }
};


//class RideVehicle : public Vehicle {
//private:
//    string category;  
//public:
//    RideVehicle(int id, int regNo, float mileage, char* license, bool stat, char* fuel, float rank, Date mfgDate, string cat)
//        : Vehicle(id, regNo, mileage, license, stat, fuel, rank, mfgDate), category(cat) {}
//
//    void displayVehicleDetails() override {
//        Vehicle::displayVehicleDetails();
//        cout << "Category: " << category << " (Ride Vehicle)" << endl;
//    }
//
//    void displayVehicleCategory() override {
//        cout << "Ride Vehicle - Category: " << category << endl;
//    }
//};
//class TransportVehicle : public Vehicle 
//{
//private:
//    string category; 
//public:
//    TransportVehicle(int id, int regNo, float mileage, char* license, bool stat, char* fuel, float rank, Date mfgDate, string cat)
//        : Vehicle(id, regNo, mileage, license, stat, fuel, rank, mfgDate), category(cat) {}
//
//    void displayVehicleDetails() override {
//        Vehicle::displayVehicleDetails();
//        cout << "Category: " << category << " (Transport Vehicle)" << endl;
//    }
//
//    void displayVehicleCategory() override {
//        cout << "Transport Vehicle - Category: " << category << endl;
//    }
//};



class TMS
{
    //	Driver** drivers;
    //	Customer** customers;
    //	Vehicle** vehicles;
    //	Service** services;
    //	int driverSize;
    //	int customerSize;
    //	int vehicleSize;
    //	int serviceSize;
    //	
    //	public:
    //		TMS()
    //		{
    //			drivers = new Driver*[10];
    //			customers = new Customer*[15];
    //			vehicles = new Vehicle*[20];
    //			services = new Service*[150];
    //			driverSize = 0;
    //			customerSize = 0;
    //			vehicleSize = 0;
    //			serviceSize = 0;
    //		}
    //		
    //		
    //		
    //		void addCustomer(Customer& customer)
    //		{
    //			if (customerSize==15)
    //			{
    //				cout<<"Space not Available"<<endl;
    //				return;
    //			}
    //			customerSize++;
    //			
    //			customers[customerSize] = new Customer(customer);
    //			cout<<"Customer added successfully"<<endl;	
    //		}
    //		
    //		void addDriver(Driver& driver)
    //		{
    //			if (driverSize >=10)
    //			{
    //				cout<<"No space for Driver"<<endl;
    //				return;
    //			}
    //			
    //			driverSize++;
    //			drivers[driverSize] = new Driver(driver);
    //			cout<<"Driver Added"<<endl;
    //		}
    //		
    //		void removeDriver(int driverId)
    //		{
    //			for (int i=0; i<driverSize; i++)
    //			{
    //				if (drivers[i]->getdriverId() == driverId)
    //				{
    //					delete drivers[i];
    //					
    //					for (int j=i; j<driverSize;j++)
    //					{
    //						drivers[j] = drivers[j+1];
    //					}
    //					
    //					driverSize--;
    //					cout<<"Driver Removed Successfully"<<endl;
    //					
    //					return;
    //				}
    //				else
    //				{
    //					continue;
    //				}
    //			}
    //		}
    //		
    //		void addVehicle(Vehicle& vehicle)
    //		{
    //			if (vehicleSize>=20)
    //			{
    //				cout<<"Vehicle Limit Reached"<<endl;
    //				return;
    //			}
    //			vehicleSize++;
    //			vehicles[vehicleSize] = new Vehicle(vehicle);
    //			cout<<"Vehicle added successfully"<<endl;
    //		}
    //		
    //		void removeVehicle(int vID)
    //		{
    //			for (int i=0; i<vehicleSize; i++)
    //			{
    //				if (vehicles[i]->getVehicleId() == vID)
    //				{
    //					delete vehicles[i];
    //					
    //					for (int j=i;j<vehicleSize;j++)
    //					{
    //						vehicles[j] = vehicles[j+1];
    //					}
    //					vehicleSize--;
    //					cout<<"Vehicle removed"<<endl;
    //					return;
    //				}
    //				else
    //				{
    //					continue;
    //				}
    //			}
    //		}
    //		
    //		
    //		void printCustomers()
    //		{
    //			for (int i=0; i<customerSize; i++)
    //			{
    //			//	customers[i]->displayPersonDetails();
    //			//	cout<<*customers[i]<<endl;
    //			}
    //		}
    //		
    //		void printDrivers()
    //		{
    //			for (int i=0; i<driverSize; i++)
    //			{
    //				drivers[i]->printDriverDetails();
    //			}
    //		}
    //		
    //		void printVehicles()
    //		{
    //			for (int i=0; i<vehicleSize; i++)
    //			{
    //				vehicles[i]->printVehicleDetails();
    //			//	cout<<vehicles[i]->
    //			}
    //		}
    //		

    Driver** drivers;
    Customer** customers;
    Vehicle** vehicles;
    Service** services;
    int driverSize;
    int customerSize;
    int vehicleSize;
    int serviceSize;


public:
    TMS() {
        drivers = new Driver * [10];
        customers = new Customer * [15];
        vehicles = new Vehicle * [20];
        services = new Service * [150];
        driverSize = 0;
        customerSize = 0;
        vehicleSize = 0;
        serviceSize = 0;
    }

    void addCustomer(Customer& customer) {
        if (customerSize == 15) {
            cout << "Space not available for more customers." << endl;
            return;
        }
        customers[customerSize] = new Customer(customer);
        customerSize++;
        cout << "Customer added successfully." << endl;
    }

    void addDriver(Driver& driver) {
        if (driverSize >= 10) {
            cout << "No space for more drivers." << endl;
            return;
        }
        drivers[driverSize] = new Driver(driver);
        driverSize++;
        cout << "Driver added successfully." << endl;
    }

    void removeDriver(int driverId) {
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getdriverId() == driverId) {
                delete drivers[i];
                // Shift elements to fill the gap
                for (int j = i; j < driverSize - 1; j++) {
                    drivers[j] = drivers[j + 1];
                }
                drivers[driverSize - 1] = nullptr; // Optional: set the last pointer to nullptr
                driverSize--;
                cout << "Driver removed successfully." << endl;
                return;
            }
        }
        cout << "Driver not found." << endl;
    }

    void addVehicle(Vehicle& vehicle) {
        if (vehicleSize >= 20) {
            cout << "Vehicle limit reached." << endl;
            return;
        }
        vehicles[vehicleSize] = new Vehicle(vehicle);
        vehicleSize++;
        cout << "Vehicle added successfully." << endl;
    }

    void removeVehicle(int vID) {
        for (int i = 0; i < vehicleSize; i++) {
            if (vehicles[i]->getVehicleId() == vID) {
                delete vehicles[i];
                // Shift elements to fill the gap
                for (int j = i; j < vehicleSize - 1; j++) {
                    vehicles[j] = vehicles[j + 1];
                }
                vehicles[vehicleSize - 1] = nullptr; // Optional: set the last pointer to nullptr
                vehicleSize--;
                cout << "Vehicle removed successfully." << endl;
                return;
            }
        }
        cout << "Vehicle not found." << endl;
    }

    void printCustomers() {
        cout << "\n============TMS Customer Details=============" << endl;
        for (int i = 0; i < customerSize; i++) {
            customers[i]->displayPersonDetails();
        }
    }

    void printDrivers() {
        cout << "\n===========TMS Drivers Details=============" << endl;
        for (int i = 0; i < driverSize; i++) {
            drivers[i]->printDriverDetails();
        }
    }

    void printVehicles() {
        cout << "\n============TMS Vehicle Details============" << endl;
        for (int i = 0; i < vehicleSize; i++) {
            vehicles[i]->printVehicleDetails();
        }
    }

    ~TMS() {
        // Clean up memory
        for (int i = 0; i < driverSize; i++) {
            delete drivers[i];
        }
        delete[] drivers;

        for (int i = 0; i < customerSize; i++) {
            delete customers[i];
        }
        delete[] customers;

        for (int i = 0; i < vehicleSize; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;

        for (int i = 0; i < serviceSize; i++) {
            delete services[i];
        }
        delete[] services;
    }

    void vehicleDetails(int vehicleId)
    {
        for (int i = 0; i < vehicleSize; i++)
        {
            if (vehicleId == vehicles[i]->getVehicleId())
            {
                vehicles[i]->printVehicleDetails();
                return;
            }
        }
        cout << "Vehicle Not Found" << endl;
    }

    void customerDetails(int customerID)
    {
        for (int i = 0; i < customerSize; i++)
        {
            if (customerID == customers[i]->getCustomerId())
            {
                cout << customers[i];
                return;
            }
        }
        cout << "Customer ID not Found" << endl;
    }

    void DriverDetails(int driverID)
    {
        for (int i = 0; i < driverSize; i++)
        {
            if (driverID == drivers[i]->getdriverId())
            {
                drivers[i]->printDriverDetails();
                return;
            }
        }
        cout << "Driver Not Found" << endl;
    }

    void priorityDrivers()
    {
        for (int i = 0; i < serviceSize; i++)
        {
            if (drivers[i]->getOverAllRatings() >= 4.5)
            {
                drivers[i]->printDriverDetails();
            }
        }
    }

    void lisencedDrivers() {
        bool found = false;
        cout << "\nListing drivers with licenses:\n";
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getNoOfLisences() >= 1) {
                drivers[i]->printDriverDetails();
                drivers[i]->printLisenceList();
                found = true;
            }
        }
        if (!found) {
            cout << "No drivers found with licenses.\n";
        }
    }
    void updateSalary() {
        bool found = false;
        cout << "\nListing drivers with ratings above 4.5:\n";
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getOverAllRatings() > 4.5) {
                drivers[i]->printDriverDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No drivers found with ratings above 4.5.\n";
        }
    }

    bool searchID(int customerID)
    {
        for (int i = 0; i < customerSize; i++)
        {
            if (customers[i]->getCustomerId() == customerID)
            {
                return true;
            }
        }
        return false;
    }

//   tms.addServiceRequest(custID, Name(fname, lname), Date(day, month, year), 24, 101, dest, src, rateOfFuel, dist, serviceId, day, month, year);
    void addServiceRequest(int custID, Name custName, Date dob, int age, int nid, char* dest, char* src, float rateofFuel, float dist, int serviceid, int day, int month, int year, int hour, int minute, int second)
    {
        //			if (searchID(customer.getcustID()) != true)
        //			{
        //				addCustomer(customer);
        //			}
        //			

        Driver* freeDrivers = new Driver[10];
        Vehicle* freeVehicles = new Vehicle[20];
        int freeDriverCount = 0;
        int freeVehicleCount = 0;

        for (int i = 0; i < driverSize; i++)
        {
            if (drivers[i]->getStatus() == 1)
            {
                freeDrivers[freeDriverCount++] = *drivers[i];
            }
        }

        for (int i = 0; i < vehicleSize; i++)
        {
            if (vehicles[i]->getStatus() == true)
            {
                freeVehicles[freeVehicleCount++] = *vehicles[i];
            }
        }

        if (freeDriverCount == 0 || freeVehicleCount == 0)
        {
            cout << "Sorry, No Slots available" << endl;
            return;
        }


        cout << "Available Slots" << endl;
        for (int i = 0; i < freeDriverCount; i++)
        {
            cout << "Driver ID: " << freeDrivers[i].getdriverId() << "\t" << "Driver Rating: " << freeDrivers[i].getOverAllRatings() << endl;
        }

        cout << "Available Vehicles" << endl;
        for (int i = 0; i < freeVehicleCount; i++)
        {
            cout << "Vehicle ID: " << vehicles[i]->getVehicleId() << "\t" << "Vehicle Ranking: " << vehicles[i]->getOverallRating() << endl;
        }


        int selectedVehicleID;
        int selectedDriverID;

        cout << "Choose a Driver: " << endl;
        cin >> selectedVehicleID;
        cout << "Choose a Vehicle: " << endl;
        cin >> selectedDriverID;



        Driver* selectedDriver = nullptr;
        Vehicle* selectedVehicle = nullptr;

        for (int i = 0; i < freeDriverCount; i++)
        {
            if (freeDrivers[i].getdriverId() == selectedDriverID)
            {
                selectedDriver = &freeDrivers[i];
                //	cout<<"Working"<<endl;
                break;
            }
        }

        for (int i = 0; i < freeVehicleCount; i++)
        {
            if (freeVehicles[i].getVehicleId() == selectedVehicleID)
            {
                selectedVehicle = &freeVehicles[i];
                //	cout<<"Working 2"<<endl;
                break;
            }
        }

        if (!selectedDriver || !selectedVehicle)
        {
            cout << "Driver or Vehicle Not selected" << endl;
            return;
        }


        //			    auto now = std::chrono::system_clock::now();
        //    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
        //    std::tm* localTime = std::localtime(&currentTime);
        //
        //    int year = localTime->tm_year + 1900;
        //    int month = localTime->tm_mon + 1;
        //    int day = localTime->tm_mday;
        //    int hour = localTime->tm_hour;
        //    int minute = localTime->tm_min;
        //    int second = localTime->tm_sec;

            // Initialize Date and mTime with current values
        Date bDate(day, month, year);
        mTime bTime(hour, minute, second);

        double baseFare = 50.0;
        double distanceFare = dist * 10.0;
        double driverRankingFactor = 1.0 + (selectedDriver->getOverAllRatings() / 10);
        double vehicleRankingFactor = 1.0 + (selectedVehicle->getOverallRating() / 10);


        double totalFare = baseFare + (distanceFare * driverRankingFactor * vehicleRankingFactor);


        //		    Service* service = nullptr;
        cout << "Click on Service Required: ";
        cout << "1. Ride \t\t   2. Delivery" << endl;



        int serviceType;
        cin >> serviceType;
        if (serviceType == 1)
        {
            int passengers;
            char* selectedRideType = new char[9];

            cout << "Number of Passengers: ";
            cin >> passengers;
            cin.ignore();
            cout << "Ride Type(InterCity or IntraCity): ";
            cin.getline(selectedRideType, 9);
            services[serviceSize++] = new Ride(serviceid, src, dest, dist, bDate, bTime, rateofFuel, custID, selectedDriverID, selectedVehicleID, passengers, selectedRideType);
            cout << "====================SERVICE DETAILS====================" << endl;
            services[serviceSize - 1]->displayServiceDetails();

            if (selectedRideType == "intercity")
            {
                totalFare = totalFare + 1000;
            }
            else
            {
                totalFare = totalFare + 400;
            }

            if (passengers > 3)
            {
                totalFare = totalFare + 200;
            }


        }

        else if (serviceType == 2)
        {
            float goodsWeight;
            char* goodsType = new char[20];

            cout << "Enter the goods weight: ";
            cin >> goodsWeight;
            cout << "Enter the type of Goods: ";
            cin.getline(goodsType, 20);

            services[serviceSize++] = new Delivery(serviceid, src, dest, dist, bDate, bTime, rateofFuel, custID, selectedDriverID, selectedVehicleID, goodsWeight, goodsType);

            float weightFactor = 1;
            if (goodsWeight > 2.0 && goodsWeight < 5)
            {
                weightFactor = 1.5;
            }
            else if (goodsWeight > 5 && goodsWeight < 40)
            {
                weightFactor = 2;
            }
            else
            {
                weightFactor = 3;
            }
            totalFare = totalFare * weightFactor;
        }
        else
        {
            cout << "Invalid Command" << endl;
            return;
        }


        selectedDriver->setStatus(2);
        selectedVehicle->setStatus(false);
        cout << "Status after adding service Request" << endl;
        cout << selectedDriver->getStatus() << endl;
        cout << selectedVehicle->getStatus() << endl;

        selectedDriver->addServiceHistory(services[serviceSize - 1]);
        selectedDriver->printDriverDetails();
        //			selectedDriver->incrementServiceCount();
        selectedVehicle->addServiceHistory(services[serviceSize - 1]);
        //			selectedVehicle->incrementServiceCount();

        cout << "Booking has been Successfull" << endl;
        //		cout<<"Following are the details of your Booking"<<endl;
        cout << "Total Fare is: " << totalFare << endl;

        if (searchID(custID) == true)
        {
            for (int i = 0; i < customerSize; i++)
            {
                if (customers[i]->getCustomerId() == custID)
                {
                    cout << "Customer Found" << endl;
                    customers[i]->displayPersonDetails();
                    customers[i]->addBooking(services[serviceSize - 1]);
                    cout << "Booking COunt" << endl;
                    cout << customers[i]->getBookingHistory()[0]->getServiceId() << endl;
                    cout << customers[i]->getBookingCount() << endl;
                    break;
                }
            }
        }
        else
        {
            Customer newCustomer(custName, dob, age, nid, custID);
            addCustomer(newCustomer);

        }


    }
    void displayVehicleServiceHistory(int vehicleId) {
        // Search for the vehicle by its ID
        for (int i = 0; i < vehicleSize; ++i) {
            if (vehicles[i]->getVehicleId() == vehicleId) {
                // If found, display its service history
                vehicles[i]->displayServiceHistory();
                return;
            }
        }
        cout << "Vehicle with ID " << vehicleId << " not found!" << endl;
    }
    void cancelServiceRequest(int serviceId, int customerId)
    {
        Service* serviceToCancel = nullptr;
        int serviceIndex = -1;
        Customer* customer = nullptr;
        Service* currentService = nullptr;

        // Step 1: Find the customer and the service to cancel
        for (int i = 0; i < customerSize; i++) {
            if (customers[i]->getCustomerId() == customerId) {
                customer = customers[i];
                // Search for the service in the customer's booking history
                for (int j = 0; j < customer->getBookingCount(); j++)
                {
                    if (customers[i]->getBookingHistory()[j]->getServiceId() == serviceId) {
                        serviceToCancel = customer->getBookingHistory()[j];
                        serviceIndex = j;
                        //       	cout<<"Working 3"<<endl;
                        break;
                    }
                }
                break;
            }
        }

        if (!customer || !serviceToCancel) {
            cout << "Invalid Customer ID or Service ID. Cancellation failed.\n";
            return;
        }

        // Step 2: Calculate the cancellation fee (5% of the total fare)
        double baseFare = 50.0;
        double distanceFare = serviceToCancel->getDistance() * 10.0;
        Driver* driver = nullptr;
        Vehicle* vehicle = nullptr;

        // Find the driver and vehicle associated with the service
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getdriverId() == serviceToCancel->getdId()) {
                driver = drivers[i];
                break;
            }
        }

        for (int i = 0; i < vehicleSize; i++) {
            if (vehicles[i]->getVehicleId() == serviceToCancel->getvId()) {
                vehicle = vehicles[i];
                break;
            }
        }

        if (!driver || !vehicle) {
            cout << "Associated driver or vehicle not found. Cancellation failed.\n";
            return;
        }

        for (int i = 0; i < serviceSize; i++)
        {
            if (services[i]->getServiceId() == serviceId)
            {
                currentService = services[i];
                break;
            }
        }

        double driverRankingFactor = 1.0 + (driver->getOverAllRatings() / 10);
        double vehicleRankingFactor = 1.0 + (vehicle->getOverallRating() / 10);
        double totalFare = baseFare + (distanceFare * driverRankingFactor * vehicleRankingFactor);
        double cancellationFee = totalFare * 0.05;

        // Step 3: Display the cancellation fee
        cout << "The cancellation fee is 5% of the total fare: $" << cancellationFee << "\n";

        // Step 4: Update statuses of driver and vehicle
        driver->setStatus(3); // Mark driver as free
        vehicle->setStatus(false); // Mark vehicle as free
        currentService->setStatus(3);

        // Step 5: Update customer's booking history by removing the canceled service
      //  customer->removeBooking(serviceIndex);

        // Step 6: Deallocate the memory for the canceled service
        delete serviceToCancel;
        cout << "Service has been canceled successfully.\n";
    }

    // Function to complete a service request
    void completeServiceRequest(int serviceId) {
        Service* completedService = nullptr;
        Customer* customer = nullptr;
        Driver* driver = nullptr;
        Vehicle* vehicle = nullptr;

        // Step 1: Find the service, customer, driver, and vehicle associated with the service ID
        for (int i = 0; i < customerSize; i++) {
            cout << "Checking Customer: " << customers[i]->getName() << endl;
            for (int j = 0; j < customers[i]->getBookingCount(); j++) {
                cout << "Checking Booking j " << j << "For " << customers[i]->getName() << endl;

                if (customers[i]->getBookingHistory()[j]->getServiceId() == serviceId) {
                    completedService = customers[i]->getBookingHistory()[j];
                    customer = customers[i];
                    break;
                }
            }
            if (completedService) break;
        }


        if (!completedService) {
            cout << "Service with ID " << serviceId << " not found.\n";
            return;
        }

        // Find the associated driver
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getdriverId() == completedService->getdId()) {
                driver = drivers[i];
                break;
            }
        }
        for (int i = 0; i < vehicleSize; i++) {
            if (vehicles[i]->getVehicleId() == completedService->getvId()) {
                vehicle = vehicles[i];
                break;
            }
        }

        if (!driver || !vehicle) {
            cout << "Associated driver or vehicle not found.\n";
            return;
        }

        // Step 2: Update the status of the service to complete
        completedService->setStatus(1);

        // Step 3: Add the service to the driver and vehicle service history
        driver->addServiceHistory(completedService);
        vehicle->addServiceHistory(completedService);

        // Step 4: Update the status of the driver and vehicle to free
        driver->setStatus(1);   // 1 indicates free
        vehicle->setStatus(false); // false indicates free

        // Step 5: Prompt the customer to rate the driver and vehicle
        float driverRating, vehicleRating;
        cout << "Please rate the driver (0 to 5): ";
        cin >> driverRating;
        while (driverRating < 0 || driverRating > 5) {
            cout << "Invalid rating. Please enter a value between 0 and 5: ";
            cin >> driverRating;
        }

        cout << "Please rate the vehicle (0 to 5): ";
        cin >> vehicleRating;
        while (vehicleRating < 0 || vehicleRating > 5) {
            cout << "Invalid rating. Please enter a value between 0 and 5: ";
            cin >> vehicleRating;
        }

        // Step 6: Update the overall rankings of the driver and vehicle
        driver->updateRanking(driverRating);
        vehicle->updateRanking(vehicleRating);

        // Step 7: Display confirmation of service completion
        cout << "Service with ID " << serviceId << " has been completed successfully.\n";
        cout << "Driver and vehicle ratings have been updated.\n";
    }



    // Function to print details of all customers who used the same vehicle in a ride service on different dates
    void printCustomersByVehicleUsage(int vehicleId) {
        bool found = false;
        cout << "Details of Customers who used Vehicle ID " << vehicleId << " on different dates:\n";

        // Step 1: Iterate through all customers and check their booking history
        for (int i = 0; i < customerSize; i++) {
            Customer* customer = customers[i];
            bool usedVehicle = false;
            Date previousDate;

            // Step 2: Check customer's booking history for ride services with the same vehicle ID
            for (int j = 0; j < customer->getBookingCount(); j++) {
                Service* service = customer->getBookingHistory()[j];


                // Check if the service is a ride and matches the provided vehicle ID
                if (Ride* ride = dynamic_cast<Ride*>(service)) {
                    if (ride->getvId() == vehicleId) {
                        // If this is the first occurrence, store the date
                        if (!usedVehicle) {
                            previousDate = ride->getBookingDate();
                            usedVehicle = true;
                        }
                        else {
                            // Compare with the previous date to check if it's a different date
                            Date currentDate = ride->getBookingDate();
                            if (previousDate.getday() != currentDate.getday() ||
                                previousDate.getmonth() != currentDate.getmonth() ||
                                previousDate.getyear() != currentDate.getyear()) {

                                // Customer used the same vehicle on a different date
                                cout << *customer << "\n"; // Print customer details
                                found = true;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if (!found) {
            cout << "No customers found who used Vehicle ID " << vehicleId << " on different dates.\n";
        }
    }
    void printDriversWithSameDayDeliveries() {
        bool found = false;

        cout << "Drivers who completed delivery services on the same days:\n";

        // Step 1: Iterate through the list of drivers
        for (int i = 0; i < driverSize; i++) {
            Driver* driver = drivers[i];
            if (!driver)
            {
                cout << "Driver is null" << endl;
                continue; // Skip if driver pointer is null
            }

            // Array to store delivery dates and their counts
            Date deliveryDates[100];  // Assume max 100 unique dates per driver
            int dateCounts[100] = { 0 }; // Initialize all counts to 0
            int uniqueDates = 0;       // Track the number of unique dates

            // Step 2: Check the driver's service history for completed delivery services
            for (int j = 0; j < driver->getServiceCount(); j++) {
                Service* service = driver->getServiceHistory()[j];
                if (!service) continue; // Skip null services

                // Check if the service is a completed delivery
                if (Delivery* delivery = dynamic_cast<Delivery*>(service)) {
                    if (delivery->getStatus()) { // Check if the delivery is completed
                        Date bookingDate = delivery->getBookingDate(); // Get the booking date

                        // Step 3: Check if this date already exists in the deliveryDates array
                        bool dateFound = false;
                        for (int k = 0; k < uniqueDates; k++) {
                            if (deliveryDates[k].getday() == bookingDate.getday() &&
                                deliveryDates[k].getmonth() == bookingDate.getmonth() &&
                                deliveryDates[k].getyear() == bookingDate.getyear()) {
                                // Increment the count for the existing date
                                dateCounts[k]++;
                                dateFound = true;
                                break;
                            }
                        }

                        // If the date is not found, add it as a new unique date
                        if (!dateFound) {
                            if (uniqueDates < 100) { // Prevent out-of-bounds access
                                deliveryDates[uniqueDates] = Date(bookingDate.getday(), bookingDate.getmonth(), bookingDate.getyear());
                                dateCounts[uniqueDates] = 1;
                                uniqueDates++;
                            }
                            else {
                                cerr << "Warning: Exceeded maximum unique dates for driver " << driver->getdriverId() << ".\n";
                            }
                        }
                    }
                }
            }

            // Step 4: Identify if the driver has multiple deliveries on the same date
            for (int k = 0; k < uniqueDates; k++) {
                if (dateCounts[k] > 1) {
                    //                cout << *driver << "\n"; // Print complete information of the driver
                    driver->printDriverDetails();
                    found = true;
                    break; // No need to check further dates for this driver
                }
            }
        }

        if (!found) {
            cout << "No drivers found who completed delivery services on the same days.\n";
        }
    }



    // Function to print details of all pending services on a particular date
    void printPendingServicesOnDate(int day, int month, int year) {
        bool found = false;
        cout << "Pending services on " << day << "/" << month << "/" << year << ":\n";

        // Step 1: Iterate through all customers
        for (int i = 0; i < customerSize; i++) {
            Customer* customer = customers[i];

            // Step 2: Check the customer's booking history for pending services
            for (int j = 0; j < customer->getBookingCount(); j++) {
                Service* service = customer->getBookingHistory()[j];

                // Check if the service is pending (status == false)
                if (!service->getStatus()) {
                    // Get the booking date of the service
                    //cout<<"======Entered========="<<endl;
                    Date bookingDate = service->getBookingDate();

                    // Step 3: Compare the booking date with the given date
                    if (bookingDate.getday() == day &&
                        bookingDate.getmonth() == month &&
                        bookingDate.getyear() == year) {
                        service->displayServiceDetails(); // Print complete details of the pending service
                        found = true;
                    }
                }
            }
        }

        if (!found) {
            cout << "No pending services found on " << day << "/" << month << "/" << year << ".\n";
        }
    }

    void printPendingServicesOfDriver(int driverId) {
        bool found = false; // To track if any pending services are found
        // Step 1: Find the driver by driverId
        Driver* driver = nullptr;
        for (int i = 0; i < driverSize; i++) {
            if (drivers[i]->getdriverId() == driverId) {
                driver = drivers[i];
                driver->getServiceCount();
                driver->printDriverDetails();
                break;
            }
        }
        if (!driver) {
            cout << "Driver with ID " << driverId << " not found.\n";
            return;
        }
        cout << "Pending services for Driver ID " << driverId << ":\n";
        cout << driver->getServiceCount() << endl;
        for (int i = 0; i < driver->getServiceCount(); i++) {
            Service* service = driver->getServiceHistory()[i];
            cout << "PRINTING STATUS FOR CHECKING: " << service->getStatus() << endl;
            if (!service->getStatus()) { // `getStatus()` returns 
                //cout << *service << "\n"; // Print the details of the pending service
                service->displayServiceDetails();
                found = true;
            }
        }
        if (!found) {
            cout << "No pending services found for Driver ID " << driverId << ".\n";
        }
        cout << "Service Size: " << serviceSize << endl;
        for (int i = 0; i < serviceSize; i++)
        {
            services[i]->displayServiceDetails();
            if (services[i]->getdId() == driverId)
            {
                services[i]->displayServiceDetails();
            }
        }
    }
    void addServiceToVehicle(int vehicleId, Service* newService) {
        bool vehicleFound = false;

        // Loop through vehicles to find the one with the matching ID
        for (int i = 0; i < vehicleSize; ++i) {
            if (vehicles[i]->getVehicleId() == vehicleId) {
                // Vehicle found, add the service to this vehicle
                vehicles[i]->addServiceHistory(newService);
                vehicleFound = true;
                cout << "Service successfully added to Vehicle ID: " << vehicleId << endl;
                break;  // Exit the loop once the service is added
            }
        }

        // If no vehicle with the given ID was found
        if (!vehicleFound) {
            cout << "Error: Vehicle with ID " << vehicleId << " not found!" << endl;
        }
    }
    void printServicesByVehicle(int vehicleId) {
        bool vehicleFound = false;

        // Loop through all vehicles to find the one with the matching vehicleId
        for (int i = 0; i < vehicleSize; ++i) {
            if (vehicles[i]->getVehicleId() == vehicleId) {
                vehicleFound = true;
                cout << "Services for Vehicle ID: " << vehicleId << endl;

                // Display all services for the found vehicle
                vehicles[i]->displayServiceHistory();  // Assuming the Vehicle class has a method to print service history
                break;
            }
        }

        if (!vehicleFound) {
            cout << "Error: Vehicle with ID " << vehicleId << " not found!" << endl;
        }
    }
    void printCustomerHistory(int customerId) {
        bool found = false;
        for (int i = 0; i < customerSize; ++i) {
            if (customers[i]->getCustomerId() == customerId) {
                found = true;
                cout << "Complete History for Customer ID " << customerId << ":\n";
                for (int j = 0; j < serviceSize; ++j) {
                    if (services[j]->getcid() == customerId) {
                        services[j]->displayServiceDetails();
                    }
                }
                break;
            }
        }
        if (!found) {
            cout << "Error: Customer with ID " << customerId << " not found.\n";
        }
    }
    void printDriverHistory(int driverId) {
        bool found = false;
        for (int i = 0; i < driverSize; ++i) {
            if (drivers[i]->getdriverId() == driverId) {
                found = true;
                cout << "Complete History for Driver ID " << driverId << ":\n";
                for (int j = 0; j < serviceSize; ++j) {
                    if (services[j]->getdId() == driverId) {
                        services[j]->displayServiceDetails();
                    }
                }
                break;
            }
        }
        if (!found) {
            cout << "Error: Driver with ID " << driverId << " not found.\n";
        }
    }
    void printVehiclesByCategory(const string& category) {
        bool found = false;

        cout << "Vehicles in category: " << category << endl;
        for (int i = 0; i < vehicleSize; ++i) {
            if (vehicles[i]->getVehicleType() == category) {
                found = true;
                cout << "Vehicle ID: " << vehicles[i]->getVehicleId() << endl;
                cout << "Registration No: " << vehicles[i]->getRegistrationNo() << endl;
                cout << "Mileage: " << vehicles[i]->getAvgMileage() << endl;
                cout << "Fuel Type: " << vehicles[i]->getFuelType() << endl;
                cout << "License Type: " << vehicles[i]->getLicenseType() << endl;
                cout << "Manufacturing Date: " << vehicles[i]->getManufacturingDate() << endl;
                cout << "Overall Ranking: " << vehicles[i]->getOverallRanking() << endl;
                cout << "----------------------------" << endl;
            }
        }

        if (!found) {
            cout << "No vehicles found in the " << category << " category." << endl;
        }
    }
    void printDriversWithRankingAbove4_5() {
        bool found = false;
        cout << "List of Drivers with Ranking Above 4.5:\n";
        for (int i = 0; i < driverSize; ++i) {
            if (drivers[i]->getRanking() > 4.5) {
                found = true;
                cout << "Driver ID: " << drivers[i]->getdriverId() << ", Name: "
                    << drivers[i]->getName() << ", Ranking: " << drivers[i]->getRanking() << endl;
            }
        }
        if (!found) {
            cout << "No drivers with ranking above 4.5.\n";
        }
    }
    // Function to print details of all canceled services by a customer
    void printCanceledServicesOfCustomer(int customerId) {
        bool found = false; // To track if any canceled services are found

        // Step 1: Find the customer by customerId
        Customer* customer = nullptr;
        for (int i = 0; i < customerSize; i++) {
            if (customers[i]->getCustomerId() == customerId) {
                customer = customers[i];
                break;
            }
        }

        // If customer is not found
        if (!customer) {
            cout << "Customer with ID " << customerId << " not found.\n";
            return;
        }

        // Step 2: Check the booking history of the customer for canceled services
        cout << "Canceled services for Customer ID " << customerId << ":\n";
        for (int i = 0; i < customer->getBookingCount(); i++) {
            Service* service = customer->getBookingHistory()[i];

            // Check if the service is canceled
            if (service->getStatus() == 3) { // Assuming `status == 3` indicates canceled
                // cout << *service << "\n"; // Print the details of the canceled service
                service->displayServiceDetails();
                found = true;
            }
        }

        // If no canceled services were found
        if (!found) {
            cout << "No canceled services found for Customer ID " << customerId << ".\n";
        }
    }


};
int main()
{
    TMS tms;
    	Customer customer1(Name("mehran", "shah"), Date(13, 8, 2001), 23, 1, 1);
	Customer customer2(Name("Ali", "shah"), Date(21, 7, 2003), 17, 102, 2);
	
	tms.addCustomer(customer1);
	tms.addCustomer(customer2);
	Driver driver1(Name("Liaqat", "Rickshaw Wala"), Date(13,2,1978), 45, 101, 1, 3000, 15, 1, 4);
	string licenses[] = {"Car", "Truck"};
	driver1.assignLicenses(licenses, 2);
	Driver driver2(Name("Khan", "Baba"), Date(23,6,1981), 38, 102, 2, 3050, 10, 1, 4.6);
	Driver driver3(Name("Arslan", ""), Date(21,5,1990), 35, 103, 3, 4010, 7, 1, 4.3);
	tms.addDriver(driver1);
	tms.addDriver(driver2);
	tms.addDriver(driver3);
	char License[] = "Car";
	char* license = License;
	char fuel[] = "Petrol";
	char* fuelptr = fuel;
	Vehicle vehicle1(1, 101, 350.2, license, true, fuelptr, 4.6, Date(1, 1, 2020));
	Vehicle vehicle2(2, 102, 350.5, license, true, fuelptr, 4.6, Date(1, 1, 2020));
	Vehicle vehicle3(3, 103, 350.9, license, true, fuelptr, 4.6, Date(1, 1, 2020));
	tms.addVehicle(vehicle1);
	tms.addVehicle(vehicle2);
	tms.addVehicle(vehicle3);
//	tms.addServiceRequest(1, Name("Mehran", "Shah"), Date(28, 11, 2024), 24, 101, "Lahore", "Multan", 150, 10, 1, 28, 10, 2018, 10, 35, 00);	

    
    int choice;
    bool running = true;
    while (running) {
        cout << "\n==== Transport Management System Dropdown Menu ====" << endl;
        cout << "1. Add a new Customer" << endl;
        cout << "2. Add or remove a Driver" << endl;
        cout << "3. Add or remove a Vehicle" << endl;
        cout << "4. Print List of All Customers" << endl;
        cout << "5. Print List of All Drivers" << endl;
        cout << "6. Print List of Vehicles with Details by Category" << endl;
        cout << "7. Print Complete List of Services by Vehicle (Provide Vehicle ID)" << endl;
        cout << "8. Print Complete History of a Particular Customer (Provide Customer ID)" << endl;
        cout << "9. Print Complete History of a Driver (Provide Driver ID)" << endl;
        cout << "10. Print List of All Drivers with Ranking Above 4.5" << endl;
        cout << "11. Print List of Drivers with Multiple Licenses" << endl;
        cout << "12. Print Updated Salary of All Drivers" << endl;
        cout << "13. Add a Service Request" << endl;
        cout << "14. Cancel a Service Request (Provide Service and Customer ID)" << endl;
        cout << "15. Complete a Service Request (Provide Service ID)" << endl;
        cout << "16. Print Details of All Customers Who Used Same Vehicle" << endl;
        cout << "17. Print Drivers Who Completed Delivery on Same Day" << endl;
        cout << "18. Print Pending Services on a Particular Date" << endl;
        cout << "19. Print Pending Services of a Particular Driver" << endl;
        cout << "20. Print Canceled Services by a Customer" << endl;
        cout << "0. Exit" << endl;
        cout << "Please, Enter a valid choice : ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string firstName, lastName;
            int age, nid, id, day, month, year;

            cout << "Enter Customer First Name: ";
            cin >> firstName;
            cout << "Enter Customer Last Name: ";
            cin >> lastName;
            cout << "Enter Customer Age: ";
            cin >> age;
            cout << "Enter Customer NID: ";
            cin >> nid;
            cout << "Enter Customer ID: ";
            cin >> id;
            cout << "Enter Customer Date of Birth (day month year): ";
            cin >> day >> month >> year;

            Customer newCustomer(Name(firstName, lastName), Date(day, month, year), age, nid, id);
            tms.addCustomer(newCustomer);
            break;
        }
        case 2: {
            string firstName, lastName;
            int age, nid, id, driverId;
            cin >> id;
            float salary, ranking;
            int experience, vehicleId;
            int driverChoice;
            cout << "Enter Driver First Name: ";
            cin >> firstName;
            cout << "Enter Driver Last Name: ";
            cin >> lastName;
            cout << "Enter Driver Age: ";
            cin >> age;
            cout << "Enter Driver NID: ";
            cin >> nid;
            cout << "Enter Driver ID: ";
            cin >> driverId;
            cout << "Enter Salary: ";
            cin >> salary;
            cout << "Enter Driver Ranking: ";
            cin >> ranking;
            cout << "Enter Years of Experience: ";
            cin >> experience;
            cout << "Enter Vehicle ID: ";
            cin >> vehicleId;

            Driver newDriver(Name(firstName, lastName), Date(0, 0, 0), age, nid, driverId, salary, experience, vehicleId, ranking);
            cout << "Please Enter 1 to add and 2 to remove a driver " << endl;
            cin >> driverChoice;
            if (driverChoice == 1) {
                tms.addDriver(newDriver);
            }
            if (driverChoice == 2) {
                tms.removeDriver(driverId);
            }
            break;
        }
        case 3: {
            int vehiclechoice;
            int vehicleId, driverId;
            float mileage, fuelEfficiency;
            char license[50], fuel[50];
            int day, month, year;

            cout << "Enter Vehicle ID: ";
            cin >> vehicleId;
            cout << "Enter Driver ID: ";
            cin >> driverId;
            cout << "Enter Mileage: ";
            cin >> mileage;
            cout << "Enter License Type: ";
            cin >> license;
            cout << "Enter Fuel Type: ";
            cin >> fuel;
            cout << "Enter Fuel Efficiency: ";
            cin >> fuelEfficiency;
            cout << "Enter Manufacture Date (day month year): ";
            cin >> day >> month >> year;

            Vehicle newVehicle(vehicleId, driverId, mileage, license, true, fuel, fuelEfficiency, Date(day, month, year));
            cout << "Adding or removing the driver" << endl;
            cout << "Enter 1 to add or 2 if you want to remove " << endl;
            cin >> vehiclechoice;

            if (vehiclechoice == 1)
            {
                tms.addVehicle(newVehicle);
            }
            if (vehiclechoice == 2) {
                tms.removeVehicle(vehicleId);

            }

            break;
        }
        case 4: {

            tms.printCustomers();
            break;
        }
        case 5:
            tms.printDrivers();
            break;
        case 6: {
            string category;
            cout << "Enter Vehicle Category (e.g., Car, Truck, Van): ";
            cin >> category;
            tms.printVehiclesByCategory(category);
            break;
        }

        case 7: {
            int vehicleId;
            cout << "Enter Vehicle ID to view services: ";
            cin >> vehicleId;
            tms.printServicesByVehicle(vehicleId);
            break;
        }
        case 8: {
            int customerId;
            cout << "Enter Customer ID to fetch history: ";
            cin >> customerId;
            tms.printCustomerHistory(customerId);

            break;
        }
        case 9: {
            int driverId;
            cout << "Enter Driver ID to fetch history: ";
            cin >> driverId;
            tms.printDriverHistory(driverId);
            break;
        }
        case 10: {
            tms.printDriversWithRankingAbove4_5();
            break;
        }

        case 11:
            tms.lisencedDrivers();
            break;
        case 12:
            tms.updateSalary();
            break;
        case 13: {
            float dist, rateOfFuel;
            int serviceId;
         char* dest = new char[50];
    	char* src = new char[50];
            cout << "Enter Distance: ";
            cin >> dist;
            cout << "Enter Fuel Rate : ";
            cin >> rateOfFuel;
            cout << "Enter Service ID: ";
            cin >> serviceId;
            int day, month, year;
            cout<<"Enter Day: ";
            cin>>day;
            cout<<"Enter Month: ";
            cin>>month;
            cout<<"Enter Year: ";
            cin>>year;
            int custID;
            cout<<"Enter Customer ID: ";
            cin>>custID;
            cin.ignore();
            cout << "Enter Source Ad: ";
            cin.getline(src, 50);
            cout << "Enter Dest Ad: ";
            cin.getline(dest, 50);
            string fname, lname;
            cout<<"First Name: ";
            cin>>fname;
            cout<<"Last Name: ";
            cin>>lname;
            int nid, age;
            cout<<"Enter NID: ";
            cin>>nid;
            cout<<"Enter Age: ";
            cin>>age;

            tms.addServiceRequest(custID, Name(fname, lname), Date(day, month, year), 24, nid, dest, src, rateOfFuel, dist, serviceId, day, month, year, 3, 0, 0);
            break;
        }
        case 14: {
            int serviceId, customerId;
            cout << "Enter the Service id in order to cancel: ";
            cin >> serviceId;
            cout << "Enter the Customer ID: ";
            cin >> customerId;
            tms.cancelServiceRequest(serviceId, customerId);
            break;
        }
        case 15: {
            int serviceId;
            cout << "Enter Service ID you want to Complete: ";
            cin >> serviceId;
            tms.completeServiceRequest(serviceId);
            break;
        }
        case 16: {
            int vehicleId;
            cout << "Enter the Vehicle id: ";
            cin >> vehicleId;
            tms.printCustomersByVehicleUsage(vehicleId);
            break;
        }
        case 17: {

            tms.printDriversWithSameDayDeliveries();
            break;
        }
        case 18: {
            int day, month, year;
            cout << "Enter the Date to check pending services ! ";
            cin >> day >> month >> year;
            tms.printPendingServicesOnDate(day, month, year);
            break;
        }

        case 19: {
            int driverId;
            cout << "Enter Driver ID: ";
            cin >> driverId;
            tms.printPendingServicesOfDriver(driverId);
            break;
        }
        case 20: {
            int customerId;
            cout << "Enter Customers ID: ";
            cin >> customerId;
            tms.printCanceledServicesOfCustomer(customerId);
            break;
        }
        case 0:
            cout << "Exited " << endl;
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }
    }

    return 0;
}

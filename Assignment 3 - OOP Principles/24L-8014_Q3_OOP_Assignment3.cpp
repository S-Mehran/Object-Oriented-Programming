#include <iostream>
#include <string>

using namespace std;

class systemInfo {
private:
    string systemName;
    string systemOS;
    string IP;

    // Private constructor for Singleton
    systemInfo(string name, string OS, string ip) {
        systemName = name;
        systemOS = OS;
        IP = ip;
    }
    
    
	//creating the static instance
    static systemInfo* instance; 

public:
    void print() 
	{
        cout << "System Name: " << systemName << endl;
        cout << "Operating System: " << systemOS << endl;
        cout << "IP Address: " << IP << endl;
    }

    // Providing Global Access
    static systemInfo* getInstance() 
	{
        if (instance == nullptr) {
            instance = new systemInfo("Dell", "Windows", "192.168.0.1");
        }
        return instance;
    }
    
    
    //Destructor
    ~systemInfo()
    {
    	delete instance;
	}
};

// Initializing the static member
systemInfo* systemInfo::instance = nullptr;

int main() 
{

    systemInfo* system = systemInfo::getInstance();
    system->print();

    return 0;
}




#include <string>
#include <chrono>
#include <ctime>
//REMOVED: typedef string pin;
using namespace std;


/*struct datetime {
	//tm* day = localtime(&t);
	time_t _time;
}*/
time_t GetTime () {
	time_t now;
	return now;
}

// Global constants to set pin size values
struct PINSIZE {
  const int SERVER = 3; 										//##CONFIGURABLE##//
  const int COOK = 3; 											//##CONFIGURABLE##//
  const int MANAGER = 4; 										//##CONFIGURABLE##//
} PINSIZE;


// REMOVED: enum Position = { Server = 1, Cook = 2, Manager = 3, DNE = 0 };


class Employee {
	
	private:
	
		int id;
		string name;
		time_t kronos_in;
		time_t kronos_out;
		bool kronos_otc;
		int role;
		
	public:
		
		// Constructor
		Employee(int newId);
		Employee(int newId, string newName);
		Employee(string newPin, string newName, int newRole);
		// this Constructor specifically for reading in data
		Employee(int Load_Id, string Load_Name, string Load_Role, string Load_TimeIn, string Load_TimeOut, char Load_TimeOtc );
		~Employee();
		
		void SetPin(int newId);
		int GetPin();
		
		void SetName(string newName);
		string GetName();
		
		void SetRole(int newRole);
		int GetRole();
		
		void SetIn();
		time_t GetIn();
		
		void SetOut();
		time_t GetOut();
		
		//void SetOTC();
		bool GetOTC();
		
		int IdentifyRole(string scanPin);
		
};
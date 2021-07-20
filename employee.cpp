

#include <string>
#include <chrono>
#include <ctime>
#include "employee.h"
using namespace std;


// Global constants to set return values for authenticate()
struct ROLE_RETURN {
  int SERVER = 2; 											//##CONFIGURABLE##//
  int COOK = 1; 											//##CONFIGURABLE##//
  int MANAGER = 3; 											//##CONFIGURABLE##//
} ROLE_RETURN;
struct ROLE_RETURN_NAME {
  string SERVER = "SERVER"; 								//##CONFIGURABLE##//
  string COOK = "COOK"; 									//##CONFIGURABLE##//
  string MANAGER = "MANAGER"; 								//##CONFIGURABLE##//
 } ROLE_RETURN_NAME;


/* CONSTRUCTORS */

Employee::Employee( int newPin) {
	id = newPin;
}
Employee::Employee( int newPin, string newName) {
	id = newPin;
	name = newName;
}
Employee::Employee( int newPin, string newName, newRole) {
	id = newPin;
	name = newName;
	role = newRole;
}
// for loading database only:
Employee::Employee( int Load_Id, string Load_Name, string Load_Role, string Load_TimeIn, string Load_TimeOut, char Load_TimeOtc ) {
	id = Load_Id;
	name = Load_Name;
	if (Load_Role == ROLE_RETURN_NAME.SERVER) {
		role = ROLE_RETURN.SERVER;
	} else if (Load_Role == ROLE_RETURN_NAME.COOK) {
		role = ROLE_RETURN.COOK;
	} else if (Load_Role == ROLE_RETURN_NAME.MANAGER) {
		role = ROLE_RETURN.MANAGER;
	} else {
		role = 0;
	}
	//kronos_in = Load_TimeIn; //FIXME
	//kronos_out = Load_TimeOut; //FIXME
	if (Load_TimeOtc == 'Y') {
		kronos_otc = true;
	} else if (Load_TimeOtc == 'N') {
		kronos_otc = false;
	} else {}
}

/* DESTRUCTOR */
Employee::~Employee() {
	// apparently need to be pointers
	delete id; 
	delete name;
	delete kronos_in;
	delete kronos_out;
	delete kronos_otc;
	delete role;
}


/* CLASS METHODS */

void Employee::SetPin( int newId ) { id = newId; };
int Employee::GetPin() { return id; };

void Employee::SetName(string newName) { name = newName; };
string Employee::GetName() { return name; };

void Employee::SetRole(int newRole) {/*
	switch (newRole) {
		case ROLE_RETURN.SERVER:
			role = ROLE_RETURN.SERVER;
		case ROLE_RETURN.COOK:
			role = ROLE_RETURN.COOK;
		case ROLE_RETURN.MANAGER:
			role = ROLE_RETURN.MANAGER;
		default:
			// ERROR
			;
	}*/
};
int Employee::GetRole() { return role; };

void Employee::SetIn() { kronos_in = GetTime(); kronos_otc = true;};
time_t Employee::GetIn() { return kronos_in; };

void Employee::SetOut() { kronos_out = GetTime(); kronos_otc = false;};
time_t Employee::GetOut() { return kronos_out; };

//void Employee::SetOTC(bool newOtc) { kronos_otc = newOtc }; // unneeded; this should only be changed when time in/out anyway
bool Employee::GetOTC() { return kronos_otc; };


/* OTHER CLASS METHODS */
int Employee::IdentifyRole(string scanPin) {
	if ( scanPin.length() == PINSIZE.MANAGER ) {
		return ROLE_RETURN.MANAGER;
	}
	else if ( scanPin.length() == PINSIZE.SERVER ) {
		return ROLE_RETURN.SERVER;
	}
	else if ( scanPin.length() == PINSIZE.COOK ) {
		return ROLE_RETURN.COOK;
	}
	else {
		//cout << endl << "ERR: Pin is not valid number of digits." << endl;
		return 0;
	}
};
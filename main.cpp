

#include "auth_new.cpp"
#include "employee.cpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


// Global constants to set return values for authenticate()
struct PINAUTH_RETURN {
  int SERVER = 2; 											//##CONFIGURABLE##//
  int COOK = 1; 											//##CONFIGURABLE##//
  int MANAGER = 3; 											//##CONFIGURABLE##//
} PINAUTH_RETURN;


int main () {
	
	Load(DATABASE);
	
	if (DEBUGMODE) {
		TestMenu();
	}
	
	return 0;
	
}
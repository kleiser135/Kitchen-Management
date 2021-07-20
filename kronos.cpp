/*

	TIMECLOCK

*/

#include <chrono>
#include <ctime>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


// Global constants to set return values for ClockIn() and ClockOut()
struct TIMECLOCK_RETURNVALUE {
  const int _TRUE = 1; // clock in/out success 					//##CONFIGURABLE##//
  const int _FALSE = 0; // clock in/out failed 					//##CONFIGURABLE##//
} TIMECLOCK_RETURNVALUE;


// struct is to define a row in the database
struct clockentry {
  int id; // pin
  int in; // time out
  int out; // time in
  bool otc; // "on the clock"
};





/* Constants */
//vector<clockentry>


// ClockIn():

// validate pin exists
//   if !found return ^false^
// iterate over pin list
// set THIS.in = CURR_TIME
// set THIS.otc = true
// store data (employee_db.csv) [NEW]


// ClockOut()
// validate pin exists
//   if !found return ^false^
// validate employee otc=true
//   if !found return ^false^
// iterate over pin list
// set THIS.in = CURR_TIME
// set THIS.otc = true
// store data (employee_db.csv) [NEW]

// Read()


// Write()


// 


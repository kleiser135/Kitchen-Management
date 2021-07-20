

#include <ctime>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "timeclock.h"
//typedef string pin;
using namespace std;


// Global constants to set return values for authenticate()
struct TIMECLOCK_RETURNVALUE {
  const int _TRUE = 1; // clock in/out success 					//##CONFIGURABLE##//
  const int _FALSE = 0; // clock in/out failed 					//##CONFIGURABLE##//
} TIMECLOCK_RETURNVALUE;

struct TimeClock_data {
  int id; // pin
  int in; // time out
  int out; // time in
  bool otc; // "on the clock"
} TimeClock_data;

const string FILE_TIMECLOCK = "timeclockdb.csv"; 				//##CONFIGURABLE##//
const string FILE_TIMECLOCKIN = "timeclock_in.csv"; 			//##CONFIGURABLE##//
const string FILE_TIMECLOCKOUT = "timeclock_out.csv"; 			//##CONFIGURABLE##//
vector<TimeClock_data> local_timeclock; // "on the clock"
int localTCn = 0;


void Store2 ( string file ) {
	ofstream out;
	out.open(file);
	
	// Store data from local runtime database into file
	localTCn = local_timeclock.size(); // confirm that the initial value represents the size of local_timeclock
	out << localTCn << endl; // store number of records on the first line
	for ( int i = 0; i < localTCn; i++ ) {
		out << localTCn.at(i).id << ","
			<< localTCn.at(i).in << ","
			<< localTCn.at(i).out << ","
			<< localTCn.at(i).otc << endl;
	}
	
	out.close();
}


void Load2 (string file ) {
	ifstream in;	
	in.open(file);
	
	// Load data from file into local runtime database
	int n;
	in << n; // get number of records from the first line
	
	string tc_dat_id; // new pin
	unsigned int tc_dat_in; // new time in
	unsigned int tc_dat_out; // new time out
	bool tc_dat_otc; // new otc value
	/*
	while( getline(in,tc_dat_id,',') ) {
		TimeClock_data;
		TimeClock_data *_dat = &dat;
		new(_dat) TimeClock_data();
		
		getline(in,tc_dat_in,',');
		getline(in,tc_dat_out,',');
		getline(in,tc_dat_otc,',');
		
		tc_data.id = tc_dat_id;
		tc_data.in = tc_dat_in;
		tc_data.out = tc_dat_out;
		tc_data.otc = tc_dat_otc;
		
		local_timeclock.push_back(tc_data);
	}*/
	/*
	int r;
	in >> r;
	localDBn = r;
	for ( int i = 0; i < localDBn; i++ ) {
		string t;
		in >> t;
		localTCn.push_back(t);
	}*/
	
	
	
	TimeClock_Row *temp;
	string tc_dat_id;
	unsigned int  tc_dat_in;
	unsigned int  tc_dat_out;
	bool tc_dat_otc;
	
	getline(in,tc_dat_id,',');
	getline(in,tc_dat_in,',');
	getline(in,tc_dat_out,',');
	getline(in,tc_dat_otc,',');


	// Construct a new record and add them to the database
	temp = new TimeClock_Row(tc_dat_id,tc_dat_in,tc_dat_out,tc_dat_otc);
	local_timeclock.push_back(temp);
	//upNum();
	
	in.close();
}


int ClockIn (string pin) {
	
	// Validate employee exists
	bool found = false;
	for ( int i = 0; i < localTCn; i++ ) {
		if ( pin == localTCn.at(i) ) {
			found = true;
			break;
		}
	}
	if (!found) {
		// return TIMECLOCK_RETURNVALUE._FALSE;
	}
	
	// iterate over runtime_db
	// *.in = time
	// *.otc = true

	// store data
	// return TIMECLOCK_RETURNVALUE._TRUE;
	
}


int ClockOut (string pin) {
	
	// Validate employee exists AND is clocked-in
	bool found = false;
	for ( int i = 0; i < localTCn; i++ ) {
		if ( pin == localTCn.at(i) ) {
			found = true;
			break;
		}
	}
	if (!found) {
		// return TIMECLOCK_RETURNVALUE._FALSE;
	}
	
	// iterate over runtime_db
	// *.out = time
	// *.otc = false
	
	// store data
	// return TIMECLOCK_RETURNVALUE._TRUE;
	
}


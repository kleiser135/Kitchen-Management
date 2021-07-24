

#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
//typedef string pin;
using namespace std;


/* DEBUG MODE */
const int DEBUGMODE = 1;

// Global constants to set pin size values
struct PINSIZE {
  const int SERVER = 3; 										//##CONFIGURABLE##//
  const int COOK = 3; 											//##CONFIGURABLE##//
  const int MANAGER = 4; 										//##CONFIGURABLE##//
} PINSIZE;

// Global constants to set return values for authenticate()
struct PINAUTH_RETURN {
  const int SERVER = 2; 										//##CONFIGURABLE##//
  const int COOK = 1; 											//##CONFIGURABLE##//
  const int MANAGER = 3; 										//##CONFIGURABLE##//
} PINAUTH_RETURN;


const string DATABASE = "userdb.dat";							//##CONFIGURABLE##//
int DATABASE_SIZE = 0;
vector<string> localDB = {};
int localDBn = 0;

const string TIMEFILESDIR = "times.dat";						//##CONFIGURABLE##//
int TIMEFILESDIR_SIZE = 0;
vector<string> timeFiles = {};
const string TIMEFILEFOLDER = "";								//				  //
const string TIMEFILEPRE = "timesheet-";						//##CONFIGURABLE##//
const string TIMEFILEPOST = ".dat";								//##CONFIGURABLE##// 

// clock in/out object
struct kronos {
	string pin;
	bool onclock;
	string timein;
	string timeout;
};
vector<kronos> KRONOS_DATA = {};



int authenticate (string input) {
	
	// Validate
	//	check for exisiting pin
	bool found = false;
	for ( int i = 0; i < localDBn; i++ ) {
		if ( input == localDB.at(i) ) {
			found = true;
			break;
		}
	}
		
	if ( found == true ) {
		if ( input.length() == PINSIZE.MANAGER ) {
			return PINAUTH_RETURN.MANAGER;
		}
		else if ( input.length() == PINSIZE.SERVER ) {
			return PINAUTH_RETURN.SERVER;
		}
		else if ( input.length() == PINSIZE.COOK ) {
			return PINAUTH_RETURN.COOK;
		}
		else {
			return 0;
		}
	}
	
}
string AUTHPIN;
int authenticate (string input, int minAccess) { // ex: authenticate("585",PINSIZE.MANAGER);
	
	// Validate
	//	check for exisiting pin
	bool found = false;
	for ( int i = 0; i < localDBn; i++ ) {
		if ( input == localDB.at(i) ) {
			found = true;
			break;
		}
	}
		
	AUTHPIN = ""; // clear gloabal authpin; value already passed to function
	
	if ( validate(input) ) {
		if ( input.length() >= minAccess ) {
			return 1;
		}
		else {
			return 0;
		}
	}
	
}


// return 1 if match found
int validateExists (string input) {
	
	// Validate
	//	check for exisiting pin
	for ( int i = 0; i < localDBn; i++) {
		if ( input == localDB.at(i) ) {
			return 1;
		}
	}
	
	return 0;
	
}

void setTimeFiles () {
	
	string master = TIMEFILESDIR;
	ofstream out;
	out.open(master);
	
	TIMEFILESDIR_SIZE = timeFiles.size();
	out << TIMEFILESDIR_SIZE << endl; // store size on first line
	
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		out << timeFiles.at(i) << endl;
	}
	
	out.close();
}

// called once at start
void importKronos () {
	
	if ( !(TIMEFILESDIR_SIZE > 0) && DEBUGMODE ) cout << "ERR: Unable to locate leaf files. Master may be empty.";
	if ( !(TIMEFILESDIR_SIZE > 0) ) return;
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		
		ifstream in;	
		in.open(timeFiles.at(i)); // open the i'th file
		if(!in) { return; }
		
		string _pin, _in, _out;
		bool _otc = 0;
		in >> _pin;
		in >> _otc;
		getline(in, _in);
		getline(in, _out);
		kronos _temp = {_pin, _otc, _in, _out};
		KRONOS_DATA.push_back(_temp);
		in.close();
		
	}
	
}

// this just syncs runtime to database, all it needs is which database file to update
void updateKronosFile (string findFile) {
	
	string leaf = findFile;
	ofstream out;
	out.open(leaf);
	
	// update external database
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		out << KRONOS_DATA.at(i).pin << endl;
		out << KRONOS_DATA.at(i).timein << endl;
		out << KRONOS_DATA.at(i).timeout << endl;
		out << KRONOS_DATA.at(i).onclock << endl;
	}
	
	out.close();
		
}

// clears user clock in info, not files or pins
int ClockClear (string user) {
	
	// validate user exists
	if ( !validateExists(user) ) return 0; // 1st fail condition
	
	// update local database
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		if ( KRONOS_DATA.at(i).pin == user) {
			//NOTE: KRONOS_DATA.at(i).pin stays; it should not be reset.
			//		also the entry remains in vector, not popped. only removed when reloading app without the pin present.
			//		the removed users clock files are not deleted. (we can look into this later, though).
			KRONOS_DATA.at(i).timein = "";
			KRONOS_DATA.at(i).timeout = "";
			KRONOS_DATA.at(i).onclock = 0;
		}
	}
	// NOTE: if this doesn't work, use a temp to copy existing info then delete the erntry entirely and create new entry again with all the data
	
	// locate output file to update
	string findFile;
	findFile = TIMEFILEFOLDER + TIMEFILEPRE + user + TIMEFILEPOST;
	updateKronosFile(findFile);
	
}


void getTimeFiles () {
	
	string master = TIMEFILESDIR;
	ifstream in;
	in.open(master);
	{ if (!in) {
		if (!(DEBUGMODE)) return;
		if (DEBUGMODE) { cout << endl << "ERR: Problem accessing input file. File may be moved or missing." << endl; in.close(); };
	/*}}
	
	int r;
	in >> r;
	TIMEFILESDIR_SIZE = r;
	cout << r;
	// times.dat is empty (cannot just be ?=0 because if file DNE it can be anything really)
	if ( TIMEFILESDIR_SIZE <= 0 || TIMEFILESDIR_SIZE > 99999 ) {*/
		// set up times.dat for first time (pins are missing)
		in.close(); // cancel load; file is empty anyway
		timeFiles.clear();
		for ( int i = 0; i < localDBn; i++) {
			// update local database
			TIMEFILESDIR_SIZE = localDBn;
			ofstream out;
			out.open(master);
			out << TIMEFILESDIR_SIZE << endl;
			for ( int i = 0; i < localDBn; i++ ) { 
				
				string findFile = TIMEFILEPRE + localDB.at(i) + TIMEFILEPOST;
				out << findFile << endl;
				timeFiles.clear();
				
			}
			out.close();
		}
		
		getTimeFiles(); // try again
	}}
	
	// times.dat has data
	int r;
	in >> r;
	TIMEFILESDIR_SIZE = r;
	//in.close(); in.open(master); // re-open
	for ( int i = 0; i < r; i++ ) {
		string t;
		in >> t;
		timeFiles.push_back(t);
		
	}
	KRONOS_DATA.clear();
	for ( int i = 0; i < localDBn; i++ ) { 
		string _pin, _in, _out; bool _otc = 0;
		_pin = localDB.at(i);
		kronos _temp = {_pin, _otc, _in, _out};
		KRONOS_DATA.push_back(_temp);
		
		string findFile = TIMEFILEPRE + _pin + TIMEFILEPOST;
		//updateKronosFile(findFile);
	}
	in.close();
	
	
	
	for ( int i = 0; i < timeFiles.size(); i++ ) { // for every file...
		fstream out;
		string file = timeFiles.at(i);
		out.open(file);
		// update external database
		//for ( int j = 0; j < KRONOS_DATA.size(); j++ ) {
			out << KRONOS_DATA.at(i).pin << endl;
			out << KRONOS_DATA.at(i).timein << endl;
			out << KRONOS_DATA.at(i).timeout << endl;
			out << KRONOS_DATA.at(i).onclock << endl;
		//}
		out.close();
	}
	
	
	
	//importKronos();
	
}


void save (string file) {
	ofstream out;
	out.open(file);
	
	localDBn = localDB.size();
	out << localDBn << endl; // store size on first line
	for ( int i = 0; i < localDBn; i++ ) {
		out << localDB.at(i) << endl;
	}
	
	out.close();
}

void load (string file) {
	ifstream in;	
	in.open(file);
	// error case (if file does not open or exist):
	{ if(!in) {
		if (!DEBUGMODE) return;
		if (DEBUGMODE) { cout << endl << "ERR: Problem accessing input file. File may be moved or missing." << endl; in.close(); };
		int option = 0;
		if (DEBUGMODE) { cout << "Enter 0 to cancel the operation, and locate or repair the file.\n" <<
		"Enter 1 to create a replacement.\n" << endl; }
		cin >> option;
		DATABASE_SIZE++;
		if ( option == 1 ) {
			save(file);
		}
		else {
			return;
		}
	}}
	
	int r;
	in >> r;
	localDBn = r;
	for ( int i = 0; i < localDBn; i++ ) {
		string t;
		in >> t;
		localDB.push_back(t);
	}
	
	in.close();
}

int UserCreate(string input) {
		
	// Validate
	//	check for exisiting pin; pin must not exist to be created
	if ( validateExists(input) && DEBUGMODE ) {
	if (DEBUGMODE) { cout << "ERR: Pin " << input << " already exists. Select a different pin." << endl; }
		return 0;
	}
	
	// Store
	//	save pin to the database (runtime and storage)
	localDB.push_back(input);
	localDBn = localDB.size();
	save(DATABASE);
	
	return 1;
	
}

int UserDelete(string input) {
		
	// Validate
	//	check for exisiting pin; pin must exist to be deleted
	if ( !validateExists(input) ) return 0;
	if ( !validateExists(input) & DEBUGMODE) {cout << "ERR: Pin " << input << " already exists. Select a different pin." << endl;}
	
	auto it = localDB.begin();
	while ( it != localDB.end() ) {
		if ( *it == input ) {
			it = localDB.erase(it);
			// Store
			//	save pin to the database (runtime and storage)
			localDBn = localDB.size();
			save(DATABASE);
			return 1;
		}
		else {
			++it;
		}
	}
	return 0;
	
}

int UserEdit(string oldInput, string newInput) {
		
	// Replace
	//	replace the existing pin with the new pin
	UserDelete(oldInput);
	UserCreate(newInput); // bug: does not stop from duplicating existing pins // nvm i think it does
	
	// Store
	//	save pin to the database (runtime and storage)
	localDBn = localDB.size();
	save(DATABASE);
	
	return 1;
	
}

// 1 = success, 0 = fail
int ClockIn (string user, string time) {
	
	// validate user exists
	if ( !validateExists(user) ) return 0; // 1st fail condition
	
	// validate user is clocked-out
	bool co;
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		if ( KRONOS_DATA.at(i).pin == user) {
			if ( KRONOS_DATA.at(i).onclock == 0 ) {
				co = false;
			}
		}
	}
	if (!co) {
		if (DEBUGMODE) cout << "ERR: Employee is on-the-clock." << endl;
		return 0; // 2nd fail condition
	}
	
	// update local database
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		if ( KRONOS_DATA.at(i).pin == user) {
			KRONOS_DATA.at(i).timein = time;
			KRONOS_DATA.at(i).onclock = 1;
		}
	}
	// NOTE: if this doesn't work, use a temp to copy existing info then delete the erntry entirely and create new entry again with all the data
	
	// locate output file to update
	string findFile;
	findFile = TIMEFILEFOLDER + TIMEFILEPRE + user + TIMEFILEPOST;
	updateKronosFile(findFile);
	
}

// 1 = success, 0 = fail
int ClockOut (string user, string time) {
	
	// validate user exists
	if ( !validateExists(user) ) return 0; // 1st fail condition
	
	// validate user is clocked-in
	bool ci;
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		if ( KRONOS_DATA.at(i).pin == user) {
			if ( KRONOS_DATA.at(i).onclock == 1 ) {
				ci = true;
			}
		}
	}
	if (!ci) {
		if (DEBUGMODE) cout << "ERR: Employee not clocked-in." << endl;
		return 0; // 2nd fail condition
	}
	
	// update local database
	for ( int i = 0; i < TIMEFILESDIR_SIZE; i++ ) {
		if ( KRONOS_DATA.at(i).pin == user) {
			KRONOS_DATA.at(i).timeout = time;
			KRONOS_DATA.at(i).onclock = 0;
		}
	}
	// NOTE: if this doesn't work, use a temp to copy existing info then delete the erntry entirely and create new entry again with all the data
	
	// locate output file to update
	string findFile;
	findFile = TIMEFILEFOLDER + TIMEFILEPRE + user + TIMEFILEPOST;
	updateKronosFile(findFile);

}


void TestMenu () {
	
	cout << endl;
	cout << "TestMenu() started." << endl;
	cout << endl;
	cout << "Locating database... ";
	cout << DATABASE << endl;
	cout << "Database accessed: " << DATABASE_SIZE << " lines\n" << endl;
	cout << "Locating database... ";
	cout << TIMEFILESDIR << endl;
	cout << "Database accessed: " << TIMEFILESDIR_SIZE << " lines\n" << endl;
	
	bool menuloop;
	do {
		menuloop = true;
		int choice;
		cout << endl;
		cout << "============================================================================" << endl;
		cout << endl;
		cout << "FUNCTIONS" << endl;
		cout << "1. Create User" << "\t" << "2. Edit User" << "\t" << "3. Delete User" << "\n"
			"4. Clock In" << "\t" << "5. Clock Out" << "\t" << /*"6. Clock Inquiry" <<*/ "\n" << endl; 
		cout << "VECTORS" << endl;
		cout << "7. localDB<>" << "\t" << "8. timeFiles<>" << "\t" << "9. KRONOS_DATA<>" << "\n" << endl;
		cout << "Option: ";
		cin >> choice;
		cout << endl;
		switch (choice) {
			case 1: {
				string newPin;
				cout << "Create User" << endl;
				//if (!authenticate(AUTHPIN,minAccess)) break;
				cout << "Pin: ";
				cin >> newPin;
				UserCreate(newPin);
				//menuloop = false;
			break; }
				
			case 2: {
				string newPin, oldPin;;
				cout << "Edit User" << endl;
				//if (!authenticate(AUTHPIN,minAccess)) break; // this should be done in main or other menus when getting input
				cout << "Current Pin: " << endl;
				cin >> oldPin;
				cout << "New Pin: " << endl;
				cin >> newPin;
				UserEdit(oldPin,newPin);
				//menuloop = false;
				break; }
				
			case 3: {
				string delPin;
				cout << "Delete User" << endl;
				//if (!authenticate(AUTHPIN,minAccess)) break; // this should be done in main or other menus when getting input
				cout << "Delete Pin: " << endl;
				cin >> delPin;
				UserDelete(delPin);
				//menuloop = false;
				break; }
				
			case 4: {
				string ciPin, ciTime;
				cout << "Clock-in User" << endl;
				cout << "Pin: " << endl;
				cin >> ciPin;
				cout << "Time: " << endl;
				getline(cin,ciTime);
				ClockIn(ciPin,ciTime);
				//menuloop = false;
				break; }
				
			case 5: {
				string coPin, coTime;
				cout << "Clock-out User" << endl;
				cout << "Pin: " << endl;
				cin >> coPin;
				cout << "Time: " << endl;
				getline(cin,coTime);
				ClockOut(coPin,coTime);
				//menuloop = false;
				break; }
				
			case 7: {
				cout << "size=" << localDB.size() << endl;
				for ( int i = 0; i < localDBn; i++) {
					cout << localDB.at(i) << endl;
				}
				cout << endl;
				//menuloop = false;
				break; }
			
			case 8: {
				cout << "size=" << timeFiles.size() << endl;
				for ( int i = 0; i < timeFiles.size(); i++) {
					cout << timeFiles.at(i) << endl;
				}
				cout << endl;
				//menuloop = false;
				break; }
				
			case 9: {
				cout << "size=" << KRONOS_DATA.size() << endl;
				for ( int i = 0; i < KRONOS_DATA.size(); i++ ) {
					cout << KRONOS_DATA.at(i).pin << "\t";
					cout << KRONOS_DATA.at(i).timein << "\t";
					cout << KRONOS_DATA.at(i).timeout << "\t";
					cout << KRONOS_DATA.at(i).onclock << "\n";
				}
				cout << endl;
				//menuloop = false;
				break; }
				
				
			default:
				menuloop = false;
				break;
		}
	} while ( menuloop == true );
	
	
};
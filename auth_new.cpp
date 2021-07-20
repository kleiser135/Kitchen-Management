

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



const string DATABASE = "database.csv";						//##CONFIGURABLE##//
// was meant to pre-load file and get number of lines (number of records):
/*ifstream in;
in.open(DATABASE);
string line;
while(!DATABASE.eof()){
	getline(DATABASE,line);
	DATABASE_SIZE++;
}
DATABASE.close();*/
int DATABASE_SIZE;
vector<Employee> Users;

// OLD:
//vector<string> localDB = {};
//int localDBn = 0;


//FIXME
void Save ( string file ) {
	
	// NOT WORKING
	ofstream out;
	out.open(file);
	
	
	
	if(DEBUGMODE){cout<<"Saved!"<<endl;};
	out.close();
}


//FIXME
void Load (string file ) {
	
	// NOT WORKING
	ifstream in;
	in.open(file);
	string Load_id , Load_name , Load_role , Load_timein , Load_timeout , Load_timeotc;
	for ( int i = 0; i < DATABASE_SIZE; i++) {
		in >> Load_id >> Load_name >> Load_role >> get_time(Load_timein,"%R") >> get_time(Load_timeout,"%R") >> Load_timeotc;
		Users.push_back( new Employee(Load_id,Load_name,Load_role,Load_timein,Load_timeout,Load_timeotc) );
	}
	
	
	/*
	ifstream data(file);
    string line;
    vector<vector<string>> parsedCsv;
	while(getline(data,line)) {
        stringstream lineStream(line);
        string cell;
        vector<string> parsedRow;
        while(getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }

        parsedCsv.push_back(parsedRow);
    }*/
	/*string Load_id, Load_name; int Load_role; bool Load_timeotc; string Load_timein, Load_timeout;
	while (getline(in,Load_id,',')) {
		getline(in,Load_name,',');
		getline(in,Load_role,',');
		getline(in,get_time(Load_timein,"%R"),',');
		getline(in,get_time(Load_timeout,"%R"),',');
		getline(in,Load_timeotc,',');
		time_t Conv_timein = mktime(Load_timein);
		time_t Conv_timeout = mktime(Load_timeout);
	}*/
	cout << "Test: ";
	//cout << Load_id << "\t" << Load_name << "\t" << Load_role << "\t" << Load_timein << " " << Load_timeout << " " << Load_timeotc << endl;
	
	if(DEBUGMODE){cout<<"Loaded!"<<endl;};
	//in.close();
}


int authenticate (string authPin) {
	
	// NEW CODE:
	/*
	for (i=0; i< numUsers; i++) { // FIXME
		if ( Employee.at(i).id == authPin ) { return this.GetRole(); } // if match found, instantly return role int
	}
	*/
	return 0; // return 0 for "authentication failed"
	
	
	
	
	
	
	// OLD CODE:
	// Validate
	//	check for exisiting pin
	/*bool found = false;
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
			cout << endl << "ERR: Pin is not valid number of digits." << endl;
			return 0;
		}
	}*/
	
}


/*
int validateRole (string valPin, int targRole) {
	
	// switch statment returns 1/true if valPin has access to requested role
	
}
int validateExists (string Pin) {
	
	// iterates over all employees to check if a pin already exists and returns 1/true if found
	// see code in authenticate();
	
}
*/


void UserCreate(string newPin) {
	// authenticate; can be built into this function or called in menu before this function
	Employee(string newPin);
}
void UserCreate(string newPin, string newName) {
	// authenticate; can be built into this function or called in menu before this function
	Employee(string newPin, string newName);
}
void UserCreate(string newPin, string newName, int newRole) {
	// for newRole, you should be able to pass the ROLE_RETURN.{ROLE}
	// authenticate; can be built into this function or called in menu before this function
	Employee(string newPin, string newName, int newRole);
}

//FIXME
void UserDelete(string delPin) {
	// authenticate; can be built into this function or called in menu before this function
	~Employee();
	
}

//FIXME
void UserEdit(string editPin) {
	// authenticate; can be built into this function or called in menu before this function
	UserCreate(editPin);
	UserDelete(editPin);
}



void TestMenu () {
	
	cout << endl;
	cout << "TestMenu() started.\n" << endl;
	cout << "Locating database... ";
	cout << DATABASE << endl;
	cout << "Database accessed: " << DATABASE_SIZE << " lines\n" << endl;
	
	bool menuloop;
	do {
		menuloop = true;
		int choice;
		cout << "1. Create User" << "\t" << "2. Edit User" << "\t" << "3. Delete User" << "\n"
			"4. Clock In" << "\t" << "5. Clouck Out" << "\t" << "6. Clock Inquiry" << "\n" << endl; 
		cin >> choice;
		switch (choice) {
			case 1: {
				string newPin;
				string newName;
				cout << "Create User" << endl;
				cout << "Pin: ";
				cin >> newPin;
				cout << "Name: ";
				cin >> newName;
				cout << "1. COOK\t2. SERVER\t3. MANAGER" << endl;
				cout << "Role: ";
				cin >> newName;
				menuloop = false;
			break;}
				
			case 2:{
				string newPin;
				cout << "Edit User" << endl;
				cout << "Pin: " << endl;
				cin >> newPin;
				menuloop = false;
				break;}
				
			case 3:{
				string newPin;
				cout << "Delete User" << endl;
				cout << "Pin: " << endl;
				cin >> newPin;
				menuloop = false;
				break;}
				
			default:
				menuloop = true;
		}
	} while ( menuloop == true );
	
	
};
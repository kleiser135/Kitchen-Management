

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


const string FILE_AUTHDB = "authdb.csv";
vector<string> localDB = {};
int localDBn = 0;


void store ( string file ) {
	ofstream out;
	out.open(file);
	
	localDBn = localDB.size();
	out << localDBn << endl; // store size on first line
	for ( int i = 0; i < localDBn; i++ ) {
		out << localDB.at(i) << endl;
	}
	
	out.close();
}


void load (string file ) {
	ifstream in;	
	in.open(file);
	// error case (if file does not open or exist):
	{ if(!in) {
		cout << endl << "ERR: Problem accessing input file. File may be moved or missing." << endl;
		in.close();
		int option = 0;
		cout << "Enter 0 to cancel the operation, and locate or repair the file.\n" <<
			"Enter 1 to create a replacement.\n" << endl;
		cin >> option;
		if ( option == 1 ) {
			store(file);
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


void sort () {}


bool locate (string a) {
	localDBn = localDB.size();
	for ( int i = 0; i < localDBn; i++) {
		if ( a == localDB.at(i) ) {
			return 1;
		}
	}
	return 0;
}


void authenticate () {
	
	cout << endl;
	cout << "PIN: ";
	cout << endl;
	
	// check against vector DB
	// return 1 for server/cook
	// return 2 for management
	// return 0 
	
}


void menu_pin_create(string input) {
	
	localDBn = localDB.size();
		
	// Validate
	//	check for exisiting pin
	for ( int i = 0; i < localDBn; i++) {
		if ( input == localDB.at(i) ) {
			cout << "ERR: Pin " << input << " already exists. Select a different pin." << endl;
			return;
		}
	}
	
	// Store
	//	save pin to the database (runtime and storage)
	localDB.push_back(input);
	localDBn = localDB.size();
	store(FILE_AUTHDB);
	
}


void menu_pin_delete(string input) {
	
	localDBn = localDB.size();
	
	// Validate & Remove
	//	check for exisiting pin
	for ( int i = 0; i < localDBn; i++ ) {
		if ( input == localDB.at(i) ) {
			localDB.erase(localDB.begin()+i+1);
		}
	}
	
	// Store
	//	save pin to the database (runtime and storage)
	localDBn = localDB.size();
	store(FILE_AUTHDB);
	
}


void menu_pin_update(string input) {
	
	localDBn = localDB.size();
	
	// Replace
	//	replace the existing pin with the new pin
	menu_pin_delete(input);
	input = "";
	cin >> input;
	menu_pin_create(input);
	localDB.push_back(input);
	
	// Store
	//	save pin to the database (runtime and storage)
	localDB.push_back(input);
	localDBn = localDB.size();
	store(FILE_AUTHDB);
	
}


void menu_pin () {
	
	/* Menu */
	cout << "1. New Pin" << endl;
	cout << "2. Update Pin" << endl;
	cout << "3. Delete Pin" << endl;
	cout << endl;
	cout << ": ";
	int option;
	cin >> option;
	cout << endl;
	
	switch (option) {
		
		case 1: {// 1. New Pin
			cout << endl;
			cout << "CREATE PIN" << endl;
			// Input
			//	prompt user to input new pin
			string input;
			cout << "Enter new pin: " << endl;
			cin >> input;
			menu_pin_create(input);
		break;}
		
		case 2: {// 2. Update Pin
			cout << endl;
			cout << "UPDATE PIN" << endl;
			// Input
			//	prompt user to input pin to change
			string input;
			cout << "Enter pin to update: " << endl;
			cin >> input;
			menu_pin_update(input);
		break;}
		
		case 3: {// 3. Delete Pin
			cout << endl;
			cout << "DELETE PIN" << endl;
			// Input
			//	prompt user to input new pin
			string input;
			cout << "Enter pin to delete: " << endl;
			cin >> input;
			menu_pin_delete(input);
		break;}
		
		default:
			break;
	}
	
}
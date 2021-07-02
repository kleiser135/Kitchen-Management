

#include "auth.cpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;


int main () {
	
	load(FILE_AUTHDB);
	menu_pin();
	
	return 0;
	
}
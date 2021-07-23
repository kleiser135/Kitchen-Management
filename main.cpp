

#include "usermgmt.cpp"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;


int main () {
	
	load(DATABASE);
	getTimeFiles();
	
	if (DEBUGMODE) TestMenu();
	
	return 0;
	
}
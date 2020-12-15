// Workshop 3:
// Version: 0.9
// Date: 10/02/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////

#include "Transcript.h"
using namespace sdds;

	int main() {
		Transcript T;
		T.init("Fred Soley", 5);
		T.add("EAC150", 65);
		T.add("DBS211", 85);
		T.add("DCF255", 75);
		T.add("OOP244", 95);
		// Premature call to display will result an error
		T.display();
		T.add("WEB222", 100);
		T.display();
		T.deallocate();
		return 0;
	}

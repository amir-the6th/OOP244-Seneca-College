/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-04            ///
********************************************/


#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#pragma once

#define DATAFILE "accounts_subtest.csv"
namespace sdds {
	struct Account {
		int m_accountNo;
		double m_balance;
	};

	//sorts the dynamic array of students based on the balance of the accounts.
	void sort();

	// allocates the dyanmic array of accounts and loads all the file
	// recoreds into the array
	bool load(const char filename[]);

	// Declare the prototype for the display function that
	// displays an account record on the screen:
	void display(const Account* accounts);

	// Declare the prototype for the display function that 
	// first sorts the accounts then displays all the accounts on the screen
	void display();

	// Declare the prototype for the deallocateMemory function that
	// first will deallocate all the account numbers in the account elements
	// then it will deallocate the accounts array 
	void deallocateMemory();

}
#endif // SDDS_ACCOUNT_H_
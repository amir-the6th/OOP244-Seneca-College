/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-10-04            ///
********************************************/

// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "Account.h"
#include "File.h"

using namespace std;
namespace sdds {
    int noOfAccounts;
    Account* accounts;

    void sort() {
        int i, j;
        Account temp;
        for (i = noOfAccounts - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (accounts[j].m_balance > accounts[j + 1].m_balance) {
                    temp = accounts[j];
                    accounts[j] = accounts[j + 1];
                    accounts[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char filename[]) {
        bool ok = false;
        int i = 0;

        if (openFile(DATAFILE)) {
            // set the noOfAccounts to the number of records in the file.
            noOfAccounts = noOfRecords();

            // dyanamically allocated an array of accounts into the global
            // Account pointer; "accounts" to the size of the noOfAccounts.
            accounts = new Account[noOfAccounts];

            // in a loop load the account records from the file into 
            // the dynamic array.
            for (i = 0; i < noOfAccounts; i++) {
                read(accounts[i].m_accountNo);
                read(accounts[i].m_balance);
            }

            // if the number of the records does not match the number of reads
            // print an error message
            if (i != noOfAccounts) {
                cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }


    void display(const Account* accounts) {
        int i = 0;
        int row = 1;
        cout << "Account#: Balance" << endl;
        for (i = 0; i < noOfAccounts; i++) {
            cout << row << ": ";
            cout << accounts[i].m_accountNo << ":  " << accounts[i].m_balance;
            cout << endl;   
            row++;
        }
    }

    void display() {
        sort();
        display(accounts);    
    }

    void deallocateMemory() {
        delete[] accounts;
        accounts = nullptr;
    }
}
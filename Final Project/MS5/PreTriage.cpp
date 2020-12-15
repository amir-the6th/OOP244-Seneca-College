/********************************************
///    Name:        Amirhossein Sabagh    ///
///    Student#:    152956199             ///
///    Email:       asabagh@myseneca.ca   ///
///    Date:        2020-12-05            ///
|*******************************************|
|**********  Final Project - MS5  **********|
|*******************************************|
|   I have done all the coding by myself    |
|     and only copied the code that my      |
|     professor provided to complete my     |
|        workshops and assignments.         |
********************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
	//******************* PreTriage Constructor *******************
	PreTriage::PreTriage(const char* dataFilename) : m_averCovidWait(15), m_averTriageWait(5),
		m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
		m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2) {
		m_dataFilename = new char[strlen(dataFilename) + 1];
		strcpy(m_dataFilename, dataFilename);
		load();
	}
	//******************* PreTriage Destructor *******************
	PreTriage::~PreTriage() {
		int rowNo;
		ofstream file(m_dataFilename);
		cout << "Saving Average Wait Times," << endl;
		cout << "   COVID Test: " << m_averCovidWait << endl;
		cout << "   Triage: " << m_averTriageWait << endl;
		cout << "Saving m_lineup..." << endl;
		for (rowNo = 0; rowNo < m_lineupSize; rowNo++) {
			m_lineup[rowNo]->fileIO(true);
			cout << rowNo + 1 << "- " << *m_lineup[rowNo] << endl;
			if (rowNo == 0) {
				file << m_averCovidWait << ',' << m_averTriageWait << endl;
			}
			file << *m_lineup[rowNo] << endl;
			delete m_lineup[rowNo];
		}
		delete[] m_dataFilename;
		cout << "done!" << endl;
	}
	//******************* Display menu and get the selection *******************
	void PreTriage::run(void) {
		int selection;
		while (m_appMenu >> selection) {
			switch (selection) {
			case 1:
				reg();
				break;
			case 2:
				admit();
				break;
			default:
				break;
			}
		}
	}
	//******************* Registers a new patient *******************
	void PreTriage::reg() {
		int selection;
		if (m_lineupSize == maxNoOfPatients) {
			cout << "Line up full!" << endl;
		}
		else {
			m_pMenu >> selection;
			switch (selection) {
			case 1:
				m_lineup[m_lineupSize] = new CovidPatient();
				m_lineup[m_lineupSize]->setArrivalTime();
				m_lineup[m_lineupSize]->fileIO(false);
				cout << "Please enter patient information: " << endl;
				cin >> *m_lineup[m_lineupSize];
				cout << endl << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
				cout << endl << "******************************************" << endl << endl;
				m_lineupSize++;
				break;
			case 2:
				m_lineup[m_lineupSize] = new TriagePatient();
				m_lineup[m_lineupSize]->setArrivalTime();
				m_lineup[m_lineupSize]->fileIO(false);
				cout << "Please enter patient information: " << endl;;
				cin >> *m_lineup[m_lineupSize];
				cout << endl << "******************************************" << endl;
				cout << *m_lineup[m_lineupSize];
				cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
				cout << "******************************************" << endl << endl;;
				m_lineupSize++;
				break;
			default:
				break;
			}
		}
	}
	//***** Calls the next patient in line to be admitted to the COVID test centre or Triage centre *****
	void PreTriage::admit() {
		char type = '\0';
		int selection, firstIndex = 0;
		m_pMenu >> selection;
		switch (selection) {
		case 1:
			type = 'C';
			if (indexOfFirstInLine(type) != -1) {
				firstIndex = indexOfFirstInLine(type);
				cout << endl << "******************************************" << endl;
				//set the patient not to do File IO V0.91
				m_lineup[firstIndex]->fileIO(false);
				cout << "Calling for ";
				cout << *m_lineup[indexOfFirstInLine(type)];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[firstIndex]);
				removePatientFromLineup(firstIndex);
			}
			break;
		case 2:
			type = 'T';
			if (indexOfFirstInLine(type) != -1) {
				firstIndex = indexOfFirstInLine(type);
				cout << endl << "******************************************" << endl;
				//set the patient not to do File IO V0.91
				m_lineup[firstIndex]->fileIO(false);
				cout << "Calling for ";
				cout << *m_lineup[indexOfFirstInLine(type)];
				cout << "******************************************" << endl << endl;
				setAverageWaitTime(*m_lineup[firstIndex]);
				removePatientFromLineup(firstIndex);
			}
			break;
		default:
			break;
		}
	}
	//*** Receives a constant Patient Reference and returns the total estimated wait time for that type of Patient (COVID or Triage) ****
	const Time sdds::PreTriage::getWaitTime(const Patient& p) const {
		int i, count = 0;
		for (i = 0; i < m_lineupSize; i++) {
			if (m_lineup[i]->type() == p.type()) {
				count++;
			}
		}
		return Time(p) *= count;
	}
	//*** Receives the reference of the admitting patient and adjusts the average wait time of that type of patient base on the admittance time of the patient ***
	void PreTriage::setAverageWaitTime(const Patient& p) {
		Time CT;
		CT.reset();
		if (p.type() == 'C') {
			m_averCovidWait = ((CT - Time(p)) + (m_averCovidWait * (p.number() - 1))) / p.number();
		}
		else if (p.type() == 'T') {
			m_averTriageWait = ((CT - Time(p)) + (m_averTriageWait * (p.number() - 1))) / p.number();
		}
	}
	//***** removes a Patient form the line up at a specific index and also removes it from memory *****
	void PreTriage::removePatientFromLineup(int index) { 
		removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
	}
	//*** Loads the average wait times and the patient records from the data file and stores them in the m_lineup array ***
	void PreTriage::load() {
		int i;
		ifstream ptnt(m_dataFilename);
		cout << "Loading data..." << endl;
		if (!ptnt) {
			cout << "No data or bad data file!\n" << endl;
		}
		else {
			ptnt >> m_averCovidWait;
			ptnt.ignore(200, ',');
			ptnt >> m_averTriageWait;
			ptnt.ignore(200, '\n');
			for (i = 0; ptnt && m_lineupSize != maxNoOfPatients; i++) {
				Patient* patient = nullptr;
				char pType = ptnt.get();
				ptnt.ignore(200, ',');
				if (pType == 'C') {
					patient = new CovidPatient();
					patient->fileIO(true);
					ptnt >> *patient;
					ptnt.ignore(200, '\n');
					patient->fileIO(false);
					m_lineup[i] = patient;
					m_lineupSize++;
				}
				else if (pType == 'T') {
					patient = new TriagePatient();
					patient->fileIO(true);
					ptnt >> *patient;
					ptnt.ignore(200, '\n');
					patient->fileIO(false);
					m_lineup[i] = patient;
					m_lineupSize++;
				}
			}
			if (ptnt.peek() != -1) {
				cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
			}
			cout << m_lineupSize << " Records imported...\n" << endl;
		}
	}
	//***** Finds the index of the first patient in line which matches the type argumentr *****
	int PreTriage::indexOfFirstInLine(char type) const {
		int i, match = -1;

		ifstream file(m_dataFilename);
		for (i = 0; i < m_lineupSize && match == -1; i++) {
			if (m_lineup[i]->type() == type) {
				match = i;
			}
		}
		return match;
	}
}
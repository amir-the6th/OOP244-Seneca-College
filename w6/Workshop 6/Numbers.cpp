#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <fstream>
#include "Numbers.h"
using namespace std;
namespace sdds {

  
   Numbers::Numbers() { 
      setEmpty();
      m_isOriginal = false;
   }
   Numbers::Numbers(const char* filename) { 
      setEmpty();
      m_isOriginal = true;
      setFilename(filename);
      m_numCount = numberCount();
      if (m_numCount == 0 || !load()) {
         delete[] m_numbers;
         delete[] m_filename;
         setEmpty();
         m_isOriginal = false; 
      }
      else {
         sort();
      }
   }
   Numbers::~Numbers() {
      save();
      delete[] m_numbers;
      delete[] m_filename;
   }

   Numbers::Numbers(const Numbers& src){
       setEmpty();
       m_isOriginal = false;
       *this = src;
   }
   Numbers& Numbers::operator=(const Numbers& src){
           delete[] m_numbers;
           m_numCount = src.m_numCount;
           m_numbers = new double[m_numCount];
           //memcpy(&m_numbers, &src.m_numbers, m_numCount);
           for (int i = 0; i < m_numCount; i++) {
               m_numbers[i] = src.m_numbers[i];
           }
       return *this;
   }
   int Numbers::numberCount() const{
       int numOfLines = 0;
       std::string line;
       std::ifstream file(m_filename);
       if (file.is_open()) {
           while (std::getline(file, line))
               numOfLines++;
           file.close();
       }
       return numOfLines;
   }
   bool Numbers::load(){
       bool loaded = false;
       int count = 0;

       if (m_numCount > 0) {
           m_numbers = new double[m_numCount];
           std::ifstream file(m_filename);
           //file.ignore(1000, '\n');
           while (count < m_numCount && file) {
               //getline(file, m_numbers[count]);
               file >> m_numbers[count];
               //file.ignore();
               if (file) {
                   count++;
               }
           }
           if (count == m_numCount) loaded = true;  
       }
       return loaded;
   }
   void Numbers::save() const{
       if (m_isOriginal && !isEmpty()) {
           std::ofstream file(m_filename);
           for (int i = 0; i < m_numCount; i++) {
               file << m_numbers[i] << endl;
           }
       }
   }
   Numbers& Numbers::operator+=(const double& number){
       if (!isEmpty()) {
           int i;
           double* temp = new double[m_numCount + 1];
           for (i = 0; i < m_numCount; i++) {
               temp[i] = m_numbers[i];
           }
           m_numCount++;
           temp[i] = number;
           delete[] m_numbers;
           m_numbers = temp;
           sort();
       }
       return *this;
   }
   ostream& Numbers::display(ostream& ostr)const{
       if (isEmpty()) {
           ostr << "Empty list";
       }
       else {
           ostr << "=========================" << endl;
           /*char* original = (m_isOriginal) ? m_filename : "*** COPY ***";
           ostr << original << endl;*/
           if (m_isOriginal){
               ostr << m_filename << endl;
           }
           else {
               ostr << "*** COPY ***" << endl;
           }

           for (int i = 0; i < m_numCount; i++) {
               ostr << m_numbers[i];
               if (i != m_numCount - 1) {
                   ostr << ", ";
               }
               else {
                   ostr << endl;
               }
           }
           ostr << "-------------------------" << endl;
           ostr << "Total of " << m_numCount << " number(s)" << endl;
           ostr << "Largest number:  " << max() << endl;
           ostr << "Smallest number: " << min() << endl;
           ostr << "Average :        " << average() << endl;
           ostr << "=========================";
       }
       return ostr;
   }
   bool Numbers::isEmpty() const { 
      return m_numbers == nullptr;
   }
   void Numbers::setEmpty() { 
      m_numbers = nullptr;
      m_filename = nullptr;
      m_numCount = 0;
   }
   void Numbers::setFilename(const char* filename) { 
      delete[] m_filename;
      m_filename = new char[strlen(filename) + 1];
      strcpy(m_filename, filename);
   }
   void Numbers::sort() {
      int i, j;
      double temp;
      for (i = m_numCount - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (m_numbers[j] > m_numbers[j + 1]) {
               temp = m_numbers[j];
               m_numbers[j] = m_numbers[j + 1];
               m_numbers[j + 1] = temp;
            }
         }
      }
   }
   double Numbers::average() const {
      double aver = 0.0;
      if (!isEmpty()) {
         for (int i = 0; i < m_numCount; i++)
            aver += m_numbers[i];
         aver = aver / m_numCount;
      }
      return aver;
   }
   double Numbers::min() const {
      double minVal = 0.0;
      if (!isEmpty()) {
         minVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (minVal > m_numbers[i]) minVal = m_numbers[i];
      }
      return minVal;
   }
   double Numbers::max() const {
      double maxVal = 0.0;
      if (!isEmpty()) {
         maxVal = m_numbers[0];
         for (int i = 1; i < m_numCount; i++)
            if (maxVal < m_numbers[i]) maxVal = m_numbers[i];
      }
      return maxVal;
   }
   std::ostream& operator<<(ostream& os, const Numbers& N){
       return N.display(os);
   }
   std::istream& operator>>(istream& istr, Numbers& N){
       double val;
       istr >> val;
       N += val;

       return istr;
   }

}

// Workshop 4:
// Version: 0.9
// Date: 10/09/2020
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
using namespace std;
#include "Box.h"
using namespace sdds;
void showBoxes(const Box* boxArray, int num = 1);
int main() {
   cout << "Testing all the contstructors: "<<endl;
   Box C[5] = {Box(), Box(8), Box(7, "Sugar"), Box(8,20,7,"Gummy Bears"), Box(5, 7, 6) };
   Box BadBoxes[8] = { Box(4),Box(37),Box(4,10, 10),Box(10,4, 10), Box(10, 10,4),Box(37,10, 10),Box(10,37, 10), Box(10, 10,37) };
   Box X;
   Box Y(5, "Sugar");
   Box Z(6, 6, 6, "Sugar");
   Box B(5, 5, 5, "Beans");
   showBoxes(C, 5);
   cout << "Bad Boxes: " << endl;
   showBoxes(BadBoxes, 8);

   cout << "---------------------------------------------------------" << endl;
   cout << "Box X" << endl;
   X.display() << endl << endl;
   cout << "Box Y" << endl;
   Y.display() << endl << endl;
   cout << "Box Z" << endl;
   Z.display() << endl << endl;
   B.add(20);
   cout << "Box B" << endl;
   B.display() << endl;
   cout << "---------------------------------------------------------" << endl << endl;

   cout << "Added 1500 Cubic inches of rice to the empty box \"X\" and displaying it" << endl;
   X.setContent("Rice").add(1500).display() << endl << endl;
   cout << "Adding too much sugar to the box \"Y\" and displaying it" << endl;
   Y.add(500).display() << endl << endl;
   cout << "Pouring rice form box \"X\" to the empty sugar box \"Z\" and displaying both" << endl << "Z: ";
   Z.add(X).display() << endl << "X: ";
   X.display() << endl << endl;
   cout << "Pouring rice form box \"Z\" to the box of beans \"B\" and displaying both" << endl << "B: ";
   B.add(Z).display() << endl <<"Z: ";
   Z.display() << endl;

   return 0;
}
void showBoxes(const Box* boxArray, int num ) {
   cout << "  Content                      Dimensions    Qty/Capacity" << endl;
   cout << "------------------------------  --------  ------/-------------" << endl;
   for (int i = 0; i < num; i++) {
      boxArray[i].display() << endl;
   }
   cout << "--------------------------------------------------------------" << endl << endl;
}

/*
Expected output:

Testing all the contstructors:
  Content                      Dimensions    Qty/Capacity
------------------------------  --------  ------/-------------
Empty box.....................  12x12x12       0/1728 C.I.
Empty box.....................  08x08x08       0/512 C.I.
Sugar.........................  07x07x07       0/343 C.I.
Gummy Bears...................  08x20x07       0/1120 C.I.
Empty box.....................  05x07x06       0/210 C.I.
--------------------------------------------------------------

Bad Boxes:
  Content                      Dimensions    Qty/Capacity
------------------------------  --------  ------/-------------
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
Unusable box, discard the content, and recycle.
--------------------------------------------------------------

---------------------------------------------------------
Box X
Empty box.....................  12x12x12       0/1728 C.I.

Box Y
Sugar.........................  05x05x05       0/125 C.I.

Box Z
Sugar.........................  06x06x06       0/216 C.I.

Box B
Beans.........................  05x05x05      20/125 C.I.
---------------------------------------------------------

Added 1500 Cubic inches of rice to the empty box "X" and displaying it
Rice..........................  12x12x12    1500/1728 C.I.

Adding too much sugar to the box "Y" and displaying it
Unusable box, discard the content, and recycle.

Pouring rice form box "X" to the empty sugar box "Z" and displaying both
Z: Rice..........................  06x06x06     216/216 C.I.
X: Rice..........................  12x12x12    1284/1728 C.I.

Pouring rice form box "Z" to the box of beans "B" and displaying both
B: Unusable box, discard the content, and recycle.
Z: Rice..........................  06x06x06     111/216 C.I.
*/
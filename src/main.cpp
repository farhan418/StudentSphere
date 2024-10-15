#include <iostream>
#include <cstdlib>
#include "tests.hpp"
#include "Utility.hpp"
#include "DoublyLinkedList.hpp"
//#include "Student.hpp"

int main() {
	int choice = 0;
	
	do {
		choice = displayMainMenu();
//		clearScreen();
		switch (choice) {
			case 21 :
				doublyLinkedListPlayground();
				break;
			case 81 :
				processChoice(&testUtilityDateObj, "testUtilityDateObj");
			 	break;
			 	
			case 82 :
				processChoice(testClassStudent, "testClassStudent");
				break;
				
			case 83 :
				processChoice(testDoublyLinkedList, "testDoublyLinkedList");
				break;
				
			case 99 :
				break;
		}
		
		getchar();
		
	} while (choice != 99);
	
	std::cout << "\n\nExiting program, press any key to continue...\n";
    getchar();
	return 0;
}

/* File : Utility.cpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : This file contains the main function which
 * is the entry point of StudentSphere application.
 * It also contains code for displaying Main Menu.
 */

#include <iostream>
#include <cstdlib>
#include "tests.hpp"
#include "Utility.hpp"
#include "DoublyLinkedList.hpp"

int main() {
	int choice = 0;
	
	do {
		choice = displayMainMenu();
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

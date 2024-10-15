/* File : testDoublyLinkedList.cpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : This file contains some test function definitions
 * for testing Class DoublyLinkedList.
 */
 
#include <vector>
#include "DoublyLinkedList.hpp"
#include "tests.hpp"
#include "Utility.hpp"

Status testDoublyLinkedList() {
	std::vector<Student> studentList = {Student("Mohammed Farhan", "Haider"), Student("Maimuna", "Iqbal", 21)};
	DoublyLinkedList dll;
	for (auto& student : studentList) {
		dll.insert(student);	
	}
	dll.display();
	return Status::SUCCESS;
}

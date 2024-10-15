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

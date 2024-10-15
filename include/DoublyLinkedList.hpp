/* File : DoublyLinkedList.hpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : This file contains required declarations for the
 * implementation of DoublyLinkedList.
 */

#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP

#include <iostream>
#include <memory>
#include "Utility.hpp"
#include "Student.hpp"

class DoublyLinkedListNode {
public:
	DoublyLinkedListNode(const Student& obj);
	DoublyLinkedListNode(Student&& obj);
	~DoublyLinkedListNode();
	void displayNode() const;
// member variables
	std::shared_ptr<Student> dataObjPtr;
	std::weak_ptr<DoublyLinkedListNode> prevNodePtr;
	std::shared_ptr<DoublyLinkedListNode> nextNodePtr;
};

//class DoublyLinkedList : public IDataStructure {
class DoublyLinkedList {
public:
	const unsigned long NOT_FOUND_CODE = 4294967295L;
	
	DoublyLinkedList();
	DoublyLinkedList(const Student& obj);
	Status insert(const Student& obj);  // insert at end
	Status insert(const Student& obj, unsigned long index);  // insert at index, for beginning, index = 0
	Status insert(Student&& obj) noexcept;  // insert at end
	Status insert(Student&& obj, unsigned long index) noexcept;  // insert at index, for beginning, index = 0
	unsigned long search(const std::string& registrationId);
	Status deleteItem(unsigned long index);
	Status traverse(Status (*functionPtr)(Student& obj));
	Status display() const;
	Status sortByRegistrationId(bool reverse);
	~DoublyLinkedList();
private:
	unsigned long size;
	std::shared_ptr<DoublyLinkedListNode> head;
	std::shared_ptr<DoublyLinkedListNode> tail;
};

void doublyLinkedListPlayground();

#endif  // DOUBLYLINKEDLIST_HPP

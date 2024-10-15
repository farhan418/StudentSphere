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
	DoublyLinkedList();
	DoublyLinkedList(const Student& obj);
//	DoublyLinkedList(const std::vector<Student>& objList);
	Status insert(const Student& obj);  // insert at end
	Status insert(const Student& obj, unsigned long index);  // insert at index, for beginning, index = 0
	Status insert(Student&& obj) noexcept;  // insert at end
	Status insert(Student&& obj, unsigned long index) noexcept;  // insert at index, for beginning, index = 0
//	std::shared_ptr<DoublyLinkedListNode> createNode(Student& obj);
	unsigned long search(const std::string& registrationId);
	Status deleteItem(unsigned long index);
	Status traverse(Status (*functionPtr)(Student& obj));
	Status display() const;
	~DoublyLinkedList();
private:
	unsigned long size;
	std::shared_ptr<DoublyLinkedListNode> head;
	std::shared_ptr<DoublyLinkedListNode> tail;
};

void doublyLinkedListPlayground();

#endif  // DOUBLYLINKEDLIST_HPP

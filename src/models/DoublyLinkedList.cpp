#include <iostream>
#include <memory>
#include "Utility.hpp"
#include "DoublyLinkedList.hpp"

DoublyLinkedListNode::DoublyLinkedListNode(const Student& obj) {
	this->dataObjPtr = std::make_shared<Student>(obj);
	this->prevNodePtr.reset();
	this->nextNodePtr = nullptr;
}

DoublyLinkedListNode::DoublyLinkedListNode(Student&& obj) {
	this->dataObjPtr = std::make_shared<Student>(std::move(obj));
	this->prevNodePtr.reset();
	this->nextNodePtr = nullptr;
}

DoublyLinkedListNode::~DoublyLinkedListNode() {
	std::cout << "\nDeleting node " << *dataObjPtr;
}

void DoublyLinkedListNode::displayNode() const {
	std::cout << "\ndataObjPtr = " << this->dataObjPtr.get() << ", value :\n" << *(this->dataObjPtr);
	std::cout << "\nnextNodePtr = " << this->nextNodePtr.get();
}

DoublyLinkedList::DoublyLinkedList() : size(0), head(nullptr), tail(nullptr) {}

DoublyLinkedList::DoublyLinkedList(const Student& obj) : size(1) {
	insert(obj);
}

DoublyLinkedList::~DoublyLinkedList() {
	head.reset();
	tail.reset();
}

//DoublyLinkedList::DoublyLinkedList(const std::vector<Student>& objList) {
//	std::shared_ptr<DoublyLinkedListNode> temp = nullptr;
//	for(const Student& obj : objList) {
////			std::shared_ptr<DoublyLinkedListNode> ptr = std::make_shared<DoublyLinkedListNode>(obj);
//		if (nullptr != head) {
//			temp->nextNodePtr = createNode(obj);
//			// check for error in creation of new node
//			temp = temp->nextNodePtr;
//		}
//		else {
//			head = createNode(obj);
//			tail = head;
//			temp = head;
//		}
//	}
//	this->size = objList.length();
//}


/* function to insert a new dynamically created node
 * at the index position of the linked list
 */
Status DoublyLinkedList::insert(const Student& obj, unsigned long index) {	
	if (index > size) {
		std::cout << "\nInvalid index, valid index is [0, " << size << "] = \n";
		return Status::FAILURE;
	}
	
	auto temp = std::make_shared<DoublyLinkedListNode>(obj);  // create node
	if (nullptr == temp)
		return Status::FAILURE;
		
	if(nullptr == head) {  // Empty list
		if (0 != index)
			std::cout << "\nList is empty, so inserting at index = 0";
		head = temp;
		tail = temp;
	}
	else if(0 == index) {  // non-empty list and index = 0
		head->prevNodePtr = temp;
		temp->nextNodePtr = head;
		head = temp;
	}
	else {  // Non-Empty list
		auto cursor = head;
		unsigned long position = 1;
		while(cursor->nextNodePtr && position < index) {
			cursor = cursor->nextNodePtr;
			position += 1;
		}
		auto nextNode = cursor->nextNodePtr;
		cursor->nextNodePtr = temp;
		temp->nextNodePtr = nextNode;
		temp->prevNodePtr = cursor;
		if (nullptr == nextNode)
			tail = temp;
		else
			nextNode->prevNodePtr = temp;
	}
	size += 1;
	return Status::SUCCESS;
}


/* function to insert a new dynamically created node
 * at the end of the linked list
 */
Status DoublyLinkedList::insert(const Student& obj) {
	insert(obj, size);
//	auto temp = std::make_shared<Student>(obj);
//	if (temp == nullptr)
//		return Status::FAILURE;
//			
//	if(nullptr == head) {  // Empty list
//		head  = temp;
//		tail = temp;
//	}
//	else {  // Non-Empty list
//		tail->nextNodePtr = temp;
//		temp->prevNodePtr = tail;
//		tail = temp;
//	}
//	size += 1;
	return Status::SUCCESS;
}

Status DoublyLinkedList::insert(Student&& obj) noexcept {  // insert at end
	std::cout << "\nMove semantic insert at end\n";
	insert(obj, size);
	return Status::SUCCESS;
}

Status DoublyLinkedList::insert(Student&& obj, unsigned long index) noexcept {  // insert at index, for beginning, index = 0
// insert at end
	std::cout << "\nMove semantic insert at index\n";
	insert(obj, index);
	return Status::SUCCESS;
}

//std::shared_ptr<DoublyLinkedListNode> DoublyLinkedList::createNode(const Student& obj) {
//	// create a Node in heap and return shared_ptr
//	return std::make_shared<DoublyLinkedListNode>(obj);
//}


unsigned long DoublyLinkedList::search(const std::string& registrationId) {
	auto temp = head;
	unsigned long index = 0;
	while (nullptr != temp) {
		if (temp->dataObjPtr->getRegistrationId() == registrationId) {
			std::cout << "\nFound the object in the DoublyLinkedList at index = " << index << "\n";
			return index;
		}
		index += 1;
		temp = temp->nextNodePtr;	
	}
	return 4294967295L;  // returning huge number to indicate not found
}


Status DoublyLinkedList::deleteItem(unsigned long index) {
	if (nullptr == head) {  // case: empty list
		std::cout << "Empty linked list\n";
		return Status::FAILURE;
	}
	else if (index >= size) {
		std::cout << "Index out of bounds\n";
		return Status::FAILURE;
	}
//	else if (size == 1) {
//		head.reset();
//		head = nullptr;
//		tail = nullptr;
//		size = 0;
//		return Status::SUCCESS;
//	}
	else {
		auto cursor = head;
		unsigned long position = 0;
		while (position < size && cursor){
			if (position == index) {  // deletion
				auto prevNode = (cursor->prevNodePtr).lock();
				auto nextNode = cursor->nextNodePtr;
				if (prevNode)
					prevNode->nextNodePtr = nextNode;
				if(nextNode)
					nextNode->prevNodePtr = prevNode;
				if (tail == cursor)
					tail = prevNode;
				if (head == cursor)
					head = nextNode;
				size -= 1;
				cursor.reset();
				return Status::SUCCESS;
			}
			cursor = cursor->nextNodePtr;
			position += 1;
		}
	}
	return Status::FAILURE;
}

//Status DoublyLinkedList::deleteItem(unsigned long index) {
//	if (nullptr == head) {
//		return Status::FAILURE;	
//	}
//	else {
//		auto temp = head;
//		while (nullptr != temp) {
//			if ((*temp).getRollNumber() == obj.getRollNumber()) {
//				auto prevNode = temp->prevNodePtr;
//				auto nextNode = temp->nextNodePtr;
//				
//				if (nullptr != prevNode) {
//					prevNode->nextNodePtr = nextNode;
//				}
//				
//				if (nullptr != nextNode) {
//					nextNode->prevNodePtr = prevNode;
//				}
//				temp.reset();
//			}	
//		}
//		return Status::SUCCESS;
//	}
//}

Status DoublyLinkedList::traverse(Status (*functionPtr)(Student&)) {
	auto temp = head;
	while (nullptr != temp) {
		functionPtr(*(temp->dataObjPtr));
		temp = temp->nextNodePtr;	
	}
	return Status::SUCCESS;
}


Status DoublyLinkedList::display() const {
	auto temp = head;
	while (nullptr != temp) {
		std::cout << *(temp->dataObjPtr);
		temp = temp->nextNodePtr;	
	}
	return Status::SUCCESS;
}

void doublyLinkedListPlayground() {
	int choice = 0;
	std::string inputString = "";
	unsigned long index = 0;
	DoublyLinkedList dll;
	std::vector<std::string> menu = {
			"\nDOUBLY LINKED LIST MENU\n",
			"11. Display",
			"\n21. Insert",
			"22. Insert at index",
			"23. Search",
			"24. Traverse",
			"25. Delete",
			"\n99. Exit",
			"\nEnter your choice : "
	};
		
	while(99 != choice) {
		clearScreen();
		
		for(auto& menuItem : menu) {
			std::cout << menuItem << "\n";
		}
		
		std::cin >> choice;
		switch(choice) {
			case 11 :  // Display
				dll.display();
				break;
			case 21 :  // Insert
				dll.insert(std::move(generateStudentObj()));
				break;
			case 22 :  // Insert at index
				std::cout << "\nEnter index : ";
				std::cin >> index;
				dll.insert(std::move(generateStudentObj()), index);
				break;
			case 23 :  // Search
				std::cout << "\nEnter registrationId to search : ";
				std::cin >> inputString;
				dll.search(inputString);
				break;	
			case 24 :  // Traverse
				dll.traverse(processStudentObj);
				break;
			case 25 :  // Delete
				std::cout << "\nEnter index : ";
				std::cin >> index;
				dll.deleteItem(index);
				break;
			case 99 : break;
			default :
				std::cout << "\nEnter valid option...";
				break;
		}
		std::cout << "\nPress any key to continue...";
		getchar();
		getchar();
	}	
}

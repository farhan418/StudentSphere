#include <iostream>
#include <cstdlib>
#include <vector>
#include "Utility.hpp"

// Utility structure - Date
//// constructors and destructors
Date::Date() {}

Date::Date(const unsigned short day,
           const unsigned short month,
           const unsigned short year) {

    this->setDay(day);
    this->setMonth(month);
    this->setYear(year);
}

Date::Date(const struct Date& anotherDateObj)
    : day(anotherDateObj.day),
	  month(anotherDateObj.month),
	  year(anotherDateObj.year) 
{ }

Date::Date(struct Date&& anotherDateObj) noexcept
    : day(anotherDateObj.day),
	  month(anotherDateObj.month),
	  year(anotherDateObj.year) 
{ }

Date::~Date() {}

//// Assignment operator overloadings
struct Date& Date::operator=(const struct Date& otherDate) {
    this->day = otherDate.day;
    this->month = otherDate.month;
    this->year = otherDate.year;
    return *this;
}

struct Date& Date::operator=(struct Date&& otherDate) noexcept {
    if (this != &otherDate) {
        this->day = std::move(otherDate.day);
        this->month = std::move(otherDate.month);
        this->year = std::move(otherDate.year);
    }
    return *this;
}

//// operator<< overloadings using lvalue and rvalue for struct Date
std::ostream& operator<<(std::ostream& out, const struct Date& date) {
    out << date.day << "/" << date.month << "/" << date.year;
//    out << "\nlvalue operator<< called\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, struct Date&& date) noexcept {
    out << date.day << "/" << date.month << "/" << date.year;
//    out << "\nrvalue (move) operator<< called\n";
    return out;
}

void clearScreen() {
	#ifdef _WIN32
		system("cls");
	#else
		int r = system("clear");
	#endif
	if (r == 1)
		std::cerr << "cleared screen";
}

int displayMainMenu() {
	clearScreen();
	std::vector<std::string> mainMenu = {
		"\nMAIN MENU\n",
		"21. DoublyLinkedList Playground",
		"\n81. TestUtilityDate",
		"82. TestClassStudent",
		"83. TestDoublyLinkedList",
		"\n99. Exit",
		"\nEnter your choice : "
	};
	
	for(auto& menuItem : mainMenu) {
		std::cout << menuItem << "\n";
	}
	int choice;
	std::cin >> choice;
	return choice;
}

void processChoice(Status (*funcPtr)(), const std::string& functionName) {
	clearScreen();
	std::cout << "Choice : " + functionName + '\n';
	if (Status::SUCCESS == funcPtr())
		std::cout << "\n" + functionName + "() : SUCCESS\n";
	else
		std::cout << "\n" + functionName + "() : Failure\n";
	std::cout << "\nPress any key to continue...";
	getchar();
}

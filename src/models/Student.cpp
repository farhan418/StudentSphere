/* File : Student.cpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : This file contains definitions of member functions of class
 * Student along with definitions of some other related functions
 */

#include <iostream>
#include "Student.hpp"
#include "Utility.hpp"

//// Definitions of constructors and destructors
Student::Student(const std::string& firstName, const std::string& lastName) {
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->age = 0;  // default
    this->setDateOfBirth(Date(1, 1, 1000)); // default
    this->address = "NA"; // default
    this->setRegistrationId();
    this->feePaymentStatus = PaymentStatus::UNPAID; // default
}

Student::Student(const std::string& firstName, const std::string& lastName, const unsigned short age) {
    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->age = age;
    this->setDateOfBirth(Date(1, 1, 1000)); // default
    this->address = "NA"; // default
	this->setRegistrationId();
    this->feePaymentStatus = PaymentStatus::UNPAID; // default
}

Student::Student(const std::string& firstName,
            const std::string& lastName,
            const unsigned short age,
            const struct Date& dateOfBirth) {

    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->age = age;
    this->setDateOfBirth(dateOfBirth);
    this->address = "NA"; // default
    this->setRegistrationId();
    this->feePaymentStatus = PaymentStatus::UNPAID; // default
}

Student::Student(const std::string& firstName,
            const std::string& lastName,
            const unsigned short age,
            const struct Date& dateOfBirth,
            const std::string& address,
            PaymentStatus feePaymentStatus) {

    this->setFirstName(firstName);
    this->setLastName(lastName);
    this->age = age;
    this->setDateOfBirth(dateOfBirth);
    this->address = address;
    this->setRegistrationId();
    this->feePaymentStatus = feePaymentStatus;
}

// move constructor
Student::Student(Student&& otherStudent) noexcept {
    this->firstName = std::move(otherStudent.firstName);
    this->lastName = std::move(otherStudent.lastName);
    this->age = std::move(otherStudent.age);
    this->dateOfBirth = std::move(otherStudent.dateOfBirth);
    this->address = std::move(otherStudent.address);
    this->registrationId = std::move(otherStudent.registrationId);
    this->feePaymentStatus = std::move(otherStudent.feePaymentStatus);
}

// destructor
Student::~Student() {}


//// operator overloadings
Student& Student::operator=(const Student& otherStudent) {
	if (this != &otherStudent) {
	    this->firstName = otherStudent.firstName;
	    this->lastName = otherStudent.lastName;
	    this->age = otherStudent.age;
	    this->dateOfBirth = otherStudent.dateOfBirth;
	    this->address = otherStudent.address;
	    this->registrationId = otherStudent.registrationId;
	    this->feePaymentStatus = otherStudent.feePaymentStatus;
	}
    return *this;
}

Student& Student::operator=(Student&& otherStudent) noexcept {
	if (this != &otherStudent) {		
	    this->firstName = std::move(otherStudent.firstName);
	    this->lastName = std::move(otherStudent.lastName);
	    this->age = std::move(otherStudent.age);
	    this->dateOfBirth = std::move(otherStudent.dateOfBirth);
	    this->address = std::move(otherStudent.address);
	    this->registrationId = std::move(otherStudent.registrationId);
	    this->feePaymentStatus = std::move(otherStudent.feePaymentStatus);
	}
	return *this;
}

bool Student::operator==(const Student& otherStudent) {
    return this->registrationId == otherStudent.getRegistrationId();
}
bool Student::operator==(Student&& otherStudent) noexcept {
	return this->registrationId == otherStudent.getRegistrationId();
}

void Student::setRegistrationId() noexcept {
		static std::random_device rd;  // Seed
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> distr(1000, 99999);
		registrationId = "S" + std::to_string(distr(gen));
}

// Utilities for class Student
//// operator<< overloading for Student class
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << "Studentlvalue(firstName : \"" << student.firstName << "\", ";
    out << "lastName : \"" << student.lastName << "\", ";
    out << "age : " << std::to_string(student.age) << ", ";
    out << "dateOfBirth : " << student.dateOfBirth << "\", ";
    out << "address : \"" << student.address << "\", ";
    out << "registrationId : \"" << student.registrationId << "\", ";
    out << "feePaymentStatus : " << (student.feePaymentStatus == PaymentStatus::PAID ? "PAID" : "UNPAID") << ")\n";
    return out;
}

std::ostream& operator<<(std::ostream& out, Student&& student) noexcept {
    out << "Student(firstName : \"" << student.firstName << "\", ";
    out << "lastName : \"" << student.lastName << "\", ";
    out << "age : " << std::to_string(student.age) << ", ";
    out << "dateOfBirth : " << student.dateOfBirth << "\", ";
    out << "address : \"" << student.address << "\", ";
    out << "registrationId : \"" << student.registrationId << "\", ";
    out << "feePaymentStatus : " << (student.feePaymentStatus == PaymentStatus::PAID ? "PAID" : "UNPAID") << ")\n";
    return out;
}

/* function to generate and return a Student object
 * with random values set
 */
Student generateStudentObj() {
	std::vector<std::string> firstNameList = {
        "Ahmed", "Fatima", "Youssef", "Aisha", "Omar",
        "Layla", "Zayd", "Sara", "Hassan", "Nour"
    };
    std::vector<std::string> lastNameList = {
        "Ali", "Hussein", "Karim", "Saeed", "Nasser",
        "Jabari", "Khalil", "Omani", "Farah", "El-Masri"
    };
	
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(0, 9);
	
	return Student (
		firstNameList.at(distr(gen)),
		lastNameList.at(distr(gen)),
		5 + distr(gen)
	);
}

/* demo function which process a student object
 * used along with traverse function of DoublyLinkedList
 */
Status processStudentObj(Student& obj) {
	std::cout << "\nStudent(" << obj.getFirstName() << " " << obj.getLastName();
	std::cout << ", age*10 = " << 10 * obj.getAge() << " ";
	std::cout << ", registrationId = " << obj.getRegistrationId() << ")";
	return Status::SUCCESS;
}

bool Student::operator<(const Student& otherStudent) {
	return this->registrationId < otherStudent.getRegistrationId();
}
bool Student::operator<(Student&& otherStudent) noexcept {
	return this->registrationId < otherStudent.getRegistrationId();
}

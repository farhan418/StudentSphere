/* File : Student.hpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : Header file containing declarations for implementing
 * class Student
 */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <random>
#include "Utility.hpp"

class Student {
public:
    // Constructors and destructors declaration
    Student() = delete;
    Student(const std::string& firstName, const std::string& lastName);
    Student(const std::string& firstName,
			const std::string& lastName,
			const unsigned short age);
    Student(const std::string& firstName,
            const std::string& lastName,
            const unsigned short age,
            const struct Date& dateOfBirth);
    Student(const std::string& firstName,
            const std::string& lastName,
            const unsigned short age,
            const struct Date& dateOfBirth,
            const std::string& address);
    Student(const std::string& firstName,
            const std::string& lastName,
            const unsigned short age,
            const struct Date& dateOfBirth,
            const std::string& address,
            PaymentStatus feePaymentStatus);
    Student(const Student& otherStudent) = default;
    Student(Student&& otherStudent) noexcept;
    ~Student();

    // getters
    std::string getFirstName() const {
        return firstName;
    }

    std::string getLastName() const {
        return lastName;
    }

    unsigned short getAge() const {
        return age;
    }

    struct Date getDateOfBirth() const {
        return dateOfBirth;
    }

    std::string getAddress() const {
        return address;
    }

    std::string getRegistrationId() const {
        return registrationId;
    }

    PaymentStatus getFeePaymentStatus() const {
        return feePaymentStatus;
    }

    // setters
    void setFirstName(const std::string& firstName) {
        checkForEmptyString(firstName, "firstName");
        this->firstName = firstName;
    }

    void setLastName(const std::string& lastName) {
        checkForEmptyString(lastName, "lastName");
        this->lastName = lastName;
    }

    void setAge(const unsigned short age) {
        this->age = age;
    }

    void setDateOfBirth(const struct Date& dateOfBirth) {
        this->dateOfBirth = dateOfBirth;
    }

    void setAddress(const std::string& address) {
        /*if (address.len() == 0) {
            throw std::invalid_argument("Error : Empty string provided for address!");
        }*/
        checkForEmptyString(address, "address");
        this->address = address;
    }

    void setRegistrationId(const std::string& registrationId) {
        checkForEmptyString(registrationId, "registrationId");
        this->registrationId = registrationId;
    }

    void setFeePaymentStatus(const PaymentStatus feePaymentStatus) {
        this->feePaymentStatus = feePaymentStatus;
    }

    // operator overloadings
    Student& operator=(const Student& otherStudent);
    Student& operator=(Student&& otherStudent) noexcept;
    bool operator==(const Student& otherStudent);
	bool operator==(Student&& otherStudent) noexcept;

    friend std::ostream& operator<<(std::ostream& out, const Student& student);
    friend std::ostream& operator<<(std::ostream& out, Student&& student) noexcept;
private:
    std::string firstName;
    std::string lastName;
    unsigned short age;
    struct Date dateOfBirth;
    std::string address;
    std::string registrationId;
    PaymentStatus feePaymentStatus;
    
    // misc functions
	void setRegistrationId() noexcept;
};

std::ostream& operator<<(std::ostream& out, const Student& student);
std::ostream& operator<<(std::ostream& out, Student&& student) noexcept;

Student generateStudentObj();
Status processStudentObj(Student& obj);

#endif // STUDENT_HPP

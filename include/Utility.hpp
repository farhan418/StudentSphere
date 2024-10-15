/* File : Utility.hpp
 * Author : Mohammed Farhan Haider <mohammed-farhan.haider@capgemini.com>
 * Description : Header file containing utility declarations
 */
 
#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>
#include <stdexcept>
#include <cstdlib>

// Utility Enums
enum class PaymentStatus {
    PAID,
    UNPAID
};

enum class Status {
	SUCCESS,
	FAILURE
};

// Utility Structures
struct Date {
public:
    // constructors and destructors
	Date();
    Date(const unsigned short day,
         const unsigned short month,
         const unsigned short year);
    Date(const struct Date& anotherDateObj);
    Date(struct Date&& anotherDateObj) noexcept;
	~Date();

    // getters
    unsigned short getDay() const {
        return day;
    }

    unsigned short getMonth() const {
        return month;
    }

    unsigned short getYear() const {
        return year;
    }

    // setters
    void setDay(const unsigned short day) {
        if (day < 1 || day > 31) {  // did not do robust check by checking value of month
            // std::cerr << "Error : illegal value given for setting day of Date object.";
            throw std::invalid_argument("Error : illegal value given for setting day of Date object.");
        }
        this->day = day;
    }

    void setMonth(const unsigned short month) {
        if (month < 1 || month > 12) {
            throw std::invalid_argument("Error : illegal value given for setting month of Date object.");
        }
        this->month = month;
    }

    void setYear(const unsigned short year) {
        this->year = year;
    }

	// misc functions
	std::string toString() const{
		char date_str_arr[11];
		std::sprintf(date_str_arr, "%02d/%02d/%04d", day, month, year);
		return std::string(date_str_arr);
	}
	
    // operator overloadings
    struct Date& operator=(const struct Date& otherDate);
    struct Date& operator=(struct Date&& otherDate) noexcept;

    friend std::ostream& operator<<(std::ostream& out, const struct Date& date);
    friend std::ostream& operator<<(std::ostream& out, struct Date&& date) noexcept;

private:
    unsigned short day;
    unsigned short month;
    unsigned short year;
};

// Utility functions
inline void checkForEmptyString(const std::string& inputString, const std::string& variable_name) {
    if(inputString.length() == 0) {
        throw std::invalid_argument("Error : Empty string provided for" + variable_name);
    }
}

std::ostream& operator<<(std::ostream& out, const struct Date& date);
std::ostream& operator<<(std::ostream& out, struct Date&& date) noexcept;

void clearScreen();
int displayMainMenu();

void processChoice(Status (*funcPtr)(), const std::string& functionName);

#endif // UTILITY_HPP

//#include "catch.hpp"

//
//TEST_CASE( "Factorials are computed", "[factorial]" ) {
//    REQUIRE( Factorial(1) == 1 );
//    REQUIRE( Factorial(2) == 2 );
//    REQUIRE( Factorial(3) == 6 );
//    REQUIRE( Factorial(10) == 3628800 );
//}
#include <iostream>
#include "Utility.hpp"
#include "tests.hpp"

Status testUtilityDateObj() {
	// testing creation of Date obj using parameterized constructor
    Date d1(18, 04, 1999);
    std::cout << "std::cout << d1; | Testing operator<< overload\n" << d1 << '\n';  // OUTPUT
    if (18 != d1.getDay() || 4 != d1.getMonth() || 1999 != d1.getYear()) {
    	std::cerr << "\nDate object not set properly!\n";
		return Status::FAILURE;
	}
	if (d1.toString() != "18/04/1999") {
    	std::cerr << "\nDate object not set properly!\n";
		return Status::FAILURE;
	}
	
	// Test copy constructor
	Date d2(d1);
    std::cout << "\nDate d2(d1); | Testing copy constructor:\nd2=" << d2 << '\n';  // OUTPUT
	
	Date d3 = Date(10, 10, 2024);
	std::cout << "\nDate d3 = Date(10, 10, 2024); | Testing assignment operator:\nd3=" << d3 << '\n';  // OUTPUT
	
	d3 = d1;
	std::cout << "\nd3 = d1; | Testing assignment operator:\nd3=" << d3 << '\n';  // OUTPUT
	
	d3 = Date(1, 1, 2000);
	std::cout << "\nd3 = Date(1, 1, 2000); | Testing move assignment operator:\nd3=" << d3 << '\n';  // OUTPUT
	
	std::cout << "\nstd::cout << Date(1, 1, 100); | testing move operator<< overload\n";  
	std::cout << Date(1, 1, 100);// OUTPUT
	
    std::cout << "\nAll tests for testUtilityDateObj were successful!\n";
    return Status::SUCCESS;
}

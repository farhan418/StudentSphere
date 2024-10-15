#include <iostream>
#include "Student.hpp"
#include "tests.hpp"

Status testClassStudent() {
	Student s1("student1_firstName", "student2_lastName");
	Student s2("student2_firstName", "student2_lastName", 14);
	std::cout << "\n==========\nOUTPUT\n==========\n";
	std::cout << "std::cout << s1 << s2;\n" << s1 << '\n' << s2 << '\n';
	Date d1(18, 4, 1999);
	Student s3("student3_firstName", "student3_lastName", 15, Date(18, 4, 1999));
	Student s4("student4_firstName", "student4_lastName", 16, Date(18, 12, 2009), "Kadugoid Extension", PaymentStatus::PAID);
	std::cout << "\n==========\nOUTPUT\n==========\n";
	std::cout << "std::cout << s3 << s4;\n" << s3 << '\n' << s4 << '\n';
	
	s1 = s4;
	Student s5 = Student("student5_firstName", "student5_lastName");
	std::cout << "\n==========\nOUTPUT\n==========\n";
	std::cout << "a1 = s4; std::cout << s1 << s5;\n" << s1 << '\n' << s5 << '\n';
	
	return Status::SUCCESS;
}

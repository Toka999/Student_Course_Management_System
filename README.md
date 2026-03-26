Student Course Management System 🎓
A C++ console application designed to manage student records, track their GPAs, and handle course enrollments. This project applies core Object-Oriented Programming (OOP) and Standard Template Library (STL) concepts.

🚀 Features
The system provides a menu-driven interface with the following options:


Add Student: Create a new record with a Unique ID, Name, and GPA (0.0 - 4.0).


Remove Student: Delete a student record using their ID.


Search Student: Find students by ID, Name, or GPA.


Display All: List all students currently in the system.


Enroll in Course: Add courses to a student's profile (preventing duplicates using std::set).


Show Courses: Display all courses a specific student is enrolled in.


Sort by GPA: Rank students from highest to lowest GPA using std::sort.

🛠️ Technical Implementation
This project satisfies all the academic requirements listed in the assignment:

OOP Principles:


Inheritance: The Student class inherits from the Person class.


Encapsulation: Private and protected members are used with getter/setter functions.

STL Containers:


std::vector: Used as the main database for storing student objects.


std::map: Used to manage the menu options and UI.


std::set: Used within each student object to store unique courses.

STL Algorithms:


std::sort: Implemented with a custom lambda function for GPA sorting.

📂 Project Structure

main.cpp: The entry point containing the menu loop and logic.


person.h / person.cpp: Defines the base class for personal details.


student.h / student.cpp: Defines the student class with academic data and courses.

🖥️ How to Run
Clone the repository.

Compile using a C++ compiler:

Bash
g++ main.cpp person.cpp student.cpp -o student_system
Run the executable:

Bash
./student_system

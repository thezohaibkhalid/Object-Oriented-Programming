#include <iostream>
// #include <string>
// #include <vector>

// class StudentManagementSystem {
// private:
//     static const int MAX_STUDENTS = 100;
//     static const int NUM_SUBJECTS = 5;

//     struct Student {
//         std::string name;
//         std::string rollNumber;
//         bool attendance[NUM_SUBJECTS] = {false};
//     };

//     std::vector<Student> students;

// public:

//         int getNumSubjects() const {//i have done this because code was showing an error that, NUM_SUBJECTS is private, at line no 121
//         return NUM_SUBJECTS;
//     }
//     void addStudent(const std::string& name, const std::string& rollNumber) {
//         if (students.size() < MAX_STUDENTS) {
//             Student newStudent;
//             newStudent.name = name;
//             newStudent.rollNumber = rollNumber;
//             students.push_back(newStudent);
//             std::cout << "Student added: " << name << " (Roll Number: " << rollNumber << ")" << std::endl;
//         } else {
//             std::cout << "Maximum number of students reached." << std::endl;
//         }
//     }

//     void markAttendance(const std::string& rollNumber, int subjectIndex) {
//         int studentIndex = findStudentIndexByRollNumber(rollNumber);
//         if (studentIndex != -1) {
//             students[studentIndex].attendance[subjectIndex] = true;
//             std::cout << "Attendance marked for Roll Number " << rollNumber << " in subject " << getSubjectName(subjectIndex) << std::endl;
//         } else {
//             std::cout << "Student not found with Roll Number: " << rollNumber << std::endl;
//         }
//     }

//     void displayAttendanceByRollNumber(const std::string& rollNumber) {
//         int studentIndex = findStudentIndexByRollNumber(rollNumber);
//         if (studentIndex != -1) {
//             std::cout << "Attendance for " << students[studentIndex].name << " (Roll Number: " << rollNumber << "):" << std::endl;
//             for (int i = 0; i < NUM_SUBJECTS; ++i) {
//                 std::cout << getSubjectName(i) << ": " << (students[studentIndex].attendance[i] ? "Present" : "Absent") << std::endl;
//             }
//         } else {
//             std::cout << "Student not found with Roll Number: " << rollNumber << std::endl;
//         }
//     }

//     bool isRollNumberRegistered(const std::string& rollNumber) {
//         for (const Student& student : students) {
//             if (student.rollNumber == rollNumber) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     std::string getSubjectName(int subjectIndex) {
//         switch (subjectIndex) {
//             case 0: return "OOP";
//             case 1: return "English";
//             case 2: return "Math";
//             case 3: return "Software Engineering";
//             case 4: return "Pakistan Studies";
//             default: return "Unknown";
//         }
//     }


//     int findStudentIndexByRollNumber(const std::string& rollNumber) {
//         for (int i = 0; i < students.size(); ++i) {
//             if (students[i].rollNumber == rollNumber) {
//                 return i;
//             }
//         }
//         return -1;
//     }
// };

// int main() {
//     using namespace std;

//     StudentManagementSystem sms;

//     int choice;
//     do {
//         cout << "Select an option:" << endl;
//         cout << "1. Add Student" << endl;
//         cout << "2. Mark Attendance" << endl;
//         cout << "3. Display Attendance" << endl;
//         cout << "4. Exit" << endl;
//         cin >> choice;

//         if (choice == 1) {
//             string studentName, studentRollNumber;
//             cout << "Enter student name: ";
//             cin >> studentName;
//             cout << "Enter student roll number: ";
//             cin >> studentRollNumber;

//             if (sms.isRollNumberRegistered(studentRollNumber)) {
//                 cout << "Student already registered." << endl;
//             } else {
//                 sms.addStudent(studentName, studentRollNumber);
//                 cout << "Student registered successfully." << endl;
//             }
//         } else if (choice == 2) {
//             string studentRollNumber;
//             cout << "Enter student roll number: ";
//             cin >> studentRollNumber;

//             cout << "Select subject to mark attendance:" << endl;
//             for (int i = 0; i < StudentManagementSystem::NUM_SUBJECTS; ++i) {
//                 cout << i << ". " << sms.getSubjectName(i) << endl;
//             }
//             int subjectIndex;
//             cin >> subjectIndex;

//             sms.markAttendance(studentRollNumber, subjectIndex);
//         } else if (choice == 3) {
//             string studentRollNumber;
//             cout << "Enter student roll number to display attendance: ";
//             cin >> studentRollNumber;
//             sms.displayAttendanceByRollNumber(studentRollNumber);
//         }
//     } while (choice != 4);

//     return 0;
// }
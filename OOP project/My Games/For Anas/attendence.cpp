#include <iostream>
#include <fstream> //File handling
#include <string> // for string
#include <vector> //for vector that store data
#include <sstream> //isa iss k lia use kr rha line no 95, 96 mn mention kia hua ha
#include <windows.h> //For sleep function i am using in main (student management system)
#include <conio.h> //line no 181 mn con.ignore() use kia ha uska lia ya header file ha iska bgar program ak loop mn run krta rhata, ---- 

using namespace std;

class StudentManagementSystem {
private:
    static const int MAX_STUDENTS = 100; //pura code mn const specify krna k lia use kr rha k ya constant ha like change ni hona
    static const int NUM_SUBJECTS = 5;

    struct Student {
        string name;
        string rollNumber;
        bool attendance[NUM_SUBJECTS] = {false};
    };

    vector<Student> students;

    static const string STUDENT_INFO_FILE;
    static const string ATTENDANCE_FILE;

    int findStudentIndexByRollNumber(const string& rollNumber) {
        for (int i = 0; i < students.size(); ++i) {
            if (students[i].rollNumber == rollNumber) {
                return i;
            }
        }
        return -1;
    }

public:
    int getNumSubjects() const {   //using it kiunka is k bgar error ata, like program nhin run krta, 
                                   //ya NUM_SUBJECT k variable ko import krna k lia use ho rha ha private sa
        return NUM_SUBJECTS;
    }

    void addStudent(const string& name, const string& rollNumber) {
        if (students.size() < MAX_STUDENTS) {
            Student newStudent;
            newStudent.name = name;
            newStudent.rollNumber = rollNumber;
            students.push_back(newStudent);
            cout << "\033[32mStudent added: \033[0m" << name << " (Roll Number: " << rollNumber << ")" << endl;

            ofstream studentInfoFile(STUDENT_INFO_FILE, ios::app); /*ios::app (append use hota file mn 
            data add krna k lia is sa woh data jo pahla sa file mn store hota ha del ni hota, or jo data
             pahla sa file mn hota ha uska aga or write kr data, ha)*/
            if (studentInfoFile.is_open()) {
                studentInfoFile << rollNumber << "," << name << "\n";
                studentInfoFile.close();
            } else {
                cout << "Failed to open student info file." << endl;
            }
        } else {
            cout << "Maximum number of students reached." << endl;
        }
    }

    void markAttendance(const string& rollNumber, int subjectIndex) {
        int studentIndex = findStudentIndexByRollNumber(rollNumber);
        if (studentIndex != -1) {
            students[studentIndex].attendance[subjectIndex] = true;
            cout << "\033[32mAttendance marked for Roll Number \033[0m" << rollNumber << " in subject " << getSubjectName(subjectIndex) << endl;

            ofstream attendanceFile(ATTENDANCE_FILE, ios::app);
            if (attendanceFile.is_open()) {
                attendanceFile << rollNumber << "," << subjectIndex << "\n";
                attendanceFile.close();
            } else {
                cout << "Failed to open attendance file." << endl;
            }
        } else {
            cout << "Student not found with Roll Number: " << rollNumber << endl;
        }
    }

    void displayAttendanceByRollNumber(const string& rollNumber) {
        int studentIndex = findStudentIndexByRollNumber(rollNumber);
        if (studentIndex != -1) {
            cout << "Attendance for " << students[studentIndex].name << " (Roll Number: " << rollNumber << "):" << endl;
            for (int i = 0; i < NUM_SUBJECTS; ++i) {
                cout << getSubjectName(i) << ": " << (students[studentIndex].attendance[i] ? "Present" : "Absent") << endl;
            }

            ifstream attendanceFile(ATTENDANCE_FILE);
            if (attendanceFile.is_open()) {
                string line;
                while (getline(attendanceFile, line)) {
                    istringstream iss(line);
                    string storedRollNumber, subjectIndexStr;
                    getline(iss, storedRollNumber, ',');/*(std::istringstream)It's basically string stream, like input string stream or istringstream*/
                    getline(iss, subjectIndexStr, ',');//using to extract data from a coma seprated line, jo file sa read krti ha, jo folder mn ha
                    if (storedRollNumber == rollNumber) {
                        int storedSubjectIndex = stoi(subjectIndexStr);
                        cout << getSubjectName(storedSubjectIndex) << ": " << (students[studentIndex].attendance[storedSubjectIndex] ? "Present" : "Absent") << endl;
                    }
                }
                attendanceFile.close();
            } else {
                cout << "Failed to open attendance file." << endl;
            }
        } else {
            cout << "Student not found with Roll Number: " << rollNumber << endl;
        }
    }

    bool isRollNumberRegistered(const string& rollNumber) {
        for (const Student& student : students) {
            if (student.rollNumber == rollNumber) {
                return true;
            }
        }
        return false;
    }

    string getSubjectName(int subjectIndex) {
        switch (subjectIndex) {
            case 0: return "OOP";
            case 1: return "English";
            case 2: return "Math";
            case 3: return "Software Engineering";
            case 4: return "Pakistan Studies";
            default: return "Unknown";
        }
    }
};
    // const string STUDENT_INFO_FILE = "student_info.txt"; //const string k mtlb is mn ak string value ha jo ak br define krna k bd change ni ki ja skti, to prevemt accidental changes......etc
    // const string ATTENDANCE_FILE = "attendance_records.txt";
    //---->it was showing error sometimes after  execution that's why it's changed or nicha wala mn bs refrence add kia class ka outside the class,file bnata hua refrence k bgr work ni kra ga
    // Define static variables outside of the class 
    const string StudentManagementSystem::STUDENT_INFO_FILE = "student_info.txt";  //to store student info 
    const string StudentManagementSystem::ATTENDANCE_FILE = "attendance_records.txt"; //to store attendence record 


int main() {

    cout << "\033[31m  _____  _               _               _    " << endl;
    cout << " / ____|| |             | |             | |   " << endl;
    cout << "| (___  | |_  _   _   __| |  ___  _ __  | |_  " << endl;
    cout << " \\___ \\ | __|| | | | / _` | / _ \\| '_ \\ | __| " << endl;
    cout << " ____) || |_ | |_| || (_| ||  __/| | | || |_  " << endl;
    cout << "|_____/  \\__| \\__,_| \\__,_| \\___||_| |_| \\__| " << endl;
    cout << "                                            " << endl;
    cout << "                                            " << endl;
    cout << " __  __                                                            _    " << endl;
    cout << "|  \\/  |                                                          | |   " << endl;
    cout << "| \\  / |  __ _  _ __    __ _   __ _   ___  _ __ ___    ___  _ __  | |_  " << endl;
    cout << "| |\\/| | / _` || '_ \\  / _` | / _` | / _ \\| '_ ` _ \\  / _ \\| '_ \\ | __| " << endl;
    cout << "| |  | || (_| || | | || (_| || (_| ||  __/| | | | | ||  __/| | | || |_  " << endl;
    cout << "|_|  |_| \\__,_||_| |_| \\__,_| \\__, | \\___||_| |_| |_| \\___||_| |_| \\__| " << endl;
    cout << "                               __/ |                                    " << endl;
    cout << "                              |___/                                     " << endl;
    cout << "  _____              _                    " << endl;
    cout << " / ____|            | |                   " << endl;
    cout << "| (___   _   _  ___ | |_   ___  _ __ ___  " << endl;
    cout << " \\___ \\ | | | |/ __|| __| / _ \\| '_ ` _ \\ " << endl;
    cout << " ____) || |_| |\\__ \\| |_ |  __/| | | | | |" << endl;
    cout << "|_____/  \\__, ||___/ \\__| \\___||_| |_| |_|" << endl;
    cout << "          __/ |                           " << endl;
    cout << "         |___/                            " << endl;
    Sleep(5000);
    cout << "\033[34m"
    "********************************************************************************\n"
    "*                  Student Management System - Attendance                        *\n"
    "********************************************************************************\n"
    "\033[0m";

    StudentManagementSystem sms;

    int choice;
    
    while (true) {
        cout << "\n\033[34mSelect an option:\033[0m" << endl;
        cout << "\033[32m1. \033[32mAdd Student" << endl;
        cout << "\033[32m2. \033[32mMark Attendance" << endl;
        cout << "\033[32m3. \033[32mDisplay Attendance" << endl;
        cout << "\033[31m4.  \033[31mExit\033[0m" << endl;
        cout << "\033[34mEnter your choice: \033[0m";
        cin >> choice;
        cin.ignore(); //single line character ignore krna k lia, already mentioned in line no 7

        if (choice == 1) {
            string studentName, studentRollNumber;
            cout << "\033[32m\nEnter student name: \033[0m";
            cin >> studentName;
            cout << "\033[32mEnter student roll number: \033[0m";
            cin >> studentRollNumber;

            if (sms.isRollNumberRegistered(studentRollNumber)) {
                cout << "\n\033[31mStudent already registered.\033[0m" << endl;
            } else {
                sms.addStudent(studentName, studentRollNumber);
                cout << "\n\033[32mStudent registered successfully.\033[0m" << endl;
            }
        } else if (choice == 2) {
            string studentRollNumber;
            cout << "\033[32m\nEnter student roll number: \033[0m";
            cin >> studentRollNumber;

            cout << "\n\033[32mSelect subject to mark attendance:\n\033[0m";
            for (int i = 0; i < sms.getNumSubjects(); ++i) {
                cout << i << ". " << sms.getSubjectName(i) << endl;
            }
            int subjectIndex;
            cin >> subjectIndex;

            sms.markAttendance(studentRollNumber, subjectIndex);
        } else if (choice == 3) {
            string studentRollNumber;
            cout << "\033[32m\nEnter student roll number to display attendance: \033[0m";
            cin >> studentRollNumber;
            sms.displayAttendanceByRollNumber(studentRollNumber);
        } else if (choice == 4) {
            cout << "\n\033[31mThank you for using Student Management System. Goodbye!\033[0m" << endl;
            break; // Exit the loop
        } else {
            cout << "\033[31mInvalid choice. Please enter a valid option.\033[0m" << endl;
        }
    }

    return 0;
}

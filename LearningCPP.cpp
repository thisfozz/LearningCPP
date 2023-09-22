#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Date {
public:
    string dd;
    string mm;
    string yyyy;

    void parseDate(const std::string& dateStr) {
        std::stringstream ss(dateStr);
        std::getline(ss, dd, '.');
        std::getline(ss, mm, '.');
        std::getline(ss, yyyy, '.');
    }

    std::string getDate() const {
        return dd + "." + mm + "." + yyyy;
    }
};

class StudentTwo {
private:
    std::string name;
    std::string surname;
    int age;
    Date date;
    string phoneNumber;
public:
    void setName(const std::string& name) {
        this->name = name;
    }
    std::string getName() const {
        return name;
    }

    void setSurname(const std::string& surname) {
        this->surname = surname;
    }
    std::string getSurname() const {
        return surname;
    }

    void setAge(const int& age) {
        this->age = age;
    }
    int getAge() const {
        return age;
    }

    void setDate(const Date& dateOfBirth) {
        this->date = dateOfBirth;
    }

    Date getDateOfBirth() const {
        return date;
    }
    void setPhoneNumber(const std::string& phoneNumber) {
        this->phoneNumber = phoneNumber;
    }
    std::string getPhoneNumber() const {
        return phoneNumber;
    }


    StudentTwo() {}

    StudentTwo(std::string name, std::string surname, int age, const Date& dateOfBirth, const std::string& phoneNumber)
        : name(name), surname(surname), age(age), date(dateOfBirth), phoneNumber(phoneNumber) {
    }
};


class Dot {
private:
    int x = 0;
    int y = 0;
    int z = 0;

public:
    void setX(const int& x) {
        this->x = x;
    }
    void setY(const int& y) {
        this->y = y;
    }
    void setZ(const int& z) {
        this->z = z;
    }

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    void saveFile() {
        std::ofstream outputFile("file.txt", std::ios::out);

        if (outputFile.is_open()) {
            outputFile << "x = " << x;
            outputFile << "\ny = " << y;
            outputFile << "\nz = " << z;

            outputFile.close();
        }
        else {
            std::cout << "Error";
        }
    }
};

class Task {
public:
    void task1() {
        std::vector<StudentTwo> studentsTwo;

        std::cout << "How many students would you like to have? ";
        int count = 0;
        std::cin >> count;
        std::cin.ignore();

        for (int i = 0; i < count; i++) {
            std::string name;
            std::cout << "Enter the name of student " << i + 1 << ": ";
            std::getline(std::cin, name);

            string surname;
            std::cout << "Enter the surname of student " << i + 1 << ": ";
            std::getline(std::cin, surname);

            int age = 0;
            std::cout << "Enter the student's age " << i + 1 << ": ";
            cin >> age;
            std::cin.ignore();

            std::string dateStr;
            std::cout << "Enter the date of birth for student " << i + 1 << " (dd.mm.yyyy): ";
            std::getline(std::cin, dateStr);
            std::cin.ignore();

            string phoneNumber;
            std::cout << "Enter the phoneNumber of student " << i + 1 << ": ";
            std::getline(std::cin, phoneNumber);
            std::cin.ignore();

            Date dateOfBirth;
            dateOfBirth.parseDate(dateStr);

            studentsTwo.emplace_back(name, surname, age, dateOfBirth, phoneNumber);

            system("cls");
        }

        for (size_t i = 0; i < studentsTwo.size(); ++i) {
            std::cout << "Student " << i + 1 << ":\n";
            std::cout << "Name: " << studentsTwo[i].getName() << "\n";
            std::cout << "Name: " << studentsTwo[i].getSurname() << "\n";
            std::cout << "Name: " << studentsTwo[i].getAge() << "\n";
            std::cout << "Date Of Birth: " << studentsTwo[i].getDateOfBirth().getDate() << "\n";

            std::cout << "\n\n";
        }
    }

    void task2() {
        Dot dot;

        int x, y, z;
        std::cout << "Enter value X: ";
        std::cin >> x;
        
        std::cout << "\n";

        std::cout << "Enter value Y: ";
        std::cin >> y;

        std::cout << "\n";

        std::cout << "Enter value Z: ";
        std::cin >> z;

        dot.setX(x);
        dot.setY(y);
        dot.setZ(z);

        dot.saveFile();
    }
};



int main() {
    Task task;
    //task.task1();
    task.task2();
}


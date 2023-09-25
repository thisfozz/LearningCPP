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
        : name(name), surname(surname), age(age), date(dateOfBirth), phoneNumber(phoneNumber) {}
};
class Dot {
private:
    int x = 0;
    int y = 0;
    int z = 0;

public:

    Dot() {}

    Dot(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

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

    inline double calculateDistance(Dot& dotOther) {
        if (this->x == 0 && this ->y == 0 && this ->z == 0) {
            std::cout << "Error: Current Dot has zero coordinates.\n";
            return -1.0;
        }
        if (dotOther.x == 0 && dotOther.y == 0 && dotOther.z == 0) {
            std::cout << "Error: Other Dot has zero coordinates.\n";
            return -1.0;
        }

        // Вычисление Евклидового расстояния между точками в пространстве
        return std::sqrt(std::pow(dotOther.getX() - this->x, 2) + std::pow(dotOther.getY() - this->y, 2) + std::pow(dotOther.getZ() - this->z, 2));
    }
};
class NNTName {
private:
    int valueOne;
    int valueTwo;

public:
    void SetValueOne(const int& valueOne) {
        this->valueOne = valueOne;
    }
    int GetValueOne() {
        if (valueOne != NULL) {
            return valueOne;
        }
        return 0;
    }

    void SetValueTwo(const int& valueTwo) {
        this->valueTwo = valueTwo;
    }
    int GetValueTwo() {
        if (valueTwo != NULL) {
            return valueTwo;
        }
        return 0 ;
    }

    int Sum() {
        if (valueOne != NULL && valueTwo != NULL) {
            return valueOne + valueTwo;
        }
    }
    int MaxValue() {
    }

    int minValue() {
        return std::min(valueOne, valueTwo);
    }
};
class People {
public:
    virtual ~People() {}

    virtual void setName(const std::string& Name) = 0;
    virtual void setSurname(const std::string& Surname) = 0;
    virtual void setAge(const int Age) = 0;
    virtual void setGender(const std::string& Gender) = 0;

    virtual std::string getName() = 0;
    virtual std::string getSurname() = 0;
    virtual int getAge() = 0;
    virtual std::string getGender() = 0;

protected:
    std::string Name;
    std::string Surname;
    int Age;
    std::string Gender;
};

class Student : public People {
public:

    Student() {}

    Student(const std::string& name, const std::string& surname, int age, const std::string& gender, int numberGroup)
    {
        setName(name);
        setSurname(surname);
        setAge(age);
        setGender(gender);
        setNumberGroup(numberGroup);
    }

    virtual void setName(const std::string& Name) override
    {
        this->Name = Name;
    }
    virtual void setSurname(const std::string& Surname) override
    {
        this->Surname = Surname;
    }
    virtual void setAge(const int Age) override
    {
        this->Age = Age;
    }
    virtual void setGender(const std::string& Gender) override
    {
        this->Gender = Gender;
    }
    virtual std::string getName() override
    {
        return Name;
    }
    virtual std::string getSurname() override
    {
        return Surname;
    }
    virtual int getAge() override
    {
        return Age;
    }
    virtual std::string getGender() override
    {
        return Gender;
    }

    void setNumberGroup(const int numberGroup) {
        NumberGroup = numberGroup;
    }
    int getNumberGroup() {
        return NumberGroup;
    }

private:
    int AverageRating;
    int NumberGroup;
};

class Group {
public:

    Group() {}

    Group(const std::vector<Student>& initialStudents) : groupStudents(initialStudents) {}

    void Menu() {
        system("cls");
        char choice;

        std::cout << "Menu:\n";
        std::cout << "1. Print Students\n";
        std::cout << "2. Add Student\n";
        std::cout << "3. Remove Students\n";

        std::cin >> choice;

        switch (choice) {
        case '1':
            PrintStudents();
            break;
        case '2':
            AddStudent();
            break;
        case '3':
            std::cout << "You chose to Remove Students.\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 3.\n";
            break;
        }
    }
private:
    void AddStudent() {
        system("cls");
        std::string Name;
        std::string Surname;
        int Age;
        std::string Gender;
        int NumberGroup;

        std::cout << "Enter name Student: ";
        std::cin >> Name;

        std::cout << "\nEnter Surname Student: ";
        std::cin >> Surname;

        std::cout << "\nEnter Age Student: ";
        std::cin >> Age;

        std::cout << "\nEnter Gender Student: ";
        std::cin >> Gender;

        std::cout << "\nEnter Number Group Student: ";
        std::cin >> NumberGroup;

        Student student(Name, Surname, Age, Gender, NumberGroup);
        groupStudents.push_back(student);

        system("cls");
        Menu();
    }

    void PrintStudents() {
        system("cls");
        for (size_t i = 0; i < groupStudents.size(); i++) {

            std::cout << "Student " << i + 1;
            std::cout << "\nName: " << groupStudents[i].getName();
            std::cout << "\nSurname: " << groupStudents[i].getSurname();
            std::cout << "\nAge: " << groupStudents[i].getAge();
            std::cout << "\nGender: " << groupStudents[i].getGender();
            std::cout << "\nGroup Number: " << groupStudents[i].getNumberGroup();

            std::cout << "\n\n";

            bool choice;
            std::cout << "Go back to the menu?";
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                Menu();
                break;
            case 2:
                break;
            default:
                break;
            }

            //Menu();
        }
    }
protected:
    std::vector<Student> groupStudents;
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

    void task3() {
        NNTName n;
        n.SetValueOne(5);
        n.SetValueTwo(10);

        std::cout << n.MaxValue();
    }
    void task4() {
        Group groupStudent;
        groupStudent.Menu();

    }
};

int main() {
    Task task;
    //task.task1();
    //task.task2();
    //task.task3();
    task.task4();
}


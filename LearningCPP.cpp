#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <map>
#include <ctime>
#include <cstring>

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

public:
    virtual void setName(const std::string& Name) override { this->Name = Name; }
    virtual void setSurname(const std::string& Surname) override { this->Surname = Surname; }
    virtual void setAge(const int Age) override { this->Age = Age; }
    void setNumberGroup(const int numberGroup) { NumberGroup = numberGroup; }
    virtual void setGender(const std::string& Gender) override { this->Gender = Gender; }

    virtual std::string getName() override { return Name; }
    virtual std::string getSurname() override { return Surname; }
    virtual int getAge() override { return Age;}
    virtual std::string getGender() override { return  Gender; }
    int getNumberGroup() { return NumberGroup; }

private:
    int AverageRating;
    int NumberGroup;
};
class Group {
public:
    Group() {}
    Group(const std::vector<Student>& initialStudents) : groupStudents(initialStudents) {}

public:
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
    ~Group() {};
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

class Elevator {
public:
    Elevator()
    {
        currentFloor = 1;
        powerElevator = true;
        elevator[1] = "1st floor";
        elevator[2] = "2st floor";
        elevator[3] = "3st floor";
        elevator[4] = "4st floor";
        elevator[5] = "5st floor";
        elevator[6] = "6st floor";
        elevator[7] = "7st floor";
        elevator[8] = "8st floor";
    }

    void MovementButton(const int& floor) {
        if (!powerElevator) {
            std::cout << "The elevator is not included";
            return;
        }

        if (elevator.find(floor) != elevator.end()) {
            std::cout << "Moving to " << elevator[floor] << std::endl;
            currentFloor = floor;
        }
        else std::cout << "Invalid floor requested" << std::endl;
    }
    void ElevatorPowerManagement(const bool power) {
        if (power != powerElevator)
            powerElevator = power;

        return;
    }
    bool getStatusPowerElevator() {
        return powerElevator;
    }
    int getStatusFloorElevator() {

        return currentFloor;
    }
private:
    std::map<int, string> elevator;
    bool powerElevator;
    int currentFloor;
};

class Counter {
public:
    Counter() : _counter(0) {}

    Counter(const int counterStart) : _counter(counterStart) {}

    void CounterManager() {
        int value;
        short choice = 0;
        bool isContinue = false;
        do {
            std::cout << "1. " << "Increase by one" << std::endl;
            std::cout << "\n2. " << "Increase by value" << std::endl;

            std::cin >> choice;

            switch (choice)
            {
            case 1:
                ++_counter;
                PrintValue();
                std::cout << "\nIsContinue?";
                std::cin >> isContinue;
                break;
            case 2:
                std::cout << "Enter a number: ";
                std::cin >> value;
                _counter += value;
                PrintValue();
                std::cout << "\nIsContinue?";
                std::cin >> isContinue;
                break;
            default:
                break;
            }
        } while (isContinue);
    }

private:
    int _counter;

    Counter operator ++ ()
    {
        _counter + 1;
        return *this;
    }

    Counter operator += (int value)
    {
        _counter + value;
        return *this;
    }

    void PrintValue() {
        std::cout << "Value = " << _counter << std::endl;
    }
};

class WallpaperRollType {
private:
    string wallpaperType;
    int costWallpaper;
    int onsquares;

    int GenerateRandomNumber() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int random_number = std::rand() % 6 + 5;
        return random_number;
    }
public:
    WallpaperRollType(){}

    WallpaperRollType(const std::string& type, int cost)
        : wallpaperType(type), costWallpaper(cost), onsquares(GenerateRandomNumber()) {}

    void SetWallpapperType(const std::string& wallpaperType) {
        this->wallpaperType = wallpaperType;
    }
    std::string GetWallpaperType() const { return wallpaperType; }

    void setCostWallpaper(const int costWallpapper) {
        this->costWallpaper = costWallpaper;
    }
    int GetCostWallpaper() const { return costWallpaper; }

    int GetOnSquares() const { return onsquares; }

    bool IsValid() const {
        return !wallpaperType.empty() && costWallpaper >= 0;
    }
};
class WallpapperRoll {
protected:
    std::map<string, int> wallpaperRolls;
public:
    void AddWallpaperRoll(const WallpaperRollType& roll) {
        wallpaperRolls[roll.GetWallpaperType()] = roll.GetCostWallpaper();
    }
    int GetCostByWallpaperType(const std::string& type) const {
        auto it = wallpaperRolls.find(type);
        if (it != wallpaperRolls.end()) {
            return it->second;
        }
        return -1;
    }
};
class Store {
private:
    std::map<string, WallpaperRollType> availableWallpapers;
public:
    void AddWallpapper(const std::string& type, const int cost) {
        if (availableWallpapers.find(type) == availableWallpapers.end()) {
            availableWallpapers[type] = WallpaperRollType(type, cost);
        }
        else {
            std::cout << "Such wallpapers are already in the collection" << std::endl;
        }
    }
    WallpaperRollType BuyWallpapper(const std::string& type) {
        auto it = availableWallpapers.find(type);
        if (it != availableWallpapers.end()) {
            return it->second;
        }
        else {
            return WallpaperRollType("0", 0);
        }
    }
};
class Room {
private:
    WallpaperRollType selectedWallpaper;
    int squares;
public:
    Room(){}
    Room(const int squares) :squares(squares) {};

    void SelectedWallpaper(Store& store, const std::string& type) {
        selectedWallpaper = store.BuyWallpapper(type);
    }

    int GetCostOfGluing() {
        if (selectedWallpaper.GetWallpaperType() != "") {
            return selectedWallpaper.GetCostWallpaper() * squares;
        }
        return -1;
    }
};
class Flat {
private:
    Room room;
    int countRoom;
public:
    Flat(const int countRoom) :countRoom(countRoom) {}

    int getAllCostOfGluing() {
        return getAllCostOfGluing() * countRoom;
    }
};

class Figure {
public:
    double area;

    virtual double CalculatingArea() = 0;

    virtual ~Figure() {}
};
class Square : public Figure{
public:

    Square(const double& side) : side(side) {}

    int getArea() const {
        if (area != 0) {
            return area;
        }
        else {
            return NULL;
        }
    }
    virtual ~Square(){}
private:
    double side;

    double CalculatingArea() override {
        area = std::pow(side, 2);
    }
};
class Triangle : public Figure {
public:
    Triangle(const double& a, const double& h) : a(a), h(h) {}

    double getArea() const {
        if (area != 0) {
            return area;
        }
        else {
            return NULL;
        }
    }
    virtual ~Triangle() {}
private:
    double a;
    double h;

    double CalculatingArea() override {
        area = (1 / 2) * a * h;
    }
};
class Rhomb : public Figure {
public:
    Rhomb(const double& a, const double& h) : a(a), h(h) {}

    double getArea() const {
        if (area != 0) {
            return area;
        }
        else {
            return NULL;
        }
    }
    virtual ~Rhomb() {}

private:
    double a;
    double h;

    double CalculatingArea() override {
        area = std::pow(a, 2) * std::sin(a);
    }
};

class Integer {
private:
    int value;
public:

    Integer(int value) : value(value){}

    //CTOR copy
    Integer(const Integer& other) {
        this->value = other.value;
    }

    //Operation
    Integer operator + (const Integer& other) const {
        return Integer{ value + other.value };
    }
    Integer operator - (const Integer& other) const {
        return Integer{ value - other.value };
    }
    Integer operator * (const Integer& other) const {
        return Integer{ value * other.value };
    }
    Integer operator / (const Integer& other) const {
        if (other.value == 0) {
            return NULL;
        }
        return Integer{ value / other.value };
    }

    //Logic operation
    bool operator == (const Integer& other) const {
        return value == other.value;
    }
    bool operator != (const Integer& other) const {
        return value != other.value;
    }
    bool operator > (const Integer& other) const {
        return value > other.value;
    }
    bool operator < (const Integer& other) const {
        return value < other.value;
    }

    //Assignment
    Integer& operator = (const Integer& other) {
        value = other.value;
        return *this;
    }
    Integer& operator += (const Integer& other) {
        value += other.value;
        return *this;
    }

    //Prefix ++ and on nValue
    Integer operator ++ () const
    {
        value + 1;
        return *this;
    }
    Integer operator += (int value)
    {
        this->value + value;
        return *this;
    }
};

class _String {
private:
    char *_text;

    int getSize(const std::string text) {
        return text.size();
    }
public:
    _String() {
        _text = new char[81];
    }
    _String(const size_t countSymbol) {
        _text = new char[countSymbol+1];
    }
    _String(const std::string& text) {
        int size = text.size();
        _text = new char[size + 1];
        text.copy(_text, size);
        _text[size] = '\0';
    }

    _String(const _String& otherString) {
        delete[] _text;

        std::string textdat = otherString._text;

        int size = getSize(otherString._text);
        _text = new char[size + 1];
        textdat.copy(_text, size);
        _text[size] = '\0';
    }

    void setText(const std::string& text) {
        delete[] _text;

        int size = text.size();
        _text = new char[size + 1];
        text.copy(_text, size);
        _text[size] = '\0';
    }

    std::string getText() {
        return _text;
    }
    ~_String() {
        delete[] _text;
    }
};

class Array {
private:
    int* _currentArray;
    int _size;

    int GenerateRandomNumber() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int random_number = std::rand() % 6 + 5;
        return random_number;
    }

public:
    Array(const int& size) :_size(size)
    {
        _currentArray = new int[_size];
        for (int i = 0; i < size; i++)
        {
            _currentArray[i] = GenerateRandomNumber();
        }
    }
    Array() {}

    Array(const Array& otherArray) : _size(otherArray._size) {
        _currentArray = new int[_size];
        for (int i = 0; i < _size; i++)
        {
            _currentArray[i] = otherArray._currentArray[i];
        }
    }

    void ChangeSize(const int& size) {
        int* _tmpArray = _currentArray;
        _currentArray = new int[size];

        for (int i = 0; i < size; i++)
        {
            _currentArray[i] = _tmpArray[i];
        }

        delete[] _tmpArray;
        _size = size;
    }

    void PrintArray() {
        if (_size <= 0) return;
        for (size_t i = 0; i < _size; ++i) {
            std::cout << _currentArray[i] << " ";
        }
    }
    void Sort()
    {
        if (_size <= 0) return;
        for (int i = 1; i < _size; i++)
        {
            int j = i - 1;
            while (j >= 0 && _currentArray[j] > _currentArray[j + 1])
            {
                swap(_currentArray[j], _currentArray[j + 1]);
                j--;
            }
        }
    }

    int FindMax() {
        if (_size <= 0) return -1;
        int max = _currentArray[0];
        for (size_t i = 1; i < _size; ++i) {
            if (_currentArray[i] > max) {
                max = _currentArray[i];
            }
        }
        return max;
    }

    int FindMin() {
        if (_size <= 0) return -1;
        int min = _currentArray[0];
        for (size_t i = 1; i < _size; ++i) {
            if (_currentArray[i] < min) {
                min = _currentArray[i];
            }
        }
        return min;
    }

    ~Array() {
        delete[] _currentArray;
    }
};

class _Triangle {
public:
    _Triangle(): area(0), perimeter(0), pointmeridian(0) {}

    _Triangle(const double& a, const double& b, const double& c)
        :a(a), b(b), c(c), area(0), perimeter(0), pointmeridian(0)
    {}

public:
    double calculateArea() {
        if (a > 0 && b > 0 && c > 0) {
            double s = (a + b + c) / 2.0;
            area = sqrt(s * (s - a) * (s - b) * (s - c));
            return area;
        }
        else {
            return -1;
        }
    }
    double CalculatingPerimeter() {
        if (a > 0 && b > 0 && c > 0) {
            perimeter = a + b + c;
            return perimeter;
        }
        else return -1;
    }
    double meridianIntersectionPoint() {
        if (a > 0 && b > 0 && c > 0) {
            double x = (b * b + c * c - a * a) / (2 * (b * b + c * c));
            double y = sqrt(1 - x * x) * b;
            pointmeridian = x * a / 2.0;
            return pointmeridian;
        }
        else {
            return -1;
        }
    }
    double getSideA() {
        return a;
    }
    double getSideB() {
        return b;
    }
    double getSideC() {
        return c;
    }
private:
    double a;
    double b;
    double c;
    double area;
    double perimeter;
    double pointmeridian;
};

class MTime {
public:
    MTime() :hour(0), minutes(0), second(0) {}

    MTime(const int& hour, const int& minutes, const int& second)
        :hour(hour), minutes(minutes), second(second) {}

    void SetHour(const int& hour) {
        if (hour < 0 || hour > 24) {
            throw invalid_argument("Hour < 0 OR > 24");
        }
        this->hour = hour;
    }
    void SetMinutes(const int& minutes) {
        if (minutes < 0 || minutes > 60) {
            throw invalid_argument("Minutes < 0 OR > 60");;
        }
        this->minutes = minutes;
    }
    void SetSecond(const int& second) {
        if (second < 0 || second > 60) {
            throw invalid_argument("Second < 0 OR > 60");;;
        }
        this->second = second;
    }
    void setTime(const int& hour, const int& minutes, const int& second) {
        this->hour = hour;
        this->minutes = minutes;
        this->second = second;
    }

    int getHour() {
        return hour;
    }
    int getMinutes() {
        return minutes;
    }
    int getSecond() {
        return second;
    }

    void ChangeHour(const int& hour) {
        long long timeInSecond = this->hour * 3600 + this->minutes * 60 + this->second;
        timeInSecond += hour * 3600;

        if (timeInSecond < 0) {
            timeInSecond = 86400 + timeInSecond;
        }
        else {
            timeInSecond %= 86400;
        }

        this->hour = timeInSecond / 3600;
        timeInSecond %= 3600;
        this->minutes = timeInSecond / 60;
        this->second = timeInSecond % 60;
    }
    void ChangeMinutes(const int& minutes) {
        long long timeInSecond = this->hour * 3600 + this->minutes * 60 + this->second;
        timeInSecond += minutes * 60;

        if (timeInSecond < 0) {
            timeInSecond = 86400 + timeInSecond;
        }
        else {
            timeInSecond %= 86400;
        }

        this->hour = timeInSecond / 3600;
        timeInSecond %= 3600;
        this->minutes = timeInSecond / 60;
        this->second = timeInSecond % 60;
    }

    void ChangeTime(const int& hour, const int& minutes, const int& second) {
        long long timeInSecond = this->hour * 3600 + this->minutes * 60 + this->second;
        timeInSecond += hour * 3600;
        timeInSecond += minutes * 60;
        timeInSecond += second;

        if (timeInSecond < 0) {
            timeInSecond = 86400 + timeInSecond;
        }
        else {
            timeInSecond %= 86400;
        }

        this->hour = timeInSecond / 3600;
        timeInSecond %= 3600;
        this->minutes = timeInSecond / 60;
        this->second = timeInSecond % 60;

    }
    void ChangeTime(const int& second) {
        long long timeInSecond = this->hour * 3600 + this->minutes * 60 + this->second;
        timeInSecond += second;

        if (timeInSecond < 0) {
            timeInSecond = 86400 + timeInSecond;
        }
        else {
            timeInSecond %= 86400;
        }

        this->hour = timeInSecond / 3600;
        timeInSecond %= 3600;
        this->minutes = timeInSecond / 60;
        this->second = timeInSecond % 60;
    }
    void printTime() {
        std::cout << hour << " : " << minutes << " : " << second << std::endl;
    }
private:
    int hour;
    int minutes;
    int second;
};

class REDate {
private:
    unsigned short int day;
    unsigned short int mounth;
    unsigned int year;

public:
    REDate() {}

    REDate(const unsigned short int& day, const unsigned short int& mounth, const unsigned int& year)
        :day(day), mounth(mounth), year(year) {}

    void setDay(const unsigned short int& day) {
        this->day = day;
    }
    unsigned short int getDay() const { return day; }

    void setMounth(const unsigned short int& mounth) {
        this->mounth = mounth;
    }
    unsigned short int getMounth() const { return mounth; }

    void setYear(const unsigned short int& year) {
        this->year = year;
    }
    unsigned short int getYear() const { return year; }

    std::string ToString() const {
        std::cout << day << "." << mounth << "." << year << std::endl;
    }
};

class RETimne { // To be Continued
private:
    REDate date;
    unsigned short int hour;
    unsigned short int minutes;
    unsigned short int second;
};

class Author {
private:
    std::string name;
    std::string surname;
public:
    Author(const std::string& name, const std::string& surname) : name(name), surname(surname) {}

    void setName(const std::string& name) {
        if (name == this->name) {
            return;
        }
        this->name = name;
    }
    std::string getName() const { return name; }

    void setSurname(const std::string& surname) {
        if (surname == this->surname) {
            return;
        }
        this->name = name;
    }
    std::string getSurname() const { return surname; }
};
class Publishing {
private:
    std::string title;
public:
    Publishing(const std::string& title) : title(title) {}

    void setTtitle(const std::string& title) {
        if (title == this->title) {
            return;
        }
        this->title = title;
    }
    std::string getTtile() const { return title; }
};
class Book {
private:
    Author author;
    Publishing publishing;
    std::string titleBook;
    unsigned int yearRelease;
    unsigned int countInstances;
    unsigned int countPages;
public:
    Book(const std::string& name, 
        const std::string& surname, 
        const std::string& title, 
        const std::string& titleBook,
        const unsigned int& yearRelease,
        unsigned int& countInstances,
        unsigned int& countPages)
        :author(name,surname), publishing(title), titleBook(titleBook), yearRelease(yearRelease), countInstances(countInstances), countPages(countPages)
    {}

    void changeNameAuthor(const std::string& name) {
        author.setName(name);
    }
    std::string getNameAuthor() {
        return author.getName();
    }

    void changeSurnameAuthor(const std::string& surname) {
        author.setSurname(surname);
    }
    std::string getSurnameAuthor() {
        return author.getSurname();
    }

    void changePublishing(const std::string publishing) {
        this->publishing.setTtitle(publishing);
    }
    std::string getPublishing() { return publishing.getTtile(); }

    void setTitleBook(const std::string& titleBook) {
        if (titleBook == this->titleBook) {
            return;
        }
        this->titleBook = titleBook;
    }
    std::string getTitleBook() { return titleBook; }

    void setYearRelease(const unsigned int& yearRelease) {
        if (yearRelease == this->yearRelease) {
            return;
        }
        this->yearRelease = yearRelease;
    }
    unsigned int getYearRelease() { return yearRelease; }

    void setCountInstances(const unsigned int& countInstances) {
        if (countInstances == this->countInstances) {
            return;
        }
        this->countInstances = countInstances;
    }
    unsigned int getCountInstances() { return countInstances; }

    void setCountPage(const unsigned int& countPages) {
        if (countPages == this->countPages) {
            return;
        }
        this->countPages = countPages;
    }
    unsigned int getCountPage() { return countPages; }


    void printBook() {
        std::cout
            << "Author name: " << author.getName() << std::endl
            << "Author Surname: " << author.getSurname() << std::endl
            << "Publishing Title: " << publishing.getTtile() << std::endl
            << "Title Book: " << titleBook << std::endl
            << "Year Release Book: " << yearRelease << std::endl
            << "Count Instances: " << countInstances << std::endl
            << "Count Pages: " << countPages << std::endl;
    }
};
class Books {
private:
    std::vector<Book> books;
public:
    void AddBook(Book book) {
        books.emplace_back(book);
    }
    void RemoveBook(Book book) {
        auto it = std::find(books.begin(), books.end(), book);

        if (it != books.end()) {
            books.erase(it);
        }
    }
    void PrintBookSpecificAuthor(const std::string& author) {
        std::vector<Book> booksSpecificAuthor;

        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getNameAuthor() == author) {
                booksSpecificAuthor.emplace_back(books[i]);
            }
        }

        for (size_t i = 0; i < booksSpecificAuthor.size(); ++i) {
            booksSpecificAuthor[i].printBook();
            std::cout << std::endl;
        }
    }

    void PrintBookSpecificPublishing(const std::string publishing) {
        std::vector<Book> booksSpecificPublishing;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getPublishing() == publishing) {
                booksSpecificPublishing.emplace_back(books[i]);
            }
        }

        for (size_t i = 0; i < booksSpecificPublishing.size(); ++i) {
            booksSpecificPublishing[i].printBook();
            std::cout << std::endl;
        }
    }
    void PrintScpecificYearBook(const unsigned int& yearRelease) {
        std::vector<Book> booksSpecificYear;

        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getYearRelease() > yearRelease) {
                booksSpecificYear.emplace_back(books[i]);
            }
        }

        for (size_t i = 0; i < booksSpecificYear.size(); ++i) {
            booksSpecificYear[i].printBook();
            std::cout << std::endl;
        }
    }
};

class Task {
public:
    void TaskDot() {
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
    void TaskNNTName() {
        NNTName n;
        n.SetValueOne(5);
        n.SetValueTwo(10);

        std::cout << n.MaxValue();
    }
    void TaskGroup() {
        Group groupStudent;
        groupStudent.Menu();

    }
    void TaskCounter() {
        Counter counter;
        counter.CounterManager();
    }
    void TaskWallpapper() {
        Store store;
        Room room(73);

        store.AddWallpapper("Glass", 623);
        room.SelectedWallpaper(store, "Glass");
        int costGlass = room.GetCostOfGluing();
        std::cout << "Glass Wallpapper = " << costGlass << std::endl;

        store.AddWallpapper("Wood", 345);
        room.SelectedWallpaper(store, "Wood");
        int costWood = room.GetCostOfGluing();
        std::cout << "Wood Wallpapper = " << costWood << std::endl;


        store.AddWallpapper("Metal", 1000);
        room.SelectedWallpaper(store, "Metal");
        int costMetal = room.GetCostOfGluing();
        std::cout << "Metal Wallpapper = " << costMetal << std::endl;
    }
    void TaskTime() {
        MTime time;
        time.setTime(13, 45, 34);
        time.printTime();
        time.ChangeHour(5);
        time.ChangeMinutes(15);
        time.printTime();
        time.ChangeTime(2, 2, 2);
        time.printTime();
        time.ChangeTime(23562);
        time.printTime();
    }
};
int main() {
    Task task;
}
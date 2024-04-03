#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(const string& n, int a) : name(n), age(a) {}

    void display() const {
        cout << "Iм'я: " << name << ", Вiк: " << age;
    }
};

class Student : public Person {
private:
    string school;
    string group;
public:
    Student(const string& n, int a, const string& s, const string& g)
        : Person(n, a), school(s), group(g) {}

    void display() const {
        Person::display();
        cout << ", Школа: " << school << ", Група: " << group << endl;
    }

    const string& getGroup() const {
        return group;
    }
};

int main() {
    setlocale(LC_CTYPE, "ukr");
    vector<Student> students = {
        {"Вадим", 17, "Школа А", "Група 11"},
        {"Микола", 18, "Школа B", "Група 34"},
        {"Арсен", 16, "Школа C", "Група 20"}
    };

    cout << "Перед сортуванням:" << endl;
    for (const auto& student : students) {
        student.display();
    }

    sort(students.begin(), students.end(), [](const Student& s1, const Student& s2) {
        return s1.getGroup() < s2.getGroup();
        });

    cout << "\nПiсля сортування за групою:" << endl;
    for (const auto& student : students) {
        student.display();
    }

    return 0;
}

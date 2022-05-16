#include <iostream>
using namespace std;

class Student {
    public :

    static int rollNumber;

    static int getRollNumber() {
        return rollNumber;
    }
};

int Student :: rollNumber(101);

int main() {
    Student s;
    Student :: rollNumber = 101;
    cout << s.getRollNumber() << endl;
}
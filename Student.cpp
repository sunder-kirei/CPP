#include <iostream>
#include <cstring>
using namespace std;

class Student{
    private:
        int age;
        int rollNo;
        char *name;
    public:
        void display () const {
            cout<<age<<' '<<rollNo<<' '<<name<<' '<<endl;
        }
        void setName(char *name){
            this -> name = new char[strlen(name)+1];
            strcpy(this -> name, name);
        }
        Student(int age, int rollNo){
            
        }
        Student(Student const &s){
            this -> age = s.age;
            this -> rollNo = s.rollNo;
            this -> name = new char[strlen(s.name)+1];
            strcpy(this -> name, s.name);
        }


};

int main(){
    Student s1(18, 01);
    char *name = new char[100];
    cin.getline(name,100);
    s1.setName(name);
    Student s2(s1);
    s1.display();
    s2.display();
    return 0;
}
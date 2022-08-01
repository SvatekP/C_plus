#include <iostream>
#include <string>
using std::string;

class AbstractEmployee {
    virtual void AskForPromotion()=0; // Abstract function, if you sign AbtractEmployee you have to AskForPromotion
};

class Employee:AbstractEmployee {
private:
    string Name;
    string Company;
    int Age;
public:
void setName(string name) { // Setter
    Name = name;
    }
    string getName() { // Getter
        return Name;
    }

void setCompany(string company) {
    Company = company;
    }
    string getCompany() {
        return Company;
    }

void setAge(int age) {
    if (age>=18) // Only if 18+
    Age = age;
    }
    int getAge() {
        return Age;
    }
    
    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }

    void AskForPromotion() {
        if (Age > 30)
            std::cout << Name << " got promoted!" << std::endl;
        else
            std::cout << Name << " sorry, no promotion for you." << std::endl;
    }

    Employee(string name, string company, int age) { // Constructor
        Name = name;
        Company = company;
        Age = age;
    }

    virtual void Work() { // Virtual function, base class member function that you can redefine in a derived class to achieve polymorphism
        std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
    }
};

class Developer: public Employee { // Inheritance
    public:
        string FavProgrammingLanguage;
        Developer(string name, string company, int age, string favProgrammingLanguage) // Constructor
            :Employee(name, company, age) // Inheritance
        {
            FavProgrammingLanguage = favProgrammingLanguage;
        }
    void FixBug() {
        std::cout << getName() << " fixed bug using " << FavProgrammingLanguage << std::endl;
    }
    void Work() {
        std::cout << getName() << " is writing " << FavProgrammingLanguage << " code." << std::endl;
    }
};

class Teacher: public Employee {
    public:
    string Subject;
    void PrepareLesson() {
         std::cout << getName() << " is preparing " << Subject << " lesson." << std::endl;
     }
    Teacher(string name, string company, int age, string subject)
        :Employee(name, company, age)
    {
        Subject = subject;
    }
    void Work() {
        std::cout << getName() << " is teaching " << Subject << std::endl;
    }
};


int main(){
/*  CONSTRUCTED
    Employee employee1;
    employee1.Name = "Pavel";
    employee1.Company = "Digiteq";
    employee1.Age = 23;
    employee1.IntroduceYourself();

    Employee employee2;
    employee2.Name = "Tania";
    employee2.Company = "Honeywell";
    employee2.Age = 22;
    employee2.IntroduceYourself();
*/
    Employee employee1=Employee("Pavel", "Digiteq", 23);
    employee1.IntroduceYourself();

    Employee employee2=Employee("Tania", "Honeywell", 22);
    employee2.IntroduceYourself();

    employee1.setAge(35);
    std::cout << employee1.getName() << " is " << employee1.getAge() << " years old" << std::endl;

    Developer developer1=Developer("John", "Microsoft", 34, "C++");

    Teacher teacher1=Teacher("Ken", "Cambridge", 40, "Math");

    developer1.FixBug();
    developer1.AskForPromotion();

    employee1.AskForPromotion();
    employee2.AskForPromotion();

    teacher1.PrepareLesson();

    developer1.Work();
    teacher1.Work();

    Employee *e1 = &developer1; // Virtual function
    Employee *e2 = &teacher1;

    e1->Work(); // Virtual function
    e2->Work();
}
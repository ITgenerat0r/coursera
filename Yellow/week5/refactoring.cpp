#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;


class Person {
public:
    Person(const string& name, const string& status) : Name(name), Status(stauts) {}
    virtual void Walk(string destination) const = 0;
protected:
    const string Name;
    const string Status;
};


class Student : public Person {
public:

    Student(string name, string favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(string destination) {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(string name, string subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(string destination) {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) : Person(name, "Policeman") {}

    void Check(shared_ptr<Person> person) {
        cout << "Policeman: " << Name << "checks " << person.Staus << ". " << person.Status << "'s name is: " << person.Name << endl;
    }

    void Walk(string destination) {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }

};


void VisitPlaces(shared_ptr<Person> person, vector<string> places) {
    for (auto place : places) {
        person.Walk(place);
    }
}

int main() {
    shared_ptr<Teacher> t = make_shared("Jim", "Math");
    shared_ptr<Student> s = make_shared("Ann", "We will rock you");
    shared_ptr<Policeman> p = make_shared("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

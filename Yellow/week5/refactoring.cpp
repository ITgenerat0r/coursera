#include <iostream>
#include <string>
#include <vector>
#include <memory>


using namespace std;


class Person {
public:
    Person(const string& name, const string status) : Name(name), Status(status) {}
    virtual void Walk(const string& destination) const = 0;
    virtual void SingSong() const {};
    virtual void Learn() const {};
    virtual void Check(const shared_ptr<Person> person) const {};
    virtual void Teach() const {};

// protected:
    const string Name;
    const string Status;
};


class Student : public Person {
public:

    Student(const string name, const string favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << Name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << Name << " walks to: " << destination << endl;
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const {
        cout << "Student: " << Name << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string name, const string subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() const {
        cout << "Teacher: " << Name << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Teacher: " << Name << " walks to: " << destination << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string name) : Person(name, "Policeman") {}

    void Check(const shared_ptr<Person> person) const {
        cout << "Policeman: " << Name << "checks " << person->Status << ". " << person->Status << "'s name is: " << person->Name << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Policeman: " << Name << " walks to: " << destination << endl;
    }

};


void VisitPlaces(shared_ptr<Person> person, vector<string> places) {
    for (auto place : places) {
        person->Walk(place);
    }
}

int main() {
    shared_ptr<Person> t = make_shared<Teacher>("Jim", "Math");
    shared_ptr<Person> s = make_shared<Student>("Ann", "We will rock you");
    shared_ptr<Person> p = make_shared<Policeman>("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p->Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}

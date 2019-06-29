#include <iostream>
#include <string>

using namespace std;

#define BAD_NUM_BIL 5
#define GOOD_NUM_BIL 3
#define GOOD_FOR_STUDENT 4

enum SubjectProfessor {Math, Geom, Program};

class Human{
private:
    string name;
public:
    string GetName() {
        return this->name;
    }
    void SetName(string name){
        this->name = name;
    }
};

class Professor: public Human{
    SubjectProfessor Subject;
    bool MoodProf;
    int num;
public:
    Professor(string name,SubjectProfessor Subject){
        SetName(name);
        this->Subject = Subject;
    }

    SubjectProfessor GetSubject(){
        return this->Subject;
    }

    bool GetMood(){
        this->Subject = Subject;
        if (Subject == 1 || Subject == 2){
            MoodProf = true;
        }
        else{
        MoodProf = false;
        }
        return MoodProf;
    }

    void SetMood(bool mood){
        this-> MoodProf = mood;
    }

    void NumofQuest(int num) {
        this->num = num;
    }
};

class Student: public Human{
    int grade;
    int cheats;
    int NumCheat;
public:
    void SetNum(int num){
        this->NumCheat = num;
    }

    int GetNum(){
        return this->NumCheat;
    }

    void SetCheat(int cheats){
        this->cheats = cheats;
    }

    bool IsLucky(){
        if (GetCheat() == true){
            return true;
        }
        else return false;
    }

    int SetExcellentGrade(){
        return 5;
    }

    int SetGoodGrade(){
        return 4;
    }

    int SetBadGrade(){
        return 3;
    }

    void MoodGrade(int grade){
        this->grade = grade;
    }

    int GetMoodGrade(){
        return this->grade;
    }

private:
    bool GetCheat(){
        this->cheats = cheats;
        if (cheats > 0){
            return true;
        }
        else return false;
    }
};

class Print{
public:
    void printStudent(Student &s,Professor &p ){
        cout << s.GetName() << " is ";
        if (s.GetMoodGrade() >= 4){
            cout << "pleased ";
        }
        else cout << "not pleased ";

        cout << p.GetName() << "'s grade";
    }
    void printProfessor(Professor &p){
        cout << p.GetName() << " teacher today in a ";
        if (p.GetMood() == true){
            cout << "good mood" << endl;
        }
        else cout << "bad mood" << endl;
    }
};

void ListOfCommand() {
    cout << "Enter name professor and subject and name student" << endl;
    cout << "Press '1' if the subject is mathematics" << endl;
    cout << "Press '2' if the subject is geometry" << endl;
    cout << "Press '3' if the subject is programming" << endl;
}

int main() {
    ListOfCommand();
    string NameProf;
    string NameStud;
    int subj;
    cin >> subj;
    cin >> NameProf;
    cin >> NameStud;
    Professor prof(NameProf,SubjectProfessor(subj));
    Student st;
    st.SetName(NameStud);
    st.SetCheat(1);
    if (prof.GetMood() == true){
        prof.NumofQuest(GOOD_NUM_BIL);
    }
    else prof.NumofQuest(BAD_NUM_BIL);
    if (st.GetNum() <= GOOD_FOR_STUDENT && st.IsLucky()){
        st.MoodGrade(st.SetExcellentGrade());
    }
    else if (st.GetNum() <= GOOD_FOR_STUDENT && !st.IsLucky()){
        st.MoodGrade(st.SetGoodGrade());
    }
    else st.MoodGrade(st.SetBadGrade());
    Print p;
    p.printProfessor(prof);
    p.printStudent(st, prof);
    return 0;
}
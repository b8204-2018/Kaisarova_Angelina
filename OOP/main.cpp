#include <iostream>
#include <string>

using namespace std;

#define BAD_NUM_BIL 5
#define GOOD_NUM_BIL 3
#define GOOD_FOR_STUDENT 4


class Human{
private:
    string name;
public:
    string GetName(){
        return this->name;
    }
    void SetName(string name){
        this->name = name;
    }
};

class Professor: public Human{
    bool MoodProf;
    int num;
public:
    void SetMood(bool mood){
        this-> MoodProf = mood;
    }

    bool GetMood(){
        return MoodProf;
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
    void printStudent(Student &s){
        cout << s.GetName() << " is ";
        if (s.GetMoodGrade() >= 4){
            cout << "pleased ";
        }
        else cout << " not pleased ";
        cout << "his grade";
    }
    void printProfessor(Professor &p){
        cout << p.GetName() << " today in a ";
        if (p.GetMood() == true){
            cout << "good mood" << endl;
        }
        else cout << "bad mood" << endl;
    }
};

int main() {
    Professor prof;
    prof.SetMood(true);
    prof.SetName("Ivan Ivanovich");
    Student st;
    st.SetName("Ilya");
    st.SetCheat(2);
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
    p.printStudent(st);
    return 0;
}
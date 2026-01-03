#include<bits/stdc++.h>
#include<fstream>
using namespace std;

struct student
{
    /* data */
    string name;
    int marks[5];
    int total;
    float average;
    char grade;
};

void calculatemarks(student &s){
    s.total=0;
    for(int i=0;i<5;i++){
        s.total+=s.marks[i];
    }

    s.average=s.total/5.0;

    if(s.average >= 90) s.grade='A';
    else if(s.average >= 80 && s.average<90) s.grade='B';
    else if(s.average >= 70 && s.average < 80) s.grade='C';
    else if(s.average >=60 && s.average < 70) s.grade='D';
    else if(s.average >=50 && s.average<60) s.grade='E';
    else s.grade='F';
}

void addStudent(){
    student s;
    ofstream fout("exam.txt", ios :: app);

    if(!fout.is_open()){
        cout << "Failed to open" << endl;
        return;
    }

    cin.ignore();
    cout << "Enter student name" << endl;
    getline(cin, s.name);


    cout << "Enter 5 marks subject" << endl;
    for(int i=0;i<5;i++){
        cin >> s.marks[i];
    }

    calculatemarks(s);
    fout << s.name <<" ";
    for(int i=0;i<5;i++) fout << s.marks[i] << " ";
    fout << endl;
    fout << s.total << " " << s.average << " " << s.grade << endl;
    

    fout.close();
    cout << "Successfully student data added " << endl;

}

void display(){
    student s;
    ifstream fin("exam.txt");

    if(!fin.is_open()){
        cout << "Unable to open file\n";
        return;
    }

    cout << "\n--- Student Records ---\n";

    while (fin >> s.name
           >> s.marks[0] >> s.marks[1] >> s.marks[2]
           >> s.marks[3] >> s.marks[4]
           >> s.total >> s.average >> s.grade) {

    cout << "Student name: " << s.name << endl;
    cout << "MARKS: ";
    for(int i=0;i<5;i++) cout << s.marks[i] << " ";
    cout << "\nTotal: " << s.total;
    cout << "\nAverage: " << s.average;
    cout << "\nGrade: " << s.grade << endl;
    cout << "---------------------\n";
}
fin.close();
}


int main(){
    int choice;
    while(true){
        cout << "1. Adding new student data" << endl;
        cout << "2. Reading all the students data" << endl;
        cout << "3. Exit from the program" << endl;
        cout << "Enter your choice" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            display();
            break;
        case 3:
            cout << "Exit from the program" << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
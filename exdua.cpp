#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
    
};
const int n = 20;
int indexing = 0;
studentType studentArray [20];
void inputData(studentType& student){
    cout<<"Masukkan nama depan siswa : "<<endl;
    getline(cin,student.studentFName);
    cout<<"Masukkan nama belakang siswa : "<<endl;
    getline(cin,student.studentLName);

    //Nilai
    cout << "Masukkan nilai tes (0-100): ";
    cin >> student.testScore;
    if (student.testScore <0 or student.testScore>100){
        cout << "cuman boleh 0-100 ihh"<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        inputData (student); 
        return;//buat ngulangin fungsinya
    }
}

void readData(studentType* Array){
    int index = 0;
    string input;
    for (int i=0; i<n;i++){
        cout << "Student "<<i+1<<endl;
        inputData(Array[i]);
        cout << "Mau lagi/tidak : ";
        cin >> input;
        index++;
        cin.ignore();
        if (input != "lagi"){
            break;
        }
    }
    indexing = index;
}
void inputGrade(studentType* Array){
    for (int i=0;i<indexing;i++){
        if (studentArray[i].testScore >=79){
            studentArray[i].grade='A';
        }
        else if (studentArray[i].testScore >=73){
            studentArray[i].grade='B';
        }
        else if (studentArray[i].testScore >=60){
            studentArray[i].grade='C';
        }
        else if (studentArray[i].testScore >= 50){
            studentArray[i].grade='D';
        }
        else{
            studentArray[i].grade='E';
        }
    }
}

void topScore (studentType* Array){
    if (indexing<=0) 
        return;
    int topTemp = 0;
    for (int i=0;i<indexing;i++){
        if (studentArray[i].testScore > studentArray[topTemp].testScore){
            topTemp = i;
        }
    }
    cout<< "Nilai tertinggi adalah "<<studentArray[topTemp].testScore<<endl;
}

void topScorer (studentType* Array){
    if (indexing<=0)
        return;
    int topTemp = 0;
    for (int i=0;i<indexing;i++){
        if (studentArray[i].testScore > studentArray[topTemp].testScore){
            topTemp = i;
        }
    }
    cout << "Siswa dengan nilai tertinggi adalah "
    <<studentArray[topTemp].studentLName<<", "<<studentArray[topTemp].studentFName<<endl;
}
void displayStudent (studentType* Array){
    inputGrade(studentArray);
    for (int i=0;i<indexing;i++){
        cout << "Siswa "<<i+1<<endl;
        cout << "Nama siswa : "<<studentArray[i].studentLName << ", "<<studentArray[i].studentFName
        << "\n"<<"Nilai ujian : "<<studentArray[i].testScore
        <<"\n"<<"Grade : "<<studentArray[i].grade<<endl;
    }
}

int main (){
    readData(studentArray);
    cout << "===============OUTPUTTTTT==============="<<endl;
    displayStudent(studentArray);
    topScore(studentArray);
    topScorer(studentArray);
    return 0;
}
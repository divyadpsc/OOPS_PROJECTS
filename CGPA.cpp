// Code to Calculate Cgpa when cgpa array is given
#include <iostream>
using namespace std;

class CGPA {
    int cgpaArray[8];

public:
    void setCgpaArray(int arr[]) {
        for (int i = 0; i < 8; i++) {
            cgpaArray[i] = arr[i];
        }
    }

    void printCgpaArray() {
        for (int i = 0; i < 8; i++) {
            cout << "Semester " << i + 1 << ": " << cgpaArray[i] << endl;
        }
    }
    void calculateCgpaArray(int arr[]){
        int sum=0;
        for(int i=0;i<8;i++){
            sum+=arr[i];
        }
       cout<<"cgpa is"<<sum/8<<endl;
    }
};

int main() {
       CGPA student;
    int inputCgpas[8];

    cout << "Enter CGPA for 8 semesters:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << "Semester " << i + 1 << ": ";
        cin >> inputCgpas[i];
    }


    student.setCgpaArray(inputCgpas);
    student.printCgpaArray();
    student.calculateCgpaArray(inputCgpas);

    return 0;
}

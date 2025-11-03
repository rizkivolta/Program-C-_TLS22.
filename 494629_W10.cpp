#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// ================== STRUCT DEFINITION ==================
struct studentType {
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

// Jumlah siswa dalam kelas
const int NO_OF_STUDENTS = 20;

// ================== FUNCTION PROTOTYPES ==================
void getData(studentType students[], int size);
void assignGrade(studentType students[], int size);
int highestScore(const studentType students[], int size);
void printHighest(const studentType students[], int size, int highest);
void printAll(const studentType students[], int size);

// ================== MAIN FUNCTION ==================
int main() {
    studentType students[NO_OF_STUDENTS];
    int highest;

    getData(students, NO_OF_STUDENTS);
    assignGrade(students, NO_OF_STUDENTS);
    highest = highestScore(students, NO_OF_STUDENTS);

    cout << "\n=========================================\n";
    cout << "LIST DATA NILAI SISWA\n";
    cout << "=========================================\n";
    printAll(students, NO_OF_STUDENTS);

    cout << "\n-----------------------------------------\n";
    cout << "SISWA DENGAN NILAI TERTINGGI:\n";
    printHighest(students, NO_OF_STUDENTS, highest);

    return 0;
}

// ================== FUNCTION DEFINITIONS ==================

// (a) Membaca data siswa
void getData(studentType students[], int size) {
    cout << "Masukkan data siswa (FirstName LastName Nilai):\n";
    for (int i = 0; i < size; i++) {
        cout << "Siswa ke-" << i + 1 << ": ";
        cin >> students[i].studentFName >> students[i].studentLName >> students[i].testScore;
    }
}

// (b) Menentukan grade berdasarkan nilai
void assignGrade(studentType students[], int size) {
    for (int i = 0; i < size; i++) {
        int score = students[i].testScore;
        if (score >= 90)
            students[i].grade = 'A';
        else if (score >= 80)
            students[i].grade = 'B';
        else if (score >= 70)
            students[i].grade = 'C';
        else if (score >= 60)
            students[i].grade = 'D';
        else
            students[i].grade = 'F';
    }
}

// (c) Menemukan nilai tertinggi
int highestScore(const studentType students[], int size) {
    int highest = students[0].testScore;
    for (int i = 1; i < size; i++) {
        if (students[i].testScore > highest)
            highest = students[i].testScore;
    }
    return highest;
}

// (d) Menampilkan siswa dengan nilai tertinggi
void printHighest(const studentType students[], int size, int highest) {
    for (int i = 0; i < size; i++) {
        if (students[i].testScore == highest) {
            cout << left << setw(15) << students[i].studentLName + ", " + students[i].studentFName
                 << "  Nilai: " << highest
                 << "  Grade: " << students[i].grade << endl;
        }
    }
}

// (e) Menampilkan semua data siswa
void printAll(const studentType students[], int size) {
    cout << left << setw(20) << "Nama"
         << setw(10) << "Nilai"
         << setw(10) << "Grade" << endl;
    cout << "-----------------------------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(20)
             << (students[i].studentLName + ", " + students[i].studentFName)
             << setw(10) << students[i].testScore
             << setw(10) << students[i].grade << endl;
    }
}

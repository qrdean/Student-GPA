//Quinton Dean
//Lab 4 - Student GPA

/* this is the same as the previous lab but using struct for student
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#include "\getline.h"

struct student
{
    string cLog;
    string cStu;
    string grades;
    string semester;
    int pthours
    int pts
    float credits
    float stuid
    string coursid[5];
    string grade[5];

};
int main()
{
    student sc;
    int pthours, pts, i=0;              // i is counter
    float gpa;
    ifstream course;
    ifstream students;
    string junk, cLog, cStu, grades, semester; //cLog is coursID for course.txt; cStu = courseID for student.txt;
    float credits, stuid, creditTotal=0, pointTotal =0, pthoursTotal =0;
    course.open("course.txt");
    students.open("student.txt");
    vector <string> courseid(5);
    vector <string> grade(5);
    if(! course.is_open())
    {
        cout << "Can not open file 'course'";
        return 10;
    }
    if(! students.is_open())
    {
        cout << "Can not open file 'students'";
        return 10;
    }
    getline(course, junk);               //pre-read
    course >> sc.cLog >> sc.credits;
    getline(students, junk);
    students >> sc.stuid >> sc.cStu >> sc.semester >> sc.grades;
    while(!students.eof())
    {

        if(i > Student.size())
        {
          Student.push_back();
        }

        if(sc.cStu==sc.cLog)
        {
          sc.courseid(i) = sc.cStu;

        if(sc.grades=="A")
        {
            sc.grade(i)=sc.grades;
            sc.pts = 4;
        }
        if(sc.grades=="B")
        {
            sc.grade(i)=sc.grades;
            sc.pts = 3;
        }
        if(grades=="C")
        {
            grade.at(i)=grades;
            pts = 2;
        }
        if(grades=="D")
        {
            grade.at(i)=grades;
            pts = 1;
        }
        if(grades=="F")
        {
            grade.at(i)=grades;
            pts = 0;
        }
        creditTotal=credits+creditTotal; // sum of hours
        pthours = pts*credits;            // calculation for points * hours
        pthoursTotal = pthours+pthoursTotal;   // sum of calculated points * hours
        i++;
        course >> cLog >> credits;
        students >> stuid >> cStu >> semester >> grades;
        }
        else
        {
            course >> cLog >> credits;
        }

    }

    gpa = pthoursTotal/creditTotal;
    cout << "Student GPA" << '\n' << '\n' << "Course ID" << setw(10) << "Grade" << '\n' << '\n';
    for(int j=0; j<=grade.size(); j++)
    {
        cout << Students.at(j) << setw(10) << grade.at(j) << '\n';
    }
    cout << "The Student GPA is " << gpa;
    return 0;
}

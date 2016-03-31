//Quinton Dean
//Lab 3 - Student GPA

/* This lab calculates Student GPA from a letter grade and displays it on screen
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;
#include "\getline.h"

int main()
{
    int pthours, pts, i=0;                                      // i is counter
    float gpa;
    ifstream course;
    ifstream students;
    string junk, cLog, cStu, grades, semester;                  //cLog is coursID for course.txt; cStu = courseID for student.txt;
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
    course >> cLog >> credits;
    getline(students, junk);
    students >> stuid >> cStu >> semester >> grades;
    while(!students.eof())
    {


        if(i > courseid.size())
        {
          courseid.resize(i);
        }
        if(i > grade.size())
        {
          grade.resize(i);
        }
        if(cStu==cLog)
        {
          courseid.at(i) = cStu;

        if(grades=="A")
        {
            grade.at(i)=grades;
            pts = 4;
        }
        if(grades=="B")
        {
            grade.at(i)=grades;
            pts = 3;
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
        cout << courseid.at(j) << setw(10) << grade.at(j) << '\n';
    }
    cout << "The Student GPA is " << gpa;
    return 0;
}

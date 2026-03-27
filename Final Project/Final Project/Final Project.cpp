
#include <iostream>
#include"person.h"
#include"student.h"
#include <map>
#include <vector>
#include <set>
#include<algorithm>
#include<cctype>
#include <fstream>
using namespace std;

void save_to_file( Student std) {
    ofstream outFile("Studenst_data.txt",std ::ios ::app);
    if (!outFile) {
        cout << "Error opening file for saving!" << endl;
        return;
    }
    outFile
            << std.get_name() << "|"
            << std.get_ID() << "|"
            << std.get_gpa() << "|";
    std.Save_courses_to_file();
    set<string> studentCourses = std.Save_courses_to_file();
    for (const string& course : studentCourses) {outFile << course << " ";}
    outFile <<endl <<endl;
    outFile.close();
    cout << "Data saved to file successfully." << endl;
}

int main()
{
    vector <Student> db;
    map <int, string> options;
    map <int, string> sorted_students;
    

    options = {
        {1,"Add Student"},
        {2,"Remove Student"},
        {3,"Search Student"},
        {4,"Display All Students"},
        {5,"Enroll Student in Course"},
        {6,"Show Student Courses"},
        {7,"Sort Students by GPA"},
        {8,"Exit"},
    };

    char op;
    bool start = true;
    string name;
    string course;
    int id_counter = 0;
    float gpa;
    set <float,greater<float>> sorted;

    while (start) {
        cout << "------------------------" << endl;
        cout << "-    Choose an option  -" << endl;
        cout << "------------------------" << endl;

        for (auto x: options) {
            cout << x.first<<" "<< x.second << endl;
        }

        cin >> op;
        cin.ignore();
        
        switch (op) {

            case '1': 
            {
                cout << "Enter student's name: " << endl;
                getline(cin, name);
                cout << "Enter student's gpa: " << endl;
                cin >> gpa;
                if(gpa>=0.0 && gpa<=4.0)
                {
                    Student std(name, gpa, id_counter);
                    id_counter++;
                    db.push_back(std);

                    cout << "Student added!" << endl;
                    save_to_file(std);
                    break;
                }
                cout << "Invalid gpa try again!" << endl;
                break;
               
                
            }

            case '2': 
            {
                cout << "Enter student's name: " << endl;
                getline(cin, name);
                for (int i = 0; i < db.size(); i++) 
                {
                    if (db[i].get_name() == name) 
                    {
                        db.erase(db.begin() + i);
                        cout << "Student removed!" << endl;
                        break;
                    }
                    
                }
                break;
            }

            case '3':
            {
                char what;
                cout << "By what?  0:name,  1:GPA, 2:id" << endl;
                cin >> what;
                cin.ignore();
                if (what == '0')
                {
                    cout << "Enter student's name: " << endl;
                    getline(cin, name);
                    for (int i = 0; i < db.size(); i++)
                    {
                        if (db[i].get_name() == name)
                        {
                            db[i].Display_student();
                            break;
                        }
                        
                    }
                }
                else if (what == '1')
                {
                    cout << "Enter student's gpa: " << endl;
                    cin >> gpa;
                    for (int i = 0; i < db.size(); i++)
                    {
                        if (db[i].get_gpa() == gpa)
                        {
                            db[i].Display_student();
                            
                        }
                        
                    }
                }
                else if (what == '2')
                {
                    int id=0;
                    cout << "Enter student's ID: " << endl;
                    cin >> id;
                    for (int i = 0; i < db.size(); i++)
                    {
                        if (db[i].get_ID() == id)
                        {
                            db[i].Display_student();
                            break;
                        }
                        
                    }
                }
                break;
            }

            case '4':
            {
                for (int i = 0; i < db.size(); i++)
                {
                    db[i].Display_student();
                }
                break;
            }

            case '5':
            {
                cout << "Enter student's name: " << endl;
                getline(cin, name);
                cout << "Enter course's name: " << endl;
                getline(cin, course);
                for (int i = 0; i < db.size(); i++)
                {
                    if (db[i].get_name() == name)
                    {
                        db[i].set_Course(course);
                        cout << "Course added! " << endl;
                        save_to_file(db[i]);
                        break;
                    }
                    
                }

                break;
            }

            case '6':
            {
                cout << "Enter student's name: " << endl;
                getline(cin, name);
                for (int i = 0; i < db.size(); i++)
                {
                    if (db[i].get_name() == name)
                    {
                        db[i].get_Courses();
                        break;
                    }
                    
                }

                break;
            }
            case '7':
            {
                if (db.empty()) 
                {
                    cout << "No students to sort!" << endl;
                    break;
                }
                sort(db.begin(), db.end(), [](Student& a, Student& b) 
                {
                    return a.get_gpa() > b.get_gpa(); 
                });

                cout << "Students sorted by GPA (Highest to Lowest):" << endl;
                for (int i = 0; i < db.size(); i++) 
                {
                    cout << i + 1 << "Name: " << db[i].get_name()<< " | GPA: " << db[i].get_gpa() << endl;
                }

                break;
            }
            case '8':
            {
                cout << "BYE!" << endl;
                start = false;
                break;
            }
            default:
            {
                cout << "Invalid opion please try again" << endl;
                break;
            }
        }
    }
}
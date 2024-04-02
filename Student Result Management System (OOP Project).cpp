#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

class Person
{
public:
    string name;
    string fatherName;
    string roll_no;
    string id;
    string district;
    string subject[6];   
};

class Admin;
class Result;
class Student : virtual public Person
{
    private:
        string roll_no;
    public:
		void student_detail(string n, string f_n, string dist, string i_d, string r_no);
	    void student_display();
	    void student_subject(string st[]);
	    friend void display_result(Student , Admin, Result);
};

class  Admin : virtual public Person
{
	private:
	    float perScore[6] , percentage;
	    string overall_grade, designation, status_result[6], grade[6];
	public:
		float total_obt = 0 ,total_max = 0, obt_marks[6];
	public:
		float max_marks[6] = {200, 200, 200, 200, 100, 200};
	    void admin_detail(string n, string f_n , string design, string i_d, string dist);
	    void student_marks( float mark[]);
	    void Admin_display();
	    void rel_status();
	    void per_score();
	    void status();
	    void student_percentage();
	    friend void display_result(Student , Admin, Result);
};

class Result :  public Admin, public Student
{
    public:
	    friend void display_result(Student , Admin, Result);  
};

void Student::student_detail(string n, string f_n, string dist, string i_d, string r_no)
{
    name = n;
    fatherName = f_n;
    district = dist;
    id = i_d;
    roll_no = r_no;
}

void Student::student_display()
{
    ofstream student;
    student.open("result.txt", ios::app);
    student << "Name : " << name << endl;
   	student << "Roll No : " << roll_no  << endl;
    student << "Son/Daughter of : " << fatherName << endl;
    student << "Registration No : " << id << endl;
    student << "District : " << district << endl;
    student.close();
}

void Student::student_subject(string st[])
{
    for (int i = 0; i < 6; i++)
    {
        subject[i] = st[i];
    }
}

void Admin::admin_detail(string n, string f_n , string design, string i_d, string dist)
{
    name = n;
    fatherName = f_n;
    district = dist;
    id = i_d;
    designation = design;
}

void Admin::Admin_display()
{
	ofstream admin;
    admin.open("result.txt", ios::app);
    admin << "Name : " << name << endl;
    admin << "Father Name : " << fatherName << endl;
    admin << "District : " << district << endl;
    admin << "Designation : " << designation << endl;
    admin << "ID : " << id << endl;
    admin.close();
}

void Admin::student_marks(float mark[])
{
    for (int i = 0; i < 6; i++)
    {
        obt_marks[i] = mark[i];
    }
}

void Admin::rel_status()
{
	for (int i=0; i<6; i++)
	{
		if (perScore[i] >= 85)
		{
			grade[i] = "A";
		}
		else if (perScore[i] >=80)
		{
			grade[i] = "A-";
		}
		else if (perScore[i] >=75)
		{
			grade[i] = "B+";
		}
		else if (perScore[i] >=70)
		{
			grade[i] = "B";
		}
		else if (perScore[i] >=65)
		{
			grade[i] = "C+";
		}
		else if (perScore[i] >=60)
		{
			grade[i] = "C";
		}
		else if (perScore[i] >=50)
		{
			grade[i] = "D";
		}
		else if (perScore[i] < 50 )
		{
			grade[i] = "F";
		}
		
	}
}

void Admin :: per_score()
{
	for (int i=0; i<6; i++)
	{
		perScore[i] = (obt_marks[i] / max_marks[i] ) * 100;
	}
}

void Admin:: student_percentage()
{
	for (int i=0; i<6; i++)
	{
		total_obt = total_obt + obt_marks[i];
		total_max = total_max + max_marks[i];
	}
	percentage = (total_obt / total_max) * 100;
	if (percentage >= 85)
	{
		overall_grade = "A";
	}
	else if (percentage >=80)
	{
		overall_grade = "A-";
	}
	else if (percentage >=75)
	{
		overall_grade = "B+";
	}
	else if (percentage >=70)
	{
		overall_grade = "B";
	}
	else if (percentage >=65)
	{
		overall_grade= "C+";
	}
	else if (percentage >=60)
	{
		overall_grade = "C";
	}
	else if (percentage >=50)
	{
		overall_grade = "D";
	}
	else if (percentage < 50 )
	{
		overall_grade = "F";
	}
}

void Admin :: status()
{
	for (int i=0; i<6; i++)
	{
		if (grade[i] == "F")
		{
			status_result[i] = "FAIL";
		}
		else if (grade[i] != "F")
		{
			status_result[i] = "PASS";
		}
	}
}

void display_result(Student s, Admin a, Result r)
    {
    	ofstream heading;
    	heading.open("result.txt", ios::app);
    	for (int i=0; i<90; i++)
    	{
    		heading <<"*";
		}
		heading << endl;
    	heading.setf(ios::left);
        heading <<setw(20) << "SUBJECT";
		heading <<setw(15) << "MAX.MARKS";
		heading <<setw(15) << "OBT.MARKS";
		heading <<setw(15) << "%PER.SCORE";
		heading <<setw(15) << "REL.GRADE";
		heading <<setw(15) << "STATUS";  
		heading << endl;
		for (int i=0; i<90; i++)
    	{
    		heading <<"*";
		}
		heading << endl;
		heading.close();
		ofstream result;
		result.open("result.txt", ios::app);
        for (int i = 0; i < 6; i++)
        {
        result.setf(ios::left);
        result <<setw(20) << r.subject[i];
		result <<setw(15) << r.max_marks[i];
		result <<setw(15) << r.obt_marks[i];
		result <<setw(15) << r.perScore[i];
		result <<setw(15) << r.grade[i]; 
		result <<setw(15) << r.status_result[i]; 
		result << endl; 
        }
        for (int i=0; i<90; i++)
    	{
    		result <<"*";
		}
		result << endl;
		result.setf(ios::left);
        result <<setw(20) << "TOTAL MARKS";
		result <<setw(15) << r.total_max;
		result <<setw(15) << "OBTAINED MARKS";
		result <<setw(15) << r.total_obt;
		result <<setw(15) << "GRADE"; 
		result <<setw(15) << r.overall_grade;
		result << endl; 
		for (int i=0; i<90; i++)
    	{
    		result <<"*";
		}	
		result.close();	
    }

int main()
{
	   cout <<"If you want to see the result on screen say 'yes', if you want to enter the new student result card then say 'no' \n\n";
    string choice;
    cin >> choice;
    if(choice == "yes")
    {
	    string line;
	    system("cls");
	    ifstream console;
	    console.open("result.txt", ios::app);
	    while (console.eof() == 0)
	    {
	    	getline(console, line);
	    	cout <<line << endl;
		}
		console.close();
     }
     else
     {
	    Student  *s_set;
	    s_set = new Student;
	    Student *s_disp = s_set;
	    Admin *adm_set;
	    adm_set = new Admin;
	    Admin *adm_disp = adm_set;
	    Student s;
	    Admin a;
	    Result r;
	    ofstream display;
	    display.open("result.txt", ios::app);
	    s_set->student_detail("Irfan Shakil", "Shakil Ahmad", "Punjab College Raiwind", "35202-5005042-9", "557519");
	    adm_set->admin_detail("Abdul Muqeet", "Sajid Ali", "Head of Department", "35202-2366034-2", "Punjab College Raiwind");
	
	    display << "\nAdmin Data: " << endl << endl;
	    adm_disp->Admin_display();
	
	    float m[6] ;
	    string st[6] = {"English", "Math", "Chemistry", "Urdu", "Islamiyat", "Physice"};
	   
	    cout << endl << endl;
	    for (int i=0; i<6; i++)
	    {
	    	cout <<"Obtaining Marks of ( " << st[i] <<" ) : ";
	    	cin >> m[i];
		}
		system ("cls");
	
		display << "Student Intermediate Result: "  << endl << endl;
	    s_disp->student_display();
	
	    r.student_marks(m);
	    r.student_subject(st);
	    r.per_score();
	    r.rel_status();
	    r.per_score();
	    r.student_percentage();
	    r.status();
	
	    display << "\nSecond Year Result Card  Pre Engineering Student\n\n";
	    display_result(s, a, r);
	    cout <<"\n\nStudent Result Card Successfully Displayed....";
	 }

 
    return 0;
}

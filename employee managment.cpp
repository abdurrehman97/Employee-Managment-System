#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std ;

class Employee {
	
private:		
	
	int employee_id;
	string employee_name;
	string employee_post;
	string employee_department;
	int employee_salary;
	
public:
	
	void employee_manu(){
		int ch;
		cout << endl<<endl<<endl<<endl<<endl ; 
		cout << " \t\t\t ///////////////////// " << endl ;
		cout << " \t\t\t //// Welcome ///////" << endl ;
		cout << " \t\t\t //////////////////// " << endl ;
		cout << "\n\n\n 1.Sign up: ";
		cout << "\n\n\n 2.Display Record: ";
		cout << "\n\n\n 3.Search record: ";
		cout << "\n\n\n 4.Modify Record: ";
		cout << "\n\n\n 5.Delete Record: ";
		cout<< "\n\n\n Enter Your Choice: ";
		cin>>ch;
		switch (ch) {
			case 1:
				insert(); 
				break;
			case 2:
				display();
				break;
			case 3:
				search ();
				break;
			case 4:
				modify();
				break;
			case 5:
				trash();
				break;
		default:
			cout<<"\n\n\n Invalid Value:";
		}
	}
	
	void insert(){
		
		fstream file;
		int age,emp_id,emp_salary;
		string emp_name,emp_post,employee_department,username,password,roll,addr;
		cout << "\n\n\n\n\t\t\t\t  Sign up ";
		cout << "\n\n\n\n\t\t\t\t  Enter Username: ";
		cin>>username;
		cout << "\n\n\n\n\t\t\t   Enter Password: ";
		cin>>password;
		cout<<"\n\n\n\n\t\t\t\t  Enter Your Roll: ";
		cin>>roll;
		cout << "\n\n\n Enter Employee ID: ";
		cin>>emp_id;
		cout << "\n\n\n Enter Employee Name: ";
		cin>>emp_name;
		cout << "\n\n\n Enter Employee Age: ";
		cin>>age;
		cout << "\n\n\n Enter Employee Address: ";
		cin>>addr;
		cout << "\n\n\n Enter Employee Post: ";
		cin>>emp_post;
		cout << "\n\n\n Enter Employee Department: ";
		cin>>employee_department;
		cout << "\n\n\n Enter Employee Salary: ";
		cin>>emp_salary;
		file.open("emp.txt",ios::out|ios::app);
		file << username << "\t" << password << "\t" << roll << "\t" << emp_id << "\t" << emp_name << "\t" << age << "\t" << addr << "\t" << emp_post << "\t" << employee_department <<"\t" << emp_salary << "\n";
		file.close();
		cout<< "\n\n\n Record Added Sucessfully....";
	}
	
	void display(){
		
		fstream file;
		int age,emp_id,emp_salary;
		string emp_name,emp_post,emp_department,roll,addr;
		file.open("emp.txt",ios::in);
		while(!file.eof()){
			file >> roll >> emp_id >> emp_name >> age >> addr >> emp_post >> emp_department >> emp_salary;
			cout << "\n\n\n Roll:"<<roll ;
			cout << "\n\n\n Employee ID:"<<emp_id ;
			cout << "\n\n\n Employee Name:"<<emp_name ;
			cout << "\n\n\n Employee Age:"<<age ;
			cout << "\n\n\n Employee Address:"<<addr ;
			cout << "\n\n\n Employee Post:"<<emp_post ;
			cout << "\n\n\n Employee Department:"<<emp_department ;
			cout << "\n\n\n Employee Salary:"<<emp_salary ;		
		}
		file.close();
	}
	
	void search (){
		
		fstream file;
		int search_id;
		int emp_id,emp_salary;
		string emp_name,emp_post,emp_department,roll,username,password;
		
		file.open("emp.txt",ios::in);
		cout<< "\n\n\n Enter Employee ID: ";
		cin>>search_id;
			while(!file.eof()){
				file >> username  >> password >> roll >> emp_id >> emp_name >> emp_post >> emp_department >> emp_salary;
				if (search_id==emp_id){
				cout << "\n\n\n Roll:"<<roll ;
				cout << "\n\n\n Employee ID:"<<emp_id ;
				cout << "\n\n\n Employee Name:"<<emp_name ;
				cout << "\n\n\n Employee Post:"<<emp_post ;
				cout << "\n\n\n Employee Department:"<<emp_department ;
				cout << "\n\n\n Employee Salary:"<<emp_salary ;	
			}
			file >> roll >> emp_id >> emp_name >> emp_post >> emp_department >> emp_salary;
		 }
		file.close();		
	}
	
	void modify(){
		
		fstream file;
		int emp_idd,found=0;
		int emp_id;
		int salary1,test_id;
		int emp_salary;
		string emp_name,emp_post,emp_department,addr,age,username,password,roll;

		cout << "\n\n\n Enter Employee ID for Modify: ";
		cin>>test_id;
		file.open("emp.txt",ios::out|ios::app);
		file >> username  >> password >> roll >> emp_id >> emp_name >> age >> addr >> emp_post >> emp_department >> emp_salary;
		while (!file.eof()){
			if (test_id==emp_id){
				cout << "\n\n\n Enter Employee Name: ";
				cin>>emp_name;
				cout << "\n\n\n Enter Employee Age: ";
				cin>>age;
				cout << "\n\n\n Enter Employee Department: ";
				cin>>addr;
				cout << "\n\n\n Enter Employee Address: ";
				cin>>emp_post;
				cout << "\n\n\n Enter Employee Department: ";
				cin>>employee_department;
				cout << "\n\n\n Enter Employee Salary: ";
				cin>>emp_salary;
				file << emp_id << " " << emp_name << " " << age << " " << addr << " " << emp_post << " " << employee_department <<" " << emp_salary;		
			}
			file >> username  >> password >> roll >> emp_id >> emp_name >> age >> addr >> emp_post >> emp_department >> emp_salary;
		}
		file.close();
		cout<<"\n\n\n Record Modified Sucessfully:....";
	}
	
	void trash(){
		
		fstream file;
		int emp_idd,found=0;
		int emp_id;
		int salary1,test_id;
		int emp_salary;
		string emp_name,emp_post,emp_department,addr,age,username,password,roll;
		
		cout << "\n\n\n Employee ID for delete: ";
		cin>>test_id;
		file.open("emp.txt",ios::in);
		file >> username  >> password >> roll >> emp_id >> emp_name >> age >> addr >> emp_post >> emp_department >> emp_salary;
		while (!file.eof()){
			if (test_id==emp_id){
				cout <<"\n\n\n Record is deleted successfully....!";		
			}
			else {
				file << username << " " << password << " " << roll << " " << emp_id << " " << emp_name << " " << age << " " << addr << " " << emp_post << " " << employee_department <<" " << emp_salary;	
			}
			file >> username  >> password >> roll >> emp_id >> emp_name >> age >> addr >> emp_post >> emp_department >> emp_salary;	
		}
		file.close();
	}
	
	void login () {
		
		fstream file;
		string username1,password1,roll,username,password;
		string admin = "admin";
		string emp = "emp";
		start:
		cout << endl<<endl<<endl<<endl<<endl ;
		cout << " \t\t\t   ////////////////////////////////// " << endl ;
		cout << " \t\t\t  /// Employee Managment System //// " << endl ;
		cout << " \t\t\t ////////////////////////////////// " << endl ;
		cout << "\n\n\n\n\t\t\t\t   Sign in " << endl;
		cout << "\n\n\n\n\t\t\t\t    Enter Username: ";
		cin>>username1;
		cout << "\n\n\n\n\t\t\t\t     Enter Password: ";
		cin>>password1;
		
		file.open("emp.txt",ios::in);
		while (!file.eof()){
			file  >> username  >> password >> roll;
			if (username1==username && password1==password && roll == admin){
			system("CLS");
			employee_manu();
			system("CLS");
			}
			
			if (username1!=username){
				cout<< "\n\n\n\n\t\t\t Your Username is incorrect: "; 
				Sleep(3000);
				goto start;
			}
			
			if (password1!=password){
				cout<< "\n\n\n\n\t\t\t Your Password is incorrect: ";
				Sleep(3000);
				goto start;
			}
			
		 	else if (roll != admin){
				cout << " \t\t\t ///////////////////// " << endl ;
				cout << " \t\t\t //// Welcome ///////" << endl ;
				cout << " \t\t\t //////////////////// " << endl ;	
			}
		}	
	}	
};

int main (){	
	Employee e;
	e.login();
  return 0;
}

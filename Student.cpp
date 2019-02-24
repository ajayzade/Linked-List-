#include<iostream>
#include<stdlib.h>
#include<strings.h>
using namespace std;
struct Node{
	int roll;
	char name[20];
	char gender;
	char dob[20];
	char number[10];
	int age;
	float percentage;
	Node* next;
};
struct Node* root = NULL;
class LinkedList{
	public :
		void ibeg();
		void iend();
		void iloc();
		int length();
		void displayAllStudents();
		void checkStudentData();
		void modifyStudentData();
		void deleteStudentData();
		void showInsert(){
			int c;
			cout << "**********INSERT NEW DATA**********";
			cout << "\n\n";
			cout << "1.Insert At Beginning\n";
			cout << "2.Insert At End\n";
			cout << "3.Insert After Location\n\n";
			cout << "Enter your choice : ";
			cin >> c;
			switch(c){
				case 1:
					ibeg();
					break;
				case 2:
					iend();
					break;
				case 3:
					iloc();
					break;
			}
		}
};
void LinkedList :: deleteStudentData(){
	system("cls");
	cout << "1.Delete by roll number\n";
	cout << "2.Delete by student name\n\n";
	int c,r,i = 1,cn = 0;
	char n[20];
	cin >> c;
	struct Node* temp = root;
	struct Node* p,*rq;
	if(c == 1){
		cout << "Enter roll number of student\n";
		cin >> r;
		while(temp != NULL){
			if(temp->roll == r){
				rq = root;
				while(rq != temp){
					cn++;
					rq = rq->next;
				}
				rq = root;
				while(i < cn){
					rq = rq->next;
					i++;
				}
				p = temp;
			}
			temp = temp->next;
		}
		rq->next = p->next;
		p->next = NULL;
	}else if(c == 2){
		cout << "Enter roll number of student\n";
		cin >> n;
		while(temp != NULL){
			if(strcmp(temp->name,n) == 0){
				rq = root;
				while(rq != temp){
					cn++;
					rq = rq->next;
				}
				rq = root;
				while(i < cn){
					rq = rq->next;
					i++;
				}
				p = temp;
			}
			temp = temp->next;
		}
		rq->next = p->next;
		p->next = NULL;
	}else{
		cout << "You have entered wrong choice\n";
	}
}
void LinkedList :: modifyStudentData(){
	system("cls");
	int r;
	cout << "Enter roll number of student to modify its data\n";
	cin >> r;
	struct Node* temp = root;
	while(temp != NULL){
		if(temp->roll == r){
			cout << "\nEnter Roll no. of Student : ";
	        cin >> temp->roll;
	        cout << "\nEnter Name of Student : ";
	        cin >> temp->name;
	        cout << "\nEnter Gender of Student : ";
	        cin >> temp->gender;
	        cout << "\nEnter date of birth of Student : ";
	        cin >> temp->dob;
	        cout << "\nEnter contact number of Student : ";
	        cin >> temp->number;
	        cout << "\nEnter Age of Student : ";
	        cin >> temp->age;
	        cout << "\nEnter Percentage of Student : ";
	        cin >> temp->percentage;
	        break;
		}
	}
	system("cls");
}
void LinkedList :: checkStudentData(){
	system("cls");
	int r,c;
	char n[20];
	cout << "1.Check by Roll number\n";
	cout << "2.Check by Student name\n";
	cin >> c;
	struct Node* p = root;
	if(c == 1){
		cout << "\nEnter the roll number of Student\n";
		cin >> r;
		while(p != NULL){
			if(r == p->roll){
				cout << "Student's Roll Number : " << p->roll << "\n";
				cout << "Student's Name : " << p->name << "\n";
				cout << "Student's Gender : " << p->gender << "\n";
				cout << "Student's Date of Birth : " << p->dob << "\n";
				cout << "Student's Mobile Number : " << p->number << "\n";
				cout << "Student's Age : " << p->age << "\n";
				cout << "Student's Percentage : " << p->percentage << "\n\n\n";
			}
			p = p->next;
		}
	}else if(c == 2){
		cout << "\nEnter the name of Student\n";
		cin >> n;
		while(p != NULL){
			if(strcmp(p->name,n) == 0){
				cout << "Student's Roll Number : " << p->roll << "\n";
				cout << "Student's Name : " << p->name << "\n";
				cout << "Student's Gender : " << p->gender << "\n";
				cout << "Student's Date of Birth : " << p->dob << "\n";
				cout << "Student's Mobile Number : " << p->number << "\n";
				cout << "Student's Age : " << p->age << "\n";
				cout << "Student's Percentage : " << p->percentage << "\n\n\n";
			}
			p = p->next;
		}
	}
}
void LinkedList :: displayAllStudents(){
	system("cls");
	cout << "********************All Students Data*********************";
	cout << "\n";
	cout << "\tStudent Roll\t  ";
	cout << "Student Name\t        ";
	cout << "Gender\t       ";
	cout << "DOB\t          ";
	cout << "Mobile No.\t   ";
	cout << "Age\t          ";
	cout << "Percentage\n\n  ";
	struct Node* p = root;
	while(p != NULL){
		cout << "\n";
		cout << "\t\t" << p->roll;
		cout << "\t\t" << p->name;
		cout << "\t\t" << p->gender;
		cout << "\t\t" << p->dob;
		cout << "\t\t" << p->number;
		cout << "\t\t" << p->age;
		cout << "\t\t" << p->percentage;
		cout << "\n";
		p = p->next;
	}
}
int LinkedList :: length(){
	struct Node* temp;
	int count = 0;
	temp = root;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
void LinkedList :: iloc(){
	system("cls");
	int i = 1,loc;
	cout << "Enter the Location after you want to insert data\n";
	cin >> loc;
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	cout << "\n\nInsert At Beginning\n";
	cout << "\nEnter Roll no. of Student : ";
	cin >> temp->roll;
	cout << "\nEnter Name of Student : ";
	cin >> temp->name;
	cout << "\nEnter Gender of Student : ";
	cin >> temp->gender;
	cout << "\nEnter date of birth of Student : ";
	cin >> temp->dob;
	cout << "\nEnter contact number of Student : ";
	cin >> temp->number;
	cout << "\nEnter Age of Student : ";
	cin >> temp->age;
	cout << "\nEnter Percentage of Student : ";
	cin >> temp->percentage;
	temp->next = NULL;
	if(loc < length()){
		struct Node* p = root;
	    while(i < loc){	
		   p = p->next;
		   i++;
	    }
	    temp->next = p->next;
	    p->next = temp;
	}else{
		cout << "The Location you Have entered is greater than length of data list.\n";
		cout << "List Have " << length() << " data.\n";
	}
	system("cls");
}
void LinkedList :: iend(){
	system("cls");
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	cout << "\n\nInsert At Beginning\n";
	cout << "\nEnter Roll no. of Student : ";
	cin >> temp->roll;
	cout << "\nEnter Name of Student : ";
	cin >> temp->name;
	cout << "\nEnter Gender of Student : ";
	cin >> temp->gender;
	cout << "\nEnter date of birth of Student : ";
	cin >> temp->dob;
	cout << "\nEnter contact number of Student : ";
	cin >> temp->number;
	cout << "\nEnter Age of Student : ";
	cin >> temp->age;
	cout << "\nEnter Percentage of Student : ";
	cin >> temp->percentage;
	temp->next = NULL;
	if(root == NULL){
		root = temp;
	}else{
		struct Node* p;
		p = root;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = temp;
	}
	system("cls");
}
void LinkedList :: ibeg(){
	system("cls");
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	cout << "\n\nInsert At Beginning\n";
	cout << "\nEnter Roll no. of Student : ";
	cin >> temp->roll;
	cout << "\nEnter Name of Student : ";
	cin >> temp->name;
	cout << "\nEnter Gender of Student : ";
	cin >> temp->gender;
	cout << "\nEnter date of birth of Student : ";
	cin >> temp->dob;
	cout << "\nEnter contact number of Student : ";
	cin >> temp->number;
	cout << "\nEnter Age of Student : ";
	cin >> temp->age;
	cout << "\nEnter Percentage of Student : ";
	cin >> temp->percentage;
	temp->next = NULL;
	if(root == NULL){
		root = temp;
	}else{
		temp->next = root;
		root = temp;
	}
	system("cls");
}
int main(){
	LinkedList l;
	while(1){
		cout << "******************** Student Record Management ********************";
	    cout << "\n\n";
	    cout << "1.Insert New Data\n";
	    cout << "2.Display All Students Data\n";
	    cout << "3.Check Student Data\n";
	    cout << "4.Modify or Update Student Data\n";
	    cout << "5.Delete Student Data\n";
	    cout << "6.Exit\n\n";
	    int c;
	    cout << "Enter your choice : ";
	    cin >> c;
	    switch(c){	    	
		    case 1:
			    system("cls");
		        l.showInsert();
		        break;
		    case 2:
			    system("cls");
		        l.displayAllStudents();
			    break;
		    case 3:
			    system("cls");
		        l.checkStudentData();
			    break;
		    case 4:
			    system("cls");
		        l.modifyStudentData();
			    break;
		    case 5:
			    system("cls");
		        l.deleteStudentData();
			    break;
		    case 6:
		        exit(1);
			    break;
		    default:
			    system("cls");
		        cout << "You have Entered an Invalid Input\n";
			    break;	
	    }
	}
	return 0;
}

#include <iostream>
#include<fstream>

using namespace std;

const string file_path = "students.txt";

void add_student()
{

	ofstream outFile(file_path, ios::app);

	if(!outFile.is_open()){
		cout<<"Error opening the file : "<<file_path<<endl;
		return;
	}
	else{
	
		int id;
		string name, faculty, grade;
		
	cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Student Faculty: ";
    getline(cin, faculty);
    cout << "Enter Student Sem Grade: ";
    cin >> grade;
				
	outFile<< " "<<id<<" "<<name<<" "<<faculty<<" "<<grade<<endl;
	outFile.close();
	
	cout<<"Student added successfully....";
	
	}

}

void update_student() {
 
    ifstream inFile(file_path);
    ofstream outFile("temp.txt");

    if (!inFile.is_open()) {
        cout << "Error opening file: " << file_path << endl;
        return;
    }

    int searchID;
    cout << "Enter the student's ID: ";
    cin >> searchID;

    int id;
    string name, faculty, grade;
    bool found = false;

    while (inFile >> id >> name >> faculty >> grade) {
        if (id == searchID) {
       
	        found = true;
            cout << "1. Update Name\n";
            cout << "2. Update Faculty\n";
            cout << "3. Update Grade\n";
            cout << "4. Exit Update\n";
            int subChoice;
            do {
                cout << "Enter your choice: ";
                cin >> subChoice;
                cin.ignore(); // To ignore newline character left by cin

                switch (subChoice) {
                    case 1:
                        cout << "Enter new name: ";
                        getline(cin, name);
                        break;
                    case 2:
                        cout << "Enter new faculty: ";
                        getline(cin, faculty);
                        break;
                    case 3:
                        cout << "Enter new grade: ";
                        cin >> grade;
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            } while (subChoice != 4);

            outFile << id << " " << name << " " << faculty << " " << grade << endl;
        } else {
            outFile << id << " " << name << " " << faculty << " " << grade << endl;
        }
    }

    inFile.close();
    outFile.close();

    if (found) {
        remove(file_path.c_str());
        rename("temp.txt", file_path.c_str());
        cout << "Record with ID " << searchID << " has been updated." << endl;
    } else {
        remove("temp.txt");
        cout << "No record found with ID " << searchID << endl;
    }
}
void delete_student(){
	
	
	ifstream inFile(file_path);
	ofstream outFile("temp.txt");

	if(!inFile.is_open()){
		
		cout<<"Error opening file : "<<inFile<<endl;
		return;
	}
	
	
	int searchID;

	cout<<"Enter the student's ID : ";
	cin>>searchID;

	int id;
	string name,faculty, grade;
	bool found = false;

	while(inFile >> id>>name>>faculty>>grade){
	
	if(	id == searchID ){
	
	found = true;
	continue;
	
	}
	
	outFile<<id<<" "<< name<<" "<<faculty<<" "<<grade<<endl;
	
	
	}

	inFile.close();
	outFile.close();

	if(found){

	remove(file_path.c_str());
	rename("temp.txt", file_path.c_str());
	
	cout<<"record with ID "<<searchID<<" has been deleted."<<endl;
		
	}
	
	else {
		remove("temp.txt");
		cout<<"No record found with ID "<<searchID<<endl;
		
	}
	
}

void view_data()
{
	ifstream inFile(file_path);
 
 	if(!inFile.is_open()){
 	
 	cout<<"No records found"<<endl;
 	return;
 	}
	
	int id;
 	string name, faculty, grade;
 
 	cout<<"ID\tNAME\tFACULTY\tGRADE"<<endl;
	 cout << "----------------------------------------" << endl;

	while(inFile >> id>> name>>faculty>> grade){
 	
 	cout<<id<<"\t"<<name<<"\t"<<faculty<<"\t"<<grade<<endl;
 
 	}
 	
 	inFile.close();
 
}

int main()
{
    while(true){
    int choice;
    cout << "\n=====STUDENT MANAGEMENT SYSTEM====\n";
    cout << "1.Add Student\n2.View Records\n3.Update Record\n4.Delete Record\n5.Exit Program\nchoose(1-5): ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        add_student();
        break;
    case 2:
        view_data();
        break;
    case 3:
        update_student();
        break;
    case 4:
		delete_student();
        break;
    case 5:
    	cout<<"\nThe program is exiting....";
		return 0;
        break;

    default:
        cout << "Invalid input ";
    }
}
}

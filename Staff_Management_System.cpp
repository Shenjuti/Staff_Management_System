///////////////////////////////////////////////////  Library Declaration  ///////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<ctime>

using namespace std;
int Class;          //This is a Global Variable


///////////////////////////////////////////////////  Base Class  ///////////////////////////////////////////////////////////////////////////////


class Staff
{
protected:
    int ID,age,phone;
    char name[20],gender[10];
    double salary;

public:
    void setValue()         //The Member Function is to Add the Data of All Staff
    {
        cout<<"\n\n\t\t## Adding Staff Info ##";
        cout<<endl<<"Input Name: ";
        fflush(stdin);
        cin.getline(name,19);
        cout<<endl<<"Input Gender: ";
        fflush(stdin);
        cin.getline(gender,9);
        cout<<endl<<"Input Age: ";
        cin>>age;
        cout<<endl<<"Input ID: ";
        cin>>ID;
        cout<<endl<<"Input Phone: ";
        cin>>phone;
        cout<<endl<<"Input Salary: ";
        cin>>salary;
    }
};


///////////////////////////////////////////////////  Manager class Staff  ///////////////////////////////////////////////////////////////////////////////


class Manager:public Staff
{
protected:

    double monitoringTime;

public:
    void setValueManager()            //The Member Function is to Add the Data of Manager Class Staff
    {
        Staff::setValue();
        cout<<endl<<"Input Monitoring Time: ";
        cin>>monitoringTime;
    }

    int storeStaffDataManager()       //The Member Function is to Store the Data of Manager Class Staff in File
    {
        ofstream fout;
        fout.open("Manager Staff Information.txt",ios::app);
        fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<monitoringTime<<endl;
        fout.close();
    }

    void showStaffDataManager()           //The Member Function is to View the Data of Manager Class Staff
    {
        cout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<monitoringTime<<endl;
    }

    void deleteStaffDataManager(int id)           //The Member Function is to Delete the Data of Manager Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Manager.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<monitoringTime<<endl;
                }
                else
                {
                    c++;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Manager Staff Information.txt");
            rename("temp Manager.txt","Manager Staff Information.txt");
        }
    }

    void editStaffDataManager(int id)         //The Member Function is to Edit the Data of Manager Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("Manager temp.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    setValueManager();
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<monitoringTime<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<monitoringTime<<endl;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Manager Staff Information.txt");
            rename("Manager temp.txt","Manager Staff Information.txt");
        }
    }

    void searchStaffDataManager(int id)           //The Member Function is to Search the Data of Manager Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tMonitoring Time"<<endl<<endl;
                    c++;
                    showStaffDataManager();
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffDataManager()            //The Member Function is to View All the Data of Manager Class Staff
    {
        ifstream fin;
        fin.open("Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tMonitoring Time"<<endl<<endl;
            fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            while(!fin.eof())
            {
                showStaffDataManager();
                fin>>name>>gender>>age>>ID>>phone>>salary>>monitoringTime;
            }
        }
        fin.close();
    }
};

///////////////////////////////////////////////////  Assistant Manager class Staff  ///////////////////////////////////////////////////////////////////////////////

class AssistantManager:public Staff
{
protected:

    double issue;

public:
    void setValueAssistantManager()            //The Member Function is to Add the Data of Assistant Manager Class Staff
    {
        Staff::setValue();
        cout<<endl<<"Resolve Issue Status: ";
        cin>>issue;
    }

    int storeStaffDataAssistantManager()       //The Member Function is to Store the Data of Assistant Manager Class Staff in File
    {
        ofstream fout;
        fout.open("Manager Staff Information.txt",ios::app);
        fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<issue<<endl;
        fout.close();
    }

    void showStaffDataAssistantManager()           //The Member Function is to View the Data of Assistant Manager Class Staff
    {
        cout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<issue<<endl;
    }

    void deleteStaffDataAssistantManager(int id)           //The Member Function is to Delete the Data of Assistant Manager Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Assistant Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Assistant Manager.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<issue<<endl;
                }
                else
                {
                    c++;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Assistant Manager Staff Information.txt");
            rename("temp Assistant Manager.txt","Assistant Manager Staff Information.txt");
        }
    }

    void editStaffDataAssistantManager(int id)         //The Member Function is to Edit the Data of Assistant Manager Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Assistant Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("Assistant Manager temp.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    setValueAssistantManager();
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<issue<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<issue<<endl;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Assistant Manager Staff Information.txt");
            rename("Assistant Manager temp.txt","Assistant Manager Staff Information.txt");
        }
    }

    void searchStaffDataAssistantManager(int id)           //The Member Function is to Search the Data of Assistant Manager Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("Assistant Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tResolve Issue status"<<endl<<endl;
                    c++;
                    showStaffDataAssistantManager();
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffDataAssistantManager()            //The Member Function is to View All the Data of Assistant Manager Class Staff
    {
        ifstream fin;
        fin.open("Assistant Manager Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tResolve Issue Status"<<endl<<endl;
            fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            while(!fin.eof())
            {
                showStaffDataAssistantManager();
                fin>>name>>gender>>age>>ID>>phone>>salary>>issue;
            }
        }
        fin.close();
    }
};
///////////////////////////////////////////////////  Secretary class Staff  ///////////////////////////////////////////////////////////////////////////////

class Secretary:public Staff
{
protected:

    double file;

public:
    void setValueSecretary()            //The Member Function is to Add the Data of Secretary Class Staff
    {
        Staff::setValue();
        cout<<endl<<"Organizing File Status: ";
        cin>>file;
    }

    int storeStaffDataSecretary()       //The Member Function is to Store the Data of Secretary Class Staff in File
    {
        ofstream fout;
        fout.open("Secretary Staff Information.txt",ios::app);
        fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<file<<endl;
        fout.close();
    }

    void showStaffDataSecretary()           //The Member Function is to View the Data of Secretary Class Staff
    {
        cout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<file<<endl;
    }

    void deleteStaffDataSecretary(int id)           //The Member Function is to Delete the Data of Secretary Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Secretary Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Secretary.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<file<<endl;
                }
                else
                {
                    c++;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Secretary Staff Information.txt");
            rename("temp Secretary.txt","Secretary Staff Information.txt");
        }
    }

    void editStaffDataSecretary(int id)         //The Member Function is to Edit the Data of Secretary Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Secretary Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("Secretary temp.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    setValueSecretary();
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<file<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<file<<endl;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Secretary Staff Information.txt");
            rename("Secretary temp.txt","Secretary Staff Information.txt");
        }
    }

    void searchStaffDataSecretary(int id)           //The Member Function is to Search the Data of Secretary Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("Secretary Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tOrganizing File Status"<<endl<<endl;
                    c++;
                    showStaffDataSecretary();
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffDataSecretary()            //The Member Function is to View All the Data of Secretary Class Staff
    {
        ifstream fin;
        fin.open("Secretary Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tOrganizing File Status"<<endl<<endl;
            fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            while(!fin.eof())
            {
                showStaffDataSecretary();
                fin>>name>>gender>>age>>ID>>phone>>salary>>file;
            }
        }
        fin.close();
    }
};


///////////////////////////////////////////////////  Executive class Staff  ///////////////////////////////////////////////////////////////////////////////


class Executive:public Staff
{
protected:

    double experience;

public:
    void setValueExecutive()            //The Member Function is to Add the Data of Executive Class Staff
    {
        Staff::setValue();
        cout<<endl<<"Input Experience Year: ";
        cin>>experience;
    }

    int storeStaffDataExecutive()       //The Member Function is to Store the Data of Executive Class Staff in File
    {
        ofstream fout;
        fout.open("Executive Staff Information.txt",ios::app);
        fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<experience<<endl;
        fout.close();
    }

    void showStaffDataExecutive()           //The Member Function is to View the Data of Executive Class Staff
    {
        cout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<experience<<endl;
    }

    void deleteStaffDataExecutive(int id)           //The Member Function is to Delete the Data of Executive Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Executive Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp Executive.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<experience<<endl;
                }
                else
                {
                    c++;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Executive Staff Information.txt");
            rename("temp Executive.txt","Executive Staff Information.txt");
        }
    }

    void editStaffDataExecutive(int id)         //The Member Function is to Edit the Data of Executive Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("Executive Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("Executive temp.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    setValueExecutive();
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<experience<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<experience<<endl;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("Executive Staff Information.txt");
            rename("Executive temp.txt","Executive Staff Information.txt");
        }
    }

    void searchStaffDataExecutive(int id)           //The Member Function is to Search the Data of Executive Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("Executive Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tExperience Year"<<endl<<endl;
                    c++;
                    showStaffDataExecutive();
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffDataExecutive()            //The Member Function is to View All the Data of Executive Class Staff
    {
        ifstream fin;
        fin.open("Executive Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tExperience Year"<<endl<<endl;
            fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            while(!fin.eof())
            {
                showStaffDataExecutive();
                fin>>name>>gender>>age>>ID>>phone>>salary>>experience;
            }
        }
        fin.close();
    }
};


///////////////////////////////////////////////////  Enter Yours class Staff  ///////////////////////////////////////////////////////////////////////////////


class EnterYours:public Staff
{
protected:

    double workTime;

public:
    void setValueEnterYours()            //The Member Function is to Add the Data of Enter Yours Class Staff
    {
        Staff::setValue();
        cout<<endl<<"Input Working Time: ";
        cin>>workTime;
    }

    int storeStaffDataEnterYours()       //The Member Function is to Store the Data of Enter Yours Class Staff in File
    {
        ofstream fout;
        fout.open("EnterYours Staff Information.txt",ios::app);
        fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<workTime<<endl;
        fout.close();
    }

    void showStaffDataEnterYours()           //The Member Function is to View the Data of Enter Yours Class Staff
    {
        cout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<workTime<<endl;
    }

    void deleteStaffDataEnterYours(int id)           //The Member Function is to Delete the Data of Enter Yours Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("EnterYours Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("temp EnterYours.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            while(!fin.eof())
            {
                if(id!=ID)
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<workTime<<endl;
                }
                else
                {
                    c++;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            }
            if(c==0)
            {
                cout<<"ID Not Found"<<endl;
            }
            else
            {
                cout<<"\n\tDeleted Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("EnterYours Staff Information.txt");
            rename("temp EnterYours.txt","EnterYours Staff Information.txt");
        }
    }

    void editStaffDataEnterYours(int id)         //The Member Function is to Edit the Data of Enter Yours Class Staff
    {
        int c=0;
        ifstream fin;
        ofstream fout;
        fin.open("EnterYours Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "\n\n\tFile Not Found!!!\n\n";
        }
        else
        {
            fout.open("EnterYours temp.txt",ios::out);
            fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    c++;
                    setValueEnterYours();
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<workTime<<endl;
                }
                else
                {
                    fout<<std::left<<setw(20)<<name<<"\t"<<std::left<<setw(10)<<gender<<"\t"<<std::left<<setw(5)<<age<<"\t"<<std::left<<setw(10)<<ID<<"\t"<<std::left<<setw(11)<<phone<<"\t"<<std::left<<setw(7)<<salary<<"\t\t"<<std::left<<setw(7)<<workTime<<endl;
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            }
            if(c==0)
            {
                cout<<"\n\nID Not Found\n\n";
            }
            else
            {
                cout<<"\n\tEdited Successfully!!!\n\n";
            }
            fout.close();
            fin.close();
            remove("EnterYours Staff Information.txt");
            rename("EnterYours temp.txt","EnterYours Staff Information.txt");
        }
    }

    void searchStaffDataEnterYours(int id)           //The Member Function is to Search the Data of Enter Yours Class Staff
    {
        int c=0;
        ifstream fin;
        fin.open("EnterYours Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            while(!fin.eof())
            {
                if(id==ID)
                {
                    cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tWorking Time"<<endl<<endl;
                    c++;
                    showStaffDataEnterYours();
                }
                fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            }
            if(c==0)
            {
                cout<<"ID Not Found\n"<<endl;
            }
            fin.close();
        }
    }

    void viewAllStaffDataEnterYours()            //The Member Function is to View All the Data of Enter Yours Class Staff
    {
        ifstream fin;
        fin.open("EnterYours Staff Information.txt",ios::in);
        if(!fin)
        {
            throw "File Not Found";
        }
        else
        {
            cout<<endl<<std::left<<setw(20)<<"Name"<<std::left<<setw(10)<<"\tGender"<<std::left<<setw(5)<<"\tAge"<<std::left<<setw(10)<<"\tID"<<std::left<<setw(11)<<"\tPhone"<<std::left<<setw(7)<<"\tSalary"<<std::left<<setw(7)<<"\tWorking Time"<<endl<<endl;
            fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            while(!fin.eof())
            {
                showStaffDataEnterYours();
                fin>>name>>gender>>age>>ID>>phone>>salary>>workTime;
            }
        }
        fin.close();
    }
};


/////////////////////////////////////////////////// Main Menu Function  ///////////////////////////////////////////////////////////////////////////////


int mainMenu()      //The Main Menu is to Choose the Class of the Staff
{
    system("cls");
    cout<<"\n\n\n\t\t\t\tWelcome to Staff Management System"<<endl<<endl<<endl;
    cout<<endl<<endl<<"\t\t\t#####\tMain Menu\t#####"<<endl<<endl;
    cout<<"\t\t[1] Manager Class Staff"<<endl;
    cout<<"\t\t[2] Assistant Manager Class Staff"<<endl;
    cout<<"\t\t[3] Secretary Class Staff"<<endl;
    cout<<"\t\t[4] Executive Class Staff"<<endl;
    cout<<"\t\t[5] Enter Yours Class Staff"<<endl;
    cout<<"\t\t[6] Quit"<<endl<<endl;
    cout<<"\tPlease Enter Your Choice: ";
    int Choice;
    cin>>Choice;
    return Choice;
}


///////////////////////////////////////////////////  Sub Menu Function  ///////////////////////////////////////////////////////////////////////////////


int subMenu()       //The Sub Menu is to Choose the work of the (Manager,Assistant Manager,Secretary,Executive,Enter Yours) Class Staff
{
    int Choice;
    switch(mainMenu())          //The Switch is to Find the Class of the Staff
    {
        case 1:
            Class=1;
            system("cls");
            cout<<endl<<endl<<"\n\n\t\t\t#####\tManager Class Staff\t#####"<<endl<<endl;
            cout<<"\t\t[1] Add Staff Info"<<endl;
            cout<<"\t\t[2] Delete Staff Info"<<endl;
            cout<<"\t\t[3] Edit Staff Info"<<endl;
            cout<<"\t\t[4] Search Staff Info"<<endl;
            cout<<"\t\t[5] Display All Staff List"<<endl;
            cout<<"\tPlease Enter Your Choice: ";
            cin>>Choice;
            return Choice;
            break;

        case 2:
            Class=2;
            system("cls");
            cout<<endl<<endl<<"\n\n\t\t\t#####\tAssistant Manager Class Staff\t#####"<<endl<<endl;
            cout<<"\t\t[1] Add Staff Info"<<endl;
            cout<<"\t\t[2] Delete Staff Info"<<endl;
            cout<<"\t\t[3] Edit Staff Info"<<endl;
            cout<<"\t\t[4] Search Staff Info"<<endl;
            cout<<"\t\t[5] Display All Staff List"<<endl;
            cout<<"\tPlease Enter Your Choice: ";
            cin>>Choice;
            return Choice;
            break;

        case 3:
            Class=3;
            system("cls");
            cout<<endl<<endl<<"\t\t\t#####\tSecretary Class Staff\t#####"<<endl<<endl;
            cout<<"\t\t[1] Add Staff Info"<<endl;
            cout<<"\t\t[2] Delete Staff Info"<<endl;
            cout<<"\t\t[3] Edit Staff Info"<<endl;
            cout<<"\t\t[4] Search Staff Info"<<endl;
            cout<<"\t\t[5] Display All Staff List"<<endl;
            cout<<"\tPlease Enter Your Choice: ";
            cin>>Choice;
            return Choice;
            break;

            case 4:
            Class=4;
            system("cls");
            cout<<endl<<endl<<"\t\t\t#####\tExecutive Class Staff\t#####"<<endl<<endl;
            cout<<"\t\t[1] Add Staff Info"<<endl;
            cout<<"\t\t[2] Delete Staff Info"<<endl;
            cout<<"\t\t[3] Edit Staff Info"<<endl;
            cout<<"\t\t[4] Search Staff Info"<<endl;
            cout<<"\t\t[5] Display All Staff List"<<endl;
            cout<<"\tPlease Enter Your Choice: ";
            cin>>Choice;
            return Choice;
            break;

            case 5:
            Class=5;
            system("cls");
            cout<<endl<<endl<<"\t\t\t#####\tEnter Yours Class Staff\t#####"<<endl<<endl;
            cout<<"\t\t[1] Add Staff Info"<<endl;
            cout<<"\t\t[2] Delete Staff Info"<<endl;
            cout<<"\t\t[3] Edit Staff Info"<<endl;
            cout<<"\t\t[4] Search Staff Info"<<endl;
            cout<<"\t\t[5] Display All Staff List"<<endl;
            cout<<"\tPlease Enter Your Choice: ";
            cin>>Choice;
            return Choice;
            break;

        default:
            system("cls");
            cout<<"\tInvalid Choice!!!!!"<<endl;
            cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
            getch();
            return 100;
            break;
    }
}


///////////////////////////////////////////////////  Time Function  ///////////////////////////////////////////////////////////////////////////////


void Time()
{
    time_t now;
    struct tm nowlocal;
    now=time(NULL);
    nowlocal=*localtime(&now);
    cout<<"\t\tToday's Date is: ";
    cout<<nowlocal.tm_mday<<"/"<<nowlocal.tm_mon<<"/"<<nowlocal.tm_year+1900<<endl;
    cout<<"\t\tCurrent Time is: ";
    cout<<nowlocal.tm_hour<<":"<<nowlocal.tm_min<<endl<<endl<<endl;
}


///////////////////////////////////////////////////  Main function  ///////////////////////////////////////////////////////////////////////////////


int main()
{
    Manager m1;      //For Manager Class Staff
    AssistantManager as1;     //For Assistant Manager Class Staff
    Secretary s1;      //For Secretary Class Staff
    Executive e1;      //For Executive Class Staff
    EnterYours ey1;    //For Enter Yours Class Staff
    char e;
    int id,x;
    Time();
    cout<<"\tPlease Press Any Key to Start!!!";
    getch();
    while(1)
    {
        x=subMenu();
        system("cls");
        Time();
        if(Class==1)            //For Manager Class Staff
        {
            switch(x)
            {
                case 1:
                    do
                    {
                        system("cls");
                        Time();
                        m1.setValueManager();
                        m1.storeStaffDataManager();
                        cout<<"\n\tAdded Successfully!!!\n\n";
                        cout<<"\n\nAdd More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 2:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            m1.deleteStaffDataManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }
                        cout<<"\n\nDelete More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                          m1.editStaffDataManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nEdit More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 4:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            m1.searchStaffDataManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\n";
                        cout<<"\n\nSearch More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 5:
                    system("cls");
                    Time();
                    try
                        {
                          m1.viewAllStaffDataManager();
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                    cout<<"\n\n\n";
                    cout<<"\tPress Any Key for Main Menu!!!  ";
                    getch();
                    break;

                default:
                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;
            }
        }

        else if(Class==2)           //For Assistant Manager Class Staff
        {
            switch(x)
            {
                case 1:
                    do
                    {
                        system("cls");
                        Time();
                        as1.setValueAssistantManager();
                        as1.storeStaffDataAssistantManager();
                        cout<<"\n\tAdded Successfully!!!\n\n";
                        cout<<"\n\nAdd More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 2:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            as1.deleteStaffDataAssistantManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nDelete More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            as1.editStaffDataAssistantManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }
                        as1.editStaffDataAssistantManager(id);
                        cout<<"\n\nEdit More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 4:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            as1.searchStaffDataAssistantManager(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\n";
                        cout<<"\n\nSearch More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 5:
                    system("cls");
                    Time();
                    try
                        {
                            as1.viewAllStaffDataAssistantManager();
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                    cout<<"\n\n\n";
                    cout<<"\tPress Any Key for Main Menu!!!  ";
                    getch();
                    break;

                default:
                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;
            }
        }

        else if(Class==3)       //For Secretary Class Staff
        {
            switch(x)
            {
                case 1:
                    do
                    {
                        system("cls");
                        Time();
                        s1.setValueSecretary();
                        s1.storeStaffDataSecretary();
                        cout<<"\n\tAdded Successfully!!!\n\n";
                        cout<<"\n\nAdd More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 2:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            s1.deleteStaffDataSecretary(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nDelete More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            s1.editStaffDataSecretary(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nEdit More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 4:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            s1.searchStaffDataSecretary(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\n";
                        cout<<"\n\nSearch More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 5:
                    system("cls");
                    Time();
                    try
                        {
                            s1.viewAllStaffDataSecretary();
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                    cout<<"\n\n\n";
                    cout<<"\tPress Any Key for Main Menu!!!  ";
                    getch();
                    break;

                default:
                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;
            }
        }

        else if(Class==4)           //For Executive Class Staff
        {
            switch(x)
            {
                case 1:
                    do
                    {
                        system("cls");
                        Time();
                        e1.setValueExecutive();
                        e1.storeStaffDataExecutive();
                        cout<<"\n\tAdded Successfully!!!\n\n";
                        cout<<"\n\nAdd More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 2:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            e1.deleteStaffDataExecutive(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nDelete More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            e1.editStaffDataExecutive(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }
                        e1.editStaffDataExecutive(id);
                        cout<<"\n\nEdit More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 4:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            e1.searchStaffDataExecutive(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\n";
                        cout<<"\n\nSearch More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 5:
                    system("cls");
                    Time();
                    try
                        {
                            e1.viewAllStaffDataExecutive();
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                    cout<<"\n\n\n";
                    cout<<"\tPress Any Key for Main Menu!!!  ";
                    getch();
                    break;

                default:
                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;
            }
        }

        else if(Class==5)           //For Enter Yours Class Staff
        {
            switch(x)
            {
                case 1:
                    do
                    {
                        system("cls");
                        Time();
                        ey1.setValueEnterYours();
                        ey1.storeStaffDataEnterYours();
                        cout<<"\n\tAdded Successfully!!!\n\n";
                        cout<<"\n\nAdd More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 2:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Deleting Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            ey1.deleteStaffDataEnterYours(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\nDelete More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 3:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Editing Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            ey1.editStaffDataEnterYours(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }
                        ey1.editStaffDataEnterYours(id);
                        cout<<"\n\nEdit More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 4:
                    do
                    {
                        system("cls");
                        Time();
                        cout<<"\n\n\t\t## Searching Staff Info ##\n\n";
                        cout<<"\n\n\tInput ID: ";
                        cin>>id;
                        try
                        {
                            ey1.searchStaffDataEnterYours(id);
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                        cout<<"\n\n";
                        cout<<"\n\nSearch More!! (Y/N): ";
                        fflush(stdin);
                        cin>>e;
                    }while(e=='y'||e=='Y');
                    break;

                case 5:
                    system("cls");
                    Time();
                    try
                        {
                            ey1.viewAllStaffDataEnterYours();
                        }
                        catch(const char* msg)
                        {
                            cerr<<msg<<endl;
                        }

                    cout<<"\n\n\n";
                    cout<<"\tPress Any Key for Main Menu!!!  ";
                    getch();
                    break;

                default:
                    system("cls");
                    Time();
                    cout<<"\tInvalid Choice!!!!!"<<endl;
                    cout<<"\tPress Any Key to Try Again......"<<endl<<endl;
                    getch();
                    break;
            }
        }
        // End
    }
}




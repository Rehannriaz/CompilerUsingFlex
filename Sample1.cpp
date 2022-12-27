#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#define number 5

/*
Check ID , can not be same
Check ISBN, can not be same
*/

using namespace std;
void menu();
struct Book
{
    int ID = 0, price = 0, pages = 0; // Members
    string BookName = "", author = "", ISBN = "";
    void PrintAll()
    {
        cout << ID << setw(20) << BookName << setw(20) << author << setw(20) << ISBN << setw(20) << price << setw(20) << pages << endl;
    }
};
struct BookList
{

    Book books[number];

    void Add_Book(Book &bk)
    {
        int i;
        int counter=0;
        cout<<"The available index's are \n";
        for(int i=0;i<number;i++)
        {
        if(books[i].ISBN == "")
        {
        cout<<i<<" ";
        counter++;
        }
        }
        if(counter==0)
        {
            cout<<"NONE\n";
            cout<<"You are still able to replace any other book by Entering their INDEX!\n";
        }

        cout << "\nEnter the array index you want the book to be stored at: ";
        cin >> i;
        if (i >= 0 && i < number)
        {
            books[i] = bk;
            cout << "Book has been succesfully added.\n";
        }
        else
            cout << "Invalid index, Book could not be added.\n";
    }
    void PrintAll()
    {
        cout << "\nBook(s) Information \n";
        cout << "ID" << setw(20) << "Name" << setw(20) << "Author" << setw(20) << "ISBN" << setw(20) << "Price" << setw(20) << "Pages" << endl;
        for (int i = 0; i < number; i++)
        {
            if (books[i].BookName != "")
                books[i].PrintAll();
        }
    }

    void Sort(bool check)
    {
        if (check) // true= ascending
        {
            for (int i = number; i > 0; i--)
            {
                for (int j = 0; j < number - 1; j++)
                {
                    if (books[j].ID > books[j + 1].ID)
                    {
                        Book temp = books[j + 1];
                        books[j + 1] = books[j];
                        books[j] = temp;
                    }
                }
            }
        }
        else if (check == false)
        {
            for (int i = number; i > 0; i--)
            {
                for (int j = 0; j < number - 1; j++)
                {
                    if (books[j].ID < books[j + 1].ID)
                    {
                        Book temp = books[j + 1];
                        books[j + 1] = books[j];
                        books[j] = temp;
                    }
                }
            }
        }
    }
    void DeleteAll()
    {
        for (int i = 0; i < number; i++)
        {
            books[i].BookName = "";
            books[i].ISBN = "";
            books[i].author = "";
            books[i].ID = 0;
            books[i].pages = 0;
            books[i].price = 0;
        }
        cout << "All the Books have been succesfully Deleted!\n";
    }
    void DeleteBook(Book &stdISBN)
    {
        for (int i = 0; i < number; i++)
        {
            if (books[i].ISBN.compare(stdISBN.ISBN) == 0)
            {
                books[i].BookName = "";
                books[i].ISBN = "";
                books[i].author = "";
                books[i].ID = 0;
                books[i].pages = 0;
                books[i].price = 0;
            }
        }
        cout << "Book has been succesfully Deleted!\n";
    }
    void specificBook(Book stdISBN)
    {
        cout << "ID" << setw(20) << "Name" << setw(20) << "Author" << setw(20) << "ISBN" << setw(20) << "Price" << setw(20) << "Pages" << endl;

        for (int i = 0; i < number; i++)
        {
            if (books[i].ISBN.compare(stdISBN.ISBN) == 0)
            {
                books[i].PrintAll();
            }
        }
    }
    bool ValidCheck(Book a[], Book check)
    {
        bool found = false;
        for (int i = 0; i < number; i++)
        {
            if (a[i].ISBN.compare(check.ISBN) == 0) 
            {
                found = true;
                return found;
            }
            found = false;
        }

        return found;
    }
};

struct Student
{
    int ID, RollNo;
    string StdName;
    void PrintAll()
    {
        cout << ID << setw(20) << RollNo << setw(20) << StdName << endl;
    }
};
struct StudentList
{
    Student StudentList_std[number];

    void Printall()
    {
        cout << "\nStudent Information \n";
        cout << "ID" << setw(20) << "RollNo" << setw(20) << "StdName" << endl;
        for (int i = 0; i < number; i++)
        {
            if (StudentList_std[i].StdName != "")
                StudentList_std[i].PrintAll();
        }
    }
    void Add_Student(Student &stdinfo)
    {
        int i,counter=0;
        cout<<"The available index's are \n";
        for(int i=0;i<number;i++)
        {
        if(StudentList_std[i].StdName == "")
        {
        cout<<i<<" ";
        counter++;

        }

        }
        if(counter==0)
        {
            cout<<"NONE\n";
            cout<<"You are still able to replace any other Student by Entering their INDEX!\n";
        }
        cout << "\nEnter the index you would like to add the Student on: ";
        cin >> i;
        
        if (i >= 0 && i < number)
        {
            StudentList_std[i] = stdinfo;
            cout << "Student has been Successfully Added!\n";
        }
        else
            cout << "Incorrect index, Student could not be added\n";
    }
    void Delete_Student(Student &stdID)
    {

        
        for (int i = 0; i < number; i++)
        {
            if (StudentList_std[i].ID == stdID.ID)
            {
                StudentList_std[i].StdName = "";
                StudentList_std[i].ID = 0;
                StudentList_std[i].RollNo = 0;
            }
        }
        cout << "Student has been succesfully Deleted!\n";
    }
    bool ValidCheck(Student a[], Student check)
    {
        bool found = false;
        for (int i = 0; i < number; i++)
        {
            if (a[i].ID == check.ID)
            {
                found = true;
                return found;
            }
            found = false;
        }

        return found;
    }
};

int main()
{
    BookList a;
    StudentList b;
    Book c;
    char input;
    int select_menu;
    bool validation = false;
    cout << "Enter Y to start the Program: ";
    cin >> input;
    cout << "\n";
    if (tolower(input) == 'y')
    {
        
        menu();
        cin >> select_menu;
        do
        {
            switch (select_menu)
            {
            case 1:
            {
                Student stdinfo;

                cout << "\n Enter Student's Name: ";
                cin.ignore();
                getline(cin, stdinfo.StdName);
                cout << "\n Enter Student's ID: ";
                cin >> stdinfo.ID;
                validation=b.ValidCheck(b.StudentList_std,stdinfo);
                if(validation)
                {
                    cout<<"Error! User with the similar ID already EXISTS!\n";
                }
                else
                {
                cout << "\n Enter Student's RollNo: ";
                cin >> stdinfo.RollNo;
                b.Add_Student(stdinfo);
                }
                break;
            }
            case 2:
            {
                Student stdID;
                cout << "\n Enter the Student's ID: ";
                cin >> stdID.ID;
                validation=b.ValidCheck(b.StudentList_std,stdID);
                if(validation)
                b.Delete_Student(stdID);
                else
                cout<<"Error! No User with that ID EXISTS!\n";
                break;
            }
            case 3:
            {
                b.Printall();
                break;
            }
            case 4:
            {
                Book bk;
                cout << "\n Enter Book's Name: ";
                cin.ignore();
                getline(cin, bk.BookName);
                cout << "\n Enter Book's ISBN: ";
                cin >> bk.ISBN;
                for (size_t i = 0; i < bk.ISBN.length(); i++)
                    bk.ISBN[i] = toupper(bk.ISBN[i]);

                validation = a.ValidCheck(a.books, bk);
                if (validation)
                    cout << "Error! A book with that ISBN already exists!\n";
                else
                {
                    cout << "\n Enter Books ID: ";
                    cin >> bk.ID;
                    cout << "\n Enter Books author: ";
                    cin.ignore();
                    getline(cin, bk.author);
                    cout << "\n Enter Book's price: ";
                    cin >> bk.price;
                    cout << "\n Enter the Amount of Pages in the Book: ";
                    cin >> bk.pages;
                    a.Add_Book(bk);
                }

                break;
            }
            case 5:
            {
                Book stdISBN;
                int input_del;
                cout<<"Enter 1 to Delete a Specific Book OR Enter 2 to delete All the Books: ";
                cin>>input_del;

                if(input_del==1)
                {
                cout << "Enter Book's ISBN You Want to Delete: ";
                cin >> stdISBN.ISBN;
                for (int i = 0; i < stdISBN.ISBN.length(); i++)
                    stdISBN.ISBN[i] = toupper(stdISBN.ISBN[i]);
                validation = a.ValidCheck(a.books, stdISBN);
                if (validation)
                    a.DeleteBook(stdISBN);
                else
                    cout << "Error! There is no Book with that ISBN!\n";

                }
                else if(input_del==2)
                {
                    cout<<"This Action is irreversible!\n Enter 1 if you would like to continue or 2 to go back to the Menu:";
                    cin>>input_del;
                    if(input_del==1)
                    {
                        a.DeleteAll();
                        cout<<"All Books Deleted Succesfully!\n";
                    }
                    else if(input_del!=2)
                    cout<<"Invalid Input, Going back to Menu\n";
                    
                }
                break;
            }
            case 6:
            {
                Book stdISBN;
                cout << "Enter Book's ISBN You Want to get details for: ";
                cin >> stdISBN.ISBN;
                for (int i = 0; i < stdISBN.ISBN.length(); i++)
                    stdISBN.ISBN[i] = toupper(stdISBN.ISBN[i]);
                validation = a.ValidCheck(a.books, stdISBN);
                if (validation)
                    a.specificBook(stdISBN);
                else
                    cout << "Error! There is no Book with that ISBN!\n";

                break;
            }
            case 7:
            {
                a.PrintAll();
                break;
            }
            case 8:
            {
                bool check = true;

                a.Sort(check);
                cout << "All the Books have been Sorted in Ascending Order.\n";
                break;
            }
            case 9:
            {
                bool check = false;

                a.Sort(check);
                cout << "All the Books have been Sorted in Descending Order.\n";

                break;
            }
            case 10:
            {
                system("CLS");
                cout << "Program Exiting...\n\n";
                exit(1);
            }
            default:
            {
                system("CLS");
                cout << setw(50) << "Invalid Input...Try Again: \n";
            }
            }
            cout << endl;
            menu();
            cin >> select_menu;
        } while (1);
    }

    else
    {
        cout << "Program Exiting...";
        return 0;
    }
}
void menu()
{
    cout<<setw(20)<<"MAIN MENU\n";
    cout << "(1)Add New Student\n";
    cout << "(2)Delete Existing Student. \n";
    cout << "(3)Show all Students. \n";
    cout << "(4)Add New Book.\n";
    cout << "(5)Delete Existing Book.\n";
    cout << "(6)Show particular Book.\n";
    cout << "(7)Show all Books.\n";
    cout << "(8)Sort Books in Ascending order.\n";
    cout << "(9)Sort Books in descending order.\n";
    cout << "(10)Exit\n\n";
    cout << setw(50) << "Enter the menu you would like to enter or enter 10 to exit:";
}

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class MyPhoneBook
{
private:
    string* names;
    string* phones;
    int phoneBookSize;



public:
    int count = 0;

    MyPhoneBook(int s)    //Takes size
    {
        phoneBookSize = s;
        names = new string[phoneBookSize];
        phones = new string[phoneBookSize];
    }


    MyPhoneBook(const MyPhoneBook& obj)  //Copy Constructor
    {
        phoneBookSize = obj.phoneBookSize;
        names = new string[phoneBookSize];
        phones = new string[phoneBookSize];

        for (int i = 0; i < phoneBookSize; i++)
        {
            names[i] = obj.names[i];
            phones[i] = obj.phones[i];
        }

    }


    bool addEntry(string name, string phone) //to add names & phones
    {
        if (count <= phoneBookSize)
        {
            names[count] = name;
            phones[count] = phone;
            count++;

            return true;
        }
        else {

            return false;
        }
    }



    bool displayEntryAtIndex(int x)
    {
        if (x < phoneBookSize)
        {
            cout << "Name:" << names[x] << endl;
            cout << "Phone:" << phones[x] << endl;
            return true;

        }
        else
        {
            return false;
        }
    }

    void displayEntryAtIndices(int* p)
    {
        for (int i = 0; i < phoneBookSize; i++)
        {
            if (p[i] == 1)
            {
                cout << "Name:" << names[i] << endl;
                cout << "Phone:" << phones[i] << endl;

            }
        }

    }
    void displayAll()
    {
        cout << "Phone book:" << endl;
        int c = 1;
        for (int i = 0; i < phoneBookSize; i++)
        {
            cout << "Name(" << c << "):" << names[i] << endl;
            cout << "Phone(" << c << "):" << phones[i] << endl;
            c++;
        }
    }


    int* findByName(string n) //search name
    {

        int* paraarr = new int[phoneBookSize];

        char arr[n.length() + 1];

        for (int i = 0; i < phoneBookSize; i++)
        {
            char arr[names[i].length() + 1];
            int b = 0;
            strcpy(arr, names[i].c_str());
            strcpy(arr, n.c_str());

            for (int j = 0; j < n.length(); j++)
            {
                if (arr[j] == arr[j])
                {
                    b++;
                }
            }

            if (b >= n.length())
            {
                paraarr[i] = 1;
            }
            else
            {
                paraarr[i] = 0;
            }


        }

        return paraarr;

    }




    int* findByPhone(string p)//search phone
    {


        int* paraarr = new int[phoneBookSize];

        char arrr[12];

        for (int i = 0; i < phoneBookSize; i++)
        {
            char arr[12];
            int b = 0;
            strcpy(arr, phones[i].c_str());
            strcpy(arrr, p.c_str());

            for (int j = 0; j < 12; j++)
            {
                if (arr[j] == arrr[j])
                {
                    b++;
                }
            }
            if (b >= 11)
            {
                paraarr[i] = 1;
            }
            else
            {
                paraarr[i] = 0;
            }


        }



        return paraarr;

    }
    bool updateNameAt(string n, int x)
    {
        if (x < phoneBookSize)
        {
            names[x] = n;

            return  true;
        }
        else
        {
            return false;
        }


    }

    bool updatePhoneAt(string p, int x)
    {
        if (x < phoneBookSize)
        {
            phones[x] = p;

            return  true;
        }
        else
        {
            return false;
        }


    }

    ~MyPhoneBook()
    {
        delete[] names;
        delete[] phones;


    }

};

bool funcheck(string p)
{
    int c = 0;

    char arr[11];
    strcpy(arr, p.c_str());
    for (int i = 0; i < 11; i++)
    {
        if (arr[i] >= '0' && arr[i] <= '9')
        {
            c++;

        }
    }
    if (c <= 10)
    {
        return true;
    }

    else
    {
        return false;
    }
}
int main()
{
    int s, c;
    string name;
    string phone;


    cout << "Enter the size of your book:";
    cin >> s;

    MyPhoneBook b1(s);
    int z = 1;
    for (int i = 0; i < s; i++)
    {
        cin.ignore();
        cout << "Enter name " << z << ":";
        getline(cin, name);

        cout << "Enter phone " << z << ":";
        cin >> phone;
        z++;

        while (funcheck(phone))
        {
            cout << "plz enter right phone:";
            cin >> phone;
        }

        if (b1.addEntry(name, phone))
        {
            continue;
        }
        else {
            break;
        }

    }


    cout << "Enter your choice:" << endl;



    while (c != 8)
    {
        int* paraarr = new int[s];


        cout << "1- Display all phone book" << endl;
        cout << "2- Search for entry/entries by name" << endl;
        cout << "3- Search for entry/entries by phones" << endl;
        cout << "4- Find an entry by index" << endl;
        cout << "5- Update name by index" << endl;
        cout << "6- Update phone by index" << endl;
        cout << "7- copy phone book to another and display entries of the new phone book" << endl;
        cout << "8- Exit" << endl;
        cout << "Choice:";
        cin >> c;
        cout << endl;

        if (c == 1)
        {

            b1.displayAll();
            cout << endl;

        }

        if (c == 2)
        {
            string n;
            int x = 1; //counter

            cin.ignore();
            cout << " Enter the name u would to search :";
            getline(cin, n);

            paraarr = b1.findByName(n);


            for (int i = 0; i < s; i++)
            {

                cout << " " << paraarr[i] << " ";

            }
            cout << endl;

        }
        if (c == 3)
        {
            string p;
            int x = 1;


            cout << " Enter the phone u would to search :";
            cin >> p;

            paraarr = b1.findByPhone(p);

            for (int j = 0; j < s; j++)
            {
                cout << " " << x << " ";
                x++;

            }
            cout << endl;


            for (int i = 0; i < s; i++)
            {

                cout << " " << paraarr[i] << " ";

            }
            cout << endl;
        }

        if (c == 4)
        {
            int i;

            cout << "Enter the specified index: ";
            cin >> i;

            bool ch = b1.displayEntryAtIndex(i - 1);

            if (ch != true)
            {
                cout << "u have enter index out of the range";
                cout << endl;
            }


        }

        if (c == 5)
        {
            string n;
            int x;

            cin.ignore();
            cout << "Enter new name:";
            getline(cin, n);
            cout << endl;

            cout << "enter the index:";
            cin >> x;

            bool ch = b1.updateNameAt(n, x - 1);

            if (ch)
            {
                cout << "the new name has been updated";
                cout << endl;
                b1.displayAll();
                cout << endl;

            }
            else
            {
                cout << "u have enter index out of the range";
                cout << endl;
            }

        }
        if (c == 5)
        {
            string n;
            int x;

            cin.ignore();
            cout << "Enter new name:";
            getline(cin, n);
            cout << endl;

            cout << "enter the index:";
            cin >> x;

            bool ch = b1.updateNameAt(n, x - 1);

            if (ch)
            {
                cout << "the new name has been updated";
                cout << endl;
                b1.displayAll();
                cout << endl;

            }
            else
            {
                cout << "u have enter index out of the range";
                cout << endl;
            }

        }

        if (c == 6)
        {

            string ph;
            int l;


            cout << "Enter new phone:";
            cin >> ph;
            cout << endl;

            while (funcheck(ph))
            {
                cout << "plz enter right phone:";
                cin >> ph;
            }

            cout << "enter the index:";
            cin >> l;

            bool ch = b1.updatePhoneAt(ph, l - 1);

            if (ch)
            {
                cout << "the new name has been updated";
                cout << endl;
                b1.displayAll();
                cout << endl;

            }
            else
            {
                cout << "u have enter index out of the range";
                cout << endl;
            }



        }

        if (c == 7)
        {
            MyPhoneBook b2 = b1;

            b2.displayAll();
        }



        delete[] paraarr;

    }




    return 0;
}

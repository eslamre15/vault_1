// dependancies...
#include<iostream>
#include<string>
#include<array>


/*
Nouns >> {  User-Name-Age-ID-Menu-Options   }
Verbs >> {  register-store-fetch-quit   }
*/


// custom class for our need
class User
{
    public:
        std::string Name;
        int Age;
    User(std::string N,int A)
    {
        Name = N;
        Age  = A;
    }
    User()
    {

    }
};

constexpr size_t MAX_INPUT_LIMIT = 100;
std::array<User , MAX_INPUT_LIMIT> users;

enum Options
{
    ADD = 1,
    FETCH,
    QUIT
};

void PrintMenu()        // function for printing the menu ...
{
std::cout << "User Registeration Application" << "\n\n";
std::cout << "Please select an option:" << "\n";
std::cout << "1: Add Record" << "\n";
std::cout << "2: Fetch Record" << "\n";
std::cout << "3: Quit" << "\n\n";
}

size_t GetOption()      // getting option form user
{
    size_t OP;
    std::cout << "Your choice: ";
    std::cin >> OP;
    return OP;
}

void RegisterRecord(std::string Name, int Age)        // function to add name and age to the array
{
    static int ID = 0;
    User New_Record{Name, Age};
    users[ID] = New_Record;
    ID++;
}

std::string StoreName()     //  get name form user
{
    std::cout << "\nPlease enter your Name: ";
    std::string name;
    std::cin >> name;
    return name;
}

size_t StoreAge()       //  get age form user
{
    size_t age;
    std::cout << "Please enter your Age: ";
    std::cin >> age;
    return age;
}

void RetrieveRecord()       //  retrieve a record of name and age by their ID 
{
    size_t ID;
    std::cout << "\nPlease enter your ID: ";
    std::cin >> ID;
    std::cout << "Name: " << users[ID].Name <<"\nage: " << users[ID].Age <<"\n\n";
}



int main()
{
    bool isRunning = true;
    while (isRunning)
    {
        PrintMenu();                         // Start view MENU
        size_t OP = GetOption();             //   get user option of choice
        switch (static_cast<Options>(OP))    //   Switch on Options enum 
        {
            case Options::ADD:
                {                            // Add a record option body
                    std::string name = StoreName(); 
                    size_t age = StoreAge();
                    RegisterRecord(name ,age);
                }
                break;
            case Options::FETCH:
                {                            // Fetch record option body
                    size_t ID;
                    RetrieveRecord();
                }
                break;
            case Options::QUIT:              // Quit option body
               isRunning = false;
               std::cout << "Program terminated." << '\n';
                break;
            default:
                break;
            }
    }
}




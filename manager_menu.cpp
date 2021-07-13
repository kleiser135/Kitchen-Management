#include <iostream>
using namespace std;
class manager{
    public:
    void manager_functions()
    {
        int choice;

        cout << " 1. menu edits\n";
        cout << " 2. open/reopen tabs\n";
        cout << " 3. get past check\n";
        cout << " 4. track inventory\n";
        cout << " 5. 86 items\n";
        cout << " 6. adjust checks\n";
        cout << " 7. track order times\n";
        cout << " 8. order inventory\n";
        cout << " 9. manager message\n";
        cout << "10. comps and discounts\n";
        cout << "11. back to main menu; \n";

        cout << "choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: cout << "menu edits\n";
            break;
            case 2: cout << "open/reopen tabs\n";
            break;
            case 3: cout << "get past check\n";
            break;
            case 4: cout << "track inventory\n";
            break;
            case 5: cout << "86 items\n";
            break;
            case 6: cout << "adjust checks\n";
            break;
            case 7: cout << "track order times\n";
            break;
            case 8: cout << "order inventory\n";
            break;
            case 9: cout << "manager message\n";
            break;
            case 10: cout << "comps and discounts\n";
            break;
            case 11: cout << "back to menu\n";
                     manager_menu();
            break;
        }
    }

    void manager_menu()
    {
        int choice;

        cout << "please make a selection" << endl;
        cout << "1. clock in \n";
        cout << "2. new table \n";
        cout << "3. manager functions \n";
        cout << "4. get check \n";
        cout << "5. close tab \n";
        cout << "6. clock out \n";
        cout << "7: exit \n";

        cin >> choice;

        switch(choice)
        {
            case 1: cout << "clock in \n";
            break;
            case 2: cout << "new table \n";
            break;
            case 3: cout << "manager functions \n";
                    manager_functions();
            break;
            case 4: cout << "get check \n";
            break;
            case 5: cout << "close tab \n";
            break;
            case 6: cout << "clock out \n";
            break;
            case 7: break;
        }
    }
    };
    int main()
    {
        manager m;
        m.manager_menu();
    return 0;
}
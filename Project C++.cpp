#include <iostream>
#include <string>
using namespace std;

const int N = 10;

void findMaxSalesIndexes(double sales[N], bool is_max[N]) {
    int max = 0;
    for (int i = 0; i < N; i++) {
        if (sales[i] > max) max = sales[i];
    }
    for (int i = 0; i < N; i++) {
        if (sales[i] == max) is_max[i] = true;
        else is_max[i] = false;
    }
}

void findMinSalesIndexes(double sales[N], bool is_min[N]) {
    int min = 0;
    for (int i = 0; i < N; i++) {
        if (sales[i] < min) min = sales[i];
    }
    for (int i = 0; i < N; i++) {
        if (sales[i] == min) is_min[i] = true;
        else is_min[i] = false;
    }
}

int main() {
    string products[N] = { "Apple", "Banana", "Bacon", "Egg", "Bread","Cereal", "Milk", "Coffee", "Soap", "Shampoo" };
    double prices[N] = { 10, 5, 50, 7, 15, 20, 10, 15, 18, 30 };
    double totalRe = 0;
    double totalsales[N] = { 0 };

    while (true) {
        double sales[N] = { 0 };
        double totalCost = 0;
        double currentTotalSales[N] = { 0 };
        string name;

        cout << "Admin : Hello, Welcome to the 8-12 store.\n";
        cout << "Admin : This is an automatic response message for online orders from our store.\n";
        cout << "Admin : Can you please tell me the name?" << endl;
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Admin : Hello, " << name << endl;
        cout << "Admin : Here is a list of all orders you can purchase. " << endl;
        cout <<"Admin : Please enter the quantity of the item to be purchased, or enter 0 to not purchase the item." << endl;

        for (int i = 0; i < N; i++) {
            cout << "How many " << products[i] << " do you want to buy? (0 for No): ";
            string selection_user;
            getline(cin, selection_user);

            int selection;
            if (selection_user != "No") {
                char* endptr;
                double value = strtol(selection_user.c_str(), &endptr, 10);
                if (endptr == selection_user || *endptr != '\0') {
                    selection = -1;
                }
                else selection = value;
            }
            else continue;

            if (selection > 0) {
                totalCost += selection * prices[i];
                sales[i] += selection;
            }
            else if (selection < 0) {
                cout << "Wrong input. Please enter a non-negative integer or 0 for No." << endl;
                i--; // Repeat the iteration for the same product
            }
        }

        // Discount
        string Allmember;
        cout << "\nAdmin : Do you have Allmember?\n";
        cout << "Enter Yes or No: ";
        getline(cin, Allmember);
        double RATIO = 0.9;
        if (Allmember == "Yes" || Allmember == "yes") {
            totalCost = totalCost * RATIO;
            cout << "\nHere are all the items " << name << " ordered. (Discounted)" << endl;
            for (int i = 0; i < N; i++) {
                double totalsold = sales[i] * prices[i];
                if (totalsold > 0)
                    cout << products[i] << ": " << totalsold * RATIO << " Baht" << endl;
                currentTotalSales[i] += sales[i];
            }
        }
        else {
            cout << "\nHere are all the items " << name << " ordered." << endl;
            for (int i = 0; i < N; i++) {
                double totalsold = sales[i] * prices[i];
                if (totalsold > 0)
                    cout << products[i] << ": " << totalsold << " Baht" << endl;
                currentTotalSales[i] += sales[i];

            }
        }

        cout << "\nTotal cost: " << totalCost << " Baht" << endl;
        cout << "Please check whether your order is correct or not." << endl;
        cout << "If correct, please enter Correct. If not, enter No." << endl;
        string check;
        getline(cin, check);
        if (check == "correct" || check == "Correct") {
            totalRe += totalCost;
            for (int i = 0; i < N; i++) {
                totalsales[i] += currentTotalSales[i];
            }

            cout << "Thank you for using the service." << endl;
            cout << "Have a good day :)\n\n\n\n\n\n" << endl;
            cout << "Enter 'Close' to end the day or input anything else to continue: ";
            string endday;
            getline(cin, endday);
            cout << "\n\n\n\n\n";
            if (endday == "Close" || endday == "close") break;
        }
        else {
            cout << "We apologize for the inconvenience caused. You can reorder by here.\n\n";
            continue;
        }
    }

    // Part Manager
    cout << "\nToday's Summary: " << endl;

    bool maxSalesIndexes[N] = { false };
    findMaxSalesIndexes(totalsales, maxSalesIndexes);

    cout << "Best selling product:" << endl;
    for (int i = 0; i < N; i++) {
        if (maxSalesIndexes[i]) {
            cout << "  - " << products[i] << " (" << totalsales[i] << " units) " << endl;
        }
    }

    bool minSalesIndexes[N] = { false };
    findMinSalesIndexes(totalsales, minSalesIndexes);

    cout << "Worst selling product:" << endl;
    for (int i = 0; i < N; i++) {
        if (minSalesIndexes[i]) {
            cout << "  - " << products[i] << " (" << totalsales[i] << " units) " << endl;
        }
    }

    cout << "Should be bought to replenish stock:" << endl;
    for (int i = 0; i < N; i++) {
        if (maxSalesIndexes[i]) {
            cout << "  - " << products[i]  << endl;
        }
    }

    cout << "Total revenue: " << totalRe << " Baht" << endl;

    return 0;
}

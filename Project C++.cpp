#include <iostream>
#include <string>

using namespace std;

const int N  = 10;
// Function to find the index of the product with the highest sales
int findMaxSalesIndex(const int sales[]) {
    int maxsold = 0;
    for (int i = 1; i < N; i++) {
        if (sales[i] > sales[maxsold]) {
            maxsold = i;
        }
    }
    return maxsold;
}

// Function to find the index of the product with the lowest sales
int findMinSalesIndex(const int sales[]) {
    int minsold = 0;
    for (int i = 1; i < N; i++) {
        if (sales[i] < sales[minsold]) {
            minsold = i;
        }
    }
    return minsold;
}

int main() {
    string products[N] = {"Apple", "Banana", "Bacon", "Egg", "Bread","Cereal", "Milk", "Coffee", "Soap", "Shampoo"};
    int prices[N] = {10, 5, 50, 7, 15, 20, 10, 15, 18, 30};
    int totalRe = 0;
    int totalsales[N] = {0};

    while(true) {
        int sales[N] = {0}; 
        int totalCost = 0; 
        string name ;

        cout << "Hello, Welcome to the 8-12 store.\n";
        cout << "This is an automatic response message for online orders from our store.\n";
        cout << "Can you please tell me the name?"<<endl;
        getline(cin,name);
        cout << "Hello, Mr. "<< name << endl;
        cout << "Here is a list of all orders you can purchase. Please enter the quantity of the item to be purchased, or enter 0 to not purchase the item." << endl;

        for (int i = 0; i < N; i++) {
            int selection;
            cout << "How many " << products[i] << " do you want to buy? (0 for No): ";
            cin >> selection;

            if (selection > 0) {
                totalCost += selection * prices[i];
                sales[i] += selection;
            } else if (selection < 0) {
                cout << "Wrong input. Please enter a non-negative integer or 0 for No." << endl;
                i--; // Repeat the iteration for the same product
            }
        }

        cout << "\nHere are all the items Mr. "<< name<< " ordered." << endl;
        for (int i = 0; i < N; i++) {
            int totalsold = sales[i] * prices[i];
            if (totalsold > 0)
                cout << products[i] << ": " << totalsold << " Baht" << endl;
                totalsales[i] += sales[i];
        }

        totalRe += totalCost;

        cout << "\nTotal cost: " << totalCost << " Baht" << endl;
        string check;
        cout << "Please check whether your order is correct or not."<<endl;
        cout << "If correct, please enter Correct. If not, enter No."<<endl;
        cin >> check ;
        if (check == "correct" || check =="Correct" ){
             cout << "Thank you for using the service."<<endl;
             cout <<" Have a good day :) " <<endl;
             string Endday;
             cout << "Enter 'Close' to end the day or input anything else to continue: ";
             cin >> Endday;
             if (Endday == "Close" || Endday == "close") break;
        }
        else {
            
        }
    }

    // part seller
    cout << "\nToday's Summary: " << endl;

    int maxSalesIndex = findMaxSalesIndex(totalsales);
    cout << "Best selling product: " << products[maxSalesIndex] << " (" << totalsales[maxSalesIndex] << " units)" << endl;

    int minSalesIndex = findMinSalesIndex(totalsales);
    cout << "Worst selling product: " << products[minSalesIndex] << " (" << totalsales[minSalesIndex] << " units)" << endl;

    cout << "Total revenue: " << totalRe << " Bath" << endl;

    return 0;
}

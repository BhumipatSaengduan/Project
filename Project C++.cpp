#include <iostream>
#include <map>
#include <chrono>

using namespace std;

int main() {
    map<int, string> products = {
        {1, "Apple"},
        {2, "Banana"},
        {3, "Bacon"},
        {4, "Egg"},
        {5, "Bread"},
        {6, "Cereal"},
        {7, "Milk"},
        {8, "Coffee"},
        {9, "Soap"},
        {10, "Shampoo"}
    };

    map<int, int> prices = {
        {1, 10},
        {2, 5},
        {3, 50},
        {4, 7},
        {5, 15},
        {6, 20},
        {7, 10},
        {8, 15},
        {9, 18},
        {10, 30}
    };

    map<int, int > sales ;
    int totalRe = 0;
    while(true){
      int Itemsold = 0;
      int selection;
      int totalCost = 0;
      
      cout << "Hello, customer "<<"\n";

      for (int i = 1; i <= 10; ++i) {
        cout << "Do you want to buy " << products[i] << "? (1 for Yes, 0 for No): ";
        cin >> selection;

        if (selection == 1) {
            totalCost += prices[i];
            ++Itemsold;
        } else if (selection != 0) {
            cout << "Wrong input. Please enter 1 for Yes or 0 for No." << endl;
            --i; // Repeat the iteration for the same product
        }
      }
      cout << "\nSummary:" << endl;
      for (int i = 1; i <= 10; ++i) {
         if (prices[i] > 0) {
            cout << products[i] << ": " << prices[i] << " Baht" << endl;
         }
      }
      totalRe += totalCost;
      sales[Itemsold]++;

      cout << "\nTotal cost: " << totalCost << " Baht" << endl;
      string Endday;
      cout << "Enter 'Close' to end the day or input anything else to continue : ";
      cin >> Endday;
      
      if (Endday == "Close" or Endday == "close") break;
    }
    // summay
   cout << "\nToday's Summary: " << endl ;
   cout << "Total revenue: "<< totalRe <<" Bath" << endl ;

   //find the most Sold product
   int maxsold = 0 ;
   for (auto& pair : sales){
    maxsold = max(maxsold, pair.first);
   } 
   cout << "Product(s) sold the most: ";
   for (auto& pair : sales){
       if (pair.first == maxsold) cout << products[pair.first]<< " " ;
   }
   cout << endl ;
   
   // find min product sold 
   int minsold = sales.begin()->first; 
   for (auto& pair : sales){
    minsold = min(minsold, pair.first);
   }
   cout << "Product(s) that sell the least: ";
   for (auto& pair : sales){
       if (pair.first == minsold) cout << products[pair.first]<< " " ;
   }
   return 0 ;   
}

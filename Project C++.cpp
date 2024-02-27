#include <iostream>
#include <map>
#include <chrono>
#include <climits>

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
        cout << "How many " << products[i] << "Do you want to buy ? (0 for No): ";
        cin >> selection;

        if (selection > 0 ) {
            totalCost += selection*prices[i];
            Itemsold += selection;
            sales[i] += selection;
        } else if (selection <  0) {
            cout << "Wrong input. Please enter quantity or 0 for No." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            --i; // Repeat the iteration for the same product
        }
      }
      cout << "\nSummary:" << endl;
      for (int i = 1; i <= 10; ++i) {
         if (prices[i] > 0) {
            int numsold = sales[i];
            int totalnumsold = numsold*prices[i];
            if( totalnumsold > 0 ) cout << products[i] << ": " << totalnumsold << " Baht" << endl;
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
   int maxsold = 0;
   int minsold = INT_MAX;
   for (const auto &pair :sales){
     maxsold = max(maxsold,pair.second);
     minsold = min(minsold,pair.second);
   }

   cout << "Product(s) sold the most: ";
   bool firstmaxsold = true;
   for (const auto& pair : sales){
       if (pair.first == maxsold){
        if(!firstmaxsold){
            cout <<", ";
        }
        cout << products[pair.second];
        firstmaxsold = false;
       }
   }
   cout << endl ;
   
   // find min product sold 
   if(minsold == 0) cout <<"No products sold the least." << endl ;
   else {
   cout << "Product(s) that sell the least: ";
   bool firstminsold = true;
   for (const auto& pair : sales){
       if (pair.first == minsold) {
        if(!firstminsold){
            cout << ", ";
        }

        cout << products[pair.second];
        firstminsold = false ;
       }
   }
   cout << endl;
   }
   return 0 ;   
}


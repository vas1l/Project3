#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "project3.h"
#include "csvparser.h"

using namespace std;

int main() {
    // Create a hash table and trie
  //  hashTbl data;
    trie data2;

    // Read the CSV file
   // readCSV("data.csv", data, data2);

    

// Search for a country in the hash table
    cout << "Searching for country with ISO3 code 'USA' in the hash table:" << endl;
 //   data.printCountry("USA");
 //   data.plotCountry("USA");

    data2.printCountry("USA");
    data2.plotCountry("USA");

    return 0;
}
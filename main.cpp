#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "project3.h"
#include "CsvReader.h"


using namespace std;

int main() {
// Create a hash table and trie

trie data2;
hashTbl data;
 
  // Print the hash table
  //  cout << "Printing the hash table:" << endl;
  //  data2.printTable();

  // Load the csv into trie, hash
    std::string file = "data.csv"; //replace with your path
    CsvReader reader(file, ',');
    reader.Parse();
    int j = 0;
    string NA = "";
      for (auto const &row : reader.GetRows()) {
      if (j != 0){
            country c;
            c.name = row[1];
            c.ISO2 = row[2];
            c.ISO3 = row[3];
            c.Indicator = row[4];
            c.Unit = row[5];
            c.Source = row[6];
            c.CTS_CODE = row[7];
            c.CTS_NAME = row[8];
            c.CTS_FULL_DESCRIPTION = row[9];
            for (int i = 0; i < row.size()-10; i++){
                if (row[i+10] != NA)
                c.temperatureChange[1961+i] = std::stod(row[i+10]);
            }
            c.computeTrend();
            data.addCountry(c); 
            data2.addCountry(c);    
       }
          j++;
  
        }

  
  data2.printRanking();

// Search for a country in the hash table
    std::cout << "Getting for country with ISO3 code 'USA' in TRIE and printing from the COUNTRY class:" << endl;
 //   data.printCountry("USA");
 
    country c = data2.getCountry("USA");
    c.print();
   // Eigen::Vector2f Trend = c.computeTrend();
    c.printTrend();
    std::cout << "==================================================================================" << endl;

    std::cout << "Searching for country with ISO3 code 'USA' and printing it from the TRIE class:" << endl;
    data2.printCountry("USA");

        std::cout << "==================================================================================" << endl;
    
    std::cout << "Getting for country with ISO3 code 'USA' in HASH and printing from the COUNTRY class:" << endl;
    country c2 = data.getCountry("USA");
    c2.print();

    std::cout << "==================================================================================" << endl;

    std::cout << "Searching for country with ISO3 code 'USA' and printing it from the HASH class:" << endl;
    // data2.plotCountry("USA");

    data.printCountry("USA");
    
    std::cout << "==================================================================================" << endl;

  // data.printTable();
  //  data2.printTrie();
        
    return 0;
}
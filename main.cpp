#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "project3.h"
#include "CsvReader.h"


using namespace std;

int main() {
    // Create a hash table and trie
  //  hashTbl data;
trie data2;
 
  // Print the hash table
  //  cout << "Printing the hash table:" << endl;
  //  data2.printTable();

  // Load the csv into trie, hash
    std::string file = "Indicator_3_1_Climate_Indicators_Annual_Mean_Global_Surface_Temperature_577579683071085080.csv";
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
            data2.addCountry(c);     
       }
          j++;
          int x =0;
        }

    int y = 0;  

// Search for a country in the hash table
    std::cout << "Searching for country with ISO3 code 'USA' in trie:" << endl;
 //   data.printCountry("USA");
    
    country c = data2.getCountry("USA");
    c.print();
    
    std::cout << "Searching for country with ISO3 code 'USA' in trie:" << endl;
    data2.printCountry("USA");
    
        
    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include "project3.h"
#include "CsvReader.h"

using namespace std;

int main() {
    trie data2;
    hashTbl data;

    string file = "data.csv";
    CsvReader reader(file, ',');
    if (!reader.Parse()) {
        cerr << "Failed to open or parse the CSV file." << endl;
        return 1;
    }

    vector<vector<string>> rows = reader.GetRows();
    if (rows.empty()) {
        cerr << "No data in CSV file." << endl;
        return 1;
    }
 
    // Time loading into hash
    auto start = chrono::high_resolution_clock::now();
    for (size_t i = 1; i < rows.size(); ++i) {
        const auto& row = rows[i];
        if (row.size() < 10) continue;

        country c;
        try {
            c.name = row[1];
            c.ISO2 = row[2];
            c.ISO3 = row[3];
            c.Indicator = row[4];
            c.Unit = row[5];
            c.Source = row[6];
            c.CTS_CODE = row[7];
            c.CTS_NAME = row[8];
            c.CTS_FULL_DESCRIPTION = row[9];
            for (size_t j = 10; j < row.size(); ++j) {
                if (!row[j].empty() && row[j] != "NA")
                    c.temperatureChange[1961 + (j - 10)] = stod(row[j]);
            }
        } catch (const std::exception& e) {
            cerr << "Error processing data for country: " << c.ISO3 << " - " << e.what() << endl;
            continue; // Skip to next row on error
        }

        c.computeTrend();
        data.addCountry(c);
    //    data2.addCountry(c);
    }
    auto end = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed_hash = end - start;

    // Time loading into trie
    auto start1 = chrono::high_resolution_clock::now();
    for (size_t i = 1; i < rows.size(); ++i) {
        const auto& row = rows[i];
        if (row.size() < 10) continue;

        country c;
        try {
            c.name = row[1];
            c.ISO2 = row[2];
            c.ISO3 = row[3];
            c.Indicator = row[4];
            c.Unit = row[5];
            c.Source = row[6];
            c.CTS_CODE = row[7];
            c.CTS_NAME = row[8];
            c.CTS_FULL_DESCRIPTION = row[9];
            for (size_t j = 10; j < row.size(); ++j) {
                if (!row[j].empty() && row[j] != "NA")
                    c.temperatureChange[1961 + (j - 10)] = stod(row[j]);
            }
        } catch (const std::exception& e) {
            cerr << "Error processing data for country: " << c.ISO3 << " - " << e.what() << endl;
            continue; // Skip to next row on error
        }

        c.computeTrend();
       // data.addCountry(c);
       data2.addCountry(c);
    }
    auto end1 = std::chrono::high_resolution_clock::now();
   std::chrono::duration<double> elapsed_trie = end1 - start1;

    cout << "Time taken to load data into hash table: " << elapsed_hash.count() << "s" << endl;
    cout << "Time taken to load data into trie: " << elapsed_trie.count() << "s" << endl;

    
    data2.printRanking();
    data.computeAndPrintRanking();

    data2.clearFile("country_data.txt");
    //data.outputCountryInfo("AFG");
    data2.outputCountryInfo2(data2.getRoot(),"USA");

    cout << "Getting for country with ISO3 code 'USA' in TRIE and printing from the COUNTRY class:" << endl;
    country c = data2.getCountry("USA");
    c.print();
    c.printTrend();

    cout << "==================================================================================" << endl;
    cout << "Searching for country with ISO3 code 'USA' and printing it from the HASH class:" << endl;
    country c2 = data.getCountry("USA");
    c2.print();

    cout << "==================================================================================" << endl;

    return 0;
}
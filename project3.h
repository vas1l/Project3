#include <iostream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm> 
#include <sstream>

using namespace std;
/*
CSV parser store each row as a country oin the country class
hash class stores countries in hash table based on ISO3 code
trie class stores countries in trie based on country ISO3 code
*/

class country{
    public:
    string name;
    string ISO2;
    string ISO3;
    string Indicator;
    string Unit;
    string Source;
    string CTS_CODE;
    string CTS_NAME;
    string CTS_FULL_DESCRIPTION;
    map<int, double> temperatureChange;

    country(string name, string ISO2, string ISO3, string Indicator, string Unit, string Source, string CTS_CODE, string CTS_NAME, string CTS_FULL_DESCRIPTION){
        this->name = name;
        this->ISO2 = ISO2;
        this->ISO3 = ISO3;
        this->Indicator = Indicator;
        this->Unit = Unit;
        this->Source = Source;
        this->CTS_CODE = CTS_CODE;
        this->CTS_NAME = CTS_NAME;
        this->CTS_FULL_DESCRIPTION = CTS_FULL_DESCRIPTION;
    }
    //Default constructor
    country() {
        name = "";
        ISO2 = "";
        ISO3 = "";
        Indicator = "";
        Unit = "";
        Source = "";
        CTS_CODE = "";
        CTS_NAME = "";
        CTS_FULL_DESCRIPTION = "";
        // Initialize temperatureChange as an empty map
    }

    void addTemperatureChange(int year, double temperature){
        temperatureChange[year] = temperature;
    }

    void print(){
        cout << "Country: " << name << endl;
        cout << "ISO2: " << ISO2 << endl;
        cout << "ISO3: " << ISO3 << endl;
        cout << "Indicator: " << Indicator << endl;
        cout << "Unit: " << Unit << endl;
        cout << "Source: " << Source << endl;
        cout << "CTS_CODE: " << CTS_CODE << endl;
        cout << "CTS_NAME: " << CTS_NAME << endl;
        cout << "CTS_FULL_DESCRIPTION: " << CTS_FULL_DESCRIPTION << endl;
        cout << "Temperature Change: " << endl;
        for(auto it = temperatureChange.begin(); it != temperatureChange.end(); it++){
            cout << it->first << ": " << it->second << endl;
        }
    }
    
    void printTemperatureChange(int year){
        cout << "Temperature Change in " << year << ": " << temperatureChange[year] << endl;
    }

    void PlotTemperatureChange(){
        cout << "Plotting temperature change for " << name << endl;
        cout << "Year" << setw(20) << "Temperature Change" << endl;
        // bar plot of tempereture change year on the x-axis and temperature change on the y-axis, positive values in green above zero and negative values in red below zero 
        for(auto it = temperatureChange.begin(); it != temperatureChange.end(); it++){
            cout << it->first << setw(20) << it->second << endl;
        }
    }
    
};

class hashTbl{
    private:
    int size = 500;
    // change the hash function to take in a country.ISO3 and return an integer - also make it more sophisticated
    int hashfn(string ISO3){
        unsigned long i = 0;
        for(int j = 0; ISO3[j];i++){
            
            i=i+ISO3[j] ;
                   }
        return i%size;
    }
    
    public:
    country* countries = new country[size];
    
    void addCountry(country c){
           }
    
    country getCountry(string ISO3){
    }

    void removeCountry(string ISO3){
    }

    void print(){
        for(int i = 0; i < size; i++){
            countries[i].print();
            //countries[i].PlotTemperatureChange();
        }
    }

    void plot(){
        for(int i = 0; i < size; i++){
            countries[i].PlotTemperatureChange();
        }
    }

    void plotCountry(string ISO3){
        country c = getCountry(ISO3);
        c.PlotTemperatureChange();
    }

    void printCountry(string ISO3){
        country c = getCountry(ISO3);
        c.print();
    }

};

class trie{
    private:
    struct Node{
        country c;
        Node* children[26];
    };
    
    public:
    
    
    void addCountry(country c){
           }
    
    country getCountry(string ISO3){
    }

    void removeCountry(string ISO3){
    }

    void print(){
    }

    void plot(){
        
    }

     void plotCountry(string ISO3){
        country c = getCountry(ISO3);
        c.PlotTemperatureChange();
    }

    void printCountry(string ISO3){
        country c = getCountry(ISO3);
        c.print();
    }

};





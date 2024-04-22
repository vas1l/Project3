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

    void updateCountry(country c){
        name = c.name;
        ISO2 = c.ISO2;
      //  ISO3 = c.ISO3;  
        Indicator = c.Indicator;
        Unit = c.Unit;
        Source = c.Source;
        CTS_CODE = c.CTS_CODE;
        CTS_NAME = c.CTS_NAME;
        CTS_FULL_DESCRIPTION = c.CTS_FULL_DESCRIPTION;
        temperatureChange = c.temperatureChange;
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

class hashTbl {
private:
    int size = 1000;
    country* countries;

    //to convert the ISO3 string into an index
    int hashfn(const string& ISO3) {
        unsigned long hash = 0;
        for (char ch : ISO3) {
            hash = (hash * 1087 + ch) % size;
        }
        return hash % size;
    }

public:
    hashTbl() {
        countries = new country[size];
        for (int i = 0; i < size; ++i) {
            countries[i] = country();  // Initialize each element with an empty country
        }
    }

    ~hashTbl() {
        delete[] countries;
    }


    void addCountry(const country& c) {
        int index = hashfn(c.ISO3);
        countries[index] = c;
    }

    country getCountry(const string& ISO3) {
        int index = hashfn(ISO3);
        return countries[index];
    }

    void plotCountry(const string& ISO3) {
        country c = getCountry(ISO3);
        c.PlotTemperatureChange();
    }

    void printCountry(const string& ISO3) {
        country c = getCountry(ISO3);
        c.print();
    }

    void printTable() {
        for (int i = 0; i < size; ++i) {
            if (countries[i].ISO3 != "") {  // Only print non-empty entries
                std::cout << "Index " << i << ": " << std::endl;
                countries[i].print();
            }
        }
    }

    void outputCountryInfo(const std::string& ISO3) {
        string filepath = "C:\\Users\\dalva\\OneDrive\\Desktop\\Project3\\Project3\\country_data.txt"; //replace with your path
        int index = hashfn(ISO3);
        std::ofstream file(filepath);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filepath << std::endl;
            return;
        }

        if (countries[index].ISO3 == ISO3) { // Check if the correct country is at this index
            file << "Country: " << countries[index].name << std::endl;
            file << "ISO2: " << countries[index].ISO2 << std::endl;
            file << "ISO3: " << countries[index].ISO3 << std::endl;
            file << "Indicator: " << countries[index].Indicator << std::endl;
            file << "Unit: " << countries[index].Unit << std::endl;
            file << "Source: " << countries[index].Source << std::endl;
            file << "CTS_CODE: " << countries[index].CTS_CODE << std::endl;
            file << "CTS_NAME: " << countries[index].CTS_NAME << std::endl;
            file << "CTS_FULL_DESCRIPTION: " << countries[index].CTS_FULL_DESCRIPTION << std::endl;
            file << "Temperature Change:" << std::endl;
            for (auto& temp : countries[index].temperatureChange) {
                file << temp.first << ": " << temp.second << std::endl;
            }
        } else {
            file << "Country not found." << std::endl;
        }

        file.close();
    }
};
//modified trie class, used digital ocean as reference - https://www.digitalocean.com/community/tutorials/trie-data-structure-in-c-plus-plus
class trie{
    private:
    //node struct
    struct Node{
        country ctr;
        Node* children[26];
        bool is_leaf = false;

    Node(country c) {
        ctr = c;
        for (int i=0; i<26; i++)
            children[i] = NULL;
            is_leaf = true;
    }


 
    Node() {
        ctr = country();
        for (int i=0; i<26; i++)
            children[i] = NULL;
            is_leaf = false;
    };
    };
   
   Node* root = new Node();
   void releaseNode(Node* node) {
    // Free the node series
    for(int i=0; i<26; i++) {
        if (node->children[i] != NULL) {
            releaseNode(node->children[i]);
        }
        else {
            continue;
        }
    }
    free(node);
   }
    
    public:
    //add country using ISO3 code
    void addCountry(country c){
     Node* temp = root; 
     string word = c.ISO3;
     

    for (int i=0; word[i] != '\0'; i++) {
       
        int idx = (int) word[i] - 'A';
        if (temp->children[idx] == NULL) {
            
            temp->children[idx]= new Node(c);


        }
        else {
         cout << "Country already exists...updating with new values" << endl;
         updateCountryinTrie(c);
        }
       
        temp = temp->children[idx];
    }
    
    temp->is_leaf = true;
    
   }
 
    //getcountry method to retrieve a country's data
    country getCountry(string ISO3){
    Node* temp = root;
    country dummy = country();
    for(int i=0; ISO3[i]!='\0'; i++)
    {
        int position = ISO3[i] - 'A';
        if (temp->children[position] == NULL)
            {cout << "Country not found" << endl;
            return dummy;}

        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1){return temp->ctr;}
    else {cout << "Country not found" << endl;
    return dummy;}
    }
    //update country method to update a country's data
    void updateCountryinTrie(country c){
    Node* temp = root;
   
    string ISO3=c.ISO3;
    for(int i=0; ISO3[i]!='\0'; i++)
    {
        int position = ISO3[i] - 'A';
        if (temp->children[position] == NULL) return;
                       
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1){
            temp->ctr.updateCountry(c);
        }
     }
    
     void plotCountry(string ISO3){
        country c = getCountry(ISO3);
        c.PlotTemperatureChange();
    }
    //print country method
    void printCountry(string ISO3){
        country c = getCountry(ISO3);
        c.print();
    }

};





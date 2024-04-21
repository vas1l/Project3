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
        country ctr;
        Node* children[26];
        bool is_leaf = false;

    Node(country c) {
        ctr = c;
        for (int i=0; i<26; i++)
            children[i] = NULL;
            is_leaf = true;
    }

    /*string dummy_ISO3 = "\0";
    string dummy_name = "\0";
    string dummy_ISO2 = "\0";
    string dumm_ISO3 = "\0";
    string dummy_Indicator = "\0";
    string dummy_Unit = "\0";
    string dummy_Source = "\0";
    string dummy_CTS_CODE = "\0";
    string dummy_CTS_NAME = "\0";
    string dummy_CTS_FULL_DESCRIPTION = "\0";*/
 
    Node() {
        ctr = country();
        for (int i=0; i<26; i++)
            children[i] = NULL;
            is_leaf = false;
    };
    };
   
   Node* root = new Node();
   void releaseNode(Node* node) {
    // Free the trienode sequence
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
     
    void addCountry(country c){
     Node* temp = root; 
     string word = c.ISO3;
     

    for (int i=0; word[i] != '\0'; i++) {
       
        int idx = (int) word[i] - 'A';
        if (temp->children[idx] == NULL) {
            
            temp->children[idx]= new Node(c);
          //  temp->is_leaf = true;

        }
        else {
         cout << "Country already exists...updating with new values" << endl;
         updateCountryinTrie(c);
        }
       
        temp = temp->children[idx];
    }
    
    temp->is_leaf = true;
    
   }
 
    
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

    void updateCountryinTrie(country c){
    Node* temp = root;
    //country dummy = country();
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

    void printCountry(string ISO3){
        country c = getCountry(ISO3);
        c.print();
    }

};





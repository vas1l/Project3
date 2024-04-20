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

    void removeCountry(string ISO3){
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
        bool is_leaf;
    };

    
   Node* makeNode(country c) {
    // Allocate memory for a TrieNode
    Node* node = (Node*) calloc (1, sizeof(Node));
    for (int i=0; i<26; i++)
        node->children[i] = NULL;
    node->is_leaf = false;
    node->ctr = c;
    return node;
   }

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
     
    Node* addCountry(Node* root, country c){
     Node* temp = root; 
     string word = c.ISO3;

    for (int i=0; word[i] != '\0'; i++) {
       
        int idx = (int) word[i] - 'a';
        if (temp->children[idx] == NULL) {
            
            temp->children[idx] = makeNode(c);
        }
        else {
         cout << "Country already exists...updating with new values" << endl;
         updateCountryinTrie(root, c);
        }
       
        temp = temp->children[idx];
    }
    
    temp->is_leaf = true;
    return root;
   }
 
    
    country getCountry(Node* root, string ISO3){
    Node* temp = root;
    country dummy = country("dummy", "dummy", '\0', "dummy", "dummy", "dummy", "dummy", "dummy", "dummy");
    for(int i=0; ISO3[i]!='\0'; i++)
    {
        int position = ISO3[i] - 'a';
        if (temp->children[position] == NULL)
            {cout << "Country not found" << endl;
            return dummy;}

        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1){return temp->c;}
    else {cout << "Country not found" << endl;
    return dummy;}
    }

    void updateCountryinTrie(Node* root, country c){
    Node* temp = root;
    country dummy = country("dummy", "dummy", '\0', "dummy", "dummy", "dummy", "dummy", "dummy", "dummy");
    string ISO3=c.ISO3;
    for(int i=0; ISO3[i]!='\0'; i++)
    {
        int position = ISO3[i] - 'a';
        if (temp->children[position] == NULL) return;
                       
        temp = temp->children[position];
    }
    if (temp != NULL && temp->is_leaf == 1){
            temp->ctr.updateCountry(c);
        }
     }
    int check_divergence(Node* root, country c) {
    // Checks if there is branching at the last character of word
    // and returns the largest position in the word where branching occurs
    Node* temp = root;
    string word = c.ISO3;
    int len = word.length();
    if (len == 0)
        return 0;
    // We will return the largest index where branching occurs
    int last_index = 0;
    for (int i=0; i < len; i++) {
        int position = word[i] - 'a';
        if (temp->children[position]) {
            // If a child exists at that position
            // we will check if there exists any other child
            // so that branching occurs
            for (int j=0; j<26; j++) {
                if (j != position && temp->children[j]) {
                    // We've found another child! This is a branch.
                    // Update the branch position
                    last_index = i + 1;
                    break;
                }
            }
            // Go to the next child in the sequence
            temp = temp->children[position];
        }
    }
    return last_index;
}

char* find_longest_prefix(Node* root, country c) {
    // Finds the longest common prefix substring of word
    // in the Trie
    string word = c.ISO3;
    if (word[0] == '\0')
        return NULL;
    // Length of the longest prefix
    int len = word.length();

    // We initially set the longest prefix as the word itself,
    // and try to back-tracking from the deepst position to
    // a point of divergence, if it exists
    char* longest_prefix = (char*) calloc (len + 1, sizeof(char));
    for (int i=0; word[i] != '\0'; i++)
        longest_prefix[i] = word[i];
    longest_prefix[len] = '\0';

    // If there is no branching from the root, this
    // means that we're matching the original string!
    // This is not what we want!
    int branch_idx  = check_divergence(root, c) - 1;
    if (branch_idx >= 0) {
        // There is branching, We must update the position
        // to the longest match and update the longest prefix
        // by the branch index length
        longest_prefix[branch_idx] = '\0';
        longest_prefix = (char*) realloc (longest_prefix, (branch_idx + 1) * sizeof(char));
    }

    return longest_prefix;
}

bool is_leaf_node(Node* root, country c) {
    // Checks if the prefix match of word and root
    // is a leaf node
    Node* temp = root;
    string word = c.ISO3;
    for (int i=0; word[i]; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            temp = temp->children[position];
        }
    }
    return temp->is_leaf;
}

Node* removeCountry(Node* root, country c) {
    // Will try to delete the word sequence from the Trie only it 
    // ends up in a leaf node
    string word = c.ISO3;
    if (!root)
        return NULL;
    if (word[0] == '\0')
        return root;
    // If the node corresponding to the match is not a leaf node,
    // we stop
    if (!is_leaf_node(root, c)) {
        return root;
    }
    Node* temp = root;
    // Find the longest prefix string that is not the current word
    char* longest_prefix = find_longest_prefix(root, c);
    //printf("Longest Prefix = %s\n", longest_prefix);
    if (longest_prefix[0] == '\0') {
        free(longest_prefix);
        return root;
    }
    // Keep track of position in the Trie
    int i;
    for (i=0; longest_prefix[i] != '\0'; i++) {
        int position = (int) longest_prefix[i] - 'a';
        if (temp->children[position] != NULL) {
            // Keep moving to the deepest node in the common prefix
            temp = temp->children[position];
        }
        else {
            // There is no such node. Simply return.
            free(longest_prefix);
            return root;
        }
    }
    // Now, we have reached the deepest common node between
    // the two strings. We need to delete the sequence
    // corresponding to word
    int len = word.length();
    for (; i < len; i++) {
        int position = (int) word[i] - 'a';
        if (temp->children[position]) {
            // Delete the remaining sequence
            Node* rm_node = temp->children[position];
            temp->children[position] = NULL;
            releaseNode(rm_node);
        }
    }
    free(longest_prefix);
    return root;
   }

     void plotCountry(Node* root,string ISO3){
        country c = getCountry(root, ISO3);
        c.PlotTemperatureChange();
    }

    void printCountry(Node* root, string ISO3){
        country c = getCountry(root, ISO3);
        c.print();
    }

};





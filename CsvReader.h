#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <regex>
//modified code  from stack exchange - https://codereview.stackexchange.com/questions/268180/simple-lightweight-csv-reader-in-c
class CsvReader {
    using Delimiter = const char;
    using Rows = std::vector<std::vector<std::string>>;

    std::string m_FileName;
    Delimiter m_Delimiter;
    Rows m_Rows;
    //parse line function that reads the csv file and seperates according to quotations and commas
    void ParseLine(const std::string &line) {

        std::stringstream tokenizer(line);
        std::vector<std::string> cols;
        std::string col, push_col("");
        bool quotes = false;
        

        while (std::getline(tokenizer, col, m_Delimiter)){
        if (std::count(col.begin(), col.end(), '\"') % 2 != 0) quotes = true;    
        
        if (quotes == false){
            cols.push_back(col);
           
        }
        else{
            std::string  new_col;
            new_col = col;
            int commas = 0;
        
            std::getline(tokenizer, col, m_Delimiter);
            new_col= new_col.append(col.append(std::string(1, m_Delimiter)));
            while (std::count(col.begin(), col.end(), '\"') == 0)
            {
            std::getline(tokenizer, col, m_Delimiter);
            new_col= new_col.append(col.append(std::string(1, m_Delimiter)));
            commas++;
            }
            if (commas > 0) new_col= new_col.append(col.append(std::string(1, m_Delimiter)));
            
            cols.push_back(new_col);
            quotes = false;
            int x = 0;

        }

                  
    }
    m_Rows.push_back(cols);
     cols.clear();
    }

    public:
        CsvReader(const std::string& fileName, Delimiter delimiter)
            : m_FileName(fileName)
            , m_Delimiter(delimiter) {};
       
         bool Parse() {
            std::ifstream file(m_FileName);
            if (!file.is_open())
                return false;

            std::string line;
            while (std::getline(file, line)){

               ParseLine(line);
            }
           return true;
        };

         const Rows& GetRows() {
            return m_Rows;
         }

         Rows CopyRows() {
            return m_Rows;
         }
};
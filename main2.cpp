#include "CsvReader.h"
#include <string>

int main() {

    std::string file = "Indicator_3_1_Climate_Indicators_Annual_Mean_Global_Surface_Temperature_577579683071085080.csv";
    CsvReader reader(file, ',');
    reader.Parse();
      for (auto const &row : reader.GetRows()) {
  //      std::stringstream output;   
    //     output << "[Row]: ";
        int x =0;
        }

    int y = 0;
  
}

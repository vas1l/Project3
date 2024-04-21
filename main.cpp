#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include "project3.h"
//#include "csvparser.h"

using namespace std;

int main() {
    // Create a hash table and trie
  //  hashTbl data;
    country country1, country2, country3, country4;
    
    // Read the CSV file
   // readCSV("data.csv", data, data2);

country1.name = "Afghanistan, Islamic Rep. of";
country1.ISO2 = "AF";
country1.ISO3 = "AFG";
country1.Indicator = "Temperature change with respect to a baseline climatology, corresponding to the period 1951-1980";
country1.Unit = "Degree Celsius";
country1.Source =  "Food and Agriculture Organization of the United Nations (FAO). 2022. FAOSTAT Climate Change, Climate Indicators, Temperature change. License: CC BY-NC-SA 3.0 IGO. Extracted from: https://www.fao.org/faostat/en/#data/ET. Accessed on 2023-03-28.";
country1.CTS_CODE = "ECCS";
country1.CTS_NAME = "Surface Temperature Change";
country1.CTS_FULL_DESCRIPTION = "Environment, Climate Change, Climate and Weather, Surface Temperature Change";
country1.temperatureChange[1961] = -0.126;
country1.temperatureChange[1962] = -0.173;
country1.temperatureChange[1963] = 0.844;
country1.temperatureChange[1964] = -0.751;
country1.temperatureChange[1965] = -0.22;
country1.temperatureChange[1966] = 0.239;
country1.temperatureChange[1967] = -0.348;
country1.temperatureChange[1968] = -0.398;
country1.temperatureChange[1969] = -0.513;
country1.temperatureChange[1970] = 0.843;
country1.temperatureChange[1971] = 0.642;
country1.temperatureChange[1972] = -1.095;
country1.temperatureChange[1973] = 0.264;
country1.temperatureChange[1974] = -0.466;
country1.temperatureChange[1975] = -0.442;
country1.temperatureChange[1976] = -0.291;
country1.temperatureChange[1977] = 0.544;
country1.temperatureChange[1978] = 0.12;
country1.temperatureChange[1979] = 0.38;
country1.temperatureChange[1980] = 0.655;
country1.temperatureChange[1981] = 0.558;
country1.temperatureChange[1982] = -0.286;
country1.temperatureChange[1983] = 0.24;
country1.temperatureChange[1984] = 0.252;
country1.temperatureChange[1985] = 0.397;
country1.temperatureChange[1986] = -0.015;
country1.temperatureChange[1987] = 0.493;
country1.temperatureChange[1988] = 1.035;
country1.temperatureChange[1989] = 0.015;
country1.temperatureChange[1990] = 0.925;
country1.temperatureChange[1991] = -0.051;
country1.temperatureChange[1992] = -0.212;
country1.temperatureChange[1993] = 0.254;
country1.temperatureChange[1994] = 0.546;
country1.temperatureChange[1995] = 0.457;
country1.temperatureChange[1996] = -0.093;
country1.temperatureChange[1997] = 0.46;
country1.temperatureChange[1998] = 0.664;
country1.temperatureChange[1999] = 1.271;
country1.temperatureChange[2000] = 1.064;
country1.temperatureChange[2001] = 1.377;
country1.temperatureChange[2002] = 1.457;
country1.temperatureChange[2003] = 0.71;
country1.temperatureChange[2004] = 1.482;
country1.temperatureChange[2005] = 0.513;
country1.temperatureChange[2006] = 1.838;
country1.temperatureChange[2007] = 0.794;
country1.temperatureChange[2008] = 0.808;
country1.temperatureChange[2009] = 0.948;
country1.temperatureChange[2010] = 1.664;
country1.temperatureChange[2011] = 1.455;
country1.temperatureChange[2012] = 0.271;
country1.temperatureChange[2013] = 1.345;
country1.temperatureChange[2014] = 0.521;
country1.temperatureChange[2015] = 1.204;
country1.temperatureChange[2016] = 1.612;
country1.temperatureChange[2017] = 1.642;
country1.temperatureChange[2018] = 1.624;
country1.temperatureChange[2019] = 0.991;
country1.temperatureChange[2020] = 0.587;
country1.temperatureChange[2021] = 1.475;
country1.temperatureChange[2022] = 2.154;
country1.temperatureChange[2023] = 1.956;


country2.name = "Australia";
country2.ISO2 = "AU";
country2.ISO3 = "AUS";
country2.Indicator = "Temperature change with respect to a baseline climatology, corresponding to the period 1951-1980";
country2.Unit = "Degree Celsius";
country2.Source = "Food and Agriculture Organization of the United Nations (FAO). 2022. FAOSTAT Climate Change, Climate Indicators, Temperature change. License: CC BY-NC-SA 3.0 IGO. Extracted from: https://www.fao.org/faostat/en/#data/ET. Accessed on 2023-03-28.";
country2.CTS_CODE = "ECCS";
country2.CTS_NAME = "Surface Temperature Change";
country2.CTS_FULL_DESCRIPTION = "Environment, Climate Change, Climate and Weather, Surface Temperature Change";

country2.temperatureChange[1961] = 0.158;
country2.temperatureChange[1962] = 0.132;
country2.temperatureChange[1963] = -0.097;
country2.temperatureChange[1964] = -0.015;
country2.temperatureChange[1965] = 0.147;
country2.temperatureChange[1966] = -0.229;
country2.temperatureChange[1967] = -0.081;
country2.temperatureChange[1968] = -0.199;
country2.temperatureChange[1969] = 0.11;
country2.temperatureChange[1970] = 0.007;
country2.temperatureChange[1971] = -0.01;
country2.temperatureChange[1972] = 0.103;
country2.temperatureChange[1973] = 0.841;
country2.temperatureChange[1974] = -0.348;
country2.temperatureChange[1975] = 0.053;
country2.temperatureChange[1976] = -0.52;
country2.temperatureChange[1977] = 0.164;
country2.temperatureChange[1978] = 0.058;
country2.temperatureChange[1979] = 0.345;
country2.temperatureChange[1980] = 0.843;
country2.temperatureChange[1981] = 0.446;
country2.temperatureChange[1982] = 0.138;
country2.temperatureChange[1983] = 0.582;
country2.temperatureChange[1984] = -0.211;
country2.temperatureChange[1985] = 0.294;
country2.temperatureChange[1986] = 0.336;
country2.temperatureChange[1987] = 0.312;
country2.temperatureChange[1988] = 0.916;
country2.temperatureChange[1989] = 0.1;
country2.temperatureChange[1990] = 0.5;
country2.temperatureChange[1991] = 0.763;
country2.temperatureChange[1992] = 0.24;
country2.temperatureChange[1993] = 0.436;
country2.temperatureChange[1994] = 0.17;
country2.temperatureChange[1995] = 0.358;
country2.temperatureChange[1996] = 0.539;
country2.temperatureChange[1997] = 0.321;
country2.temperatureChange[1998] = 1.028;
country2.temperatureChange[1999] = 0.516;
country2.temperatureChange[2000] = 0.084;
country2.temperatureChange[2001] = 0.275;
country2.temperatureChange[2002] = 0.667;
country2.temperatureChange[2003] = 0.775;
country2.temperatureChange[2004] = 0.656;
country2.temperatureChange[2005] = 1.126;
country2.temperatureChange[2006] = 0.639;
country2.temperatureChange[2007] = 0.855;
country2.temperatureChange[2008] = 0.546;
country2.temperatureChange[2009] = 0.95;
country2.temperatureChange[2010] = 0.593;
country2.temperatureChange[2011] = 0.135;
country2.temperatureChange[2012] = 0.228;
country2.temperatureChange[2013] = 1.413;
country2.temperatureChange[2014] = 1.107;
country2.temperatureChange[2015] = 0.996;
country2.temperatureChange[2016] = 1.102;
country2.temperatureChange[2017] = 1.079;
country2.temperatureChange[2018] = 1.061;
country2.temperatureChange[2019] = 1.346;
country2.temperatureChange[2020] = 1.337;
country2.temperatureChange[2021] = 0.569;
country2.temperatureChange[2022] = 0.681;
country2.temperatureChange[2023] = 0.86;

country3.name = "United States";
country3.ISO2 = "US";
country3.ISO3 = "USA";
country3.Indicator = "Temperature change with respect to a baseline climatology, corresponding to the period 1951-1980";
country3.Unit = "Degree Celsius";
country3.Source = "Food and Agriculture Organization of the United Nations (FAO). 2022. FAOSTAT Climate Change, Climate Indicators, Temperature change. License: CC BY-NC-SA 3.0 IGO. Extracted from: https://www.fao.org/faostat/en/#data/ET. Accessed on 2023-03-28.";
country3.CTS_CODE = "ECCS";
country3.CTS_NAME = "Surface Temperature Change";
country3.CTS_FULL_DESCRIPTION = "Environment, Climate Change, Climate and Weather, Surface Temperature Change";

country3.temperatureChange[1961] = 0.003;
country3.temperatureChange[1962] = -0.027;
country3.temperatureChange[1963] = 0.425;
country3.temperatureChange[1964] = -0.281;
country3.temperatureChange[1965] = -0.36;
country3.temperatureChange[1966] = -0.212;
country3.temperatureChange[1967] = 0.078;
country3.temperatureChange[1968] = -0.079;
country3.temperatureChange[1969] = -0.268;
country3.temperatureChange[1970] = -0.02;
country3.temperatureChange[1971] = -0.411;
country3.temperatureChange[1972] = -0.257;
country3.temperatureChange[1973] = -0.025;
country3.temperatureChange[1974] = 0.092;
country3.temperatureChange[1975] = -0.367;
country3.temperatureChange[1976] = -0.12;
country3.temperatureChange[1977] = 0.4;
country3.temperatureChange[1978] = 0.022;
country3.temperatureChange[1979] = -0.337;
country3.temperatureChange[1980] = 0.41;
country3.temperatureChange[1981] = 0.872;
country3.temperatureChange[1982] = -0.351;
country3.temperatureChange[1983] = 0.551;
country3.temperatureChange[1984] = -0.23;
country3.temperatureChange[1985] = -0.028;
country3.temperatureChange[1986] = 0.584;
country3.temperatureChange[1987] = 0.92;
country3.temperatureChange[1988] = 0.483;
country3.temperatureChange[1989] = 0.316;
country3.temperatureChange[1990] = 0.675;
country3.temperatureChange[1991] = 0.529;
country3.temperatureChange[1992] = 0.396;
country3.temperatureChange[1993] = 0.01;
country3.temperatureChange[1994] = 0.472;
country3.temperatureChange[1995] = 0.638;
country3.temperatureChange[1996] = -0.005;
country3.temperatureChange[1997] = 0.389;
country3.temperatureChange[1998] = 1.274;
country3.temperatureChange[1999] = 0.756;
country3.temperatureChange[2000] = 1.002;
country3.temperatureChange[2001] = 0.788;
country3.temperatureChange[2002] = 0.953;
country3.temperatureChange[2003] = 0.991;
country3.temperatureChange[2004] = 0.863;
country3.temperatureChange[2005] = 1.154;
country3.temperatureChange[2006] = 1.033;
country3.temperatureChange[2007] = 1.148;
country3.temperatureChange[2008] = 0.219;
country3.temperatureChange[2009] = 0.408;
country3.temperatureChange[2010] = 0.704;
country3.temperatureChange[2011] = 0.543;
country3.temperatureChange[2012] = 1.455;
country3.temperatureChange[2013] = 0.619;
country3.temperatureChange[2014] = 0.506;
country3.temperatureChange[2015] = 1.53;
country3.temperatureChange[2016] = 2.223;
country3.temperatureChange[2017] = 1.434;
country3.temperatureChange[2018] = 1.277;
country3.temperatureChange[2019] = 1.037;
country3.temperatureChange[2020] = 1.332;
country3.temperatureChange[2021] = 1.149;
country3.temperatureChange[2022] = 1.223;
country3.temperatureChange[2023] = 1.212;

country4.name = "Serbia, Rep. of";
country4.ISO2 = "RS";
country4.ISO3 = "SRB";
country4.Indicator = "Temperature change with respect to a baseline climatology, corresponding to the period 1951-1980";
country4.Unit = "Degree Celsius";
country4.Source = "Food and Agriculture Organization of the United Nations (FAO). 2022. FAOSTAT Climate Change, Climate Indicators, Temperature change. License: CC BY-NC-SA 3.0 IGO. Extracted from: https://www.fao.org/faostat/en/#data/ET. Accessed on 2023-03-28.";
country4.CTS_CODE = "ECCS";
country4.CTS_NAME = "Surface Temperature Change";
country4.CTS_FULL_DESCRIPTION = "Environment, Climate Change, Climate and Weather, Surface Temperature Change";

country4.temperatureChange[2006] = 0.605;
country4.temperatureChange[2007] = 1.942;
country4.temperatureChange[2008] = 1.394;
country4.temperatureChange[2009] = 1.421;
country4.temperatureChange[2010] = 1.226;
country4.temperatureChange[2011] = 0.803;
country4.temperatureChange[2012] = 1.754;
country4.temperatureChange[2013] = 1.477;
country4.temperatureChange[2014] = 1.634;
country4.temperatureChange[2015] = 1.76;
country4.temperatureChange[2016] = 1.708;
country4.temperatureChange[2017] = 1.28;
country4.temperatureChange[2018] = 2.317;
country4.temperatureChange[2019] = 2.08;
country4.temperatureChange[2020] = 1.798;
country4.temperatureChange[2021] = 1.569;
country4.temperatureChange[2022] = 1.91;
country4.temperatureChange[2023] = 2.535;


trie data2;
data2.addCountry(country1);
data2.addCountry(country2);
data2.addCountry(country3);
data2.addCountry(country4);

    // Print the hash table
  //  cout << "Printing the hash table:" << endl;
  //  data2.printTable();
   

// Search for a country in the hash table
    cout << "Searching for country with ISO3 code 'USA' in trie:" << endl;
 //   data.printCountry("USA");
    
    country c = data2.getCountry("USA");
    c.print();
    
    cout << "Searching for country with ISO3 code 'USA' in trie:" << endl;
    data2.printCountry("USA");
    
        
    return 0;
}
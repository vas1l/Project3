# Project3
Classes:
  country - represents one row from the .csv file:  https://climatedata.imf.org/datasets/4063314923d74187be9596f10d034914/explore
    the values are stored as a map with year as key.
  hashTbl - is the first data structure which is a hash table to store the data
  trie (Marko) - is the second data structure which is a TRIE (A trie or a prefix tree is a search tree, where nodes are keyed by strings i.e. ISO3)

To run:

Compile and run main.cpp to display relevant data from the hash table and TRIE data structures. Main.cpp updates 'country_data.txt' with country information parsable by 'plot.py'. To run plot.py, activate the virtual environment venv via /venv/Scripts/activate in terminal. Once venv is active, run 'python plot.py' which will then parse country_data.txt to create a matplotlib graph of the associated temperature data.
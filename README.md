# Project3
Classes:
  country - represents one row from the .csv file:  https://climatedata.imf.org/datasets/4063314923d74187be9596f10d034914/explore
    the values are stored as a map with year as key
  hashTbl - is the first data structure which is a hash table to store the data
  trie (Marko) - is the second data structure which is a TRIE (A trie or a prefix tree is a search tree, where nodes are keyed by strings i.e. ISO3)

readCSV: which parses the csv file and stores each row into a country and then stores the country into both the hash table and trie
The main function calls readCSV then calls hash/trie methods to display the data.

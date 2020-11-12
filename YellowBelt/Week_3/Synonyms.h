#pragma once

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

using Vocabulary = map<string, set<string>>;

void AddSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2);  

size_t GetSynonymCount(Vocabulary& vocabulary, const string& word);

bool AreSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2);


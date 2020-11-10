#pragma once

#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// Создание типа-синонима Vocabulary для map<string, set<string>>

using Vocabulary = map<string, set<string>>;

void AddSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2) {
    vocabulary[word1].insert(word2);
    vocabulary[word2].insert(word1);
}

size_t GetSynonymCount(Vocabulary& vocabulary, const string& word) {
    return vocabulary[word].size();
}

bool AreSynonyms(Vocabulary& vocabulary, 
                 const string& word1, const string& word2) {
    return vocabulary[word1].count(word2) == 0;
}
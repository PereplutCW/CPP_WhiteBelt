#include "Synonyms.h"

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
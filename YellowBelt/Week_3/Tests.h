#pragma once

#include "TestRunner.h"
#include "Synonyms.h"

using namespace std;

// Определение и реализация юнит-теста для функции AddSynonyms

void TestAddSynonyms() {
    {
        Vocabulary empty;
        AddSynonyms(empty, "a", "b");
        const Vocabulary expected = {
            {"a", {"b"}},
            {"b", {"a"}}
        };
        AssertEqual(empty, expected, "Add to empty");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b"}},
            {"b", {"a", "c"}},
            {"c", {"b"}}
        };
        AddSynonyms(vocabulary, "a", "c");
        Vocabulary expected = {
            {"a", {"b", "c"}},
            {"b", {"a", "c"}},
            {"c", {"b", "a"}}
        };
        AssertEqual(vocabulary, expected, "Add to vocabulary");
    }
}

// Определение и реализация юнит-теста для функции TestCount

void TestCount() {
    {
        Vocabulary empty;
        AssertEqual(GetSynonymCount(empty, "a"), 0u, "count for empty");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        AssertEqual(GetSynonymCount(vocabulary, "a"), 2u, "count for a");
        AssertEqual(GetSynonymCount(vocabulary, "b"), 1u, "count for b");
        AssertEqual(GetSynonymCount(vocabulary, "z"), 0u, "count for z");
    }
}

// Определение и реализация юнит-теста для функции TestAreSynonyms

void TestAreSynonyms() {
    {
        Vocabulary empty;
        Assert(!AreSynonyms(empty, "a", "b"), "empty a b");
        Assert(!AreSynonyms(empty, "b", "a"), "empty b a");
    }
    {
        Vocabulary vocabulary = {
            {"a", {"b", "c"}},
            {"b", {"a"}},
            {"c", {"a"}}
        };
        Assert(AreSynonyms(vocabulary, "a", "b"), "vocabulary a b");
        Assert(AreSynonyms(vocabulary, "b", "a"), "vocabulary b a");
        Assert(AreSynonyms(vocabulary, "a", "c"), "vocabulary a c");
        Assert(AreSynonyms(vocabulary, "c", "a"), "vocabulary c a");
        // Assert(AreSynonyms(vocabulary, "b", "c"), "vocabulary b c");
    }
}

void TestAll() {
    TestRunner tr;
    tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
    tr.RunTest(TestCount, "TestCount");
    tr.RunTest(TestAreSynonyms, "TestAreSynonyms");
}
#pragma once

#include <iostream>
#include <vector>

typedef std::string String;
typedef std::vector<std::string> StringVector;
typedef std::vector<int32_t> IntVector;
typedef std::vector<IntVector> IntVectorVector;
typedef std::pair<uint16_t, uint16_t> ShortPair;

uint32_t adder(uint32_t a, uint32_t b);
uint32_t multiplier(uint32_t a, uint32_t b);
uint32_t gray_code(uint32_t n);
bool eval_formula(String &formula);
void print_truth_table(String &str);
String negation_normal_form(String const &formula);
String conjunctive_normal_form(String const &formula);
bool sat(String const &formula);
IntVectorVector powerset(IntVector const &set);
IntVector eval_set(String const &formula, const IntVectorVector &sets);
double map(uint16_t x, uint16_t y);
ShortPair reverse_map(double n);

String get_truth_table(const String& str);
void assertThatFormulaIsValid(String const &formula);
bool isAndOrOr(char const &c);

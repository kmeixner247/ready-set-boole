#pragma once

#include <iostream>

uint32_t adder(uint32_t a, uint32_t b);
uint32_t multiplier(uint32_t a, uint32_t b);
uint32_t gray_code(uint32_t n);
bool eval_formula(std::string &formula);
void print_truth_table(std::string &str);
std::string negation_normal_form(std::string const &formula);
std::string conjunctive_normal_form(std::string const &formula);
bool sat(std::string const &formula);
std::vector<std::vector<int> > powerset(std::vector<int> const &set);
std::vector<int32_t> eval_set(std::string const &formula, const std::vector<std::vector<int32_t> >& sets);

std::string get_truth_table(std::string str);
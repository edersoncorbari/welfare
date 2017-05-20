/**
 * @file welfare_compute_bmi.cxx
 *
 * Calculate body mass index BMI/IMC.
 *
 * WELFARE-LIB - Project Librarie WelFare.
 *
 * Copyright (c) 2015 BlueSalute Company Ltda.
 * Copyright (c) 2015 Widegenomics Ltda.
 *
 * @author Ederson Moura - <ederson.moura@bluesalute.com.br>
 * @author Toty Ypiranga - <toty@widegenomics.com>
 *
 * $Id: Exp$
 */

#include <welfare/bmi.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

static void usage(const std::string name)
{
  std::cerr << "Usage: " << name << " m 18 72.30 1.75\n\n"
            << "Example:\n"
            << "\tm|f\t Sex male or female.\n"
            << "\tage\t Your age (integer).\n"
	    << "\tweight\t Your weight in (kgs).\n"
	    << "\theight\t Your height in (m).\n"
            << std::endl;
}

int main(int argc, char* argv[])
{
  if(argc < 5) {
    usage(argv[0]);
    return 1;
  }

  // Parameters from the command line.
  std::string sexStr = argv[1];
  std::string ageStr = argv[2];
  std::string weightStr = argv[3];
  std::string heightStr = argv[4];

  const float weight = std::stof(weightStr);
  const float height = std::stof(heightStr);

  if(sexStr == "m" | sexStr == "f") {
    sexStr = argv[1];
  } else {
    std::cout << "Please define sex: m = Male, f = Female.\n" << std::endl;
    usage(argv[0]);
    return 1;
  }

  const short int age = std::stoul(ageStr);

  if(age < 18) {
    std::cout << "BMI is not suitable and recommended for minors.\n" << std::endl;
    usage(argv[0]);
    return 1;
  }

  // Compute BMI/IMC.
  welfare::bmi::getInstance(weight, height);

  const std::string value = welfare::bmi::getInstance()->printNumberResult();
  std::cout << "Value of your BMI/IMC is: " << value << "\n" << std::endl;

  if(welfare::bmi::getInstance()->printComputeResult() == 1) {
    std::cout << "\033[1;31mBeware! You are underweight.\033[0m\a" << std::endl;
  } else if(welfare::bmi::getInstance()->printComputeResult() == 2) {
    std::cout << "\033[1;32mCool! You are with normal weight.\033[0m" << std::endl;
  } else if(welfare::bmi::getInstance()->printComputeResult() == 3) {
    std::cout << "\033[1;31mBeware! You are overweight.\033[0m\a" << std::endl;
  } else {
    std::cerr << "It was not possible to calculate your BMI/IMC, please try again.\a" << std::endl;
  }

  return 0;
}

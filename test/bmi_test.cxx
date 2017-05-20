/**
 * @file bmi_test.hpp
 *
 * Test for an bmi class.
 *
 * WELFARE-LIB - Project Librarie WelFare.
 *
 * Copyright (c) 2015 BlueSalute Company Ltda.
 * Copyright (c) 2015 Widegenomics Ltda.
 *
 * @author Ederson Moura - <ederson.moura@bluesalute.com.br>
 * @author Toty Ypiranga - <toty@widegenomics.com>
 * @mainteiner ederson.moura@bluesalute.com.br
 *
 * $Id: Exp$
 */

#include <welfare/bmi.hpp>

#include <iostream>

static float m_weight = 91.2;
static float m_height = 1.80;

static void test_bmi_instance_pointer()
{
  std::cout << "\033[1;31m\n=== Testing the method (test_bmi_instance_pointer) ==="
	    << "\033[0m\n" 
	    << std::endl;

  // Instance using pointer.
  welfare::bmi *bmi = new welfare::bmi(m_weight, m_height);

  unsigned int result = bmi->printComputeResult();
  const std::string value = bmi->printNumberResult();
  
  std::cout << "Value of your BMI/IMC is: " << value << std::endl;

  if(result == 1) {
    std::cout << "Beware! You are underweight.\a" << std::endl;
  } else if(result == 2) {
    std::cout << "Cool! You are with normal weight." << std::endl;
  } else if(result == 3) {
    std::cout << "Beware! You are overweight.\a" << std::endl;
  } else {
    std::cerr << "It was not possible to calculate your BMI/IMC, please try again.\a" << std::endl;
  }

  delete bmi;

  std::cout << "\033[1;32m\nEnd.\033[0m" << std::endl;
}

static void test_bmi_instance_simple() 
{
  std::cout << "\033[1;31m\n=== Testing the method (test_bmi_instance_simple) ==="
	    << "\033[0m\n"
            << std::endl;

  float weight = m_weight;
  float height = m_height;

  using namespace welfare;

  // Instance using simple.
  bmi bmi(weight, height);

  std::cout << "Value of your BMI/IMC is: " << bmi.printNumberResult(1) << std::endl;

  if(bmi.printComputeResult() == 1) {
    std::cout << "Beware! You are underweight.\a" << std::endl;
  } else if(bmi.printComputeResult() == 2) {
    std::cout << "Cool! You are with normal weight." << std::endl;
  } else if(bmi.printComputeResult() == 3) {
    std::cout << "Beware! You are overweight.\a" << std::endl;
  } else {
    std::cerr << "It was not possible to calculate your BMI/IMC, please try again.\a" << std::endl;
  }

  std::cout << "\033[1;32m\nEnd.\033[0m" << std::endl;
}

static void test_bmi_instance_singleton()
{
  std::cout << "\033[1;31m\n=== Testing the method (test_bmi_instance_singleton) ==="
	    << "\033[0m\n"
            << std::endl;

  // Instance using singleton.
  welfare::bmi::getInstance(m_weight, m_height);

  const std::string value = welfare::bmi::getInstance()->printNumberResult();
  std::cout << "Value of your BMI/IMC is: " << value << std::endl;

  if(welfare::bmi::getInstance()->printComputeResult() == 1) {
    std::cout << "Beware! You are underweight.\a" << std::endl;
  } else if(welfare::bmi::getInstance()->printComputeResult() == 2) {
    std::cout << "Cool! You are with normal weight." << std::endl;
  } else if(welfare::bmi::getInstance()->printComputeResult() == 3) {
    std::cout << "Beware! You are overweight.\a" << std::endl;
  } else {
    std::cerr << "It was not possible to calculate your BMI/IMC, please try again.\a" << std::endl;
  }

  std::cout << "\033[1;32m\nEnd.\033[0m" << std::endl;
}

int main(int argc, char *argv[])
{
  test_bmi_instance_pointer();
  test_bmi_instance_simple();
  test_bmi_instance_singleton();
  return 0;
}


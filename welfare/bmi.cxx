/**
 * @file bmi.hpp
 *
 * Implementations for an bmi.
 *  
 * WELFARE-LIB - Project Librarie WelFare.
 *
 * Copyright (c) 2015 BlueSalute Company Ltda.
 * Copyright (c) 2015 Widegenomics Ltda.
 *
 * @author Ederson Moura - <ederson.moura@bluesalute.com.br>
 * @author Toty Ypiranga - <toty@widegenomics.com>
 * @version 1.0
 * 
 * $Id: Exp$
 */

#include <welfare/bmi.hpp>

#include <iostream>
#include <cmath>

// Start static variables and objects.
welfare::bmi* welfare::bmi::instance = 0;

namespace welfare {

  bmi *bmi::getInstance(const float weight, const float height)
  {
    if(instance == 0) {
      instance = new bmi(weight, height);
    }
    return instance;
  }

  bmi::bmi(const float weight, const float height) 
    : m_weight(weight), m_height(height)
  {
    // Compute BMI.
    this->compute();
  }

  bmi::~bmi()
  {
  }

  inline float bmi::compute()
  {
    this->m_bmi = this->m_weight / std::pow(this->m_height, 2);
    
    if(this->m_bmi <= 18.5) {
      this->m_weights = BMI_UNDER_WEIGHT;
    } else if((this->m_bmi > 18.5 ) && (this->m_bmi < 25)) {
      this->m_weights = BMI_NORMAL_WEIGHT;
    } else {
      this->m_weights = BMI_OVER_WEIGHT;
    }

    return this->m_bmi;
  }

  unsigned int bmi::printComputeResult()
  {
    unsigned int result = 0;

    switch(this->m_weights) {
    case BMI_UNDER_WEIGHT:
      result = 1;
      break;
    case BMI_NORMAL_WEIGHT:
      result = 2;
      break;
    case BMI_OVER_WEIGHT:
      result = 3;
      break;
    default:
      result = 0;
      break;
    }

    return result;
  }

  const std::string bmi::printNumberResult(unsigned int rounded)
  {
    std::string value = "";

    if(rounded == 0) {
      value = std::to_string(this->m_bmi); 
    } else if(rounded == 1) {
      value = std::to_string(static_cast<int>(this->m_bmi));
    }

    return value;
  }

}


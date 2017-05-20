/**
 * @file bmi.hpp
 *
 * Definitions for an bmi.
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

#ifndef WELFARE_BMI_HPP
#define WELFARE_BMI_HPP

#include <string>

/**
 * Main namespace that access the library.
 */
namespace welfare {
  /**
   * Enumerators to identify the weights.
   */
  typedef enum eWeights {
    BMI_UNDER_WEIGHT, //! The person is underweight.
    BMI_NORMAL_WEIGHT, //! The person is in the correct weight.
    BMI_OVER_WEIGHT //!  The person is overweight.
  } Weights;

  /**
   * @brief This class compute body mass index BMI/IMC.
   *
   * BMI is supposed to estimate the amount of body fat a person carries based 
   * on height and weight, and categorizes people based on what is appropriate 
   * for their size. BMI readings under 18.5 mean you are underweight, and could 
   * put on a few pounds. If you fall between 18.5 and 24.9, you're  considered normal, 
   * while a BMI of 30 or higher qualifies as overweight.
   *
   * @see http://healthland.time.com/2013/08/26/why-bmi-isnt-the-best-measure-for-weight-or-health/
   */
  class bmi {
  public:
    /**
     * Construtor.
     *
     * @param weight - The person's weight in kilograms.
     * @param height - The person's height in centimeters.
     * @return the person's BMI, rounded to an integer
     */
    explicit bmi(const float weight = 0.0, const float height = 0.0);

    /**
     * Destructor.
     */
    ~bmi();

    /**
     * @brief Singleton class bmi get instance.
     *
     * @param weight - The person's weight in kilograms.
     * @param height - The person's height in centimeters.
     * @return The static class bmi.
     */
    static bmi* getInstance(const float weight = 0.0, const float height = 0.0);

    /**.
     * Print the results found, the compute method must be 
     * called before.
     *
     * Results:
     *
     * Number result (0) = Error computing.
     * Number result (1) = The person is underweight.
     * Number result (2) = The person is in the correct weight.
     * Number result (3) = The person is overweight.
     *
     * @return The number according to the enumeration above.
     */
    unsigned int printComputeResult();

    /**
     * Prints the number of results BMI/IMC.
     *
     * @param rounded - If set to 1, does rounded to integer number.
     */
    const std::string printNumberResult(unsigned int rounded = 0);

  private:
    /**
     * Compute body mass index BMI/IMC.
     *
     * @param weight - The person's weight in kilograms.
     * @param height - The person's height in centimeters.
     * @return The person's BMI, rounded to an integer
     */
    inline float compute();

  protected:
    /// Pointer class for singleton instance.
    static bmi *instance;

    /// Store value weight.
    float m_weight;

    /// Store value height.
    float m_height;

    /// Store values BMI.
    float m_bmi;

    /// Store results.
    Weights m_weights;
  };
};

#endif // WELFARE_BMI_HPP

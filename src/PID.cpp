#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * Initialize PID coefficients (and errors, if needed)
   */
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;

  p_error = 0;
  i_error = 0;
  d_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * Update PID errors based on cte.
   */
  double prev_cte = p_error;

  p_error = cte;
  i_error = i_error + cte;
  d_error = cte - prev_cte;
}

double PID::TotalError() {
  /**
   * Calculate and return the total error
   */
  double total = Kp * p_error + Ki * i_error + Kd * d_error;
  return total;  // Add your total error calc here!
}
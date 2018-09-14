#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    this->sum_cte = 0.0;
    this->prev_cte = 0.0;
}

void PID::UpdateError(double cte) {
    double diff_cte = cte - prev_cte;
    sum_cte += cte;

    p_error = -Kp * cte;
    i_error = -Ki * sum_cte;
    d_error = -Kd * diff_cte;

    prev_cte = cte;
}

double PID::TotalError() {
    return p_error + i_error + d_error;
}

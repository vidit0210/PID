#include "PID.h"
#include <deque>

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

    this->p_error = 0;
    this->i_error = 0;
    this->d_error = 0;

    i_window = new deque<double>;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    if (i_window->size() == 30) {
        i_window->pop_back();
    }

    i_window->push_front(cte);
    i_error = 0;
    for (auto& i : *i_window) {
        i_error += i;
    }
}

double PID::TotalError() {
    return  (-Kp * p_error)
            + (-Kd * d_error)
            + (-Ki * i_error);
}
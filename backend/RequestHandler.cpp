#include "RequestHandler.hpp"

#include <cmath>
#include <iostream>

std::string RequestHandler::HandleReq(int ID) {
  if (ID < 10) {
    NumPress(ID);
  } else {
    ((*this).*(funcs[ID - 10]))();
  }
  // ((*this).*(method_ptr))();

  return mem[0].GetString();
}

void RequestHandler::Turn() {
  powered_on = !powered_on;
  Cx();
}

void RequestHandler::Cx() {
  for (int i = 0; i < 8; ++i) {
    mem[i] = 0.0f;
  }
  p_pressed = false;
  f_pressed = false;
  digs_entered = 0;
  input_state = entering_int_part;
}

void RequestHandler::PPress() { p_pressed = !f_pressed; }

void RequestHandler::XPowY() {
  if (!p_pressed) {
    mem[0] = std::pow(mem[0].GetDouble(), mem[1].GetDouble());
    input_state = showing_res;
  }
}

void RequestHandler::SwapXY() {
  if (!p_pressed) {
    swap(mem[0], mem[1]);
  } else {
    mem[0] = std::log(mem[0].GetDouble());
    p_pressed = !p_pressed;
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::ArrowUp() {
  if (!p_pressed) {
    mem[1] = mem[0];
    mem[0] = 0.0f;
    digs_entered = 0;
    input_state = entering_int_part;
  }
}

void RequestHandler::Mult() {
  if (p_pressed) {
    mem[0] = M_PI;
    digs_entered = 8;
    p_pressed = !p_pressed;
  } else {
    mem[0] = mem[0] * mem[1];
    digs_entered = 8;
  }
  input_state = showing_res;
}

void RequestHandler::Plus() {
  if (p_pressed) {
    mem[0] = std::sin(mem[0].GetDouble());
    p_pressed = !p_pressed;
  } else {
    mem[0] = mem[0] + mem[1];
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Minus() {
  if (p_pressed) {
    mem[0] = std::cos(mem[0].GetDouble());
    p_pressed = !p_pressed;
  } else {
    mem[0] = mem[1] - mem[0];
  }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Delen() {
  if (p_pressed) {
    mem[0] = std::exp(mem[0].GetDouble());
    p_pressed = !p_pressed;
  }
  { mem[0] = mem[1] / mem[0]; }
  digs_entered = 8;
  input_state = showing_res;
}

void RequestHandler::Negative() {
  if (f_pressed) {
    mem[0] = mem[0] * mem[0];
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else if (input_state == entering_int_part ||
             input_state == entering_fract_part || input_state == showing_res) {
    mem[0].ChangeIntSign();
  } else {
    mem[0].ChangePowSign();
  }
}

void RequestHandler::Dot() {
  if (f_pressed) {
    mem[0] = 1 / mem[0];
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else if (input_state == entering_int_part) {
    input_state = entering_fract_part;
    ++digs_entered;
  }
}

void RequestHandler::VP() {
  if (f_pressed) {
    mem[0] = std::sqrt(mem[0].GetDouble());
    f_pressed = !f_pressed;
    digs_entered = 8;
    input_state = showing_res;
  } else {
    input_state = entering_exp_part;
  }
}

void RequestHandler::FPress() { f_pressed = !f_pressed; }

void RequestHandler::NumPress(int ID) {
  if (f_pressed) {
    if (ID >= 2 && ID <= 7) {
      mem[0] = mem[ID];
      digs_entered = 8;
    }
    f_pressed = !f_pressed;
    return;
  }
  if (p_pressed) {
    if (ID >= 2 && ID <= 7) {
      mem[ID] = mem[0];
      mem[0] = 0.0f;
      digs_entered = 0;
    }
    p_pressed = !p_pressed;
    return;
  }

  if (input_state == showing_res) {
    mem[0] = 0.0f;
    input_state = entering_int_part;
    digs_entered = 0;
  }

  if (digs_entered >= 8 && input_state != entering_exp_part) {
    return;
  }
  switch (input_state) {
    case entering_int_part:
      mem[0].AddToInt('0' + ID);
      ++digs_entered;
      break;
    case entering_fract_part:
      mem[0].AddToFract('0' + ID);
      ++digs_entered;
      break;
    case entering_exp_part:
      mem[0].AddToPow('0' + ID);
      break;
    default:
      break;
  }
}

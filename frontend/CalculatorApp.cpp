/***************************************************************
 * Name:      CalculatorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    GeorgeLab ()
 * Created:   2023-04-24
 * Copyright: GeorgeLab ()
 * License:
 **************************************************************/

#include "CalculatorApp.h"

//(*AppHeaders
#include <wx/wx.h>

#include "CalculatorMain.h"
//*)

IMPLEMENT_APP(CalculatorApp);

bool CalculatorApp::OnInit() {
  CalculatorFrame* frame = new CalculatorFrame();
  frame->Show(true);
  return true;
}

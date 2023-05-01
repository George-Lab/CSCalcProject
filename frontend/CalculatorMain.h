/***************************************************************
 * Name:      CalculatorMain.h
 * Purpose:   Defines Application Frame
 * Author:    GeorgeLab ()
 * Created:   2023-04-24
 * Copyright: GeorgeLab ()
 * License:
 **************************************************************/

#ifndef CALCULATORMAIN_H
#define CALCULATORMAIN_H

#include "../backend/RequestHandler.hpp"

//(*Headers(CalculatorFrame)
#include <wx/filename.h>
#include <wx/stdpaths.h>
#include <wx/wx.h>
//*)

class CalculatorFrame : public wxFrame {
 public:
  CalculatorFrame();

  void OnExit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnButton(wxCommandEvent& event);
  void OnPaint(wxPaintEvent& event);

 private:
  RequestHandler rh;

  wxStaticText* staticText;
  wxString pics_location;
  wxDECLARE_EVENT_TABLE();
};

#endif  // CALCULATORMAIN_H

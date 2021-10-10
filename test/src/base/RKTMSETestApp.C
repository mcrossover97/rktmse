//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "RKTMSETestApp.h"
#include "RKTMSEApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
RKTMSETestApp::validParams()
{
  InputParameters params = RKTMSEApp::validParams();
  return params;
}

RKTMSETestApp::RKTMSETestApp(InputParameters parameters) : MooseApp(parameters)
{
  RKTMSETestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

RKTMSETestApp::~RKTMSETestApp() {}

void
RKTMSETestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  RKTMSEApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"RKTMSETestApp"});
    Registry::registerActionsTo(af, {"RKTMSETestApp"});
  }
}

void
RKTMSETestApp::registerApps()
{
  registerApp(RKTMSEApp);
  registerApp(RKTMSETestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
RKTMSETestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RKTMSETestApp::registerAll(f, af, s);
}
extern "C" void
RKTMSETestApp__registerApps()
{
  RKTMSETestApp::registerApps();
}

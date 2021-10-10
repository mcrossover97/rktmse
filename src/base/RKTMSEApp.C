#include "RKTMSEApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
RKTMSEApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

RKTMSEApp::RKTMSEApp(InputParameters parameters) : MooseApp(parameters)
{
  RKTMSEApp::registerAll(_factory, _action_factory, _syntax);
}

RKTMSEApp::~RKTMSEApp() {}

void
RKTMSEApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"RKTMSEApp"});
  Registry::registerActionsTo(af, {"RKTMSEApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
RKTMSEApp::registerApps()
{
  registerApp(RKTMSEApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
RKTMSEApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  RKTMSEApp::registerAll(f, af, s);
}
extern "C" void
RKTMSEApp__registerApps()
{
  RKTMSEApp::registerApps();
}

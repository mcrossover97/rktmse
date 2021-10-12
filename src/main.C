//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "RKTMSETestApp.h"
#include "MooseInit.h"
#include "Moose.h"
#include "MooseApp.h"
#include "AppFactory.h"
#include "Reaktoro/Reaktoro.hpp"

// Create a performance log
PerfLog Moose::perf_log("RKTMSE");

// Begin the main program.
int
main(int argc, char * argv[])
{
  // Running a Reaktoro example
  Reaktoro::ChemicalEditor editor;
  editor.addAqueousPhaseWithElements("H O C Na Cl");
  editor.addGaseousPhase({"H2O(g)", "CO2(g)"});
  editor.addMineralPhase("Halite");

  Reaktoro::ChemicalSystem system(editor);

  Reaktoro::EquilibriumProblem problem(system);
  problem.setTemperature(60, "celsius");
  problem.setPressure(300, "bar");
  problem.add("H2O", 1, "kg");
  problem.add("CO2", 100, "g");
  problem.add("NaCl", 0.1, "mol");

  Reaktoro::ChemicalState state = equilibrate(problem);

  state.output("state-cmake-example.txt");
  
  // Initialize MPI, solvers and MOOSE
  MooseInit init(argc, argv);

  // Register this application's MooseApp and any it depends on
  RKTMSETestApp::registerApps();

  // Create an instance of the application and store it in a smart pointer for easy cleanup
  std::shared_ptr<MooseApp> app = AppFactory::createAppShared("RKTMSETestApp", argc, argv);

  // Execute the application
  app->run();

  return 0;
}

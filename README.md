RKTMSE
=====

A Moose-Based Application Coupled with the Reaktoro Geochemical Library.


Installation
================

To use this application, you should have both MOOSE (https://mooseframework.inl.gov/) and Reaktoro (https://reaktoro.org/) frameworks installed.

MOOSE Installation
================

The instructions to install MOOSE can be found in the following webpage:
https://mooseframework.inl.gov/getting_started/installation/

Please follow the instructions exactly as they are.

Reaktoro Installation
================

The instructions to install Reaktoro can be found in the following webpage:
https://reaktoro.org/installation.html

Please install Reaktoro using CMake. If Reaktoro is installed in a directory other than the following default directory (`reaktoro/build/install`), change the configuration of the application's Makefile `rktmse.mk` by modifying `ADDITIONAL_INCLUDES`, `ADDITIONAL_LIBS`, and `LDFLAGS`, accordingly. After installing Reaktoro, remove the Eigen library located in the moose environment:
```
cd /path/to/conda/envs/moose/libmesh/include
rm -rf Eigen
```
Otherwise, the compilation would probably be stopped complaining:
```
'all' is not a member of 'eigen'
```
This is because MOOSE and Reaktoro each uses a different version of Eigen and during the compilation of Reaktoro, the compiler might decide to look for the Eigen version used by Reaktoro and thus, since this version does not contain `eigen:all`, it throws an error. By removing the default Eigen library used by MOOSE and having the following line added the `rktmse.mk`:
```
ADDITIONAL_INCLUDES += -I /home/mcrossover97/reaktoro/build/install/include/Reaktoro/deps/eigen3 
```
By doing this, MOOSE will also uses the Eigen version used by Reaktoro and has no problem with this.

Building RKTMSE Application
================

Clone the application running the following command:
```git clone https://github.com/mcrossover97/rktmse.git```

In the application root directory, type `make -j4` and wait for the application to be built. Go to application directory and make sure it is working properly:
`cd rktmse`
`./run_tests -j4`

RKTMSE
=====

A MOOSE-Based Application Coupled with the Reaktoro Geochemical Library.


# Installation

To build the RKTMSE application, you should have both [MOOSE](https://mooseframework.inl.gov/) and [Reaktoro](https://reaktoro.org/) installed first.

## 1. MOOSE Installation

The instructions to install MOOSE can be found [here](https://mooseframework.inl.gov/getting_started/installation/conda.html). Please follow the instructions exactly as they are.

## 2. Reaktoro Installation

Before installing Reaktoro, make sure to deactivate the exisiting `moose` environment:
```
conda deactivate
``` 

The instructions to install Reaktoro can be found [here](https://reaktoro.org/installation.html). Install Reaktoro using CMake. Make sure to clone Reaktoro in the root directory of the application. After installing Reaktoro, remove the Eigen library located in the `moose` environment:
```
cd /path/to/conda/envs/moose/libmesh/include
rm -rf Eigen
```
Otherwise, the following error probably terminates the compilation:
```
'all' is not a member of 'eigen'
```
This is because MOOSE and Reaktoro each use different versions of the Eigen library. While compiling Reaktoro, the compiler might decide to look for the Eigen version used by MOOSE and thus, since this version is not compatible with Reaktoro, an error terminates the compilation. By removing the default Eigen library used by MOOSE and having the following line added to `rktmse.mk`:
```
ADDITIONAL_INCLUDES += -I /path/to/Reaktoro/install/directory/include/Reaktoro/deps/eigen3 
```
MOOSE also uses the Eigen version used by Reaktoro and has no problem with this. 

## 3. Building RKTMSE Application 

Clone the application running the following command:
```
git clone https://github.com/mcrossover97/rktmse.git
```
Activate the `moose` environment:
```
conda activate moose
```
In the application's root directory, type `make -j4` and wait for the application to be built. Make sure it is working properly by running a test case:
```
./rktmse-opt -i test/tests/kernels/simple_diffusion/simple_diffusion.i
```
If executed successfully, you should be able to see `state-cmake-example.txt` in the application's root directory.


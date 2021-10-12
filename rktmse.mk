#
# Check the existence of the contrib submodules and build accordingly
#
CONDA_DIR  := $(shell find $(APPLICATION_DIR)/../.. -name "*conda3")
ADDITIONAL_INCLUDES += -I $(CONDA_DIR)/envs/reaktoro/include
ADDITIONAL_INCLUDES += -I $(APPLICATION_DIR)/../reaktoro/build/install/include
ADDITIONAL_INCLUDES += -I $(APPLICATION_DIR)/../reaktoro/build/install/include/Reaktoro/deps/eigen3

ADDITIONAL_LIBS += $(CONDA_DIR)/lib/libReaktoro.so
ADDITIONAL_LIBS += $(CONDA_DIR)/lib/libThermoFun.so
ADDITIONAL_LIBS += $(CONDA_DIR)/lib/libThermoHubClient.so


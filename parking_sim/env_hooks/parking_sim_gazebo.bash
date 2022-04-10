#! /bin/bash

source /usr/share/gazebo/setup.bash
export GAZEBO_MODEL_PATH="${CATKIN_ENV_HOOK_WORKSPACE}/../src/Bvp_Galat_Family/parking_sim/models/:${GAZEBO_MODEL_PATH}"
export GAZEBO_RESOURCE_PATH="${CATKIN_ENV_HOOK_WORKSPACE}/../src/Bvp_Galat_Family/parking_sim/models/:${CATKIN_ENV_HOOK_WORKSPACE}/../src/parking_sim/worlds/:${GAZEBO_RESOURCE_PATH}"


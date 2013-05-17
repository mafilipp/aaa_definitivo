FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/sl_controller/msg"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/sl_controller/psi_debugging.h"
  "../msg_gen/cpp/include/sl_controller/output.h"
  "../msg_gen/cpp/include/sl_controller/ext_state.h"
  "../msg_gen/cpp/include/sl_controller/waypoint.h"
  "../msg_gen/cpp/include/sl_controller/AngleMeasStamped.h"
  "../msg_gen/cpp/include/sl_controller/control_message.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

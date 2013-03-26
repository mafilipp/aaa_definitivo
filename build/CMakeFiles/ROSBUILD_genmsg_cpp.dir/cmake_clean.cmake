FILE(REMOVE_RECURSE
  "../src/aaa_definitivo/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_cpp"
  "../msg_gen/cpp/include/aaa_definitivo/DoubleArrayStamped.h"
  "../msg_gen/cpp/include/aaa_definitivo/waypoint.h"
  "../msg_gen/cpp/include/aaa_definitivo/controller_out.h"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

FILE(REMOVE_RECURSE
  "../src/aaa_definitivo/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/aaa_definitivo/msg/__init__.py"
  "../src/aaa_definitivo/msg/_DoubleArrayStamped.py"
  "../src/aaa_definitivo/msg/_waypoint.py"
  "../src/aaa_definitivo/msg/_controller_out.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

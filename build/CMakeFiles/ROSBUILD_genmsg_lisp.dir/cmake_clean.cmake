FILE(REMOVE_RECURSE
  "../src/aaa_definitivo/msg"
  "../msg_gen"
  "../msg_gen"
  "CMakeFiles/ROSBUILD_genmsg_lisp"
  "../msg_gen/lisp/DoubleArrayStamped.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_DoubleArrayStamped.lisp"
  "../msg_gen/lisp/waypoint.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_waypoint.lisp"
  "../msg_gen/lisp/controller_out.lisp"
  "../msg_gen/lisp/_package.lisp"
  "../msg_gen/lisp/_package_controller_out.lisp"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_lisp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

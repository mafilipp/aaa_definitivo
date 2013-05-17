FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/sl_controller/msg"
  "CMakeFiles/ROSBUILD_genmsg_py"
  "../src/sl_controller/msg/__init__.py"
  "../src/sl_controller/msg/_psi_debugging.py"
  "../src/sl_controller/msg/_output.py"
  "../src/sl_controller/msg/_ext_state.py"
  "../src/sl_controller/msg/_waypoint.py"
  "../src/sl_controller/msg/_AngleMeasStamped.py"
  "../src/sl_controller/msg/_control_message.py"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_genmsg_py.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)

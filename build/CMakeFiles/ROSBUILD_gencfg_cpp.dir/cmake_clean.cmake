FILE(REMOVE_RECURSE
  "../msg_gen"
  "../msg_gen"
  "../src/sl_controller/msg"
  "CMakeFiles/ROSBUILD_gencfg_cpp"
  "../cfg/cpp/sl_controller/reconfigureConfig.h"
  "../docs/reconfigureConfig.dox"
  "../docs/reconfigureConfig-usage.dox"
  "../src/sl_controller/cfg/reconfigureConfig.py"
  "../docs/reconfigureConfig.wikidoc"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/ROSBUILD_gencfg_cpp.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)


(cl:in-package :asdf)

(defsystem "sl_controller-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "psi_debugging" :depends-on ("_package_psi_debugging"))
    (:file "_package_psi_debugging" :depends-on ("_package"))
    (:file "output" :depends-on ("_package_output"))
    (:file "_package_output" :depends-on ("_package"))
    (:file "ext_state" :depends-on ("_package_ext_state"))
    (:file "_package_ext_state" :depends-on ("_package"))
    (:file "waypoint" :depends-on ("_package_waypoint"))
    (:file "_package_waypoint" :depends-on ("_package"))
    (:file "AngleMeasStamped" :depends-on ("_package_AngleMeasStamped"))
    (:file "_package_AngleMeasStamped" :depends-on ("_package"))
    (:file "control_message" :depends-on ("_package_control_message"))
    (:file "_package_control_message" :depends-on ("_package"))
  ))
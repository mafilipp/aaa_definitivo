
(cl:in-package :asdf)

(defsystem "aaa_definitivo-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "DoubleArrayStamped" :depends-on ("_package_DoubleArrayStamped"))
    (:file "_package_DoubleArrayStamped" :depends-on ("_package"))
    (:file "waypoint" :depends-on ("_package_waypoint"))
    (:file "_package_waypoint" :depends-on ("_package"))
    (:file "controller_out" :depends-on ("_package_controller_out"))
    (:file "_package_controller_out" :depends-on ("_package"))
  ))
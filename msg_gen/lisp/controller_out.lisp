; Auto-generated. Do not edit!


(cl:in-package aaa_definitivo-msg)


;//! \htmlinclude controller_out.msg.html

(cl:defclass <controller_out> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (set_thrust
    :reader set_thrust
    :initarg :set_thrust
    :type cl:float
    :initform 0.0)
   (set_phi
    :reader set_phi
    :initarg :set_phi
    :type cl:float
    :initform 0.0)
   (set_theta
    :reader set_theta
    :initarg :set_theta
    :type cl:float
    :initform 0.0)
   (set_psi
    :reader set_psi
    :initarg :set_psi
    :type cl:float
    :initform 0.0))
)

(cl:defclass controller_out (<controller_out>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <controller_out>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'controller_out)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name aaa_definitivo-msg:<controller_out> is deprecated: use aaa_definitivo-msg:controller_out instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <controller_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:header-val is deprecated.  Use aaa_definitivo-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'set_thrust-val :lambda-list '(m))
(cl:defmethod set_thrust-val ((m <controller_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:set_thrust-val is deprecated.  Use aaa_definitivo-msg:set_thrust instead.")
  (set_thrust m))

(cl:ensure-generic-function 'set_phi-val :lambda-list '(m))
(cl:defmethod set_phi-val ((m <controller_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:set_phi-val is deprecated.  Use aaa_definitivo-msg:set_phi instead.")
  (set_phi m))

(cl:ensure-generic-function 'set_theta-val :lambda-list '(m))
(cl:defmethod set_theta-val ((m <controller_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:set_theta-val is deprecated.  Use aaa_definitivo-msg:set_theta instead.")
  (set_theta m))

(cl:ensure-generic-function 'set_psi-val :lambda-list '(m))
(cl:defmethod set_psi-val ((m <controller_out>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:set_psi-val is deprecated.  Use aaa_definitivo-msg:set_psi instead.")
  (set_psi m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <controller_out>) ostream)
  "Serializes a message object of type '<controller_out>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_thrust))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_phi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'set_psi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <controller_out>) istream)
  "Deserializes a message object of type '<controller_out>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_thrust) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_phi) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_theta) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'set_psi) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<controller_out>)))
  "Returns string type for a message object of type '<controller_out>"
  "aaa_definitivo/controller_out")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'controller_out)))
  "Returns string type for a message object of type 'controller_out"
  "aaa_definitivo/controller_out")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<controller_out>)))
  "Returns md5sum for a message object of type '<controller_out>"
  "6f0b0c8f2a4eb2e2a2dd2b810666958b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'controller_out)))
  "Returns md5sum for a message object of type 'controller_out"
  "6f0b0c8f2a4eb2e2a2dd2b810666958b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<controller_out>)))
  "Returns full string definition for message of type '<controller_out>"
  (cl:format cl:nil "Header    header~%~%float64 set_thrust~%float64 set_phi~%float64 set_theta~%float64 set_psi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'controller_out)))
  "Returns full string definition for message of type 'controller_out"
  (cl:format cl:nil "Header    header~%~%float64 set_thrust~%float64 set_phi~%float64 set_theta~%float64 set_psi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <controller_out>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <controller_out>))
  "Converts a ROS message object to a list"
  (cl:list 'controller_out
    (cl:cons ':header (header msg))
    (cl:cons ':set_thrust (set_thrust msg))
    (cl:cons ':set_phi (set_phi msg))
    (cl:cons ':set_theta (set_theta msg))
    (cl:cons ':set_psi (set_psi msg))
))

; Auto-generated. Do not edit!


(cl:in-package aaa_definitivo-msg)


;//! \htmlinclude waypoint.msg.html

(cl:defclass <waypoint> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (waypoint_x
    :reader waypoint_x
    :initarg :waypoint_x
    :type cl:float
    :initform 0.0)
   (waypoint_y
    :reader waypoint_y
    :initarg :waypoint_y
    :type cl:float
    :initform 0.0)
   (waypoint_z
    :reader waypoint_z
    :initarg :waypoint_z
    :type cl:float
    :initform 0.0)
   (waypoint_psi
    :reader waypoint_psi
    :initarg :waypoint_psi
    :type cl:float
    :initform 0.0))
)

(cl:defclass waypoint (<waypoint>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <waypoint>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'waypoint)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name aaa_definitivo-msg:<waypoint> is deprecated: use aaa_definitivo-msg:waypoint instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <waypoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:header-val is deprecated.  Use aaa_definitivo-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'waypoint_x-val :lambda-list '(m))
(cl:defmethod waypoint_x-val ((m <waypoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:waypoint_x-val is deprecated.  Use aaa_definitivo-msg:waypoint_x instead.")
  (waypoint_x m))

(cl:ensure-generic-function 'waypoint_y-val :lambda-list '(m))
(cl:defmethod waypoint_y-val ((m <waypoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:waypoint_y-val is deprecated.  Use aaa_definitivo-msg:waypoint_y instead.")
  (waypoint_y m))

(cl:ensure-generic-function 'waypoint_z-val :lambda-list '(m))
(cl:defmethod waypoint_z-val ((m <waypoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:waypoint_z-val is deprecated.  Use aaa_definitivo-msg:waypoint_z instead.")
  (waypoint_z m))

(cl:ensure-generic-function 'waypoint_psi-val :lambda-list '(m))
(cl:defmethod waypoint_psi-val ((m <waypoint>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader aaa_definitivo-msg:waypoint_psi-val is deprecated.  Use aaa_definitivo-msg:waypoint_psi instead.")
  (waypoint_psi m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <waypoint>) ostream)
  "Serializes a message object of type '<waypoint>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'waypoint_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'waypoint_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'waypoint_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'waypoint_psi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <waypoint>) istream)
  "Deserializes a message object of type '<waypoint>"
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
    (cl:setf (cl:slot-value msg 'waypoint_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'waypoint_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'waypoint_z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'waypoint_psi) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<waypoint>)))
  "Returns string type for a message object of type '<waypoint>"
  "aaa_definitivo/waypoint")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'waypoint)))
  "Returns string type for a message object of type 'waypoint"
  "aaa_definitivo/waypoint")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<waypoint>)))
  "Returns md5sum for a message object of type '<waypoint>"
  "2acafb9604ce5593f72837a14273dd01")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'waypoint)))
  "Returns md5sum for a message object of type 'waypoint"
  "2acafb9604ce5593f72837a14273dd01")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<waypoint>)))
  "Returns full string definition for message of type '<waypoint>"
  (cl:format cl:nil "Header    header~%~%float64 waypoint_x~%float64 waypoint_y~%float64 waypoint_z~%float64 waypoint_psi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'waypoint)))
  "Returns full string definition for message of type 'waypoint"
  (cl:format cl:nil "Header    header~%~%float64 waypoint_x~%float64 waypoint_y~%float64 waypoint_z~%float64 waypoint_psi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <waypoint>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <waypoint>))
  "Converts a ROS message object to a list"
  (cl:list 'waypoint
    (cl:cons ':header (header msg))
    (cl:cons ':waypoint_x (waypoint_x msg))
    (cl:cons ':waypoint_y (waypoint_y msg))
    (cl:cons ':waypoint_z (waypoint_z msg))
    (cl:cons ':waypoint_psi (waypoint_psi msg))
))

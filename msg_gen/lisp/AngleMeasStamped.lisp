; Auto-generated. Do not edit!


(cl:in-package sl_controller-msg)


;//! \htmlinclude AngleMeasStamped.msg.html

(cl:defclass <AngleMeasStamped> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (theta
    :reader theta
    :initarg :theta
    :type cl:float
    :initform 0.0)
   (phi
    :reader phi
    :initarg :phi
    :type cl:float
    :initform 0.0))
)

(cl:defclass AngleMeasStamped (<AngleMeasStamped>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <AngleMeasStamped>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'AngleMeasStamped)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sl_controller-msg:<AngleMeasStamped> is deprecated: use sl_controller-msg:AngleMeasStamped instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <AngleMeasStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:header-val is deprecated.  Use sl_controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'theta-val :lambda-list '(m))
(cl:defmethod theta-val ((m <AngleMeasStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:theta-val is deprecated.  Use sl_controller-msg:theta instead.")
  (theta m))

(cl:ensure-generic-function 'phi-val :lambda-list '(m))
(cl:defmethod phi-val ((m <AngleMeasStamped>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:phi-val is deprecated.  Use sl_controller-msg:phi instead.")
  (phi m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <AngleMeasStamped>) ostream)
  "Serializes a message object of type '<AngleMeasStamped>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'theta))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'phi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <AngleMeasStamped>) istream)
  "Deserializes a message object of type '<AngleMeasStamped>"
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
    (cl:setf (cl:slot-value msg 'theta) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'phi) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<AngleMeasStamped>)))
  "Returns string type for a message object of type '<AngleMeasStamped>"
  "sl_controller/AngleMeasStamped")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'AngleMeasStamped)))
  "Returns string type for a message object of type 'AngleMeasStamped"
  "sl_controller/AngleMeasStamped")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<AngleMeasStamped>)))
  "Returns md5sum for a message object of type '<AngleMeasStamped>"
  "d5b6306d616b12d92ce706280607d735")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'AngleMeasStamped)))
  "Returns md5sum for a message object of type 'AngleMeasStamped"
  "d5b6306d616b12d92ce706280607d735")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<AngleMeasStamped>)))
  "Returns full string definition for message of type '<AngleMeasStamped>"
  (cl:format cl:nil "Header header~%~%float64 theta~%float64 phi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'AngleMeasStamped)))
  "Returns full string definition for message of type 'AngleMeasStamped"
  (cl:format cl:nil "Header header~%~%float64 theta~%float64 phi~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <AngleMeasStamped>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <AngleMeasStamped>))
  "Converts a ROS message object to a list"
  (cl:list 'AngleMeasStamped
    (cl:cons ':header (header msg))
    (cl:cons ':theta (theta msg))
    (cl:cons ':phi (phi msg))
))

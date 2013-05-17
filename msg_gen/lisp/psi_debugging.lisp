; Auto-generated. Do not edit!


(cl:in-package sl_controller-msg)


;//! \htmlinclude psi_debugging.msg.html

(cl:defclass <psi_debugging> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (psi_ref
    :reader psi_ref
    :initarg :psi_ref
    :type cl:float
    :initform 0.0)
   (psi_state
    :reader psi_state
    :initarg :psi_state
    :type cl:float
    :initform 0.0)
   (e_psi
    :reader e_psi
    :initarg :e_psi
    :type cl:float
    :initform 0.0)
   (psi_APM
    :reader psi_APM
    :initarg :psi_APM
    :type cl:float
    :initform 0.0)
   (e_psi_corr
    :reader e_psi_corr
    :initarg :e_psi_corr
    :type cl:float
    :initform 0.0)
   (psi_ref_APM
    :reader psi_ref_APM
    :initarg :psi_ref_APM
    :type cl:float
    :initform 0.0))
)

(cl:defclass psi_debugging (<psi_debugging>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <psi_debugging>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'psi_debugging)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name sl_controller-msg:<psi_debugging> is deprecated: use sl_controller-msg:psi_debugging instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:header-val is deprecated.  Use sl_controller-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'psi_ref-val :lambda-list '(m))
(cl:defmethod psi_ref-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:psi_ref-val is deprecated.  Use sl_controller-msg:psi_ref instead.")
  (psi_ref m))

(cl:ensure-generic-function 'psi_state-val :lambda-list '(m))
(cl:defmethod psi_state-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:psi_state-val is deprecated.  Use sl_controller-msg:psi_state instead.")
  (psi_state m))

(cl:ensure-generic-function 'e_psi-val :lambda-list '(m))
(cl:defmethod e_psi-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:e_psi-val is deprecated.  Use sl_controller-msg:e_psi instead.")
  (e_psi m))

(cl:ensure-generic-function 'psi_APM-val :lambda-list '(m))
(cl:defmethod psi_APM-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:psi_APM-val is deprecated.  Use sl_controller-msg:psi_APM instead.")
  (psi_APM m))

(cl:ensure-generic-function 'e_psi_corr-val :lambda-list '(m))
(cl:defmethod e_psi_corr-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:e_psi_corr-val is deprecated.  Use sl_controller-msg:e_psi_corr instead.")
  (e_psi_corr m))

(cl:ensure-generic-function 'psi_ref_APM-val :lambda-list '(m))
(cl:defmethod psi_ref_APM-val ((m <psi_debugging>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader sl_controller-msg:psi_ref_APM-val is deprecated.  Use sl_controller-msg:psi_ref_APM instead.")
  (psi_ref_APM m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <psi_debugging>) ostream)
  "Serializes a message object of type '<psi_debugging>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'psi_ref))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'psi_state))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'e_psi))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'psi_APM))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'e_psi_corr))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'psi_ref_APM))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <psi_debugging>) istream)
  "Deserializes a message object of type '<psi_debugging>"
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
    (cl:setf (cl:slot-value msg 'psi_ref) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi_state) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'e_psi) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi_APM) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'e_psi_corr) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'psi_ref_APM) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<psi_debugging>)))
  "Returns string type for a message object of type '<psi_debugging>"
  "sl_controller/psi_debugging")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'psi_debugging)))
  "Returns string type for a message object of type 'psi_debugging"
  "sl_controller/psi_debugging")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<psi_debugging>)))
  "Returns md5sum for a message object of type '<psi_debugging>"
  "2653d294dcf7ae964444bf7debb02cd4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'psi_debugging)))
  "Returns md5sum for a message object of type 'psi_debugging"
  "2653d294dcf7ae964444bf7debb02cd4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<psi_debugging>)))
  "Returns full string definition for message of type '<psi_debugging>"
  (cl:format cl:nil "Header    header~%~%float64 psi_ref~%float64 psi_state~%float64 e_psi~%float64 psi_APM~%float64 e_psi_corr~%float64 psi_ref_APM~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'psi_debugging)))
  "Returns full string definition for message of type 'psi_debugging"
  (cl:format cl:nil "Header    header~%~%float64 psi_ref~%float64 psi_state~%float64 e_psi~%float64 psi_APM~%float64 e_psi_corr~%float64 psi_ref_APM~%~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.secs: seconds (stamp_secs) since epoch~%# * stamp.nsecs: nanoseconds since stamp_secs~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <psi_debugging>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <psi_debugging>))
  "Converts a ROS message object to a list"
  (cl:list 'psi_debugging
    (cl:cons ':header (header msg))
    (cl:cons ':psi_ref (psi_ref msg))
    (cl:cons ':psi_state (psi_state msg))
    (cl:cons ':e_psi (e_psi msg))
    (cl:cons ':psi_APM (psi_APM msg))
    (cl:cons ':e_psi_corr (e_psi_corr msg))
    (cl:cons ':psi_ref_APM (psi_ref_APM msg))
))

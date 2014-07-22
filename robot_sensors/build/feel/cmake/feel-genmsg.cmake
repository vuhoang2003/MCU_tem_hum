# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "feel: 1 messages, 1 services")

set(MSG_I_FLAGS "-Ifeel:/home/vuhoang/robot_sensors/src/feel/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(feel_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(feel
  "/home/vuhoang/robot_sensors/src/feel/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/feel
)

### Generating Services
_generate_srv_cpp(feel
  "/home/vuhoang/robot_sensors/src/feel/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/feel
)

### Generating Module File
_generate_module_cpp(feel
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/feel
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(feel_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(feel_generate_messages feel_generate_messages_cpp)

# target for backward compatibility
add_custom_target(feel_gencpp)
add_dependencies(feel_gencpp feel_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS feel_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(feel
  "/home/vuhoang/robot_sensors/src/feel/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/feel
)

### Generating Services
_generate_srv_lisp(feel
  "/home/vuhoang/robot_sensors/src/feel/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/feel
)

### Generating Module File
_generate_module_lisp(feel
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/feel
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(feel_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(feel_generate_messages feel_generate_messages_lisp)

# target for backward compatibility
add_custom_target(feel_genlisp)
add_dependencies(feel_genlisp feel_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS feel_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(feel
  "/home/vuhoang/robot_sensors/src/feel/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel
)

### Generating Services
_generate_srv_py(feel
  "/home/vuhoang/robot_sensors/src/feel/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel
)

### Generating Module File
_generate_module_py(feel
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(feel_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(feel_generate_messages feel_generate_messages_py)

# target for backward compatibility
add_custom_target(feel_genpy)
add_dependencies(feel_genpy feel_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS feel_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/feel)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/feel
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(feel_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/feel)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/feel
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(feel_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/feel
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(feel_generate_messages_py std_msgs_generate_messages_py)

# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "temp_hum: 1 messages, 1 services")

set(MSG_I_FLAGS "-Itemp_hum:/home/vuhoang/tem_hum_sensor/src/temp_hum/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(temp_hum_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/temp_hum
)

### Generating Services
_generate_srv_cpp(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/temp_hum
)

### Generating Module File
_generate_module_cpp(temp_hum
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/temp_hum
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(temp_hum_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(temp_hum_generate_messages temp_hum_generate_messages_cpp)

# target for backward compatibility
add_custom_target(temp_hum_gencpp)
add_dependencies(temp_hum_gencpp temp_hum_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS temp_hum_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/temp_hum
)

### Generating Services
_generate_srv_lisp(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/temp_hum
)

### Generating Module File
_generate_module_lisp(temp_hum
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/temp_hum
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(temp_hum_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(temp_hum_generate_messages temp_hum_generate_messages_lisp)

# target for backward compatibility
add_custom_target(temp_hum_genlisp)
add_dependencies(temp_hum_genlisp temp_hum_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS temp_hum_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum
)

### Generating Services
_generate_srv_py(temp_hum
  "/home/vuhoang/tem_hum_sensor/src/temp_hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum
)

### Generating Module File
_generate_module_py(temp_hum
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(temp_hum_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(temp_hum_generate_messages temp_hum_generate_messages_py)

# target for backward compatibility
add_custom_target(temp_hum_genpy)
add_dependencies(temp_hum_genpy temp_hum_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS temp_hum_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/temp_hum)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/temp_hum
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(temp_hum_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/temp_hum)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/temp_hum
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(temp_hum_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/temp_hum
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(temp_hum_generate_messages_py std_msgs_generate_messages_py)

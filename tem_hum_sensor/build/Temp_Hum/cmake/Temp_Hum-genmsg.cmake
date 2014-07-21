# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "Temp_Hum: 1 messages, 1 services")

set(MSG_I_FLAGS "-ITemp_Hum:/home/vuhoang/tem_hum_sensor/src/Temp_Hum/msg;-Istd_msgs:/opt/ros/hydro/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(Temp_Hum_generate_messages ALL)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Temp_Hum
)

### Generating Services
_generate_srv_cpp(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Temp_Hum
)

### Generating Module File
_generate_module_cpp(Temp_Hum
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Temp_Hum
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(Temp_Hum_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(Temp_Hum_generate_messages Temp_Hum_generate_messages_cpp)

# target for backward compatibility
add_custom_target(Temp_Hum_gencpp)
add_dependencies(Temp_Hum_gencpp Temp_Hum_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Temp_Hum_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Temp_Hum
)

### Generating Services
_generate_srv_lisp(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Temp_Hum
)

### Generating Module File
_generate_module_lisp(Temp_Hum
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Temp_Hum
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(Temp_Hum_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(Temp_Hum_generate_messages Temp_Hum_generate_messages_lisp)

# target for backward compatibility
add_custom_target(Temp_Hum_genlisp)
add_dependencies(Temp_Hum_genlisp Temp_Hum_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Temp_Hum_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/msg/Num.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum
)

### Generating Services
_generate_srv_py(Temp_Hum
  "/home/vuhoang/tem_hum_sensor/src/Temp_Hum/srv/AddTwoInts.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum
)

### Generating Module File
_generate_module_py(Temp_Hum
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(Temp_Hum_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(Temp_Hum_generate_messages Temp_Hum_generate_messages_py)

# target for backward compatibility
add_custom_target(Temp_Hum_genpy)
add_dependencies(Temp_Hum_genpy Temp_Hum_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS Temp_Hum_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Temp_Hum)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/Temp_Hum
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
add_dependencies(Temp_Hum_generate_messages_cpp std_msgs_generate_messages_cpp)

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Temp_Hum)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/Temp_Hum
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
add_dependencies(Temp_Hum_generate_messages_lisp std_msgs_generate_messages_lisp)

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/Temp_Hum
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
add_dependencies(Temp_Hum_generate_messages_py std_msgs_generate_messages_py)

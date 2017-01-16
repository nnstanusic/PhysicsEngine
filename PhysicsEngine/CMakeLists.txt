project(PhysicsEngine)
cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/src/GameObject)
include_directories(${CMAKE_SOURCE_DIR}/src/GraphicsComponents)
include_directories(${CMAKE_SOURCE_DIR}/src/GraphicsComponents/ParticleEffects)
include_directories(${CMAKE_SOURCE_DIR}/src/PhysicsComponents)
include_directories(${CMAKE_SOURCE_DIR}/src/PhysicsComponents/Collider)
include_directories(${CMAKE_SOURCE_DIR}/src/AIComponents)
include_directories(${CMAKE_SOURCE_DIR}/src)


file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES} )

#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )


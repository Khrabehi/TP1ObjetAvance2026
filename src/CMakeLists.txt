
add_library( base )

target_sources( base
  PRIVATE
    tp1_cpp/Vegetal.cpp tp1_cpp/Arbre.cpp tp1_cpp/Fleur.cpp 
)

target_include_directories( base
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable( ${PROJECT_NAME}
                main.cpp )

target_link_libraries( ${PROJECT_NAME} PRIVATE base )

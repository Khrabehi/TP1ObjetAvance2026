
add_library( base )

target_sources( base
  PRIVATE
    tp1_cpp/Vegetal.cpp tp1_cpp/Arbre.cpp tp1_cpp/Fleur.cpp tp1_cpp/Champignon.cpp
)
target_sources( base
  PRIVATE
		tp1_cpp/strategie/Dormance.cpp tp1_cpp/strategie/CroissancePrintaniere.cpp tp1_cpp/strategie/CroissanceEstivale.cpp tp1_cpp/strategie/Secheresse.cpp
)

target_sources( base
  PRIVATE
	tp1_cpp/Terrain.cpp tp1_cpp/fabrique/FabriqueBase.cpp
)

target_include_directories( base
  PUBLIC "." )

add_executable( ${PROJECT_NAME}
                main.cpp )

target_link_libraries( ${PROJECT_NAME} PRIVATE base )

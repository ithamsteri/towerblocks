add_executable(towerblock
        main.cpp
        Application.cpp
        Application.h
        Scene.cpp
		Scene.h
		MainMenuScene.cpp
		MainMenuScene.h
		Resource.cpp
		Resource.h
		HowToPlayScene.cpp
		HowToPlayScene.h
		GameScene.cpp
		GameScene.h
		Game.cpp
		Game.h
		Crane.cpp
		Crane.h
		Unit.cpp
		Unit.h
		Tower.cpp
		Tower.h
		Background.cpp
		Background.h
        HighScoreScene.cpp
		HighScoreScene.h
		ScoreStorage.h
		)

target_compile_definitions(towerblock PRIVATE ${OXYGINE_DEFINITIONS})
target_link_libraries(towerblock PRIVATE ${OXYGINE_CORE_LIBS})
set_target_properties(towerblock PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        INCLUDE_DIRECTORIES "${OXYGINE_INCLUDE_DIRS}"
        )

if (WIN32) #disable console mode for VC++
		set_target_properties(towerblock PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

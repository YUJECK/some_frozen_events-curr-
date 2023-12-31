cmake_minimum_required(VERSION 3.26)
project(some_frozen_events)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(libs/SFML)

add_executable(some_frozen_events main.cpp
        apMoon/Game.h
        apMoon/Game.cpp
        apMoon/Entity.h
        apMoon/Entity.cpp
        apMoon/Component.cpp
        apMoon/Component.h
        Player.cpp
        Player.h
        apMoon/Renderer/RendererManager.cpp
        apMoon/Renderer/RendererManager.h
        apMoon/Renderer/IRendererComponent.h
        MovementComponent.cpp
        MovementComponent.h
        apMoon/Renderer/RendererMethod.h
        apMoon/Renderer/SpriteRenderer.cpp
        apMoon/Renderer/SpriteRenderer.h
        apMoon/Renderer/Pseudo3DRenderer.cpp
        apMoon/Renderer/Pseudo3DRenderer.h
        apMoon/Transform.h
        apMoon/Transform.cpp
        apMoon/Inputs/InputService.cpp
        apMoon/Inputs/InputService.h
        apMoon/WorldMap.cpp
        apMoon/WorldMap.h
        Wall.cpp
        Wall.h
        apMoon/MapCell.cpp
        apMoon/MapCell.h
        apMoon/Renderer/IRendererComponent.cpp
        PlayerShooting.cpp
        PlayerShooting.h
        apMoon/Renderer/RayData.cpp
        apMoon/Renderer/RayData.h
        Enemy.cpp
        Enemy.h
        Health.cpp
        Health.h
        PlayerHealth.cpp
        PlayerHealth.h
        apMoon/Scene.cpp
        apMoon/Scene.h
        apMoon/BasicRenderer.cpp
        apMoon/BasicRenderer.h
        content/IntroLevel.cpp
        content/IntroLevel.h
        apMoon/GUI/GUILevel.cpp
        apMoon/GUI/GUILevel.h
        apMoon/GUI/GUIElement.cpp
        apMoon/GUI/GUIElement.h
        apMoon/GUI/GUIRenderer.cpp
        apMoon/GUI/GUIRenderer.h
        content/PlayerHUD.cpp
        content/PlayerHUD.h
        content/StaticImage.cpp
        content/StaticImage.h
)

target_link_libraries(some_frozen_events PRIVATE sfml-graphics sfml-system sfml-window)
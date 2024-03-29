//
// Created by User on 06.01.2024.
//

#include "IntroLevel.h"
#include "../apMoon/Game.h"
#include "PlayerHUD.h"
#include "../apMoon/GUI/GUIRenderer.h"
#include "Enemies/Enemy.h"

void IntroLevel::upload() {
    PlayerHUD * hud = new PlayerHUD(sf::Vector2f(0,0), sf::Vector2f(0,0));

    GUIRenderer::get_instance()->push_level(hud);

    Player *player = new Player;
    player->set_position(2, 10);

    Enemy *testEnemy = new Enemy;
    testEnemy->set_position(15, 9);

    sf::Image intro_level_map;
    player->name = "Player";
    intro_level_map.loadFromFile(Game::process_path("FirstLevel.png"));

    Game::get_instance()->load_map(intro_level_map);
    Game::get_instance()->push_entity(player);
    Game::get_instance()->push_entity(testEnemy);
}

#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <cstdint>
#include <ecs/ecs.hpp>
#include <ecs/entity.hpp>
#include <memory>
#include "camera.hpp"
#include "spell_manager.hpp"
#include "tilemap.hpp"

class Event;
class Renderer;

class Game {
   public:
    Game(std::shared_ptr<Renderer> r);

    void step();

    void render();

    void load();

    // Events
    void on_event(Event &e);
    void on_key_press(Event &e);
    void on_key_release(Event &e);
    void on_window_close(Event &e);
    void on_window_resize(Event &e);

    // Systems -- Game logic
    void s_age();
    void s_fire();
    void s_input();
    void s_movement_input();
    void s_movement();
    void s_camera();
    void s_timer();
    void s_spells();
    void s_health();

    // Systems -- Rendering
    void s_render();
    void s_render_debug();

   private:
    ECS ecs_;
    std::uint64_t frame_;
    std::shared_ptr<Renderer> renderer_;
    TileMap tile_map_;
    SpellManager spell_manager_;
    Camera camera_;
};

#endif

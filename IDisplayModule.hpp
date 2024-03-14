#pragma once

#include "Type.hpp"

class IDisplayModule {
    public:
        ~IDisplayModule() = default;

        virtual void display() = 0;
        virtual void clear() = 0;

        virtual std::vector<Input> event() = 0;
        virtual SelectedLib menu(Menu &menu) = 0;

        //update must be followed by a display()
        virtual void updateText(const std::string& text, Vector2D pos) = 0;
        virtual void updateEntity(IEntity &entity) = 0;
        virtual void updateMap(Map &map) = 0;

        //Display a specific non gameplay screen (splash, game over...)
        virtual void staticScreen(std::size_t id) = 0;
        virtual void loadSpriteDict(const std::map<EntityType, std::string>& spriteDict) = 0;
};

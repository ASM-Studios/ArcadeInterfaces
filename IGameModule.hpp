#pragma once

#include "Type.hpp"

class IGameModule {
    public:
        virtual std::size_t getScore() = 0;
        virtual GameState getState() = 0;
        virtual std::size_t getLive() = 0;

        //delta since the start of the game
        virtual void handleInput(std::size_t deltaTime, Input input, const std::vector<std::reference_wrapper<IEntity>>& entities) = 0;
        virtual void update(std::size_t deltaTime, const std::vector<std::reference_wrapper<IEntity>>& entities) = 0;

        virtual std::vector<std::pair<std::string, Vector2D>> getTexts() = 0;

        virtual std::vector<std::reference_wrapper<IEntity>> initEntities(Map &map) = 0;
        virtual std::map<EntityType, std::string> getSpriteDict() = 0;
};

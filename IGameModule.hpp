#pragma once

#include "Type.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;

        //delta since the start of the game
        virtual void handleInput(std::size_t deltaTime, Input input, const std::vector<std::reference_wrapper<IEntity>>& entities) = 0;
        virtual void update(std::size_t deltaTime, const std::vector<std::reference_wrapper<IEntity>>& entities) = 0;

        //return an instruction sent from the game to the core, see the documentation for more details
        virtual std::vector<std::string> getInstruction() = 0;

        //init function to call on game start
        virtual Map getMap() = 0; //Map being a IGameModule attribute
        virtual std::vector<std::reference_wrapper<IEntity>> initEntities() = 0;
        virtual std::map<EntityType, std::string> getSpriteDict() = 0;
};

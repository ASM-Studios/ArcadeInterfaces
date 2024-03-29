#pragma once

#include "Type.hpp"

class IGameModule {
    protected:
        Map map;
        std::vector<std::reference_wrapper<IEntity>> entities;
        EntitiesDescription entitiesDescriptor;

    public:
        virtual ~IGameModule() = default;

        //delta since the start of the game
        virtual void handleInput(std::size_t deltaTime, Input input) = 0;
        virtual void update(std::size_t deltaTime) = 0;

        //return an instruction sent from the game to the core, see the documentation for more details
        virtual std::vector<std::string> getInstruction() = 0;
        // return a list of entities to display.
        virtual EntitiesDescription getEntities() = 0;

        //init function to call on game start
        virtual Map& getMap() = 0;
        virtual std::map<EntityType, std::pair<std::string, std::size_t>> getSpriteDict() = 0;
        virtual std::map<StaticScreen, std::string> getStaticScreen() = 0;
};

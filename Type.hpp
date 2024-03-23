#pragma once

#include <vector>
#include <map>
#include <string>
#include <functional>

/*-----Core-----*/

enum KiwiBool {
    NotKiwi = false,
    Kiwi = true
};

struct LibSelector {
    std::vector<std::string>::iterator selected;
    std::vector<std::string> list;
};

struct Menu {
    int score;
    std::string name;
    LibSelector graphical;
    LibSelector game;
};

struct SelectedLib {
    std::string graphical;
    std::string game;
};

struct Vector2D {
    int x;
    int y;

    Vector2D operator+(Vector2D other) const {
        return {x + other.x, y + other.y};
    }

    Vector2D operator-(Vector2D other) const {
        return {x - other.x, y - other.y};
    }

    Vector2D& operator+=(Vector2D other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2D& operator-=(Vector2D other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};

enum EntityType {
    UNDEFINED = -1,
    WALL = 0,
    PLAYER = 1,
    ENEMY = 2,
    ITEM1 = 3,
    ITEM2 = 4,
    ITEM3 = 5,
    ITEM4 = 6,
    ENTITY_SEC, // Special entity type wich is link to another entity. e.g. a bullet // the snake corpse
};

using Map = std::vector<std::vector<EntityType>>;

using EntitiesDescription = std::vector<std::pair<EntityType, Vector2D>>;

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    MENU,
    ACTION
};

enum Signature {
    GAME = 404,
    GRAPHICAL = 808,
};

class IEntity {
    protected:
        EntityType entityType;
        Vector2D position;
        bool visibility;

    public:
        virtual ~IEntity() = 0;
        virtual EntityType getEntityType() const = 0;
        virtual void setEntityType(EntityType) = 0;
        virtual Vector2D getPosition() const = 0;
        virtual void setPosition(Vector2D position) = 0;
        virtual bool getVisibility() const = 0;
        virtual void setVisibility(bool visibility) = 0;
};

enum GameState {
    RUNNING,
    WIN,
    GAMEOVER,
    SPLASH
};

enum StaticScreen {
    SCREEN_SPLASH,
    SCREEN_GAMEOVER
};

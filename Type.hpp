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

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    QUIT,
    MENU,
    ACTION,
    RESET,
    NEXT_DI,
    NEXT_GA
};

struct Vector2D {
    float x;
    float y;
    Input rotation;

    Vector2D() = default;
    Vector2D(float X, float Y) : x(X), y(Y), rotation(RIGHT) {}
    Vector2D(float X, float Y, Input R) : x(X), y(Y), rotation(R) {}

    Vector2D operator+(Vector2D other) const {
        return {x + other.x, y + other.y, rotation};
    }

    Vector2D operator-(Vector2D other) const {
        return {x - other.x, y - other.y, rotation};
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

    bool operator==(Vector2D other) {
        return x == other.x && y == other.y && rotation == other.rotation;
    }

    bool operator!=(Vector2D other) {
        return x != other.x || y != other.y || rotation != other.rotation;
    }
};

enum EntityType {
    UNDEFINED,
    WALL,
    PLAYER,
    PLAYER_SEC,
    PLAYER_MOVE,
    PLAYER_DYING,
    ENEMY,
    ENEMY1,
    ENEMY1_SEC,
    ENEMY1_MOVE,
    ENEMY1_DYING,
    ENEMY2,
    ENEMY2_SEC,
    ENEMY2_MOVE,
    ENEMY2_DYING,
    ENEMY3,
    ENEMY3_SEC,
    ENEMY3_MOVE,
    ENEMY3_DYING,
    ENEMY4,
    ENEMY4_SEC,
    ENEMY4_MOVE,
    ENEMY4_DYING,
    ENEMY5,
    ENEMY5_SEC,
    ENEMY5_MOVE,
    ENEMY5_DYING,
    ITEM1,
    ITEM2,
    ITEM3,
    ITEM4,
    ITEM5,
    ITEM6,
    ITEM7,
    ITEM8,
    ITEM9,
    BULLET
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
    ACTION,
    RESET,
    NEXT_DI,
    NEXT_GA
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
        virtual ~IEntity() = default;
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

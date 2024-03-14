/*-----Types-----*/

#include <string>
#include <vector>
#include <map>

enum EntityType {
    WALL = 0,
    PLAYER = 1,
    ENEMY = 2,
    ITEM1 = 3,
    ITEM2 = 4,
    ITEM3 = 5,
    ITEM4 = 6,
};

struct LibSelector {
    std::vector<std::string>::iterator selected;
    std::vector<std::string> list;
};

struct Menu {
    int score;
    std::string name;
    LibSelector graphical;
    LibSelector games;
};

struct SelectedLib {
    std::string graphical;
    std::string game;
};

struct Vector2D {
    int x;
    int y;

    Vector2D operator+(Vector2D other) const;
    Vector2D operator-(Vector2D other) const;

    Vector2D& operator+=(Vector2D other);
    Vector2D& operator-=(Vector2D other);
};

struct Map {
    std::vector<std::vector<EntityType>> grid;
};

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

enum GameState {
    RUNNING,
    WIN,
    GAMEOVER,
    SLAPSH
};

class IEntity {
    private:
        EntityType entityType;
        Vector2D position;
        bool visibility;

    public:
        virtual EntityType getEntityType() = 0;
        virtual void setEntityType(EntityType) = 0;

        virtual Vector2D getPosition() = 0;
        virtual void setPosition(Vector2D position) = 0;

        virtual bool getVisibility() = 0;
        virtual void setVisibility(bool visibility) = 0;
};

/*-----Display-----*/

class IDisplayModule {
    public:
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

extern "C" {
    IDisplayModule *entryPoint();
    Signature getSignature();
}

/*-----Game-----*/

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

extern "C" {
    IDisplayModule *entryPoint();
    Signature getSignature();
}

#include "../libs/chesto/src/TextElement.hpp"
#include "../libs/chesto/src/Button.hpp"

class SetupScreen : public Element
{
public:
    SetupScreen();
    ~SetupScreen();

    bool process(InputEvents *event);
    void render(Element *parent);

    std::string getIp();

private:
    ImageElement icon;
    TextElement title;
    TextElement setupInscructions;
    Button btnQuit;
};
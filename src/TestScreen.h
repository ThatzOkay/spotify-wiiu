
#include "../libs/chesto/src/TextElement.hpp"
#include "../libs/chesto/src/Button.hpp"

class TestScreen : public Element
{
    public:
        TestScreen();
    
    private:
        TextElement testText;
        Button btnQuit;
};
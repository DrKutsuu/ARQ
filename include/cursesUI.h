#ifndef CURSES_UI_H
#define CURSES_UI_H

#include <string>
#include "ui.h"
 
#define MAINWIN_REAR_X     getMaxX()
#define MAINWIN_REAR_Y     getMaxY()
#define MAINWIN_FRONT_X    MAINWIN_REAR_X-2
#define MAINWIN_FRONT_Y    MAINWIN_REAR_Y-2

#define CONSOLEWIN_REAR_X  MAINWIN_REAR_X-2
#define CONSOLEWIN_REAR_Y  6
#define CONSOLEWIN_FRONT_X CONSOLEWIN_REAR_X-2
#define CONSOLEWIN_FRONT_Y CONSOLEWIN_REAR_Y-2

#define INVWIN_REAR_X MAINWIN_REAR_X
#define INVWIN_REAR_Y MAINWIN_REAR_Y-CONSOLEWIN_REAR_Y

#define INVWIN_FRONT_X INVWIN_REAR_X-2
#define INVWIN_FRONT_Y INVWIN_REAR_Y-2

#define INV_ITEM_Y 10 //The number of chars wide an inventory slot should be (How much text it can hold)

class CursesUI : public UI {
private:

    WINDOW* titlewin=NULL; //Creates the stats window for content

    WINDOW* mainwin_rear =NULL; //Creates a new window called new win at 0,1 that has the dimensions of grid_x, and grid_y.
    WINDOW* mainwin_front=NULL; //Creates a new window called new win at 1,2 that has the dimensions of grid_x, and grid_y.

    WINDOW* consolewin_rear=NULL; //Creates the console window for deco
    WINDOW* consolewin_front=NULL; //Creates the console window for content

    WINDOW* invwin_front=NULL;
    WINDOW* invwin_rear=NULL;
    
    
    
    
public:
    
    int wprintw_col(WINDOW* winchoice, const char* text, int color_choice);
    int wprint_at(WINDOW* winchoice, const char* text, int pos_y, int pos_x);
    int wprintNoRefresh(WINDOW* win, std::string text);

    Item* AccessPlayerInventory(Player* p);
    int PlayerItemProc(Player* p, Item* itm, int x, int y);

    void TileProc(int y, int x, tile t);


    virtual int InitScreen();
    virtual void InitWindows();
    virtual void DestroyWindows();
    virtual void DecorateWindows();

    virtual void DrawItems(Map* m);
    virtual void DrawContainers(Map* m);

    virtual void DrawPlayerStats(std::string name, int health, int loot);

    void HighlightInvList(int i, int max_x, int max_y);
    virtual void ListInv(Container* c,long unsigned int invIndex);
//    virtual void ListInv(Inventory* a);
    virtual void ClearInvHighlighting();
    virtual void HighlightInv(int index);

    virtual int DrawMap(Map* m, bool fogOfWar, int playerX, int playerY, int viewDistance);
    virtual void DrawCharacter(int x, int y, int colour, char symbol);

    virtual void ShowInfo();
    virtual void ShowNotification(const char* text);
    virtual int Menu(const char** text, int buttons);

    virtual void UpdateUI();

    virtual void ClearConsole();
    virtual void ConsolePrint(std::string text, int posX, int posY);
    virtual void ConsolePrintWithWait(std::string text, int posX, int posY);
    virtual int ConsoleGetInput();
    virtual std::string ConsoleGetString();
    
    virtual void ClearConsoleHighlighting();
    virtual void HighlightConsole(int scr_x, int scr_y);
    
    void copyUI(const CursesUI& ui) {
        this->consolewin_front = ui.consolewin_front;
        this->consolewin_rear = ui.consolewin_rear;
        this->invwin_front = ui.invwin_front;
        this->invwin_rear = ui.invwin_rear;
        this->mainwin_front = ui.mainwin_front;
        this->mainwin_rear = ui.mainwin_rear;
        this->titlewin = ui.titlewin;
    }
    
    //Overriding assignment operator
    CursesUI& operator=(const CursesUI& ui) {  
        copyUI(ui);
        return *this;
    }
    
    //Copy constructor  
    CursesUI(const CursesUI& ui) {  
        copyUI(ui);
    }
    
    CursesUI() {
        raw(); //stops needing [Enter] to input text
    }
    

};

#endif

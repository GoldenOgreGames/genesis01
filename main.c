// make sure to change include path to find local copy of SGDK/inc & res
#include <genesis.h>
#include <resources.h>

    // player sprite
    Sprite* player;
    int player_x = 10; // xy coordinates
    int player_y = 10;
    int player_vel = 2; // velocity

int main(){
    
    SPR_init();
    PAL_setPalette(PAL2, player1_sp.palette->data, DMA);
    player = SPR_addSprite(&player1_sp, player_x, player_y, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
    // will remove
  VDP_drawText("From the Local", 20, 20);
    

    while(1){
        SPR_setPosition(player,player_x, player_y);
        SPR_update();
        SYS_doVBlankProcess();
    }
    return 0;
}
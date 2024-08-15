// make sure to change include path to find local copy of SGDK/inc & res
#include <genesis.h>
#include <resources.h>

    // player sprite
    Sprite* player;
    int player_x = 10; // xy coordinates
    int player_y = 10;
    int player_vel = 2; // velocity

    // MAP 
    u16 ind = TILE_USER_INDEX;
    Map* level_1_map;

static void handleInput();
int main(){
    // Add MAP
    VDP_loadTileSet(&zelda_ts, ind, DMA);
    level_1_map = MAP_create(&zelda_map, BG_B, TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, ind));
    PAL_setPalette(PAL0, zelda_pal.data, DMA);
    MAP_scrollTo(level_1_map, 0, 0);
    ind+= zelda_ts.numTile;
    //
    SPR_init();
    PAL_setPalette(PAL2, player1_sp.palette->data, DMA);
    player = SPR_addSprite(&player1_sp, player_x, player_y, TILE_ATTR(PAL2, FALSE, FALSE, FALSE));
    // will remove
  VDP_drawText("SONIC: ", 0, 0);
    

    while(1){
        //SPR_setPosition(player,player_x, player_y);
        handleInput();
        SPR_update();
        SYS_doVBlankProcess();
    }
    return 0;
}

// handle movement
static void handleInput(){
    u16 value = JOY_readJoypad(JOY_1);
    if(value & BUTTON_LEFT){
        player_x -=player_vel;
       // SPR_setAnim(player,ANIM_WALK);
        SPR_setHFlip(player,TRUE);
    } else if(value & BUTTON_RIGHT){
        player_x +=player_vel;
      //  SPR_setAnim(player,ANIM_WALK);
        SPR_setHFlip(player,FALSE);
    }
    if(value & BUTTON_UP){
        player_y -=player_vel;
    } else if(value & BUTTON_DOWN){
        player_y +=player_vel;
    }

    // will need to reset idle when anim is used

    // Move sprite
    SPR_setPosition(player, player_x, player_y);
}
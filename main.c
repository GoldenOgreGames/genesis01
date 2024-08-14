// make sure to change include path to find local copy of SGDK/inc & res
#include <genesis.h>

int main(){
    // test changes
    VDP_drawText("From the HUB", 20, 20);
    while(1){

        VDP_waitVSync();
    }
    return 0;
}

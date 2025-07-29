#include "/home/codeleaded/System/Static/Library/SoundBoard.h"

void* SoundBoard_Starter(SoundBoard* sb){
    SoundBoard_Start(sb);
}

int main(int argc, char *argv[]) {

    SoundBoard sb = SoundBoard_New();

    Thread t = Thread_New(NULL,(void*)SoundBoard_Starter,&sb);
    Thread_Start(&t);

    short buffer[1024 * 2];
    for (int i = 0; i < 1024 * 2; i++) {
        //buffer[i] = rand() % 65536 - 32768;
        buffer[i] = 10000 + rand() % 1000;
    }
    SoundBoard_Set(&sb,buffer,1024);

    Thread_Join(&t,NULL);

    SoundBoard_Free(&sb);
    return 0;
}
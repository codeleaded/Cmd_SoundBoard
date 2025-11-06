#if defined(__linux__)
    #include "/home/codeleaded/System/Static/Library/SoundBoard.h"
#elif defined(_WINE)
    #include "/home/codeleaded/System/Static/Library/SoundBoard.h"
#elif defined(_WIN32)
    #include "/home/codeleaded/System/Static/Library/SoundBoard.h"
#elif defined(__APPLE__)
    #error "Apple not supported!"
#else
    #error "Platform not supported!"
#endif


void* SoundBoard_StarterFunc(SoundBoard* sb){
    SoundBoard_Start(sb);
}

int main(int argc, char *argv[]) {

    SoundBoard sb = SoundBoard_New(SOUNDBOARD_CHANNELS,SOUNDBOARD_BITS_PER_SAMPLE,SOUNDBOARD_SAMPLE_RATE,1);

    Thread t = Thread_New(NULL,(void*)SoundBoard_StarterFunc,&sb);
    Thread_Start(&t);

    short buffer[1024 * 2];
    for (int i = 0; i < 1024 * 2; i++) {
        //buffer[i] = rand() % 65536 - 32768;
        buffer[i] = 10000 + rand() % 1000;
    }
    SoundBoard_Set(&sb,buffer,1024);

    Thread_Join(&t);

    SoundBoard_Free(&sb);
    return 0;
}
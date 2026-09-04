// ./music.c
#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main() {
    struct Song *test = add_song(get_song_name(), get_artist_name(), 3.42);
    printf("%s by %s\nDuration: %.2lf\n", test->song_title, test->artist_name, test->song_duration);

    
    return 0;
}
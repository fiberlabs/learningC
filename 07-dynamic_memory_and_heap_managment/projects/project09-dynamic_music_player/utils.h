// ./utils.h

//music player functions
struct Song
{
    char *song_title;
    char *artist_name;
    float song_duration;
    struct Song *prev;
    struct Song *next;
};

char *get_song_name();
char *get_artist_name();
struct Song *add_song(char *title_parameter, char *artist_parameter, float duration_parameter);


//menu related functions
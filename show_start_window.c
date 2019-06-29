#include <curses.h>
#include "core_functions/bass.h"
#include "game_console.h"
extern struct dimension map_size;
void show_start_window() {
    char mesg3[] = "Game starts in";
    char mesg4[] = "3";
    struct dimension win_size;
    HSTREAM start = BASS_StreamCreateFile(FALSE, "start.mp3", 0, 0, 0);
    win_size.x = 2 * map_size.x / 3;
    win_size.y = map_size.y / 3 + 1;
    WINDOW *start_win = newwin(win_size.y, win_size.x, map_size.y / 3, map_size.x / 5 - 1);
    box(start_win, ' ', ' ');
    mvwhline(start_win, 0, 0, '!', win_size.x);
    mvwhline(start_win, win_size.y - 1, 0, '!', win_size.x);
    mvwvline(start_win, 0, 0, '!', win_size.y);
    mvwvline(start_win, 0, win_size.x - 1, '!', win_size.y);
    mvwprintw(start_win, 1, (win_size.x - strlen(mesg3)) / 2, "%s", mesg3);
    mvwprintw(start_win, 3, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    BASS_ChannelPlay(start, FALSE);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, 3, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, 3, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    delay(900);
    mesg4[0] = mesg4[0] - 1;
    mvwprintw(start_win, 3, (win_size.x - strlen(mesg4)) / 2, "%s", mesg4);
    wrefresh(start_win);
    endwin();
    clear();
    refresh();
}
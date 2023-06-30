#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define str_len 30

typedef struct player {
    char pname[str_len];
    float salary;
    struct player *next_player;
} plyr;

typedef struct team {
    char tname[str_len];
    char mentor[str_len];
    int games_won;
    int games_lost;
    struct player *node_p;
    struct team *next_team;
} tm;

struct team *head = NULL;

void insert_team(char *t, char *men, int gw, int gl) {
    tm *newTeam = malloc(sizeof(tm));
    strcpy(newTeam->tname, t);
//  newTeam->tname[str_len-1] = '\0';
    strcpy(newTeam->mentor, men);
//  newTeam->mentor[str_len-1] = '\0';
    newTeam->games_won = gw;
    newTeam->games_lost = gl;
    newTeam->next_team = NULL;
    plyr *p = malloc(sizeof (plyr));
    strcpy(p->pname, men);
    newTeam->node_p = p;

    tm *current = head;
    if (current){
        while (current->next_team) {
            current = current->next_team;
        }
        current->next_team = newTeam;
    } else {
        head = newTeam;
    }

    /* if (!head) {
         head = newTeam;
     } else {
         tm *current = head;
         while (current->next_team != NULL) {
             current = current->next_team;
         }
         plyr *p = malloc(sizeof (plyr));
 //        p->pname = men;
         strcpy(p->pname, men);
         current->next_team = newTeam;
         current->node_p = p;
     }*/
};

void insert_capt(char *team, char *capt, float sal) {
    tm *temp = head;
    while (temp != NULL) {
        if (team == temp->tname) {
            break;
        }
    }
    plyr *newCapt = malloc(sizeof(plyr));
    strncpy(newCapt->pname, team, str_len);
    newCapt->pname[str_len - 1] = '\0';
    newCapt->salary = sal;
};

void traverse_team() {
    tm *temp = head;
    while (temp) {
        printf("Team : %s\n", temp->tname);
        printf("Mentor : %s\n", temp->mentor);
        printf("Games won : %d\n", temp->games_won);
        printf("Games lost : %d\n", temp->games_lost);
        temp = temp->next_team;
    }
};


void del_middle_team(char *x) {
    tm *temp = head;
    while (temp->next_team != NULL) {
        if (temp->next_team->tname == x) {
            temp->next_team = temp->next_team->next_team;
        }
        temp = temp->next_team;
    }
};

void traverse_player();

void delete_player();

void get_team();

void get_player();

int main() {
//  tm* head = NULL;
//    head = malloc(sizeof(tm));
    insert_team("Manchester City", "Pepe", 10, 1);
    insert_team("Not City", "notPepe", 10, 1);
    traverse_team();
    return 0;
}

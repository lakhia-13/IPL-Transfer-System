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

struct team *head;

void insert_team(char *t, char *men, int gw, int gl, char *cname, float sal){
    tm* newTeam = malloc(sizeof(tm));
    newTeam->node_p = malloc(sizeof(plyr));
    strcpy(newTeam->tname,t);
    strcpy(newTeam->mentor,men);
    newTeam->games_won = gw;
    newTeam->games_lost = gl;
    strcpy(newTeam->node_p->pname,cname);
    newTeam->node_p->next_player = NULL;
    newTeam->node_p->salary = sal;
    newTeam->next_team = NULL;
    tm* current = head;

    if (!current){
        head = newTeam;
    }else {
        while (current->next_team){
            current = current->next_team;
        }
        current->next_team = newTeam;
    }
}

void insert_plyr(char* team, char* playr, float sal){
    tm* temp = head;
    plyr* currentp = malloc(sizeof(plyr));
    while (temp->next_team){
        if (!strcmp(team, temp->tname)){
            break;
        }
        temp = temp->next_team;
    }
    plyr* curp = temp->node_p;
    while(curp->next_player){
        curp = curp->next_player;
    }
    strcpy(currentp->pname,playr);
    currentp->salary = sal;
    currentp->next_player = NULL;
    curp->next_player = currentp;
}

void traverse_player(char* team){
    tm* temp = head;
    while(temp){
        if (!strcmp(team, temp->tname)) break;
        temp = temp->next_team;
    }
    plyr* cup = temp->node_p->next_player;
    while(cup){
        printf("Player : %s\n", cup->pname);
        printf("Salary : %f\n\n", cup->salary);
        cup = cup->next_player;
    }
}

void traverse_team(){
    tm *temp = head;
    while(temp != NULL){
        printf("Team : %s\n", temp->tname);
        printf("Mentor : %s\n", temp->mentor);
        printf("Captain : %s\n", temp->node_p->pname);
        printf("Salary : %f\n", temp->node_p->salary);
        printf("Games won : %d\n", temp->games_won);
        printf("Games lost : %d\n\n", temp->games_lost);
        temp = temp->next_team;
    }
}

void del_middle_team(tm* head, char* x){
    tm* temp = head;
    while(temp->next_team!=NULL){
        if(temp->next_team->tname==x){
            temp->next_team = temp->next_team->next_team;
        }
        temp = temp->next_team;
    }
};

void delete_player();
void get_team();
void get_player();

int main(){
    insert_team("Gujarat Titans", "Ashish Nehra", 10, 1, "Hardik Pandya", 1000000);
    insert_team("Mumbai Indians", "Sachin Tendulkar", 20, 3, "Kevin Pollard", 2000000);

    insert_plyr("Gujarat Titans", "Shubhman Gill", 2000000);
    insert_plyr("Gujarat Titans", "Abhinav Malohar", 2000000);
    insert_plyr("Gujarat Titans", "Sai Sudarshan", 2000000);
    insert_plyr("Gujarat Titans", "David Miller", 2000000);
    insert_plyr("Gujarat Titans", "Dasun Shanaka", 2000000);
    insert_plyr("Mumbai Indians", "Foo Bar", 2000000);
    insert_plyr("Mumbai Indians", "Foo1 Bar1", 2000000);
    traverse_team();
//    traverse_player("Gujarat Titans");
    traverse_player("Mumbai Indians");
    return 0;
}
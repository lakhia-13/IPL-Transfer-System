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

void insert_team(tm* head, char *t, char *men, int gw, int gl){
  tm* newTeam = malloc(sizeof(tm));
  strncpy(newTeam->tname,t,str_len);
  newTeam->tname[str_len-1] = '\0';
  strncpy(newTeam->mentor,men,str_len);
  newTeam->mentor[str_len-1] = '\0';
  newTeam->games_won = gw;
  newTeam->games_lost = gl;
  newTeam->node_p = NULL;
  newTeam->next_team = NULL;
 
  if (head == NULL){
    head = newTeam;
  }
  else {
    tm* current = head;
    while (current->next_team != NULL){
      current = current->next_team;
  }
    current->next_team = newTeam;
  }
};

void insert_capt(tm* head, char* team, char* capt, float sal){ 
  tm* temp = head;
  while (temp!=NULL){
    if (team == temp->tname){
      break;
    }
  }
  plyr* newCapt = malloc(sizeof(plyr));
  strncpy(newCapt->pname,team,str_len);
  newCapt->pname[str_len-1] = '\0';
  newCapt->salary = sal;
};

void traverse_team(tm* head){
  tm *temp = head;
  while(temp != NULL){
    printf("Team : %s\n", temp->tname);
    printf("Mentor : %s\n", temp->mentor);
    printf("Games won : %d", temp->games_won);
    printf("Games lost : %d", temp->games_lost);
    temp = temp->next_team;
  }
};

void traverse_player();

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
  tm* head = NULL;
  insert_team(head, "Manchester City", "Pepe", 10, 1);
  traverse_team(head);
  return 0;
}

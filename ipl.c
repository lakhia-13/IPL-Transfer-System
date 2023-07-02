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

void insert_team(char *t, char *men, int gw, int gl, char *cname, float sal) {
    tm *newTeam = malloc(sizeof(tm));
    newTeam->node_p = malloc(sizeof(plyr));
    strcpy(newTeam->tname, t);
    strcpy(newTeam->mentor, men);
    newTeam->games_won = gw;
    newTeam->games_lost = gl;
    strcpy(newTeam->node_p->pname, cname);
    newTeam->node_p->next_player = NULL;
    newTeam->node_p->salary = sal;
    newTeam->next_team = NULL;
    tm *current = head;

    if (!current) {
        head = newTeam;
    } else {
        while (current->next_team) {
            current = current->next_team;
        }
        current->next_team = newTeam;
    }
}

void insert_plyr(char *team, char *playr, float sal) {
    tm *temp = head;
    plyr *currentp = malloc(sizeof(plyr));
    while (temp->next_team) {
        if (!strcmp(team, temp->tname)) {
            break;
        }
        temp = temp->next_team;
    }
    plyr *curp = temp->node_p;
    while (curp->next_player) {
        curp = curp->next_player;
    }
    strcpy(currentp->pname, playr);
    currentp->salary = sal;
    currentp->next_player = NULL;
    curp->next_player = currentp;
}

void traverse_player(char *team) {
    tm *temp = head;
    while (temp) {
        if (!strcmp(team, temp->tname)) break;
        temp = temp->next_team;
    }
    plyr *cup = temp->node_p->next_player;
    while (cup) {
        printf("Player : %s\n", cup->pname);
        printf("Salary : %f\n\n", cup->salary);
        cup = cup->next_player;
    }
}

void get_team() {
    tm *temp = head;
    while (temp) {
        printf("Team : %s\n", temp->tname);
        printf("Mentor : %s\n", temp->mentor);
        printf("Captain : %s\n", temp->node_p->pname);
        printf("Salary : %f\n", temp->node_p->salary);
        printf("Games won : %d\n", temp->games_won);
        printf("Games lost : %d\n\n", temp->games_lost);
        temp = temp->next_team;    
    }
}

void del_team(char *x) {
    tm *temp = head;
    while (temp->next_team) {
        if (!strcmp(temp->next_team->tname, x)) {
            temp->next_team = temp->next_team->next_team;
        }
        temp = temp->next_team;
    }
}


void del_player(char *t, char *p) {
    tm *temp = head;
    
    while (temp->next_team) {
        if (!strcmp(temp->tname, t)) break;
        temp = temp->next_team;
    }
    plyr* cpr = temp->node_p;
    while (cpr->next_player) {
        if (!strcmp(cpr->next_player->pname, p)) {
            cpr->next_player = cpr->next_player->next_player;
            return;
        }
        cpr = cpr->next_player;
    }
}

int checkPlayer(plyr* pl, char* p) {
    while(pl->next_player){
        if(!strcmp(pl->pname, p)){
            printf("Player : %s\n", pl->pname);
            printf("Salary : %f\n\n", pl->salary);
            return 1;
        }
        pl = pl->next_player;
    }
    return 0;
}

int get_player(char *p) {
    tm *temp = head;
    while (temp) {
        plyr *pl = temp->node_p->next_player;
        if (checkPlayer(pl, p)) {
            return 1;
        }
        temp = temp->next_team;
    }
    return 0;
}

int main() {
  insert_team("Gujarat Titans", "Ashish Nehra", 10, 1, "Hardik Pandya", 1000000);
  insert_team("Mumbai Indians", "Sachin Tendulkar", 20, 3, "Kevin Pollard", 2000000);
  insert_team("Chennai Super Kings", "MSD", 40, 5, "Ashwin", 8000000);
  insert_team("Rajasthan Royals", "David Warner", 30, 1, "John Smith", 3000000);
  insert_plyr("Gujarat Titans", "Shubhman Gill", 2000000);
  insert_plyr("Gujarat Titans", "Abhinav Malohar", 2000000);
  insert_plyr("Gujarat Titans", "Sai Sudarshan", 2000000);
  insert_plyr("Gujarat Titans", "David Miller", 2000000);
  insert_plyr("Gujarat Titans", "Dasun Shanaka", 2000000);
  insert_plyr("Mumbai Indians", "Rohit Sharma", 5000000);
  insert_plyr("Mumbai Indians", "Suryakumar Yadav", 2000000);
  get_team();
  get_player("Shubhman Gill");
  del_team("Chennai Super Kings");
  del_player("Gujarat Titans","Shubhman Gill");
  get_team();

  here :
    printf("----MENU----\n");
    printf("1) Insert Team \n2) Insert Player \n3) Delete Team \n4) Delete Player \n5) Get Team \n6) Get Player \n7) Exit \n");
    printf("\nEnter choice : ");
    char tn1[str_len];
    char mn1[str_len];
    char cn1[str_len];
    int gw,gl;
    float sl1;
    char tn2[str_len];
    char pn2[str_len];
    float sl2;
    char tn3[str_len];
    char tn4[str_len];
    char pn4[str_len];
    char tn5[str_len];
    char pn6[str_len];
    int choice;
    scanf("%d", &choice);
    switch (choice){
      case 1:
        printf("Enter team name : ");
        scanf("%s",&tn1);
        printf("Enter mentor name : ");
        scanf("%s",&mn1);
        printf("Enter number of games won : ");
        scanf("%d",&gw);
        printf("Enter number of games lost : ");
        scanf("%d",&gl);
        printf("Enter captain name : ");
        scanf("%s",&cn1);
        printf("Enter captain salary : ");
        scanf("%f",&sl1);
        insert_team(tn1, mn1, gw, gl, cn1, sl1);
        goto here;
        break;

      case 2:
        printf("Enter team name : ");
        scanf("%s",&tn2);
        printf("Enter player name : ");
        scanf("%s",&pn2);
        printf("Enter player salary : ");
        scanf("%f",&sl2);
        insert_plyr(tn2, pn2, sl2);
        goto here;
        break;

      case 3:
        printf("Enter team name : ");
        scanf("%s",&tn3);
        del_team(tn3);
        goto here;
        break;

      case 4:
        printf("Enter team name : ");
        scanf("%s",&tn4);
        printf("Enter player name : ");
        scanf("%s",&pn4);
        del_player(tn4, pn4);
        goto here;
        break;

      case 5:
        get_team();
        goto here;
        break;

      case 6:
        printf("Enter player name : ");
        scanf("%s",&pn6);
        get_player(pn6);
        goto here;
        break;

      case 7:
        return 0;
  }
}

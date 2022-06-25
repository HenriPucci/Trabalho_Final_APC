#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct team{
  int id;
  char name[50];
  char position[4];
  int age;
}Team;

typedef struct player_match{  //declarando structs
  int assist_numb;
  int kills_numb;
  int deaths_numb;
}Player_match;

typedef struct match{
  int team_total_kills;
  int adversary_total_kills;
  char result;
  int team_total_towers_destroyed;
  int adversary_total_towers_destroyed;
  Player_match player_match[5];
}Match;

//declarando funcoes
void menu();
void register_team(char *team_name,char *technician,Team player[]);
void list_team(char *team_name,char *technician,Team player[]);
void edit_id(int i,Team player[]);
void register_match(Match match[],int *match_quantity,Player_match player_match[]);
Player_match register_player_match();
void list_matches(Match match[],int match_quantity,Player_match player_match[],Team player[]);
void search_player(Team player[]);
void total_kills_assists(Match match[],int match_quantity,Player_match player_match[]);
int worst_game_pontuation(Match match[],int match_quantity,Player_match player_match[],Team player[]);
int best_game_pontuation(Match match[],int match_quantity,Player_match player_match[],Team player[]);

int main() {

  Team player[5];
  Player_match player_match[5];
  Match match[10];
  
  int match_quantity,option,i;
  char team_name[50],technician[50];

  match_quantity = 0;
 
  do{

    menu();//apresenta menu
    scanf("%d", &option);

    system("clear || cls"); //limpando tela

    switch(option){

      case 1: //opcao registra equipe

        register_team(team_name,technician,player);

      break;

      case 2: //opcao lista equipe

        list_team(team_name,technician,player);

      break;

      case 3: //opcao edita jogador

        edit_id(i,player);
            
      break;

      case 4: // opcao cadastra partida

        register_match(match,&match_quantity,player_match);

      break;

      case 5: //opcao lista partida

        list_matches(match,match_quantity,player_match,player);

      break;

      case 6: //opcao pesquisa player

        search_player(player);

      break;

      case 7: //opcao apresenta total kills e assists

        total_kills_assists(match,match_quantity,player_match);

      break;

      case 8:

        worst_game_pontuation(match,match_quantity,player_match,player);

      break;

      case 9: // opcao maior pontuacao do game

        best_game_pontuation(match,match_quantity,player_match,player);
      
      break;

      default: //validando opcao escolhida
      
        if(option != 10){
          
          printf("==========================================\n\n");
          printf(" This option do not exist!! Please choose an option that exists!! \n");
        }

    }

  }while(option != 10);

  printf(" Thanks for using my program !!!\n");//despedida
  printf(" BYE.");


  return 0;
}

void menu(){ //funcao imprime menu

  printf("\n\n==========================================");
  printf("\n\n Choose an Option:\n");
  printf("\n\n Type (1)  to Register the Team  \n");
  printf(" Type (2)  to List the Team \n");
  printf(" Type (3)  to Edit Player \n");
  printf(" Type (4)  to Register a Match \n");
  printf(" Type (5)  to List a Match \n");
  printf(" Type (6)  to Search a Player \n");
  printf(" Type (7)  to Show all kills and Assists \n");
  printf(" Type (8)  to Show Lowest Scoring Player \n");
  printf(" Type (9)  to Show Highest Scoring Player \n");
  printf(" Type (10) to Leave \n\n");
  printf("=========================================\n\n");

}

//funcao registra time
void register_team(char *team_name,char *technician,Team player[]){

  printf("=========== RECORDING TEAM ========== \n\n");
  printf(" Whrite the Team Name: ");
  scanf(" %[^\n]s",team_name);
  printf("\n Whrite the Technician Name: ");  
  scanf(" %[^\n]s",technician);
  printf("\n=================================");

    for(int i = 0; i < 5; i++){ //registrando informacoes
        
      player[i].id = (i+1); // igualando id ao contador
      printf("\n\n Id: %d\n\n",player[i].id); 
      printf(" Whrite the Player Name: ");
      scanf(" %[^\n]s",player[i].name);
      printf(" Whrite the Player Position (ADC, SUP, MID, TOP or JG): ");        
      scanf(" %[^\n]s",player[i].position);
        
        //validando posicao
        while(strcmp(player[i].position,"ADC")!= 0 && strcmp(player[i].position,"SUP")!= 0 && strcmp(player[i].position,"MID")!= 0 && strcmp(player[i].position,"TOP")!= 0 && strcmp(player[i].position,"JG")!= 0){
          
          printf("\n Invalid Position!!! Enter an Available Position: ");
          scanf(" %[^\n]s",player[i].position);
        
        }
      
      printf(" Type the Player Age: ");
      scanf("%d",&player[i].age);

        //validando idade
        while(player[i].age < 0 || player[i].age > 150){
          
          printf("\n Invalid Age!! Please, whrite a Valid Age: ");
          scanf("%d",&player[i].age);
        
        }
    }
}

//funcao imprime time
void list_team(char *team_name,char *technician,Team player[]){

  printf("=========== TEAM ========== \n\n");
  printf("        TEAM NAME: %s \n",team_name);
  printf("        TECHNICIAN: %s \n\n",technician);

    for(int i = 0; i < 5; i++){
      
      printf(" Id: %d \n\n",player[i].id);
      printf(" Player: %s \n",player[i].name);
      printf(" Position: %s \n",player[i].position);
      printf(" Age: %d\n\n",player[i].age);
      
    }
}

//funcao edita player
void edit_id(int i,Team player[]){
  
  char confirm_edit;
  
  printf("=========== EDITING ID ========== \n\n");
  printf(" Type the Id: "); //recebendo id que deseja editar
  scanf("%d",&i);
  printf(" Player: %s\n",player[i-1].name);
  printf(" Position: %s\n",player[i-1].position);
  printf(" Age: %d\n\n",player[i-1].age); //mostrando informacoes
  printf(" Want to Edit this Player? (S/N)");
  getchar();
  scanf(" %c",&confirm_edit);
  
    if(confirm_edit == 's'){ //confirmando se deseja editar
      
      printf(" Whrite the New Player Name: ");
      scanf(" %[^\n]s",player[i-1].name);
      printf(" White the New Position (ADC, SUP, MID, TOP or JG): ");
      scanf(" %[^\n]s",player[i-1].position);

        //validando posicao
        while(strcmp(player[i-1].position,"ADC")!= 0 && strcmp(player[i-1].position,"SUP")!= 0 && strcmp(player[i-1].position,"MID")!= 0 && strcmp(player[i-1].position,"TOP")!= 0 && strcmp(player[i-1].position,"JG")!= 0){
          
          printf("\n Invalid Position!!! Enter an Available Position: ");
          scanf(" %[^\n]s",player[i-1].position);
        
        }
      
      printf(" Type the New Age: ");
      scanf("%d",&player[i-1].age);

        //validando idade
        while(player[i-1].age < 0 || player[i-1].age > 150){
          
          printf("\n Invalid Age!! Please, whrite a Valid Age: ");
          scanf("%d",&player[i-1].age);
        }
    }
}

// funcao registra partida
void register_match(Match match[],int *match_quantity,Player_match player_match[]){
  
  printf("=========== RECORDING MATCH ========== \n\n");
  
  //registrando cada player
  for(int j = 0; j < 5; j++){
    
    printf("\n Player %d\n\n",j+1);
    match[*match_quantity].player_match[j] = register_player_match();
    
  }
    
  printf("\n++++++\n\n");
  printf("Number of Deaths from the Adversary Team: ");
  scanf("%d",&match[*match_quantity].adversary_total_kills);
  printf("Number of Team Towers Destroyed: ");
  scanf("%d",&match[*match_quantity].team_total_towers_destroyed);
      
    //validando quantidade
    while(match[*match_quantity].team_total_towers_destroyed < 0 ||match[*match_quantity].team_total_towers_destroyed > 11){
        
      printf("\nInvalid Number!! Please insert a Valid Number: ");
      scanf("%d",&match[*match_quantity].team_total_towers_destroyed);
      
    }
    
  printf("Number of Adversary Towers Destroyed: ");
  scanf("%d",&match[*match_quantity].adversary_total_towers_destroyed);

    //validando quantidade
    while(match[*match_quantity].adversary_total_towers_destroyed < 0 || match[*match_quantity].adversary_total_towers_destroyed > 11){
        
      printf("\nInvalid Number!! Please insert a Valid Number: ");
      scanf("%d",&match[*match_quantity].adversary_total_towers_destroyed);
      
    }
    
  printf("Result:( Press (v) for Victory / Press (d) for Defeat ): ");
  scanf(" %[^\n]s",&match[*match_quantity].result);

    //validando vitoria ou derrota
    while(strcmp(&match[*match_quantity].result,"v")!= 0 && strcmp(&match[*match_quantity].result,"d")!= 0){
        
      printf("\nPlease, Choose Between the Possible Results (v/d): ");
        scanf(" %[^\n]s",&match[*match_quantity].result);
      
    }
  (*match_quantity)++; //contador de partida
  
}

// cadastrando cada jogador na partida
Player_match register_player_match(){
  
  Player_match playermatch;
  
  printf("Assist Quantity: ");
  scanf("%d",&playermatch.assist_numb);
  printf("Kills Quantity: ");
  scanf("%d",&playermatch.kills_numb);
  printf("Deaths Quantity: ");
  scanf("%d",&playermatch.deaths_numb);

  return playermatch;
}

//funcao imprime partidas cadastradas
void list_matches(Match match[],int match_quantity,Player_match player_match[],Team player[]){
  
  int total_pontuation[500];
  int position;
  int count;
  int bigger_match_pontuation[500];
  int kills_pontuation[500];
  int assist_pontuation[500];
  int total_team_match_kill;
  int total_team_match_deaths;
  
  for(int i = 0; i < match_quantity; i++){ //Array de acordo com partidas
    
    printf("=========== MATCH %d ========== \n\n",(i+1));
      
      //verificando se resultado foi vitoria ou derrota
      if(strcmp(&match[i].result,"v")== 0){
        printf("     VICTORY \n\n");
      }else{
        printf("     DEFEAT \n\n");
      }
    
    printf("Team Towers Destroyed: %d\n\n",match[i].team_total_towers_destroyed);
    printf("Adversary Towers Destroyed: %d\n\n",match[i].adversary_total_towers_destroyed);

    //position = 0;
    total_team_match_kill = 0; //zerando variaveis
    total_team_match_deaths = 0;
    
    for(int j = 0; j < 5; j++ ){ //Array de acordo com jogadores
      
      //verificando total de kills do time na partida
      total_team_match_kill = total_team_match_kill + match[i].player_match[j].kills_numb;

      //verificando total de deaths do time na partida
      total_team_match_deaths = total_team_match_deaths + match[i].player_match[j].deaths_numb;

      //verificando pontuacao na partida de cada jogador
      kills_pontuation[j] = match[i].player_match[j].kills_numb * 3;
      assist_pontuation[j] = match[i].player_match[j].kills_numb;

      total_pontuation[j] = kills_pontuation[j] + assist_pontuation[j];

        //verificando a maior pontuacao
        if(total_pontuation[j] > bigger_match_pontuation[i]){
          
          bigger_match_pontuation[i] = total_pontuation[j];
          position = j;//verificando posicao da maior pontuacao !!!!! ERRO
        
        }
      
    }
    
    printf("Team Kills: %d\n\n",total_team_match_kill);
    printf("Team Deaths: %d\n\n",total_team_match_deaths);
    printf("Team Best Pontuation\n\n");
    printf("Player: %s - %s - %d Points \n\n",player[position].name,player[position].position,bigger_match_pontuation[i]);
  
  }
}

//funcao pesquisa jogador
void search_player(Team player[]){
  
  
  char player_search[50];

  printf("================== SEARCH PLAYER =======================\n\n");
  printf(" Whrite the Player that you Want to Search: ");
  scanf(" %[^\n]s",player_search);

    //verificando e imprimindo jogador pesquisado
  for(int i = 0; i < 5; i++){

    if(strcmp(player_search,player[i].name) == 0){
      
      printf("\n Id: %d \n",player[i].id);
      printf(" Player: %s \n",player[i].name);
      printf(" Position: %s \n",player[i].position);
      printf(" Age: %d\n",player[i].age);
    
    }
  }

}

void total_kills_assists(Match match[],int match_quantity,Player_match player_match[]){
  
  int total_kills = 0;
  int total_assists = 0;

    for(int i = 0; i < match_quantity; i++){ //for rodando partidas
      
      for(int j = 0; j < 5; j++ ){ //for rodando jogadores nas partidas
        
        total_kills = total_kills + match[i].player_match[j].kills_numb; //total de kills em todas partidas

        total_assists = total_assists + match[i].player_match[j].assist_numb; //total de deaths em todas partidas
      
      }
    }
    
    printf("=========== MATCH INFORMATIONS ========== \n\n");
    printf("Total Kils: %d\n\n",total_kills);
    printf("Total Assists: %d",total_assists);
}

int worst_game_pontuation(Match match[],int match_quantity,Player_match player_match[],Team player[]){
  
  int game_assist_points[500];
  int game_kill_points[500];
  int worst_pontuation_game;
  int game_pontuation[500];
  int game_kills;
  int game_assists;
  int count;
  int position;

  worst_pontuation_game = 999;//iniciando variavel
  for(int j = 0; j < 5; j++){
    
    
    game_kills = 0; //zerando variaveis
    game_assists = 0;
    
    for(int i = 0; i < match_quantity; i++ ){
      
      game_kills = game_kills + match[i].player_match[j].kills_numb;
      game_assists = game_assists + match[i].player_match[j].assist_numb;//verificando total de kills e assist no game
   
    }
    
    game_kill_points[j] = game_kills * 3;
    game_assist_points[j] = game_assists; //verificando total de pontos
    game_pontuation[j] = game_kill_points[j] + game_assist_points[j];  
    
      //verificando menor pontuacao do game  
      if(game_pontuation[j] < worst_pontuation_game){
        
        worst_pontuation_game = game_pontuation[j];
        position = j;//posicao da menor pontuacao     
      
      }
      
  }
  
  printf("========== WORST GAME PONTUATION ========== \n\n");
  printf("     %s - %s - %d Points \n",player[position].name,player[position].position,worst_pontuation_game);
  
  return worst_pontuation_game;
}

int best_game_pontuation(Match match[],int match_quantity,Player_match player_match[],Team player[]){
  
  int game_assist_points[500];
  int game_kill_points[500];
  int best_pontuation_game;
  int game_pontuation[500];
  int game_kills;
  int game_assists;
  int count;
  int position;

  best_pontuation_game = 0;//iniciando variavel
  for(int j = 0; j < 5; j++){
    
    
    game_kills = 0; //zerando variaveis
    game_assists = 0;
    
    for(int i = 0; i < match_quantity; i++ ){
      
      game_kills = game_kills + match[i].player_match[j].kills_numb;
      game_assists = game_assists + match[i].player_match[j].assist_numb; //verificando total de kills e assists no game
   
    }
    
    game_kill_points[j] = game_kills * 3;
    game_assist_points[j] = game_assists; //verificando total de pontos
    game_pontuation[j] = game_kill_points[j] + game_assist_points[j];  
    
    //verificando maior pontuacao do game  
      if(count == 0){
        
        best_pontuation_game = game_pontuation[j];
        count ++;
      
      }else if(game_pontuation[j] > best_pontuation_game){
        
        best_pontuation_game = game_pontuation[j];
        position = j;//posicao da maior pontuacao     
      
      }
      
  }
    
  printf("========== BEST GAME PONTUATION ========== \n\n");
  printf("     %s - %s - %d Points \n",player[position].name,player[position].position,best_pontuation_game);
  
  return best_pontuation_game;
}
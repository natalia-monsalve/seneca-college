// Name: Natalia Monsalve
// codeQuest.c

#include <stdio.h>
#include <stdbool.h>

void clearScreen();
int validate(int low, int high);
void newGame();
void load();
void rest_at_inn(float* days_remaining, int* hp_remaining, int max);
void train(float* days_remaining, int* hp_remaining, int* experience);
void battle_demon_lord(int* current_hp);
void battleSequence(float* days, int* curHP, int* exp, int maxHP, int str, int def, int intel, int luck);

bool flag = false;

int main(void)
{
  printf("+-----------------------+\n");
  printf("|                       |\n");
  printf("|      CODE QUEST       |\n");
  printf("|                       |\n");
  printf("+-----------------------+\n");
  
  int input = 0;
 
  do {
    printf("--Main Menu--\n\n");
      
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n\n");
      
    input = validate(1, 3);
  } while (input != 3 && flag == false);  
  return 0;
}

void clearScreen()
{
  int i;
  for (i = 0; i <= 40; i++) {
    printf("\n");
  }
}

int validate(int low, int high) 
{
  int input = 0;
  printf("Select: ");
  
  do {
    scanf("%d", &input);
    if (input == low) {
      newGame();
    }
    else if (input > low && input < high) {
      load();
    }
    else if (input == high) {
      printf("Good Bye!");
    }
    else {
      printf("Invalid input, try again: ");
    }
  } while (input < low || input > high);
  return input;
}

void newGame() 
{
  float playerStrength, playerSpeed, playerDefense, playerIntelligence = 0;
  float strengthRatio, speedRatio, defenseRatio, intelligenceRatio = 0;
  int sum, luck, move = 0;
  float playerHP = 10;
  float enemyStrength = 30;
  float enemyDefense = 40;
  float enemyIntelligence = 25;
  float enemyHP = 10;
  float attackPower, magicPower = 0;
  
  clearScreen();
  
  printf("Character Creation\n");
  printf("Please enter your desired stats for your character:\n\n");
  
  printf("Enter strength: ");
  scanf("%f", &playerStrength);
  
  printf("Enter speed: ");
  scanf("%f", &playerSpeed);
  
  printf("Enter defense: ");
  scanf("%f", &playerDefense);
  
  printf("Enter intelligence: ");
  scanf("%f", &playerIntelligence);
  
  printf("\n");
  
  sum = playerStrength + playerSpeed + playerDefense + playerIntelligence;
  
  strengthRatio = playerStrength / sum * 100;
  speedRatio = playerSpeed / sum * 100;
  defenseRatio = playerDefense / sum * 100;
  intelligenceRatio = playerIntelligence / sum * 100;
  
  luck = sum % 30;
  
  printf("Your player's final states are:\n\n");
  
  printf("Strength: %d\n", (int)strengthRatio);
  printf("Speed: %d\n", (int)speedRatio);
  printf("Defense: %d\n", (int)defenseRatio);
  printf("Intelligence: %d\n", (int)intelligenceRatio);  
  printf("Luck: %d\n\n", luck);
    
  printf("Battle Start!\n");
  printf("Your HP: %.0f Enemy HP: %.0f\n", playerHP, enemyHP);
  
  while (playerHP > 0 && enemyHP > 0) {
    printf("1 - Attack\n");
    printf("2 - Magic\n");
    printf("Select your move: ");
    scanf("%d", &move);
    
    if (move == 1) {
      printf("You attacked the enemy!\n");
      
      attackPower = (playerStrength / enemyDefense) * 5;
      enemyHP -= attackPower;
      
      if (enemyHP <= 0) {
        printf("You won!\n");
        flag = true;
      }
      else if (enemyHP > 0) {
        printf("The enemy attacked you!\n");
        
        attackPower = (enemyStrength / playerDefense) * 5;
        playerHP -= attackPower;
        
        if (playerHP <= 0) {
          printf("You died!\n");
          flag = true;
        }
        else {
          printf("\nYour HP: %d Enemy HP: %d\n", (int)playerHP, (int)enemyHP);
        }
      }
    }
    else if (move == 2) {
      printf("You shocked the enemy!\n");
      
      magicPower = (playerIntelligence / enemyIntelligence) * 5;
      enemyHP -= magicPower;
      
      if (enemyHP <= 0) {
        printf("You won!\n");
        flag = true;
      }
      else if (enemyHP > 0) {
        printf("The enemy attacked you!\n");
        
        attackPower = (enemyStrength / playerDefense) * 5;
        playerHP -= attackPower;
        
        if (playerHP <= 0) {
          printf("You died!\n");
          flag = true;
        }
        else {
          printf("\nYour HP: %d Enemy HP: %d\n", (int)playerHP, (int)enemyHP);
        }
      }
    }
  }
}
  
void load() {
  printf("Not Implemented!\n\n");
}

void rest_at_inn(float* days_remaining, int* hp_remaining, int max) 
{
  max = 10;
  int playerExp = 0;
  
  printf("You rested up at the inn\n\n");
  
  *hp_remaining = max;
  *days_remaining = *days_remaining - 1;
}

void train(float* days_remaining, int* hp_remaining, int* experience) 
{
  printf("You did some training!\n\n");
  
  *experience = *experience + 10;
  *hp_remaining = *hp_remaining -2;
  *days_remaining = *days_remaining - 0.5;
}

void battle_demon_lord(int* current_hp)
{
  *current_hp = 0;
  printf("He's too strong!\n");
  printf("\nGame Over!\n");
}

void battleSequence(float* days, int* curHP, int* exp, int maxHP, int str, int def, int intel, int luck)
{
}

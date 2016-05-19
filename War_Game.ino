#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2); // 

  int card = 0; // Set up Integers
  int card1 = 4;
  int card2 = 4;
  int card3 = 4;
  int card4 = 4;
  int card5 = 4;
  int card6 = 4;
  int card7 = 4;
  int card8 = 4;
  int card9 = 4;
  int card10 = 4;
  int card11 = 4;
  int card12 = 4;
  int card13 = 4;
  int cardVar = 0;
  int cardCount = 52;
  int cardDrawn = 0;
  int player1_card = 0;
  int player2_card = 0;
  int player1_point = 0;
  int player2_point = 0;
  int player1_score = 0;
  int player2_score = 0;
  int Suit = 0;
  int time = 220;
  int warTime = 1750;
  

byte heart[8] = // Set up custom characters using binary code representing each pixel on the display
{
  B00000,
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte diamond[8] =
{
  B00000,
  B00100,
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte spade[8] =
{
  B00000,
  B00100,
  B01110,
  B11111,
  B11011,
  B00100,
  B01010,
  B00000,
};

byte club[8] =
{
  B00000,
  B01110,
  B00100,
  B10101,
  B11111,
  B10101,
  B00100,
  B00000,
};

void setup() {                  // Set up to run once
 pinMode(13, INPUT);            // Button pin setup 
 lcd.begin(16,2);               // LCD Set up
 lcd.createChar(1, spade);      // Creates custom suit characters to be referenced later
 lcd.createChar(2, club);
 lcd.createChar(3, heart);
 lcd.createChar(4, diamond);
 lcd.clear();                   // Reset LCD
 lcd.setCursor(0,0);            // Display Intro Screen by setting cursor location then printing
 lcd.print("P1 Card//");
 lcd.setCursor(9,0);
 lcd.print("P2 Card");
 lcd.setCursor(0,1);
 lcd.print("P1");
 lcd.setCursor(11,1);
 lcd.print("P2");
 randomSeed(analogRead(5));     // Start Random Number Generator by reading an analog pin without data input
 

 if (digitalRead(13) == HIGH)   // Activates Lightning Rounds if button is pressed during startup
   {
     time = 20;
     warTime = 30;
   }
   
}

void loop() 
{
  while (cardCount > 0) // Loops continuously until there are no cards left to draw
  {

    if (digitalRead(13) == HIGH) // Checks for button press
    {
      if (warTime == 30) // Runs Lightning Rounds
      {
        lcd.setCursor(0,0);
        lcd.print("LIGHTNING ROUNDS");
      }
      delay(time); // waits for a moment
      
      chooseCard(); // Picks a random card
      player1_card = cardDrawn; // Saves card for P1
      
      displayCard(); // Displays P1's Card
      
      chooseCard(); // Picks a random card
      player2_card = cardDrawn; // Saves card for P2

      displayCard(); // Displays P2's Card
    
      chooseWinner(); // Determines Winner
    
      displayPoints(); // Displays Points for both players
      
      cardCount = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8 + card9 + card10 + card11 + card12 + card13; // Resets card counter
    }
    
  }
  if (player1_score > player2_score) // After there are no cards left a winner is decided based on scores
    player1_win();
  
  if (player1_score < player2_score)
    player2_win();
    
  if (player1_score == player2_score)
    tie_win();

}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Game Functions

void chooseCard(void)
{
  cardDrawn = 0; // Resets Variables
  card = 0;
  
  while (cardDrawn == 0) // Determines If a card can be drawn then draws it
  {
    if ((card == 1) && (card1 > 0)){ // If a card has already been drawn four times that card can not be drawn again
      cardVar = card1--; // Decreases the amount of a given card in the deck
      cardCount--; //Decreases the amount of cards in the deck
      cardDrawn = 1; // Sets Global variable to the card value
    }
    if ((card == 2) && (card2 > 0)){
      cardVar = card2--;
      cardCount--;
      cardDrawn = 2;
    }
    if ((card == 3) && (card3 > 0)){
      cardVar = card3--;
      cardCount--;
      cardDrawn = 3; 
    } 
    if ((card == 4) && (card4 > 0)){
      cardVar = card4--;
      cardCount--;
      cardDrawn = 4;
    }
    if ((card == 5) && (card5 > 0)){
      cardVar = card5--;
      cardCount--;
      cardDrawn = 5;
    }
    if ((card == 6) && (card6 > 0)){
      cardVar = card6--;
      cardCount--;
      cardDrawn = 6; 
    }
    if ((card == 7) && (card7 > 0)){
      cardVar = card7--;
      cardCount--;
      cardDrawn = 7;
    }
    if ((card == 8) && (card8 > 0)){
      cardVar = card8--;
      cardCount--;
      cardDrawn = 8;    
    }
    if ((card == 9) && (card9 > 0)){
      cardVar = card9--;
      cardCount--;
      cardDrawn = 9;   
    }
    if ((card == 10) && (card10 > 0)){
      cardVar = card10--;
      cardCount--;
      cardDrawn = 10; 
    }
    if ((card == 11) && (card11 > 0)){
      cardVar = card11--;
      cardCount--;
      cardDrawn = 11;    
    }
    if ((card == 12) && (card12 > 0)){
      cardVar = card12--;
      cardCount--;
      cardDrawn = 12;    
    }
    if ((card == 13) && (card13 > 0)){
      cardVar = card13--;
      cardCount--;
      cardDrawn = 13;    
    }
    if (cardDrawn == 0){              // Chooses a random card
       card = random(1,14);
    }
    
  }
    
}

void chooseWinner(void)
{
  player1_point = 0;  // Sets both players' points to zero
  player2_point = 0;
  
  while ((player1_point == 0) && (player2_point == 0)) // Waits for 
  {
    if (player1_card > player2_card)  // Determines Winner and allocates points
    {
      player1_point = 1;
    }
    if (player1_card < player2_card)
    {
      player2_point = 1;
    }
    if ((player1_card == player2_card) && (cardCount >= 8)) // If both players have the same card a war occurs
    {
      War();
    }  
    if ((player1_card == player2_card) && (cardCount < 8)) // If both players have the same card and there are not enough cards in the deck for a war, both players get points and the game ends
    {
      cardCount = 0;
      player1_point = 2;
      player2_point = 2;
    }
    
  } 
  
}

void War(void)
{
  delay(warTime);     //Flashes "WAR!" three times quickly
  lcd.setCursor(0,0);
  lcd.print("      WAR!      ");
  delay(time);
  lcd.setCursor(0,0);
  lcd.print("                ");
  delay(time);
  lcd.setCursor(0,0);
  lcd.print("      WAR!      ");
  delay(time);
  lcd.setCursor(0,0);
  lcd.print("                ");
  delay(time);
  lcd.setCursor(0,0);
  lcd.print("      WAR!      ");
  delay(time);
  lcd.setCursor(0,0);
  lcd.print("                ");
  delay(time);
  
  chooseCard();  // Draws three face-down cards from the deck for each player
  chooseCard();
  chooseCard();
  chooseCard();
  chooseCard();
  chooseCard();
  
  chooseCard(); // Draws new cards for each player
   player1_card = cardDrawn; 
  
  chooseCard();
   player2_card = cardDrawn;
  
  displayCard();
  
  if (player1_card > player2_card)  // Gives points based on the outcome of the war
  {
    player1_point = 5;
  }
  else if (player1_card < player2_card)
  {
    player2_point = 5;
  }
  else if (player1_card == player2_card)
  {
    player1_point = 2;
    player2_point = 2;
  }
      
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Win Functions

void player1_win(void)  //Shows the players who won in the end 
{
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(" Player 1 WINS! ");
}

void player2_win(void)
{
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print(" Player 2 WINS! ");
}

void tie_win(void)
{
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,0);
  lcd.print("   Its a TIE!   ");
}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
//Display Control Code


void displayCard(void)
{
  lcd.setCursor(0,0);  // Checks to see what card each player drew
  lcd.print("                 ");
  lcd.setCursor(0,0);
  if (player1_card == 1)
    lcd.print("2");
  else if (player1_card == 2)
    lcd.print("3");
  else if (player1_card == 3)
    lcd.print("4");
  else if (player1_card == 4)
    lcd.print("5");
  else if (player1_card == 5)
    lcd.print("6");
  else if (player1_card == 6)
    lcd.print("7");
  else if (player1_card == 7)
    lcd.print("8");
  else if (player1_card == 8)
    lcd.print("9");
  else if (player1_card == 9)
    lcd.print("10");
  else if (player1_card == 10)
    lcd.print("J");
  else if (player1_card == 11)
    lcd.print("Q");
  else if (player1_card == 12)
    lcd.print("K");
  else if (player1_card == 13)
    lcd.print("A");
    
  lcd.setCursor(13,0);   // Does the same for player 2
  if (player2_card == 1)
    lcd.print("2");
  else if (player2_card == 2)
    lcd.print("3");
  else if (player2_card == 3)
    lcd.print("4");
  else if (player2_card == 4)
    lcd.print("5");
  else if (player2_card == 5)
    lcd.print("6");
  else if (player2_card == 6)
    lcd.print("7");
  else if (player2_card == 7)
    lcd.print("8");
  else if (player2_card == 8)
    lcd.print("9");
  else if (player2_card == 9)
    lcd.print("10");
  else if (player2_card == 10)
    lcd.print("J");
  else if (player2_card == 11)
    lcd.print("Q");
  else if (player2_card == 12)
    lcd.print("K");
  else if (player2_card == 13)
    lcd.print("A");
    
  Suit = random(1,5); // Displays a random suit for each card
  lcd.setCursor(2,0);
  lcd.write(byte(Suit));
  Suit = random(1,5);
  lcd.setCursor(15,0);
  lcd.write(byte(Suit));
}

void displayPoints(void)
{
  if (player1_point == 1)  // Adds to each players total score the amount of points earned
  {
    player1_score++;
  }
  if (player1_point == 2)
  {
    player1_score++;
    player1_score++;
  }
  if (player1_point == 5)
  {
    player1_score++;
    player1_score++;
    player1_score++;
    player1_score++;
    player1_score++;
  }
  if (player2_point == 1)
  {
    player2_score++;
  }
  if (player2_point == 2)
  {
    player2_score++;
    player2_score++;
  }
  if (player2_point == 5)
  {
    player2_score++;
    player2_score++;
    player2_score++;
    player2_score++;
    player2_score++;
  }
  lcd.setCursor(3,1);
  lcd.print(player1_score);  // Prints each player's total score
  
  lcd.setCursor(14,1);
  lcd.print(player2_score);
  
}

//    ("`-''-/").___..--''"`-._
//     `6_ 6  )   `-.  (     ).`-.__.`)
//     (_Y_.)'  ._   )  `._ `. ``-..-'
//   _..`--'_..-_/  /--'_.' ,'
//  (il),-''  (li),'  ((!.-'

#define GREEN_PIN 2
#define YELLOW_PIN 3
#define RED_PIN 4

// BUTTONS
#define plusButton 5
#define minusButton 6 
#define enterButton 7

int guessNumber;
int initialValue = 50;

bool plusButtonPressed;
bool minusButtonPressed;
bool enterButtonPressed;

void setup() {

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  pinMode(plusButton, INPUT_PULLUP);
  pinMode(minusButton, INPUT_PULLUP);
  pinMode(enterButton, INPUT_PULLUP);

  randomSeed(analogRead(0)); 
  guessNumber = random(1, 101);

  Serial.begin(9600);
  Serial.println("Guess a number. 50 is your starting point");
}

void loop() {


  if (digitalRead(plusButton) == LOW) {
    delay(20);
    initialValue++;
    while(digitalRead(plusButton) == LOW);
    delay(20);
    Serial.print("Your guess: ");
  	Serial.println(initialValue);
    
  } else if (digitalRead(minusButton) == LOW) {
    delay(20);
    initialValue--;
    while(digitalRead(minusButton) == LOW);
    delay(20);
    Serial.print("Your guess: ");
  	Serial.println(initialValue);
  }

  if (digitalRead(enterButton) == LOW) {
    if (initialValue == guessNumber) {
      digitalWrite(GREEN_PIN, HIGH);
      delay(1000);
      digitalWrite(GREEN_PIN, LOW);
      guessNumber = random(1, 101);
    } else if (initialValue < guessNumber) {
      digitalWrite(YELLOW_PIN, HIGH);
      delay(1000);
      digitalWrite(YELLOW_PIN, LOW);
    } else {
      digitalWrite(RED_PIN, HIGH);
      delay(1000);
      digitalWrite(RED_PIN, LOW);
    }
  }
}

#define GREEN_PIN 2
#define YELLOW_PIN 3
#define RED_PIN 4

// BUTTONS
#define plusButton 5
#define minusButton 6 
#define enterButton 7

int guess_number;
int initial_value = 50; 

void setup() {

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);

  pinMode(plusButton, INPUT_PULLUP);
  pinMode(minusButton, INPUT_PULLUP);
  pinMode(enterButton, INPUT_PULLUP);

  randomSeed(analogRead(0)); 
  guess_number = random(1, 101);

  Serial.begin(9600);
  Serial.println("Guess a number.");
}

void loop() {
  bool plusButtonPressed = digitalRead(plusButton) == LOW;
  bool minusButtonPressed = digitalRead(minusButton) == LOW;
  bool enterButtonPressed = digitalRead(enterButton) == LOW;

  Serial.print("Your guess: ");
  Serial.println(initial_value);

  if (plusButtonPressed) {
    initial_value++;
    delay(200);
  } else if (minusButtonPressed) {
    initial_value--;
    delay(200);
  }

  if (enterButtonPressed) {
    if (initial_value == guess_number) {
      digitalWrite(GREEN_PIN, HIGH);
      delay(1000);
      digitalWrite(GREEN_PIN, LOW);
      guess_number = random(1, 101);
    } else if (initial_value < guess_number) {
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
